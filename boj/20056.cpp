/*
20056. 마법사 상어와 파이어볼
- 가장 중요한 것은 문제를 꼼꼼히 읽고 조건을 놓치지 않는 것
- (핵심) 어떤 자료구조를 쓸건지 잘 정해야 함
    - 맵 : 보드판 한 칸에 여러 파이어볼이 있을 수 있다는 점을 감안하여 파이어볼을 원소로 갖는 vector 의 2차원 배열
    - 파이어볼 : 구조체 정의하고, vector로 관리

- 또 처음에 모든 TC 다 틀렸다
    - 구조체 정의할 때 변수 순서를 잘못썼다 ㅠㅠ (입력 들어오는 순서랑 똑같이 맞춰줘야 함)
- 1번 TC 빼고 다 틀렸다 -> 반복하면서 뭔가 틀렸다는 말
    - 좌표 밖으로 나갔을 때 보정이 잘 안되었다.
    - 문제 이해를 아얘 잘못했다. merge()되고, 바로 move()하지 않고 다음턴에 움직인다.
- TC는 다 맞았는데 0%에서 틀렸다고 한다.
    - '질량이 0인 파이어볼은 소멸되어 없어진다.' 조건을 빼먹었다 ㅠㅠㅠㅠㅠㅠㅠㅠㅠㅠ
** Try and Error 절대 금지 ... 꼼꼼하게 구현해야한다 진짜.
*/

#include <iostream>
#include <vector>
using namespace std;
int n, m, k;

struct Fireball{
    int r,c,m,s,d;
};

vector<Fireball> arr[51][51]; // 맵
vector<Fireball> v; // 파이어볼 저장하는 벡터

// 파이어볼 방향 0~7
int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

void print(){
    printf("=========\n");
    int len = v.size();
    for(int i=0;i<len;i++) {
        printf("(%d, %d), m=%d, s=%d, d=%d\n", v[i].r, v[i].c, v[i].m, v[i].s, v[i].d);
    }

}
void move() {  // 1. 모든 파이어볼이 자신의 방향 d로 속력 s칸 만큼 이동한다
    // 일단, 모든 맵을 다 지운다.
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            arr[i][j].clear();
        }
    }
    
    int len = v.size();

    for(int i=0;i<len;i++) {
        int x = v[i].r;
        int y = v[i].c;
        int mass = v[i].m;
        int speed = v[i].s;
        int dir = v[i].d;

        // 1번 ~ N번이 연결된걸 고려해서, 몇 칸 움직일지 정하기
        int move = speed%n;

        int nx = x + dx[dir] * move;
        int ny = y + dy[dir] * move;

        // 이동하고나서, 그래도 좌표 이상한경우(두번이나 경계를 왔다갔다 한 경우) 처리
        if(nx > n )  nx -= n;
        else if(nx <= 0)   nx += n;

        if(ny > n )  ny -= n;
        else if(ny <= 0)   ny += n;

        // 파이어볼에도 반영하고,
        v[i].r = nx;
        v[i].c = ny;

        // 맵에도 반영한다
        arr[nx][ny].push_back(v[i]);
    }
}

void merge() { 
    vector<Fireball> temp;

    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++) {
            // 파이어볼 없으면 건너뛰고,
            if(arr[i][j].size() == 0)    continue;

            // 딱 1개만 있으면 그냥 v에 넣기
            if(arr[i][j].size() == 1) {
                temp.push_back(arr[i][j].front());
                continue;
            }

            // 2개 이상의 파이어볼이 있는 칸에서만 합치기 진행
            // 1. 같은 칸에 있는 파이어볼은 모두 하나로 합쳐진다.
            int massSum = 0;
            int speedSum = 0;

            bool allEven = true;
            bool allOdd = true;

            for(int k=0;k<arr[i][j].size();k++) {
                massSum += arr[i][j][k].m;
                speedSum += arr[i][j][k].s;

                if(arr[i][j][k].d%2 == 0)   allOdd = false;
                else    allEven = false;
            }

            // 새로운 질량, 방향 정하기
            int newMass = massSum/5;
            int newSpeed = speedSum/arr[i][j].size();

            // 질량이 0인 파이어볼은 소멸되어 없어진다.
            if(newMass == 0)    continue;      

            // 방향 = 파이어볼 방향이 모두 홀수이거나 모두 짝수이면 0,2,4,6 그렇지 않으면 1,3,5,7
            if(allOdd || allEven) { // 모두 짝수이거나, 모두 홀수이면
                struct Fireball f1 = {i, j, newMass, newSpeed, 0};
                struct Fireball f2 = {i, j, newMass, newSpeed, 2};
                struct Fireball f3 = {i, j, newMass, newSpeed, 4};
                struct Fireball f4 = {i, j, newMass, newSpeed, 6};

                temp.push_back(f1);
                temp.push_back(f2);
                temp.push_back(f3);
                temp.push_back(f4);
            } else {
                struct Fireball f1 = {i, j, newMass, newSpeed, 1};
                struct Fireball f2 = {i, j, newMass, newSpeed, 3};
                struct Fireball f3 = {i, j, newMass, newSpeed, 5};
                struct Fireball f4 = {i, j, newMass, newSpeed, 7};

                temp.push_back(f1);
                temp.push_back(f2);
                temp.push_back(f3);
                temp.push_back(f4);
            }
        }
    }

    // 바꿔치기
    v = temp;
}

void solution(){
    move();

    merge();
}

int calc() { // 파이어볼 남아있는 질량 구하기
    int len = v.size();
    int sum = 0;

    for(int i=0;i<len;i++) {
        sum += v[i].m;
    }

    return sum;
}

int main(){
    // 입력받기
    scanf("%d %d %d", &n, &m, &k);

    // 파이어볼 입력받기
    for(int i=0;i<m;i++) {
        int r,c,m,s,d;
        scanf("%d %d %d %d %d", &r, &c, &m, &s, &d); // 파이어볼 : 위치(r,c), 질량, 방향, 속력

        struct Fireball f = {r,c,m,s,d};

        v.push_back(f);
        arr[r][c].push_back(f);
    }

    // k번 이동 명령
    for(int i=0;i<k;i++) {
        solution();
    }

    // K번 이동 후, 남아있는 파이어볼 질량의 합 구하기
    printf("%d\n", calc());
}