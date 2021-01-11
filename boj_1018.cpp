#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
char arr[51][51];

char board1[8][8] = {
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'}
};
char board2[8][8] = {
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'},
	{'B','W','B','W','B','W','B','W'},
	{'W','B','W','B','W','B','W','B'}
};

int ans = 50*50 + 1;

int solve(int x, int y) { // 시작점마다 다시 칠해야하는 갯수 구하기 (경우 2가지, 왼쪽 위 흰색/검은색)
	// 맨 왼쪽 위가 흰색인 경우
	// printf("함수진입 >> 시작점 : (%d, %d)\n", x, y);

	int cnt1=0, cnt2=0;
	for(int i=x, a=0 ; i<x+8, a<8 ; i++, a++) {
		for(int j=y, b=0 ; j<y+8, b<8 ; j++, b++) {
			if(arr[i][j] != board1[a][b])
				cnt1++;
			if(arr[i][j] != board2[a][b])
				cnt2++;	
		}
	}

	return min(cnt1, cnt2);
}

int main() {
	// 입력받기
	scanf("%d %d", &n, &m);
	getchar();

	for(int i=0;i<n;i++) {
		for(int j=0;j<m;j++) {
			scanf("%1c", &arr[i][j]);
		}
		getchar();
	}

	// 시작점 고르기 (왼쪽 상단)
	for(int i=0 ; i+7 < n ; i++) {
		for(int j=0; j+7 < m;j++) {
			// 최솟값 구하기
			ans = min(solve(i, j), ans);
		}
	}

	printf("%d\n", ans);

}
