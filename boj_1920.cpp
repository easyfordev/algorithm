/* 
탐색을 그냥 2중 for문으로 풀었더니 시간초과났다. 이분탐색으로 찾자 
이분탐색은 반드시 먼저 정렬되어있어야하고,
직접 구현해도 되지만, stl 함수를 써도 된다 (algorithm의 binary_search()
재귀함수를 부를때는 꼭! return 함수() ㅠㅠ
*/

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[100001];

bool binarySearch(int start, int end, int key) {
	// 못찾았을 경우
	if(start > end)	return false;

	int mid = (start +end )/2;
	if(arr[mid] == key) { // 찾았으면
		return true;
	} else if (arr[mid] > key) { // key가 더 작으면,
		return binarySearch(start, mid-1, key);
	} else { // key가 더 크면
		return binarySearch(mid+1, end, key);
	}
}

int main() {
	scanf("%d", &n);

	for(int i=0;i<n;i++) {
		scanf("%d", &arr[i]);
	}

	sort(arr, arr+n);

	int key;
	scanf("%d", &m);
	for(int i=0;i<m;i++) {
		scanf("%d", &key);
		// if(binary_search(arr.begin(), arr.end(), key)) {
		if(binarySearch(0, n-1, key)) {
			printf("1\n");
		} else {
			printf("0\n");
		}
	}

}