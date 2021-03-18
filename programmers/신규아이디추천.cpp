"""
Programmers - 신규 아이디 추천 (문자열,정규식)
다른 사람 풀이) 정규식 참 잘썼다
    st = new_id
    st = st.lower()
    st = re.sub('[^a-z0-9\-_.]', '', st)
    st = re.sub('\.+', '.', st)
    st = re.sub('^[.]|[.]$', '', st)
    st = 'a' if len(st) == 0 else st[:15]
    st = re.sub('^[.]|[.]$', '', st)
    st = st if len(st) > 2 else st + "".join([st[-1] for i in range(3-len(st))])
    return st
"""
import re

def solution(new_id):
    id = new_id
    # 1단계 new_id의 모든 대문자를 대응되는 소문자로 치환합니다.
    id = id.lower()

    # 2단계 new_id에서 알파벳 소문자, 숫자, 빼기(-), 밑줄(_), 마침표(.)를 제외한 모든 문자를 제거합니다.
    id = re.sub('[^0-9a-z-_.]', '', id) # re.sub(패턴, 바꿀문자열, (count), 문자열) : 패턴에 일지하는 문자열을 다른 문자열로 바꿈
    # print(id)

    # 3단계 new_id에서 마침표(.)가 2번 이상 연속된 부분을 하나의 마침표(.)로 치환합니다.
    id = re.sub('\.+', '.', id)

    # 4단계 new_id에서 마침표(.)가 처음이나 끝에 위치한다면 제거합니다.
    id = id.strip(".")

    # 5단계 new_id가 빈 문자열이라면, new_id에 "a"를 대입합니다.
    if id == "" :
        id = "a"

    # 6단계 new_id의 길이가 16자 이상이면, new_id의 첫 15개의 문자를 제외한 나머지 문자들을 모두 제거합니다.
    if len(id) >= 16 :
        id = id[:15]
    
    #     만약 제거 후 마침표(.)가 new_id의 끝에 위치한다면 끝에 위치한 마침표(.) 문자를 제거합니다.
    id = id.rstrip(".")

    # 7단계 new_id의 길이가 2자 이하라면, new_id의 마지막 문자를 new_id의 길이가 3이 될 때까지 반복해서 끝에 붙입니다.    
    if len(id) <= 2 :
        for a in range(3-len(id)) :
            id = id + id[-1]

    return id

ans = solution("abcdefghijklmn.p")

print(ans)
