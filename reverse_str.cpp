#include <cstdio>
#include <string.h>
#include <iostream>

using namespace std;

void reverse_recursive(char *p)
{
		if(*p == '\0'){
				return;
		}
		reverse_recursive(p + 1);
		cout << *p;
}

void reverse_non_recursive(char *p)
{
		char buf[200];
		memset(buf, 0, sizeof(buf));
		memcpy(buf, p, strlen(p) + 1);

		int start = 0;
		int end = strlen(p) - 1;

		char tmp = 0;
		while(start < end){
				tmp = buf[start];
				buf[start] = buf[end];
				buf[end] = tmp;
				start++;
				end--;
		}

		cout << buf << endl;;
}

int main()
{
		char *str = "123456";
		reverse_recursive(str);
		cout << endl;

		reverse_non_recursive(str);

		return 0;
}
