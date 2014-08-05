#include <iostream>

using namespace std;

class Base1{
public:
		virtual void b1_vfunc(){ cout << "b1_vfunc" << endl; }
		void b1_func(){ cout << "b1_func" << endl; }
};

class Base2{
public:
		virtual void b2_vfunc(){ cout << "b2_vfunc" << endl; }
		void b2_func(){ cout << "b2_func" << endl; }
};

class Derived : public Base1, public Base2{
public:
		void b1_vfunc(){ cout << "d1_vfunc" << endl; }
		void b2_vfunc() { cout << "d2_vfunc" << endl; }
};

typedef void (*Fun)();
int main()
{
		Derived d;
		Base1 *b1 = &d;
		Base2 *b2 = &d;
		b1->b1_vfunc();	
		b2->b2_vfunc();	
		b1->b1_func();

		Fun pFun;

		pFun = (Fun)*((int*)*(int*)b1);
		pFun();

		return 0;
}

