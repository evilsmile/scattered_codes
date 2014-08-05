#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void multiply(char *multiplier1, char *multiplier2)
{
		int len1 = strlen(multiplier1);
		int len2 = strlen(multiplier2);

		int len3 = len1 + len2;
		unsigned char *res = (unsigned char*)malloc(len3);
		memset(res, 0, len3);

		int i = 0, j= 0;

		//每一个相应的位相乘
		for(i = 0; i < len1; ++i){
				for(j = 0; j < len2; ++j){
						res[i + j + 1] += (multiplier1[i] - '0') * (multiplier2[j] - '0');
				}
		}

		//处理乘后大于10的情况，往前进位
		for(i = len3 - 1; i > 0; --i){
				res[i - 1] += res[i] / 10;
				res[i] = res[i] % 10;
		}
		//依次打印每一位的值
		for(i = 0; i < len3; ++i){
				//忽略每一个0
				if(i == 0 && res[i] == 0)
						continue;
				printf("%d", res[i]);
		}
		printf("\n");
		free(res);
}

int main()
{
		multiply("100", "2300");
		
		return 0;
}
