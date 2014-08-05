#include <iostream>

using namespace std;

int count_one(int x)
{
		int count = 0;
		while(x){
				x &= (x - 1);
				count++;
		}

		return count;
}
int main()
{
		cout << count_one(8) << endl;

		return 0;
}
