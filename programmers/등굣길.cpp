/*
프로그래머스 - 등굣길
- memset으로 초기화화하는거 0,-1밖에 안된다. 1은 안됐었다.. 이걸 아직도 몰랐다니 충격.
- 계속 틀린 이유 : puddles에 들어오는 좌표가 (m,n) 인데 내가 평소에 했던거랑 달라서 ㅠㅠ
- 2차원 vector 초기화 알아두기
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;


int solution(int m, int n, vector<vector<int>> puddles) {
    // 최단경로의 개수를 1,000,000,007로 나눈 나머지 return
    // 2차원 vector 초기화  
    vector<vector<int>> dp(101, vector<int>(101, 1));

    // 일단 물에 잠긴 구간 -1로 처리
    for(int i=0;i<puddles.size();i++) { 
        int y = puddles[i][0];
        int x = puddles[i][1];

        // 물 구덩이는 0으로 표시한다. (아얘 못간다는 의미에서 .. 더해도 의미가 없게)
        dp[x][y] = 0;

        // 만약에, a랑 b 둘중에 하나라도 첫번째 행,열이 나오면, 그 뒤는 쭉 못간다.
        if(x == 1) {
            for(int j=y;j<=m;j++)
                dp[x][j] = 0;
        }

        if(y==1) {
            for(int j=x;j<=n;j++) 
                dp[j][y] = 0;
        }
    }
    
    // // 2,2부터 답 채우기
    for(int i=2;i<=n;i++) {
        for(int j=2;j<=m;j++) {
            // 구덩이면 안함
            if(dp[i][j] == 0)  continue;
            
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
            dp[i][j] %= 1000000007;
        }
    } 

    return dp[n][m];
}

int main(){
    vector<vector<int>> puddles = {{2,2}};
    cout << solution(4,3,puddles);
}
