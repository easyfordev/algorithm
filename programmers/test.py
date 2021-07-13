# 미국식 숫자 정렬
# 영어로 바꾸고, 오름차순 정렬
# 숫자를 영어로 바꿀 때는, 숫자를 한자리씩 잘라 영어로 변경 띄어쓰기 안함
# 11 - oneone

# N = 100만, 각 원소 = 100만
def solution(numbers):
    answer = []
    
    eng_dict = {'0':'zero', '1':'one', '2':'two', '3':'three', '4':'four', '5':'five', '6':'six', '7':'seven', '8':'eight', '9':'nine'}

    # 모든 배열 변환하기
    for n in numbers:
        # 한자리씩 변환
        num  = str(n)

        for d in num:
            print(d)
        print()

    return answer


print(solution([6, 1, 8]))
print(solution([4, 5, 11]))
