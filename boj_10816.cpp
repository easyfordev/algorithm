/* 
처음에는 어려워서 못풀었다. 
	- multiset이라는 멋진 stl 구조를 사용하면 바로 풀 수 있다!(set은 key 중복 X, multiset은 중복 o)
	   => 와 이걸로 풀었더니 시간초과 ... 
	- 우선 정렬하고, equal_range()라는 함수를 사용한다. (또는 upper_bound(), lower_bound() )
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;

vector<int> v;
int main() {
	scanf("%d", &n);
	for(int i=0;i<n;i++) {
		int num;
		scanf("%d", &num);
		v.push_back(num);
	}

	// 정렬하기
	sort(v.begin(), v.end());

	scanf("%d", &m);
	for(int i=0;i<m;i++) {
		int num;
		scanf("%d", &num);
		
		auto p = equal_range(v.begin(), v.end(), num);
		printf("%d ", p.second - p.first);
	}
}