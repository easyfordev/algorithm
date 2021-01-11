#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, k;
queue<int> q;

int main(){
	scanf("%d %d", &n, &k);

	for(int i=1;i<=n;i++)
		q.push(i);
	printf("<");
	while(!q.empty()) {
		int cnt = k-1;
		// K 앞까지 사람들 뒤로 보내기
		while(cnt--) {
			int num = q.front();
			q.pop();
			q.push(num);
		}
		// K번째 사람 제거
		if(q.size() == 1) 
			printf("%d", q.front());
		else 
			printf("%d, ", q.front());
		q.pop();
	}
	printf(">");
}
