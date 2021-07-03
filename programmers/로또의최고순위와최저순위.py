"""
프로그래머스 - 로또의 최고 순위와 최저 순위
"""
def solution(lottos, win_nums):
    answer = []
    
    # 당첨 번호 체크
    check = [0 for x in range(0,46)]
    
    for num in win_nums:
        check[num] = 1
    
    # 현재 알 수 있는 번호중에 당첨 몇개인지 판단
    win_cnt = 0
    
    for num in lottos:
        if num != 0:
            if check[num] == 1:
                win_cnt += 1
    # lottos에서 0 몇개인지 세기
    zero = lottos.count(0)
    # 현재까지 확정된 당첨
    win_dict = {6:1, 5:2, 4:3, 3:4, 2:5, 1:6, 0:6} # 갯수: 순위

    answer.append(win_dict[win_cnt+zero]) # 최고 순위
    answer.append(win_dict[win_cnt]) # 최저 순위

    return answer

lottos = [44, 1, 0, 0, 31, 25]
win_nums = [31, 10, 45, 1, 6, 19]

print( solution(lottos, win_nums) )

print( solution([0, 0, 0, 0, 0, 0], [38, 19, 20, 40, 15, 25] ) )

print( solution([45, 4, 35, 20, 3, 9], [20, 9, 3, 45, 4, 35] ) )