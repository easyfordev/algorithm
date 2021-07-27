/*
BOJ - 21608. 상어 초등학교
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

class Point{
public:
    int x, y;
    int likeCnt;
    int emptyCnt;

    Point() {
        this->x = 0;
        this->y = 0;
        this->likeCnt = 0;
        this->emptyCnt = 0;
    }

    Point(int x, int y, int likeCnt, int emptyCnt) {
        this->x = x;
        this->y = y;
        this->likeCnt = likeCnt;
        this->emptyCnt = emptyCnt;
    }
};

int n, n2;
int arr[21][21]; // 학생 앉은 자리
vector<Point> points; // 각 자리마다 체크

int likes[21*21+1][5];
bool likeCheck[21*21+1];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool cmp(const Point &a, const Point &b) {
    // 1. 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
    if(a.likeCnt == b.likeCnt) {
        // 2. 1을 만족하는 칸이 여러개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
        if(a.emptyCnt == b.emptyCnt) {
             // 3. 2를 만족하는 칸도 여러개인 경우에는 행의번호가 가장 작은 칸으로, 
            if(a.x == b.x) {
                // 그러한 칸도 여러개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
                return a.y < b.y;
            } else
                return a.x < b.x;
        } else
            return a.emptyCnt > b.emptyCnt;
    } else
        return a.likeCnt > b.likeCnt;
}

void search(){ // 생각해보면 bfs도 아님. 그냥 한 칸씩 탐색임
    // 시작점은 항상 (1, 1)
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int cnt1 = 0; // 좋아하는 학생
            int cnt2 = 0; // 빈 칸

            // 인접한 칸들 탐방
            for(int k=0;k<4;k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                // 범위 유효하고
                if(nx>=1 && nx<=n && ny>=1 && ny<=n) {
                    int now = arr[nx][ny];
                    
                    if(now == 0) { // 빈 칸이면, 빈칸으로 세기
                        cnt2++;
                    } else if(likeCheck[now]) { // 내가 좋아하는 학생이면, 좋아하는 학생 수에 count
                        cnt1++;
                    }
                }
            }

            // 다 세고, vector에 넣기
            points.push_back(Point(i, j, cnt1, cnt2));
        }
    }
}

void sit(int num){ // 학생 한 명 앉히기
    // 좋아하는 학생인지 체크하기
    memset(likeCheck, false, sizeof(likeCheck));
    for(int i=1;i<=4;i++) {
        likeCheck[ likes[num][i] ] = true;
    }

    // 각 자리마다 vector에 넣기
    points.clear();

    // 현재 자리 쭉 돌면서, 좋아하는 학생과 인접한 칸이 몇 개인지 검사
    search();

    // 자리 우선순위에 따라 정렬
    sort(points.begin(), points.end(), cmp);

    // 현재 자리에 아무도 없으면서, 정렬해서 제일 앞에 있는 곳이 내가 앉을 자리다.
    int index = 0;
    // Points를 쭉 돌면서, arr이 비어있는 곳을 찾는다.
    for(int i=0;i<n2;i++) {
        int x = points[i].x;
        int y = points[i].y;

        if(arr[x][y] == 0) {
            index = i;
            break;
        }
    }

    // index번이 내 자리다.
    // int num = likes[0]; // 현재 학생 번호
    arr[ points[index].x ][ points[index].y ] = num;
}

int calc(){
    // 그 학생과 인접한 칸에 앉은 좋아하는 학생의 수 구하기
    // 그 값이 0이면 0, 1이면 1, 2이면 10, 3이면 100, 4이면 1000
    
    int ans=0;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            int num = arr[i][j];
            // 내가 좋아하는 학생인지 체크하기
            memset(likeCheck, false, sizeof(likeCheck));
            for(int i=1;i<=4;i++) {
                likeCheck[ likes[num][i] ] = true;
            }

            int cnt1 = 0; // 좋아하는 학생

            // 인접한 칸들 탐방
            for(int k=0;k<4;k++) {
                int nx = i + dx[k];
                int ny = j + dy[k];

                // 범위 유효하고
                if(nx>=1 && nx<=n && ny>=1 && ny<=n) {
                    int now = arr[nx][ny];
                    
                    // 내가 좋아하는 학생이면, 좋아하는 학생 수에 count
                    if(likeCheck[now]) 
                        cnt1++;
                    
                }
            }

            // 다 세고, 만족도 계산하기
            if (cnt1 != 0)
                ans += (int)pow(10, cnt1-1);
        }
    }

    return ans;
}

int main(){
    // 입력받기
    scanf("%d", &n);
    n2 = n*n;

    
    for(int i=1;i<=n2;i++) {
        int num;
        scanf("%d", &num);
        likes[num][0] = num;
        scanf("%d %d %d %d", &likes[num][1], &likes[num][2], &likes[num][3], &likes[num][4]);
        
        // 한명씩 자리에 앉히기
        sit(num);
    }

    // print();

    // 학생의 만족도의 총 합 구하기
    printf("%d\n", calc());
}