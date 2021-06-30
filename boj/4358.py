"""
BOJ 4358. 생태학
- 자료구조(맵)
- 입력 끝을 어떻게 알지? for line in sys.stdin:
- dict 정렬
"""
import sys
sys.stdin = open("input.txt", "r")

trees = {}

# 입력 더 똑똑하게 받는 방법 없을까?
size = 0
for line in sys.stdin:
    t = line.strip()
    size +=1

    if t in trees:
        trees[t] += 1
    else:
        trees[t] = 1

# 각 종의 이름을 사전순으로 정렬
trees = sorted(trees.items())

# 결과 출력 : 그 종이 차지하는 비율을 백분율로 소수점 4재리까지 반올림해서 함께 출력
for tree in trees:
    name, cnt = tree
    print(f'{name} {(cnt/size)*100:.4f}')
    
    
