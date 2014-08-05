#include <iostream>
#include <fstream>
#include <string.h>
#include <ctype.h>

using namespace std;

#define MAXLINE 1024

int wordCount(char *buf)
{
		int count = 0;
		bool previousAlpha = (isalpha(*buf++) != 0)? true : false;

		while(*buf != '\0'){
				if(!isalpha(*buf)){
						if(previousAlpha){
								++count;
								previousAlpha = false;
						}
				}else{
						previousAlpha = true;
				}
				++buf;
		}
		if(previousAlpha)
				count++;

		return count;
}

int main()
{
		ifstream ifs;
		int count = 0;
		ifs.open("/tmp/test.txt");
		while(ifs.good()){
				char buf[MAXLINE];
				memset(buf, 0, sizeof(buf));
				ifs.getline(buf, sizeof(buf));

				cout << buf << endl;
				count = wordCount(buf);
				cout << count << endl;
		}
		return 0;
}

