#include <iostream>
#include <cstdlib>

using namespace std;

void quick_sort(int *a, int start, int end, int index)
{
		int left = start, right = end;
		int guard = a[start];
		if(start > end || index > end)
				return;

		while(true){
			while((left < right) && a[right] >= guard)
					right--;
			if(left < right)
					a[left] = a[right];
			else
					break;

			while((left < right) && a[left] <= guard)
					left++;
			if(left < right)
					a[right] = a[left];
			else 
					break;
		}
		a[left] = guard;
		if(left == index){
				cout << a[left];
				return;
		}
		else if(left < index){
			quick_sort(a, left + 1, end, index);
		}else{
			quick_sort(a, start, left - 1, index);
		}
}

int main()
{
		int a[] = {10, 2, 43, 9, 23, 11, 72, 21};
		int size = sizeof(a)/sizeof(a[0]);
		int kth = 2;

		cout << kth << "th: " ;
		quick_sort(a, 0, size - 1, size - kth);

		/*
		for(int i = 0; i < size; i++){
			cout <<  a[i] << " ";
		}
		*/
		cout << endl;

		cout << malloc(0) << endl;
		return 0;
}
