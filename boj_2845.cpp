#include <iostream>
using namespace std;
int l, p;
int num;

int main() {
	scanf("%d %d", &l, &p);
	int ans = l * p;

	for(int i=0;i<5;i++) {
		scanf("%d", &num);
		printf("%d ", num - ans);
	}
}