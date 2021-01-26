/* 간단한 것 같은데 엄청 헤매고 틀렸다. */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int main(){
	vector<pair<int, int> > v; // 값, index
	scanf("%d", &n);

	int num;
	for(int i=0;i<n;i++) {
		scanf("%d", &num);
		v.push_back(make_pair(num, i));
	}

	sort(v.begin(), v.end());
	vector<int > ans;
	ans.resize(n);

	int prev = v[0].first;
	int cnt = 0;
	ans[v[0].second] = 0;

	for(int i=1;i<n;i++) {
		// 이전 값과 지금 값이 중복이면
		if(v[i].first == prev) {
			ans[v[i].second] = cnt;
		} else { // 일반적인 경우
			ans[v[i].second] = ++cnt;
			prev = v[i].first;
		}
	}

	// 결과 출력
	for(int i=0;i<n;i++) {
		printf("%d ", ans[i]);
	}

}

