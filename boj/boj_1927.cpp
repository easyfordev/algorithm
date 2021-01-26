#include <iostream>
#include <queue>
using namespace std;

int main(){
	int n, num;
	scanf("%d", &n);

	priority_queue<int, vector<int>, greater<int> > pq;

	for(int i=0;i<n;i++) {
		scanf("%d", &num);
		if(num == 0) { // 배열에서 가장 작은 값을 출력하고 그 값을 배열에서 제거
			// 배열이 비어있는 경우인데 출력하라고 하면 0 출력
			if(pq.empty()) {
				printf("0\n");
			} else {
				printf("%d\n", pq.top());
				pq.pop();
			}
		} else { // x를 배열에 넣음
			pq.push(num);
		}
	}
}

