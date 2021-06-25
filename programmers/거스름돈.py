# 거스름돈 n원을 줄 때 방법의 경우의 수
def solution(n, money): # 돈, 현재 보유하고 있는 돈의 종류
    answer = 0
    # 리스트 초기화
    dp = [0] * (n+1)
    
    # (초기화 잘 해주기) 0원을 거슬러주는 방법은 안주는거 딱 하나!
    dp[0] = 1

    for i in money:
        for j in range(i, n+1):
            dp[j] += dp[j-i]
            dp[j] %= 1000000007
    
    return dp[n]

ans = solution(5, [2,1,5])
print(ans)
