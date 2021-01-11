/* 올림을 했을 때, '적어도 몇개?' */
#include <iostream>
using namespace std;

int main() {
	int cnt, avg;
	// 구하는 식 = cnt * (avg-1) +1
	scanf("%d %d", &cnt, &avg);
	printf("%d\n", cnt * (avg-1) +1);
}