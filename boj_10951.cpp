/* 테스트케이스가 주어지지 않는 경우, EOF 사용 */
#include <iostream>
using namespace std;

int main() {
	int a, b;

	while(scanf("%d %d", &a, &b) != EOF) {
		printf("%d\n",a+b);
	}

	return 0;
}