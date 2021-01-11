/* 꼭대기 층인 경우 예외처리 해줘야했다.. 항상 예외 케이스를 잘 생각해야 함. 양쪽 끝 ! */
#include <iostream>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);

	while(T--) {
		int h,w,n; // 층 수, 방 수, 몇번째 손님인지
		
		scanf("%d %d %d", &h, &w, &n);

		int ho, floor;
		if(n%h == 0) {
			ho = n/h;
			floor = h;
		} else {
			ho = n/h + 1;
			floor = n%h;
		}

		if(ho < 10)
			printf("%d0%d\n", floor, ho);
		else
			printf("%d%d\n", floor, ho);

	}

}
