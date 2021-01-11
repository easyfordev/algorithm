#include <iostream>
using namespace std;

int x,y,w,h;

int main() {
	scanf("%d %d %d %d", &x, &y, &w, &h);
	int arr[4];
	arr[0] = x;
	arr[1] = y;
	arr[2] = w-x;
	arr[3] = h-y;

	int minVal = 1001;
	for(int i=0;i<4;i++) {
		if(arr[i] < minVal)
			minVal = arr[i];
	}
	
	printf("%d\n", minVal);
}