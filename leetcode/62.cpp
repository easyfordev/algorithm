/*
leetcode - 62. Unique Paths
- 아이디어만 떠올리고 짰더니 그냥 바로 pass 받았다
- dp같지않은 dp 문제 ㅎㅎ
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
        // index는 1부터
        int dp[101][101] = {0};

        // -> 1로 다 채우고
        for(int i=1;i<=m;i++)
            dp[i][1] = 1;

        // | 아래 1로 다 채우고
        for(int i=1;i<=n;i++)
            dp[1][i] = 1;
        
        
        // 2,2부터 답 채우기
        for(int i=2;i<=m;i++) {
            for(int j=2;j<=n;j++) {
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }

        for(int i=1;i<=m;i++) {
            for(int j=1;j<=n;j++) {
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }
        return dp[m][n];
    }
};

int main(){
    Solution s;

    cout << s.uniquePaths(3,3);
}
