#include <iostream>
using namespace std;

int main() {
	int ans[] = {1,1,2,2,2,8};
	int arr[6];

	for(int i=0;i<6;i++) {
		scanf("%d", &arr[i]);
		printf("%d ", ans[i]-arr[i]);
	}
}