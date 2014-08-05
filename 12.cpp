#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class A;
typedef void (A::*pfn)();
class A{
private:
		void func(){ cout << "run func" << endl; }
public:
		void run(){ cout << "run" << endl; }
		void run_func(){ run_inner(this->func); }
		void run_inner(pfn fun){ (this->*fun)(); }
};

void foo(A *a, pfn r)
{
		(a->*r)(); 
}

int main()
{
		A a;
		foo(&a, &A::run);
		a.run_func();

		return 0;
}
