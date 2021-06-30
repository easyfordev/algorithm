"""
프로그래머스 - 메뉴 리뉴얼
- 구현, 맵
"""
from itertools import combinations

def solution(orders, course):
    answer = []

    for c in course:
        # orders에 대해 모든 조합 구하기
        m = {}

        for order in orders:
            # 1 정렬
            o = sorted(order) # 정렬된 list가 들어간다. ['C', 'D', 'E']

            # 2 조합 구하기
            comb = list( map(''.join, combinations(o, c)) ) # tuple의 list가 들어간다. [('C', 'D'), ('C', 'E'), ('D', 'E')]
            # 3 list의 모든 멤버를 map에 넣는다.
            for item in comb:
                if item in m:
                    m[item] += 1
                else:
                    m[item] = 1
        # 4 map의 values 중에 최댓값 구하기
        if len(m) == 0:
            continue
        m_max = max(m.values())

        # 예외 처리) 2명 이상이 시킨 조합이어야만 한다
        if m_max < 2:
            continue
        # 5 값이 m_max인 key를 정답에 넣기
        m_keys = [k for k,v in m.items() if m_max == v]
        for item in m_keys:
            answer.append(item)

    # 정답도 정렬해서 리턴
    return sorted(answer)

ans = solution(["XYZ", "XWY", "WXA"],[2,3,4])
print(ans)