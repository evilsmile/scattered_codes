#include <iostream>
#include <string>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <fstream>
#include <sstream>

using namespace std;

struct linkNode
{
		int data;
		struct linkNode *next;
};

class LinkList
{
private:
		struct linkNode *m_list;
		int m_length;
public:
		LinkList();
		~LinkList();
		bool insertAfter(int afterNode, int data);
		bool removeAfter(int removeNode);
		void sort();
		void print();
};

LinkList::LinkList()
{
		m_list = NULL;
		m_length = 0;
}

LinkList::~LinkList()
{
		struct linkNode *p = m_list;
		struct linkNode *q = NULL;
		while(p != NULL){
				q = p;
				p = p->next;
				delete q;
		}
}

bool LinkList::insertAfter(int afterNode, int data)
{
		struct linkNode *tmp = m_list;
		if(afterNode > m_length || afterNode < 0)
				return false;
		if(tmp == NULL){
				tmp = new linkNode;
				tmp->data = data;
				tmp->next = NULL;
				m_length++;
				m_list = tmp;
		}else{
				int i = 0;
				for(i = 0; i < afterNode - 1 && tmp != NULL; i++){
						tmp = tmp->next;
				}
				if(tmp == NULL && m_list != NULL){
						return false;
				}

				struct linkNode *newNode = new linkNode;
				newNode->data = data;
				if(afterNode == 0){
						newNode->next = tmp;
						m_list = newNode;
				}else{
						newNode->next = tmp->next;
						tmp->next = newNode;
				}
				m_length++;
		}
		return true;
}

bool LinkList::removeAfter(int removeNode)
{
		if(removeNode >= m_length || removeNode < 0)
				return false;

		struct linkNode *tmp = m_list;
		for(int i = 0; i < removeNode - 1 && tmp->next != NULL; i++)
				tmp = tmp->next;
		if(tmp->next == NULL && removeNode != 0)
				return false;
		if(removeNode == 0){
				m_list = tmp->next;
				delete tmp;
		}else{
				linkNode *del = tmp->next;
				tmp->next = del->next;
				delete del;
		}
		m_length--;
		return true;
}

void LinkList::sort()
{
		if(m_length < 0)
				return;

		int i = m_length;
		struct linkNode *p = NULL;
		struct linkNode *q = NULL;

		while(i > 0){
				p = m_list;
				while(p != NULL && (q = p->next) != NULL){
						if(p->data <= q->data){
								int tmp = p->data;
								p->data = q->data;
								q->data = tmp;
						}
						p = p->next;
				}
				--i;
		}
}

void LinkList::print()
{
		struct linkNode *p = m_list;
		while(p != NULL){
				printf("%d,", p->data);
				p = p->next;
		}
		printf("\n");
}

int main()
{
		LinkList obj;
		obj.insertAfter(0, 1);
		obj.insertAfter(0, 10);
		obj.insertAfter(1, 2);
		obj.insertAfter(2, 4);
		obj.insertAfter(1, 3);
		obj.print();

		obj.sort();
		obj.print();

		obj.removeAfter(3);
		obj.print();

		return 0;
}
