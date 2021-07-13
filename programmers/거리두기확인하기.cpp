/*
프로그래머스 - 거리두기 확인하기
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

int dist[6][6];

bool check(int tc, const vector<vector<string>> places) {
    int ddx[] = {-1, -1, 0,  1,  1,  1,  0,  -1, -2, 0,  2,  0};
    int ddy[] = {0,  1,  1,  1,  0,  -1, -1, -1, 0,  2,  0,  -2};

    // 거리가 2보다 작거나 같은 '사람'이 있나 체크한다.
    for(int i=0;i<5;i++) {
        for(int j=0;j<5;j++) {
            // -1이 아니면서, 거리가 2보다 작고, 걔가 사람이면 안된다
            if(dist[i][j] != -1 && dist[i][j] != 0) {
                if(dist[i][j] <= 2 && places[tc][i][j] == 'P') {
                    // printf("위반: (%d,%d)\n", i, j);
                    return false;
                }
            }
        }
    }

    // 끝까지 잘 왔으면 true 리턴
    return true;
}

void bfs(int a, int b, int tc, const vector<vector<string>> places) {
    // 시작점 큐에 넣기
    queue< pair<int, int> > q;
    dist[a][b] = 0;
    q.push(make_pair(a, b));

    // bfs 돌리기
    while(!q.empty()) {
        // 큐에서 하나 꺼내기
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        // 상하좌우 방문
        for(int k=0;k<4;k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // 범위 유효하고
            if(!(nx>=0&& nx<5 && ny>=0 && ny<5)) continue;

            // 아직 방문 안했으면서 파티션이 아니면
            if(dist[nx][ny] == -1 && places[tc][nx][ny] != 'X') {
                // 맨해튼 거리 계산하고, 큐에 넣기
                dist[nx][ny] = dist[x][y] + 1;
                q.push(make_pair(nx, ny));
            }
        }
    }
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;

    // 5개 대기실마다 반복
    for(int tc=0;tc<5;tc++) {
        bool flag = true;
        // 모든 좌표 검사
        for(int i=0;i<5;i++) {
            for(int j=0;j<5;j++) {
                char now = places[tc][i][j];

                // 이번 자리에 사람이 앉아있는 경우에만 나로부터 거리 검사
                if(now != 'P')  continue;

                // 이번 자리에 사람이 있는 경우, 나와 다른 모든 사람의 거리를 체크한다.
                memset(dist, -1, sizeof(dist));
                bfs(i, j, tc, places);

                // bfs 돌고 나서, 거리가 2보다 작거나 같은 '사람'이 있나 체크한다.
                // 그런 애가 있으면 false로 처리한다.
                if(!check(tc, places)) {
                    flag = false;
                    break;
                }
            }
            if(flag == false) break;
        }

        if(flag == false)   answer.push_back(0);
        else    answer.push_back(1);
        printf("%d\n", answer[tc]);
    }

    return answer;
}

int main(){
    vector< vector<string> > places = {
        {"POOOP", "OXXOX", "OPXPX", "OOXOX", "POXXP"}, 
        {"POOPX", "OXPXP", "PXXXO", "OXXXO", "OOOPP"}, 
        {"PXOPX", "OXOXP", "OXPOX", "OXXOP", "PXPOX"}, 
        {"OOOXX", "XOOOX", "OOOXX", "OXOOX", "OOOOO"}, 
        {"PXPXP", "XPXPX", "PXPXP", "XPXPX", "PXPXP"}
    };

    solution(places);
}                       

