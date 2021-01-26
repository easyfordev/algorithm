/* 그리디 알고리즘
어떤 기준으로 할 것인가? 를 생각 - 회의시간 짧은 순, 빨리 시작하는 순 ... 등 반례를 잘 생각해서
이 문제는, 시작시간과 끝시간이 주어지므로 '끝나는 시간이 빠른 순'으로 그리디하게 간다
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;

class Meeting {
public:
	int start, end;
	Meeting(int s, int e) {
		this->start = s;
		this->end = e;
	}
};

bool cmp(const Meeting &a, const Meeting &b) {
	// 끝나는 시간이 빠른 순서대로 정렬
	if(a.end == b.end) {
		return a.start < b.start;
	} else
		return a.end < b.end;
}

int main(){
	scanf("%d", &n);

	vector<Meeting> v;
	for(int i=0;i<n;i++) {
		int a,b;
		scanf("%d %d", &a, &b);

		v.push_back(Meeting(a, b));
	}

	sort(v.begin(), v.end(), cmp);

	int cnt = 1;
	int prev = v[0].end;
	for(int i=1;i<n;i++) {
		if(v[i].start >= prev) {
			cnt++;
			prev = v[i].end;
		} 
	}
	printf("%d\n", cnt);
}
