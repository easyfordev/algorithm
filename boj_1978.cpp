#include <iostream>
#include <algorithm>
using namespace std;
int n;
bool isPrime[1001];

int main() {
	// 1~1000까지 소수 찾기
	for(int i=2;i<=1000;i++) {
		for(int j=i*i ; j<=1000;j+=i) {
			isPrime[j] = true;
		}
	}
	// 값 뒤집기
	for(int i=2;i<=1000;i++)
		isPrime[i] = !isPrime[i];
	
	scanf("%d", &n);

	// 입력받아서, 소수인지 판단하기
	int ans = 0, num;
	for(int i=0;i<n;i++) {
		scanf("%d", &num);

		if(isPrime[num])	ans++;
	}

	printf("%d\n", ans);
}