template <class T, class N>
struct HashTableNode
{
		T varValue;
		N varName;
		HashTableNode<T, N> *next;
		N Scope;
		N alias;
};

template <class T, class N>
class HashTable
{
private:
		N currentScope(){ return Scope.Value(); }
		int hash(N varName, int moder = 10)
		{
				int i = 0; 
				for(int q = 0; (q < varName.len() + 1); q++)
						i = i + (q * varName[q]);
				i = i % moder;
				return i;
		}

public:
		HashTableNode<T, N> *HTNode[10];

		HashTable(){
				for(int i = 0; i < 10; ++i)
						HTNode[i] = NULL;
				Scope.Push("Global");
				ScopeID = "GlobalScope";
		}

		~HashTable(){
				for(int i = 0; i < 10; ++i){
						HTNode[i] = NULL;
				}
		}
		bool newScope(N ScopeName = ""){
				if(ScopeID == ""){
						ScopeID = "SystemScope";
				}
				if(ScopeName != ""){
						node<N> *tmp;
						tmp = Scope.First;
						while(tmp != NULL){
								if(tmp->value == ScopeName){
										newScope(ScopeName + "X");
										return true;
								}
								tmp = tmp->next;
						}
						delete[] tmp;
						Scope.Push(ScopeName);
						if(Debug) cout << "Starting" << ScopeName << endl;
						return true;
				}else{
						ScopeID += "X";
						Scope.Push(ScopeID);
						if(Debug) cout << "Starting" << ScopeID << endl;
						return true;
				}
		}
		bool endScope(){
				N tmp;
				tmp = currentScope();
				HashTableNode<T, N> *t;

				for(int i = 0; i < 10; ++i){
						t = HTNode[i];
						if(t != NULL){
								while((t != NULL) && (t->Scope == tmp)){
										HTNode[i] = t->next;
										delete t;
										t = HTNode[i];
								}
						}
				}
				tmp = Scope.Pop();

				if(Debug) cout << "ending" << tmp << endl;
				if(Scope.Value() != "") return true;
				return false;
		}
		bool addNode(N varName, T varValue, N iScope = ""){
				int i = 0;
				N S;
				S = currentScope();
				if(iScope != "") S = iScope;
				i = hash(varName);
				HashTableNode<T, N> *t;
				t = HTNode[i];
				while(t != NULL){
						if((t->varName == varName) && (t->Scope == S))
								return false;
						t = t->next;
				}
				t = new HashTableNode<T, N>;
				t->varValue = varValue;
				t->varName = varName;
				t->Scope = S;
				t->next = HTNode[i];
				t->alias = "";
				HTNode[i] = t;

				return true;
		}

		bool addAlias(N varName, N AliasName, N iScope = ""){
				int i = 0;
				N S;
				S = currentScope();
				if(iScope != "") S = iScope;
				i = hash(varName);
				HashTableNode<T, N> *t;
				t = HTNode[i];
				while(t != NULL){
						if((t->varName == varName) && (t->Scope == S))
								return false;
						t = t->next;
				}

				t = new HashTableNode<T, N>;
				t->varName = varName;
				t->Scope = S;
				t->next = HTNode[i];
				t->alias = AliasName;
				HTNode[i] = t;

				return true;
		}

		bool changeNode(N varName, T varValue){
				N S("");
				if(varName.InStr(':') > 0){
						S = Tokenize(varName, ":");
						varName.LTrim(':');
				}
				int i = 0;
				i = hash(varName);
				HashTableNode<T, N> *t;
				t = HTNode[i];
				if(S != "")
						while(t != NULL){
								if((t->varName == varName) && (t->Scope == S)){
										if(t->alias == "")
												t->varValue = varValue;
										else
												changeNode(t->alias, varValue);
										return true;
								}
								t = t->next;
						}
				else
						while(t != NULL){
								if(t->varName == varName){
										if(t->alias == "")
												t->varValue = varValue;
										else
												changeNode(t->alias, varValue);
										return true;
								}
								t = t->next;
						}
				return false;
		}

		T Value(N varName){
				N S("");
				if(varName.InStr(':') > 0){
						S = Tokenize(varName, ":");
						varName.LTrim(':');
				}
				int i = 0;
				i = hash(varName);
				HashTableNode<T, N> *t;
				t = HTNode[i];
				if(S != "")
						while(t != NULL){
								if((t->varName == varName) && (t->Scope == S)){
										if(t->alias == "") return t->varValue;
										else return Value(t->alias);
								}
								t = t->next;
						}
				else
						while(t != NULL){
								if(t->varName == varName){
										if(t->alias == "") return t->varValue;
										else return Value(t->alias);
								}
								t = t->next;
						}
				return NULL;
		}

		bool exists(N varName){
				N S("");
				if(varName.InStr(':') > 0){
						S = Tokenize(varName, ":");
						varName.LTrim(':');
				}
				int i = 0;
				i = hash(varName);
				HashTableNode<T, N> *t;
				t = HTNode[i];
				while(t != NULL){
						if(t->varName == varName) return true;
						t = t->next;
				}
				return false;
		}

		bool existInScope(N varName){
				int i = 0;
				i = hash(varName);
				HashTableNode<T, N> *t;
				t = HTNode[i];
				while(t != NULL){
						if((t->varName == varName) && (t->Scope == currentScope())) return true;
						t = t->next;
				}
				return false;
		}

		T Val(N c){
				if(exists(c))
						return (Value(c));
				else if(isNumber(c)) return c;
				else if(isStringVar(c)) return (c.Trim(""));
				return cEmpty;
		}
		N getScope(){
				return Scope.front();
		}

		N FullVarName(N varName){
				if(varName.InStr(':') > 0){ return varName; }
				int i = 0;
				i = hash(varName);
				HashTableNode<T, N> *t;
				t = HTNode[i];
				while(t != NULL){
						if(t->varName == varName) return t->Scope + ":" + t->varName;
						t = t->next;
				}
				return cEmpty;
		}
private:
		stack<N> Scope;
		N ScopeID;
};


//--------------------------------stack
template <class T>
struct node{
		T value;
		node<T> *next;
};

template <class T>
class stack
{
public:
		char Err[35];
		node<T> *First;
		int Count;

		stack(){ count = 0; strcpy(Err, ""); First = NULL; }
		T Pop(){
				node<T> *tmpNode;
				T tmpVal;

				if(First != NULL){
						tmpVal = First->value;
						tmpNode = First;
						First = First->next;
						delete(tmpNode);
				}
				else
						return NULL;
				return tmpVal;
		}

		T Front(){
				return First->value;
		}

		T Value(){
				if(First != NULL){
						return First->value;
				}
				return "";
		}

		void Push(T v){
				node<T> *tmpNode;
				tmpNode = new node<T>;

				tmpNode->value = v;
				tmpNode->nex = First;
				First = tmpNode;
		}

		bool Last(){
				if(First != NULL)
						if(First->next == NULL)
								return true;
				return false;
		}

		void Empty(){
				T t;
				while(First != NULL)
						t = Pop();
		}

		bool isEmpty(){
				if(First != NULL)
						return false;
				return true;
		}

};

template <class T>
void CopyStack(stack<T>& aStack, stack<T>& bStack)
{
		aStack.Empty();
		stack<T> tmp;
		T a;
		while(bStack.isEmpty() == false)
				tmp.Push(bStack.Pop());
		while(tmp.isEmpty() == false){
				a = tmp.Pop();
				bStack.Push(a);
				aStack.Push(a);
		}
}

