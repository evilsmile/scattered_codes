#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>

using namespace std;

void foo(int m, int n)
{
		cout << "m=" << m << ", n=" << n << endl;
}

struct Test{
		Test(int){}
		Test(){}
		void fun(){}
};


struct CLS{
		int m_i;
		CLS(int i) : m_i(i){}
		CLS()
		{
				CLS(0);
		}
};

typedef struct AA{
		int b1:5;
		int b2:2;;
}AA;

class Empty{
};


int main()
{
		int b = 3;
		foo(b+=3, b++);
		cout << "b=" << b << endl;

//		Test t();  //应该是Test t;
//		t.fun();
//

//		cout << (true ? 1 : "1") << endl; //?:的操作数应该一致

		unsigned int const size1 = 2;
		char str1[size1];
		str1[0] = '0';
		unsigned int tmp = 0;
//		cin >> tmp;
		unsigned int const size2 = tmp;
		char str[size2];
		cout << "sizeof: " << sizeof(str) << endl;

		CLS obj;
		cout << "obj.m_i: " << obj.m_i << endl;

		float a = 1.0f;
		int& ra = (int&)a;
		cout << (int)a << endl;
		cout << (int&)a << endl;
		cout << boolalpha << ((int)a == (int&)a) << endl;
		float bb = 0.0f;
		int& rbb = (int&)bb;
		cout << (int)bb << endl;
		cout << (int&)bb << endl;
		cout << boolalpha << ((int)bb == (int&)bb) << endl;
		
		vector<int> v;
		v.push_back(100);
		v.push_back(200);
		/* //逆序遍历, size_type是无符号数，i=0时i-1是个很大的整数，产生越界
		for(vector<int>::size_type i = v.size() - 1; i >= 0; --i)
				cout << v[i] << endl;
				*/

		const void* p = NULL;
		const char* psrc = static_cast<const char*>(p);

		char ch = 128;
		printf("%d\n", ch);

		AA aa;
		char cc[100];
		strcpy(cc, "0123456");
		memcpy(&aa, cc, sizeof(AA));
		cout << aa.b1 << endl;
		cout << aa.b2 << endl;

		int aaa = 0;
		//*pp 不可修改
		const int * pp = &aaa;
		//int const * pp = &aaa;
		//pp不可修改
		//int * const pp = &aaa;
//		*pp = 3;

		int w = 4;
		//w += (w++);
		//w += (++w);
		//error
		//w++ += w;
		(++w) += (w++);
		cout << w << endl;

		Empty e;
		cout << sizeof(e) << endl;
#ifdef __cplusplus
		cout << "Compiled by C++" << endl;
#endif
		return 0;
}
