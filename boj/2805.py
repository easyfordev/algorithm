"""
BOJ - 2805. 나무 자르기
- 이분 탐색
"""
# 입력받기
n, m = map(int, input().split(' ') )
trees = list( map(int, input().split(' ')) )

# h를 기준으로 이분탐색 시작
ans = 0
left = 0
right = max(trees) # right 초기값은 나무 높이들 중 max

while left<=right :
    mid = (left + right) // 2
    # print(mid)
    # 1 나무 자르기
    tree_sum = 0
    for tree in trees:
        if tree > mid:
            tree_sum += tree-mid
    # print(tree_sum)

    # 2 m과 비교
    if tree_sum >= m:
        ans = max(mid, ans)

        # h를 늘려서 탐색한다. (최적해 찾아가기)
        left = mid+1
    else:
        # h를 줄여서 탐색한다. (나무가 모자라니까)
        right = mid-1

print(ans)