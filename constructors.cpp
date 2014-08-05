#include <iostream>

using namespace std;

class A{
public:
		A(){ cout << "1" << endl; }
		A(A& a){ cout << "2" << endl; }
		A& operator=(A& a){ cout << "3" << endl; return *this;}
};
int main()
{
		A a;
		A b(a);

		return 0;
}
