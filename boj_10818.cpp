#include <iostream>
using namespace std;

int main() {
	int n;
	scanf("%d", &n);

	long minValue = 1000001, maxValue = -1000001;

	for(int i=0;i<n;i++) {
		long num;
		scanf("%ld", &num);
		if(num < minValue)
			minValue = num;
		
		if(num > maxValue) 
			maxValue = num;
		
	}
	printf("%ld %ld\n", minValue, maxValue);

}