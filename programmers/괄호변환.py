"""
Programmers - 괄호 변환
- 처음에 일부 TC 틀렸다. 정확성 52밖에 못 받음
- 틀린 이유) 문제 해석을 잘못했다 ...
나머지 문자열의 **괄호 방향을 뒤집어서** => 이걸 reverse()로 해석했는데, ( 와 ) 를 바꾸라는거였다.. ㅠㅠ
"""

def is_correct(p): # p가 올바른 문자열인지 리턴
    stack = [] # push는 append(), # pop은 pop(), top은 [-1]

    for c in p:
        # 스택이 비어있으면 넣는다.
        if len(stack) == 0:
            stack.append(c)
        # 뭔가가 있으면, top을 하나 꺼내본다.
        else:
            top = stack[-1]
            
            if (top=='(' and c == ')'): # 괄호짝이 맞는 경우에는, 괄호짝 맞으니까 하나 pop
                stack.pop()
            else: # 둘이 같으면, 그냥 스택에 넣음
                stack.append(c)
    
    # 다 돌고나서 스택에 아무것도 없으면, 올바른 문자열
    if len(stack) == 0:
        return True
    else:
        return False

def convert(p): # 괄호 방향을 뒤집는다
    ans = ''

    for c in p:
        if c == '(':
            ans += ')'
        else:
            ans += '('
    return ans

def solution(p):
    answer = ''
    # 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환합니다. 
    if len(p) == 0:
        return answer

    # 이미 올바른 괄호 문자열인지 확인. 맞으면 그대로 리턴
    if is_correct(p):
        return p
        
    # 아니면, 아래 과정 거치기
    # 2. 문자열 w를 두 "균형잡힌 괄호 문자열" u, v로 분리합니다. 
    # 단, u는 "균형잡힌 괄호 문자열"로 더 이상 분리할 수 없어야 하며, v는 빈 문자열이 될 수 있습니다. 
    u = ''
    v = ''

    p_map = {'(':0, ')':0}
    # 갯수 같아지는 순간, 그게 바로 u다
    for i in range(len(p)):
        c = p[i]
        p_map[c] += 1

        if p_map['('] == p_map[')']:
            u = p[:i+1]
            v = p[i+1:]
            break
    # 3. 문자열 u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행합니다.
    # 3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환합니다. 
    if is_correct(u):
        return u + solution(v)
    else:
        # 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행합니다. 
        #   4-1. 빈 문자열에 첫 번째 문자로 '('를 붙입니다. 
        temp = '(' + solution(v) + ')'
        #   4-2. 문자열 v에 대해 1단계부터 재귀적으로 수행한 결과 문자열을 이어 붙입니다. 
        # temp = temp + solution(v)
        #   4-3. ')'를 다시 붙입니다. 
        # temp = temp + ')'
        #   4-4. u의 첫 번째와 마지막 문자를 제거하고, 나머지 문자열의 **괄호 방향을 뒤집어서** 뒤에 붙입니다. 
        u_ = u[1:-1]
        temp = temp + convert(u_)
        #   4-5. 생성된 문자열을 반환합니다.
        return temp


print(solution("(()())()"))
print(solution(")("))
print(solution("()))((()"))