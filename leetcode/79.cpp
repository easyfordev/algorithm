/*
LeetCode - 79. Word Search
- 시간초과난다... m,n이 최대일때 너무 오래걸린다.
    ->(해결)가지치기 추가 : 정답과 아얘 다르면 탐색 멈춘다.
    - 그래도 여전히 다른 유저들보다 느리긴 하다.
*/
#include <iostream>
#include <vector>
#include <set>
#include <cstring>
using namespace std;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

class Solution {
public:
    set<string> words;
    int n, m;


    char board_copy[7][7];
    bool check[7][7] = {false};
    string target;


    void dfs(int x, int y, string str) {
        // 다음 방문할 정점 방문
        for(int k=0;k<4;k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            // 범위 유호하고, 아직 방문 안했으면
            if(nx>=0 && nx<n && ny>=0 && ny<m) {
                if(!check[nx][ny]) {
                    check[nx][ny] = true;
                    string temp = str + board_copy[nx][ny];

                    // (가지치기) 정답 가능성이 아얘 없으면, 검사 안하고 건너 뜀
                    int len =  temp.size();
                    string sliced = target.substr(0, len);

                    if(sliced != temp)   {
                        check[nx][ny] = false;
                        continue;
                    }

                    words.insert(temp);
                    dfs(nx, ny, temp);
                    // 백트래킹
                    check[nx][ny] = false;
                }
            }
        }

    }

    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        target = word;

        // 일단 전역변수로 복사
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++) 
                board_copy[i][j] = board[i][j];

        // 모든 정점 시작점으로 DFS로 쭉 돌면서 풀면 되지 않을까?
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                // 한번 돌 때마다 초기화
                memset(check, false, sizeof(check));

                // 시작점 방문
                check[i][j] = true;

                // 정답에 넣기
                string temp;
                temp += board_copy[i][j];
                words.insert(temp);

                // (가지치기) 정답 가능성이 아얘 없으면, 검사 안하고 건너 뜀
                int len =  temp.size();
                string sliced = target.substr(0, len);

                if(sliced != temp)   continue;
                // DFS로 탐색하기
                dfs(i,j, temp);
            }
        }

        // 정답 : set의 find가 true이면 true, 없으면 false
        if(words.find(word) == words.end()) return false;
        else    return true; 

    }
};

int main(){
    vector< vector<char> > board = {
        // {'A','B','C','E'},
        // {'S','F','C','S'},
        // {'A','D','E','E'}

        // {'a', 'a'}

        {'a'},
        {'a'},
        {'a'},
        {'a'}
    };
    string word = "aa";

    Solution s;
    cout << s.exist(board, word);
}