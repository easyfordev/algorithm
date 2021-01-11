#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int n;
queue<int> q;
int main() {
	scanf("%d", &n);

	for(int i=1;i<=n;i++)
		q.push(i);
	
	while(q.size() != 1) { // 카드가 한 장 남을 때 까지 반복
		// 제일 위에 있는 카드를 바닥에 버린다
		q.pop();
		// 그러고나서 제일 위에 있는 카드를, 제일 아래이는 카드 밑으로 옮긴다
		int num = q.front();
		q.pop();
		q.push(num);
	}

	printf("%d\n", q.front());
}