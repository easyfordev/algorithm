/* Programmers - DFS/BFS - 네트워크
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int arr[201][201];
int check[201];
int ans = 0;

void dfs(int x, int n) {
    // 이번 정점 방문
    check[x] = true;

    // 다음 정점 정하기
    for(int i=0;i<n;i++) {
        // 나와 인접하고, 아직 방문 안했으면
        if(arr[x][i] == 1 && check[i] == false) {
            dfs(i, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {    
    // 인접행렬 값 채우기
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if( i == j ) // 원래 대각선 0이니까 바꿔주기
                arr[i][j] = 0;
            else
                arr[i][j] = computers[i][j];
        }
    }

    // 아직 방문 안했으면, 그 점부터 dfs시작
    for(int i=0;i<n;i++) {
        if(check[i] == false) {
            dfs(i, n);
            ans++;
        }
    }

    return ans;
}

int main(){
    // string arr[] = {"classic", "pop", "classic", "classic", "pop"};
    // int arr[] = {3, 0, 6, 1, 5};
    vector<vector<int> > test{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
    // string test = "17";
    // vector<int> test;

    // vector<vector<int>> test2;
    // for(int i=0;i<5;i++) {
    //     test.push_back(arr[i]);
    // }

    printf("답 : %d\n", solution(3, test));
}