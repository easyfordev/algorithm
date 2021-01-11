/* 
	참고한 블로그 (유클리드 호제법)
	https://unagi44.wordpress.com/2018/03/23/c-%EC%B5%9C%EB%8C%80%EA%B3%B5%EC%95%BD%EC%88%98-%EA%B5%AC%ED%95%98%EA%B8%B0-%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C-%ED%98%B8%EC%A0%9C%EB%B2%95/
	https://m.blog.naver.com/PostView.nhn?blogId=kmc7468&logNo=221017936040&proxyReferer=https:%2F%2Fwww.google.com%2F
*/
#include <iostream>
using namespace std;
int a, b;
int gcd(int a, int b) {
	int c;

	while(b!=0) {
		c = a % b;
		a = b;
		b = c;
	}
	
	return a;
}
int main() {
	scanf("%d %d", &a, &b);
	// 큰 수가 앞으로 와야 함. swap
	if( a < b) {
		int c;
		c = a;
		a = b;
		b = c;
	}

	// 최대공약수 구하기
	int g = gcd(a, b);
	printf("%d\n",g);

	// 최소공배수 구하기
	printf("%d\n", a*b / g);
}