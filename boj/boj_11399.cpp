/* 이것도 그리디 알고리즘. 모든 사람이 기다리는 시간의 합이 최소가 되려면, 인출시간이 짧은 순으로 해야 함*/
#include <iostream>
#include <algorithm>
using namespace std;

int n;
int p[1001];

int main(){
	// 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값
	scanf("%d", &n);

	for(int i=0;i<n;i++) {
		scanf("%d", &p[i]);
	}

	sort(p, p+n);

	int sum=p[0];

	for(int i=1;i<n;i++) {
		int sum2=0;
		for(int j=0;j<=i;j++) {
			sum2 += p[j];
		}
		sum += sum2;
	}

	printf("%d\n", sum);
		
}

