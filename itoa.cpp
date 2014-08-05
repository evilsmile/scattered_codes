#include <stdio.h>

char *itoa_v1(int i)
{
		static char buf[20];
		char *p = buf + 19;
		int flag = 0;
		
		if(i < 0){
				i = -i;			
				flag = 1;
		}
		do{
				*--p = "0123456789abcdef"[(i % 16)];
					i /= 16;
		}while(i != 0);
		if(flag){
				*--p = '-';
		}
		return p;
}

int main()
{
		printf("%s\n", itoa_v1(33));

		return 0;
}
