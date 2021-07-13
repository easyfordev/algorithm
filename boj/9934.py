"""
BOJ - 9934. 완전 이진 트리
- 파이썬에는 RecursionError가 있다고 한다. 
RecursionError는 재귀와 관련된 에러입니다. 가장 많이 발생하는 이유는 Python이 정한 최대 재귀 깊이보다 재귀의 깊이가 더 깊어질 때입니다.
Python이 정한 최대 재귀 깊이는 sys.getrecursionlimit()을 이용해 확인할 수 있습니다. BOJ의 채점 서버에서 이 값은 1,000으로 되어 있습니다.
- 메모리 초과.. 왜 ...? ㅠㅠ
    sys.setrecursionlimit(10**4) => 재귀 깊이를 6에서 4로 바꾸니까 해결되었다.
    이건 그냥 파이썬 특성인듯 ...
"""
import sys
sys.stdin = open("input.txt", "r")

sys.setrecursionlimit(10**4) # 런타임에러 해결

# 이진 탐색 트리를 전위 순회한 결과가 주어졌을 때, 이 트리를 후위 순회한 결과를 구하는 프로그램
def postorder(start, end):
    # 종료 조건
    if start > end:
        return
    
    # 루트 - 왼쪽 - 오른쪽 을 풀어서, 후위순회를 한다
    # 오른쪽의 시작점을 찾는다
    index = start + 1
    while index <= end:
        # 이진 탐색 트리의 특성상, 더 큰 값이 나오면 걔가 오른쪽 서브트리 시작이다
        if preorders[index] > preorders[start]:
            break
        index += 1
    # print('index=',preorders[index])
    # 왼쪽
    postorder(start+1, index-1)
    # 오른쪽
    postorder(index, end)
    # 루트 출력
    print(preorders[start])
    
# 입력 받기
preorders = []

nodes = 0
while nodes<=10000:
    try:
        num = int(input())
    except:
        break
    
    preorders.append(num)
    nodes += 1

# 후위 순회
postorder(0, len(preorders)-1)
