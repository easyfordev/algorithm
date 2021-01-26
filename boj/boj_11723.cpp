/* 매우 낮은 정답률 .. 개선 포인트
1) 입출력 속도 개선 : ios_base::sync_with_stdio(0); cin.tie(); 단, 절대 scanf / cin을 같이 쓰면 안된다
2) (중요) stl을 쓰지말고, 배열의 크기가 최대 20이니 일차원 배열로 푼다
3) (중요) cout 말고 puts로 바꾼다
+ 참고 : 삼항연산자는 속도 개선에 도움이 되지 않았다.
*/
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int m;
bool check[21];

int main(){
	ios_base::sync_with_stdio(0);
 	cin.tie();

	cin >> m;

	for(int tc=0;tc<m;tc++) {
		string str;
		int num;
		cin >> str;

		if(str == "add") {
			cin >> num;
			check[num] = true;
		} else if(str == "remove") {
			cin >> num;
			check[num] = false;
		} else if(str == "check") {
			cin >> num;
			
			if(check[num])	puts("1");
			else puts("0");
			// check[num] ? puts("1") : puts("0");

		} else if(str == "toggle") {
			cin >> num;
			// S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다.
			if(check[num])	check[num] = false;
			else	check[num] = true;
			// check[num] ? check[num] = false : check[num] = true;

		} else if(str == "all") {
			memset(check, true, sizeof(check));
		} else if(str == "empty") {
			memset(check, false, sizeof(check));
		}

	}
}
