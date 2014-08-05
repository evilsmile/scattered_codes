#include <cstdio>

void common_longest_substr(char *strA, char *strB)
{
		char *pA = strA;
		char *pB = strB;
		char *pSubstr = NULL;
		int max_len = 0;
		int len = 0;

		while(true){
				char *tmpA = pA;
				//pA的逐位检查到头了，表明检查完了，退出
				if(*pA == '\0')
						break;
				//查找B中和*pA字符一样的位置
				while(*pB && *pA != *pB)
						pB++;

				//查找没有到B的末尾，则表明在B中找到了和*pA一样的字符
				if(*pB != '\0'){
					//如果后面的字符还相同，则比较下一个，长度加1
					while(*pA && (*pA == *pB)){
							pA++;
							pB++;
							len++;
					}
					//比较完了相同的字串，看看是否比最长的还长
					if(max_len < len){
							max_len = len;
							pSubstr = (pA - max_len);
					}
					len = 0;
				}

				//如果B后面还有字串，则可能后面还有更长的，则pB不变，pA重新指回初始的比较位置
				if(*pB != '\0'){
						pA = tmpA;
				}else{//B全部比较完了，A移到下一个字符，重新一一比较
					pA = tmpA + 1;
					pB = strB;
				}
		}

		for(int i = 0; i < max_len; i++){
			 	putchar(pSubstr[i]);
		}
		putchar('\n');

}

int main()
{
		char A[] = "ao123456cdefghijjklmn";
		char B[] = "pmcdefghijjklmn1234a12345678";

		common_longest_substr(A, B);

		return 0;
}
