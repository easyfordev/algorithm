"""
BOJ - 11659. 구간 합 구하기 4
- prefix sum으로 안풀면 N^2이라서 시간 초과 난다
- 와 입력을 input()으로 받으니까 시간초과나고 sys.stdin.readline().split()으로 받으니까 시간초과 안난다...참내...
"""
import sys
sys.stdin = open("input.txt", "r")

# 수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램
# N=10만, M=10만

# 입력 받기
n, m = map(int, input().split(' '))
# arr = list(map(int, input().split(' ')))
arr = list(map(int, sys.stdin.readline().split()))

# Prefix Sum 구하기
psum = [0]
s = 0

for i in range(len(arr)):
    s += arr[i]
    psum.append(s)
# print(psum)

# 입력 받으면서 문제 풀기
for tc in range(m):
    i, j = map(int, sys.stdin.readline().split())
    print(psum[j] - psum[i-1])