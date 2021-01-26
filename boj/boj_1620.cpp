/* 이것도 시간 줄이는 문제 
1) map은 key를 기준으로 오름차순 정렬되어서 들어간다.
2) cin은 정말 느리다. scanf가 짱이다. 자료형으로는 써도 되는데, 입력 받을때는 최대한 char[]로 선언해서 받자
3) 문자열은 이분탐색으로 찾아도 된다. (Option)
*/
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int n, m;
string arr[100001];
char str[21];
char com[25];
map<string, int> mm; // string을 key로 해서 오름차순 정렬

int main(){
	scanf("%d %d", &n, &m);
	getchar();

	// 입력받기
	for(int i=1;i<=n;i++) {
		scanf("%s", str);
		string s = str;
		arr[i] = s;
		mm.insert(make_pair(s, i));
	}

	// 결과 출력
	for(int i=1;i<=m;i++) {
		scanf("%s", com);

		if(com[0] >= '0' && com[0] <= '9') {// 입력으로 들어온게 숫자면
			printf("%s\n", arr[atoi(com)].c_str());
			// cout << arr[atoi(com)] << "\n";
		} else { // 입력으로 들어온게 문자면
			printf("%d\n", mm[com]);
			// cout << mm[com] << "\n";
		}
	}
}
