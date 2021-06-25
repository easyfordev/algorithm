/*
leetcode - 70. Climbing Stairs
- 맨 처음에 런타임 에러 났다 ... 앜 1 들어오는 경우 dp[2]가 없는데 초기화를 해주니까 !!!!!! 안되지 !!!
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        // 1이면 dp[2]는 없으니까 ... 예외처리
        if(n==1)    return 1;

        vector<int> dp(n+1);
        dp[1] = 1;
        dp[2] = 2;

        for(int i=3;i<=n;i++) {
            dp[i] = dp[i-1] + dp[i-2];
        }

        return dp[n];
    }
};

int main(){
    Solution s;

    cout << s.climbStairs(3);
}
