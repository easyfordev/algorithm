/*
1953. 탈주범 검거
- 인접할 조건을 잘 생각해야 함 : 나를 받아주려면 내 반대방향과 연결되어있어야 함
*/
#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;

int n, m;
int r,c; // 맨홀 뚜껑 위치
int l; // 탈출 후 소요된 시간
int arr[51][51]; // 구조물 타입 1~7, 0-터널 없음
int check[51][51];

// 방향 : 위, 왼쪽, 아래, 오른쪽
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};;

vector<int> tunnels[8] = {
    {}, // dummy
    {0,1,2,3}, // 1
    {0,2}, // 2
    {1,3}, // 3
    {0,3}, // 4
    {2,3}, // 5
    {1,2}, // 6
    {0,1} // 7
};

int calc(){ // 탈주범이 위치할 수 있는 장소의 개수를 계산, 즉 check가 0이 아닌 칸의 수 세기
    // l시간과 작거나 같은것만 세기
    int cnt = 0;

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++) 
            if(check[i][j] !=0 && check[i][j] <= l)
                cnt++;

    return cnt;
}

int oppositeDir(int d) {
    int odir;
    if(d==0)    odir = 2;
    else if(d==2)    odir = 0;
    else if(d==1)    odir = 3;
    else if(d==3)    odir = 1;

    return odir;
}

void solve(){ // l 시간 뒤의 결과
    queue< pair<int, int> > q;
    // 0. 맨홀 뚜껑으로 들어간다.
    // 이때가 1시간
    check[r][c] = 1;
    q.push(make_pair(r, c));

    // 1. 터널 구조에 따라 움직인다.
    while(!q.empty()) {
        // 큐에서 하나 꺼내기
        int x = q.front().first;
        int y = q.front().second;
        int type = arr[x][y];
        q.pop();

        // 다음 방문할 정점 정하기
        int len = tunnels[type].size();
        for(int i=0;i<len;i++) {
            int dir = tunnels[type][i];
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            // 영역 유효
            if(!(nx>=0 && nx < n && ny>=0 && ny<m)) continue;
            // 아직 방문 안했고
            if(check[nx][ny] != 0)  continue; 

            // 터널이 있고, 그 터널이 나와 연결되어 있는지
            int odir = oppositeDir(dir); // 나를 받아주려면 내 반대방향과 연결되어있어야해

            if(arr[nx][ny] != 0) { 
                int ntype = arr[nx][ny];
                bool flag = false;

                for(int k=0;k<tunnels[ntype].size();k++) {
                    if(tunnels[ntype][k] == odir) {
                        flag = true;
                        break;
                    }
                }

                if(flag == true) { // 나와 연결되어있으면
                    check[nx][ny] = check[x][y] + 1;
                    q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	freopen("input.txt", "r", stdin);
	cin>>T;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        // 이번 TC를 위해 초기화
        memset(check, 0, sizeof(check));

        // 입력 받기
        scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);

        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                scanf("%d", &arr[i][j]);
            }
        }

        solve();
        
        // (결과) 탈주범이 위치할 수 있는 장소의 개수를 계산
        printf("#%d %d\n", test_case, calc());
	}
	return 0; //정상종료시 반드시 0을 리턴해야합니다.
}