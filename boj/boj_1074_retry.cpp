/* 분할 정복 문제
와 이거 진짜로 처음에 이해가 너무 안가서 ㅋㅋㅋㅋㅋㅋㅋㅋ 나는 바보인가 ... 
* 어차피 분할정복하는 재귀함수 내에서 1-> 2-> 3-> 4 이렇게 순서대로 부르기때문에, cnt를 잘 증가시켜주면 전체가 순서대로 증가함
* 이 문제는 x와 y가 좌표계와 동일함(평소 문제 풀던거랑 다름) 이런것도 익숙해져야함
와 이렇게 풀어도 시간초과나잖아 ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  ~ ~ ~ ~ 
* 이유 : 단순히 주어진 순서대로 방문만 하는 경우 시간초과가 뜬다. 왜냐하면 정사각형이 최대 15*15의=225의 크기를 가질수 있으므로 엄청나게 많은 재귀 호출을 하게 될수 있다.

다시풀자 ㅋ ㅋ ㅋ ㅋ ㅋ ㅋ ㅋ ㅋㅋ ㅋㅋ ㅋ  ㅜㅜㅜㅜㅜㅜㅜㅜ

https://simsimjae.tistory.com/191

*/
#include <iostream>
using namespace std;

int n, r, c;
int cnt=0;

void solve(int size, int y, int x) { // 여기서는 x가 가로, y가 세로다
	if(size == 2) { // 최소크기이면 검사 시작
		if(y == r && x == c) { // 1사분면
			printf("%d\n", cnt);
			return;
		}

		cnt++;
		if(y == r && x +1 == c) { // 2사분면
			printf("%d\n", cnt);
			return;
		}

		cnt++;
		if(y+1 == r && x  == c) { // 3사분면
			printf("%d\n", cnt);
			return;
		}

		cnt++;
		if(y+1 == r && x +1 == c) { // 4사분면
			printf("%d\n", cnt);
			return;
		}
		// 이번 블록(2*2)짜리에 (r,c)가 없을경우, 다음으로 넘어간다
		cnt++;
		return;
	} 
	// 크기가 아직 최소가 아니면, 분할정복
	solve(size/2, y, x); // 1사분면
	solve(size/2, y, x+size/2); // 2사분면
	solve(size/2, y+size/2, x); // 3사분면
	solve(size/2, y+size/2, x+size/2); // 4사분면
	
}

int main(){
	// r행 c열을 몇 번째로 방문했는지 출력
	scanf("%d %d %d", &n, &r, &c);

	solve(1<<n, 0, 0); // 왼쪽 쉬프트연산자는 2의 지수승 곱하기 ~!
}
