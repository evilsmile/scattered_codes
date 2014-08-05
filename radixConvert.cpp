#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

void binary(int n)
{
		if(n >> 1)
				binary(n >> 1);
		char c = n % 2 + '0';
		putchar(c);
}

void hex(int n)
{
		if(n >> 4)
				hex(n >> 4);
		char c = n % 16;
		if(c > 9){
				putchar('a' + c);
		}else{
				putchar('0' + c);
		}
}

int main()
{
		binary(20);
		putchar('\n');

		hex(20);
		putchar('\n');

		return 0;
}
