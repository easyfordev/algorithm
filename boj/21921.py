"""
BOJ - 21921. 블로그
- 슬라이딩 윈도우 같은 느낌
"""
import sys
sys.stdin = open("input.txt", "r")

# 블로그를 시작한지 N일
# X일동안 가장 많이 들어온 방문자 수와 그 기간이 몇개인지
# 최대 방문자 수가 0명이면 SAD 출력

# 입력받기
n, x = map(int, sys.stdin.readline().split())
visitors = list(map(int, sys.stdin.readline().split()))

# 일단 0~x까지의 합 구하기
# s = 0
# for i in range(x):
#     s += visitors[i]
s = sum(visitors[:x])

# print(s)
ans = s
cnt = 1 # 최대 기간이 몇 개인지

# 슬라이딩 윈도우
left = 0
right = x-1

while right < len(visitors) -1:
    # print(f's={s}, ans ={ans}, left={left}, right={right}, cnt={cnt}')
    
    # 포인터 이동
    s -= visitors[left]
    left += 1
    right += 1
    s += visitors[right]

    # 정답 검사. 최댓값인지
    if s > ans: # 더 큰 정답을 찾았으면
        ans = s
        cnt = 1
    elif s == ans: # 이전 값이랑 똑같으면
        cnt += 1
    
if ans == 0:
    print('SAD')
else:
    print(ans)
    print(cnt)