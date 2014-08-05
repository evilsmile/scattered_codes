#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int isZhiShu(int num)
{
	int i = sqrt(num);
	int j = 2;
	while(j <= i){
			if(num % j == 0)
					return 0;
			j++;
	}
	return 1;
}
int main()
{
		int test_num = 60;
		int i = 3;
		while(i <= test_num){
				if(isZhiShu(i) == 1)
						printf("%d\t", i);
				i++;
		}

		printf("\n");

		return 0;
}
