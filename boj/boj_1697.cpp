/* 처음에 DFS로 풀려고 했는데 잘 안됐다. 이 문제의 경우 무조건 BFS로 풀어야 하는 것 같다.
다양한 경우의 수가 있고, 그중 최소를 찾아야 하는 경우 BFS로 풀자
*/
#include <iostream>
#include <cstring>
#include <queue>
#define MAX 2000000
using namespace std;

int n, k;
int check[MAX+1];

int main(){
	scanf("%d %d", &n, &k);
	if(n==k) {
		printf("0\n");
		return 0;
	}

	memset(check, -1, sizeof(check));
	queue< int > q;
	check[n] = 0;
	q.push(n);

	while (!q.empty()){
		// 큐에서 하나 꺼내기
		int x = q.front();
		q.pop();

		int next = x-1;
		if(next >=0 && check[next] == -1) {
			check[next] = check[x] + 1;
			q.push(next);
		}

		next = x+1;
		if(next <= MAX && check[next] == -1) {
			check[next] = check[x] + 1;
			q.push(next);
		}

		next = 2*x;
		if( next <= MAX && check[next] == -1) {
			check[next] = check[x] + 1;
			q.push(next);
		}
	}

	printf("%d\n", check[k]);
}
