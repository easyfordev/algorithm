#include <iostream>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);
	
	while(tc--) {
		string str;
		cin >> str;
		int len = str.length();
		int cnt=0, sum=0;
		for(int i=0;i<len;i++) {
			if(str[i] == 'O') {
				cnt++;
			} else {
				cnt = 0;
			}
			sum += cnt;
		}
		printf("%d\n", sum);
	}
}