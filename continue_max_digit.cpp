#include <iostream>
#include <ctype.h>
#include <string.h>

using namespace std;

int continue_max(char *output_str, char *input_str)
{
		char *longest_start = NULL;
		char *p = input_str;
		int curr_len = 0;
		int longest_len = 0;

		while(*p){
				if(isdigit(*p)){
						curr_len++;
				}else if(isalpha(*p)){
						if(longest_len < curr_len){
								longest_len = curr_len;
								longest_start = (p - longest_len);
						}
						curr_len = 0;
				}
				p++;
		}

		//check the tail digits
		if(longest_len < curr_len){
				longest_len = curr_len;
				longest_start = (p - longest_len);
		}
	
		if(longest_start){
			memcpy(output_str, longest_start, longest_len);
			output_str[longest_len] = '\0';
		}else{
				output_str[0] = '\0';
				longest_len = 0;
		}

		return longest_len;
}

int main()
{
		char test_str[] = "abcd123458s124ss123456789";
		char max_int[200];

		continue_max(max_int, test_str);

		cout << max_int << endl;

		return 0;
}
