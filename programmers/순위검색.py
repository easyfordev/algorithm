"""
프로그래머스 - 순위 검색
- list comprehension으로 풀었다
- 정확성은 다 맞았는데, 효율성은 다 틀렸다.
- 효율성 개선 방법(카카오 풀이 참고)
    1. 모든 경우의 수 그룹을 dict로 미리 만든다. 마치 Hash Table처럼.  {'조건합친값':''}
        - from itertools import combinations 쓸 줄 알아야 함
        - ''(빈 문자열)도 dict의 key가 될 수 있구나
    2. 점수만 list에 넣고 x 이상인 점수가 몇개인지 찾는다.
    3. 'x 이상인 점'을 찾기 위해 binary search 를 쓴다.
        - 당연히 binary search니까 정렬 해야겠지 먼저
        - binary search는 정확한 값을 찾는거라서, lower bound를 찾도록(이상인 점!) 조금 수정한다.
- 런타임 에러 .. 뭐야 ... : key가 dict에 없는 경우를 처리 안해줬었다.
- 바이너리 서치 해도 시간초과.. 답은 다 맞는데 .. 
    (효율성 2개 통과) 정렬을 16번 * query 갯수만큼 하니까 시간초과났다. 정렬은 딱 번씩만 미리 해줘야한다.
    (효율성 4개 모두 통과) list comprehension을 뺐다.. - 도 계속 remove 하게
"""
from itertools import combinations

def solution(info, query):
    # 1. 가능한 모든 경우의 수 그룹 저장
    applicants = {}

    for item in info:
        info_list = item.split()
        score = int(info_list[-1])
        info_list = info_list[:-1]

        # 효율성 개선 핵심. 하나의 info에서 가능한 모든 조합을 미리 만들어둔다
        # 모든 조합 구하는 문법 알아두기 (다 지우고 다시 해보자)
        for i in range(5):
            combs = combinations(info_list, i) # 리스트, 조합의 원소 수. 예) 2이면 2개짜리 모든 조합 구해줌
            
            for c in combs:
                key = ''.join(c) # 문자열.join(iterable한 타입)
                
                if key in applicants:
                    applicants[key].append(score)
                else:
                    applicants[key] = [score]
        
    # 정렬을 딱 한번씩만 먼저 해준다.
    for key in applicants:
        applicants[key].sort()

    # 2. 쿼리마다 맞는 답 몇 명인지 찾기
    answer = []
    for q in query:
        query_list = q.split()
        del query_list[1:6:2] # and를 다 없앤다 1,3,5번 index

        score = int(query_list[-1])
        query_list = query_list[:-1]

        # 여기때문에 시간초과 났음 !!!!!!
        # key = ''.join([x for x in query_list if x!='-'])
        while '-' in query_list: # 그냥 -를 빼준다.
            query_list.remove('-')
        key = ''.join(query_list)

        # 바이너리 서치 할거니까 정렬
        # (런타임 에러)아얘 없는 키가 있을 수도 있으니까 꼭 처리해줘야 함
        if key in applicants:
            data = applicants[key]
            # print(data)

            # 3. (핵심) 이분탐색으로 score이상인 애들이 몇개인지 찾기
            if len(data) == 0: # 조건 만족하는 애가 아무도 없으면..
                answer.append(0)
            else:
                # 바이너리 서치
                left = 0
                right = len(data) - 1

                while left <= right:
                    mid = (left+right)//2

                    # x 이상이면 (원하는 값을 찾음. 범위를 줄이자!)
                    if data[mid] >= score:
                        right = mid-1
                    else: # 너무 작으면, 더 큰값을 찾아 떠난다.
                        left = mid+1
                # 갯수
                answer.append(len(data)-left)
        else:
            answer.append(0)
    return answer

info = ["java backend junior pizza 150","python frontend senior chicken 210","python frontend senior chicken 150","cpp backend senior pizza 260","java backend junior chicken 80","python backend senior chicken 50"]
query = ["java and backend and junior and pizza 250","python and frontend and senior and chicken 200","cpp and - and senior and pizza 250","- and backend and senior and - 150","- and - and - and chicken 100","- and - and - and - 150"]

ans = solution(info, query)
print(ans)
