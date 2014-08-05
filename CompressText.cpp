/*
 * Compress text with repeated alphas, and the repeated ones are replaced by a number representing repeated times.
 */

#include <iostream>

using std::string;
using std::cout;
using std::endl;

inline char numToAscii(int num)
{
#define NUM_TO_ASCII_OFFSET 48
		return (num + NUM_TO_ASCII_OFFSET);
}

string compressText(const string& text)
{
		string compressedText = "";
		string::const_iterator previousChar = text.begin();
		string::const_iterator currChar = previousChar + 1;
		int charCounter = 1;

		for(; currChar < text.end(); currChar++){
			if(*currChar == *previousChar){
					charCounter++;
					continue;
			}else{
					compressedText += numToAscii(charCounter);
					compressedText += *previousChar;
					charCounter = 1;
					previousChar = currChar;
			}
		}

		//Handle edge situation
		compressedText += numToAscii(charCounter);
		compressedText += *previousChar;

		return compressedText;
}

int main()
{
		cout << compressText("DDDsssab") << endl;

		return 0;
}
