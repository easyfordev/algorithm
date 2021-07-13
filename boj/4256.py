"""
BOJ - 4256. 트리
"""
import sys
sys.stdin = open('input.txt', 'r')

def post_order(s, e, r) :
    # 일단 루트부터 찾자
    for i in range(s, e+1):
        if in_orders[i] == pre_orders[r]:
            # 왼쪽 서브트리
            post_order(s, i-1, r+1)
            # 오른쪽 서브트리
            post_order(i+1, e, r+1+i-s)
            # 루트
            print(pre_orders[r], end=' ')

tc = int(input())

for t in range(tc):
    # 입력받기
    n = int(input())
    pre_orders = list(map(int, input().split()))
    in_orders = list(map(int, input().split()))

    # 문제 풀기
    post_order(0, n-1, 0)
    print()
