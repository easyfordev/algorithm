/* 이것도 시간 줄이는 문제. 이분탐색 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int n, m;
char str[21];

vector<string> v1, v2;

int main(){
	// 입력받기
	scanf("%d %d", &n, &m);
	getchar();

	for(int i=0;i<n;i++) {
		scanf("%s", str);
		string s = str;
		v1.push_back(s);
	}

	for(int i=0;i<m;i++) {
		scanf("%s", str);
		string s = str;
		v2.push_back(s);
	}
	
	// 정렬하고 탐색
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());

	vector<string> ans;
	for(int i=0;i<n;i++) {
		if(binary_search(v2.begin(), v2.end(), v1[i])) {
			ans.push_back(v1[i]);
		}
	}

	// 정답 출력
	int len = ans.size();
	printf("%d\n", len);
	for(int i=0;i<len;i++) {
		printf("%s\n", ans[i].c_str());
	}
}
