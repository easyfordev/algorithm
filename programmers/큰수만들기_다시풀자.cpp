/* Programmers - 그리디 - 큰 수 만들기
K개의 수를 제거했을 때 얻을 수 있는 가장 큰 숫자

- 처음에 완전탐색으로 풀었는데, 3개 케이스 빼고 틀렸다.
- number가 1,000,000자리 이하라서 완전탐색으로 풀 수 없다고한다.
    signal: aborted (core dumped)
    시간 초과
- 어떻게 풀즤 ... 

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int ans = -1;
vector<int> check;

void go(int index, int cnt, string number, int k) {
    // 정답을 찾은 경우
    if(cnt == k) {
        // 체크한것만 없애고 숫자 새로 만들기
        string temp = "";
        int len = number.size();
        for(int i=0;i<len;i++) {
            // printf("%d ", check[i]);
            if(check[i] == 0)   temp += number[i];
        }
        // 정답이랑 비교해서, 더 크면 업데이트
        if(stoi(temp) > ans)    ans = stoi(temp);
        
        return;
    }
    // 불가능한 경우
    if(index >= number.size()) return;
    // 다음 경우
    // 이번 포함
    check[index] = 1;
    go(index+1, cnt+1, number, k);

    // 이번 포함하지 않음
    check[index] = 0;
    go(index+1, cnt, number, k);
}

string solution(string number, int k) {
    check.resize(number.size());
    // 완전탐색해서 k자리씩 없애보자
    go(0, 0, number, k);

    return to_string(ans);
}

int main(){
    vector<int> test{7, 10};

    printf("답 : %s\n", solution("4177252841", 4).c_str());
}