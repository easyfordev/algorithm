/* 소수점 아래 9자리 -> double -> lf, 9자리까지 출력하려면 %.9lf */
#include <iostream>
using namespace std;

int main() {
	double a, b;
	scanf("%lf %lf", &a, &b);
	printf("%.9lf", a/b);
}