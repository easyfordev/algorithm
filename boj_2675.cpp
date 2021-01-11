#include <iostream>
using namespace std;

int main() {
	int tc;
	scanf("%d", &tc);

	while(tc--) {
		int n;
		string s;

		scanf("%d", &n);
		cin >> s;

		int len = s.length();
		for(int i=0;i<len;i++) {
			for(int j=1;j<=n;j++) {
				printf("%c", s[i]);
			}
		}
		printf("\n");

	}

}