/*
프로그래머스 - 불량 사용자
*/
#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <algorithm>
#include <set>
using namespace std;

int check[10]; // user_id를 사용했는지 체크
// int answer = 0;

vector<string> user_ids;
vector<string> banned_ids;
set<string> answer;

void solve(int index) {
    // 정답을 찾은 경우
    if(index == banned_ids.size()){
        // 체크한것만 다 이어서 정답에 넣기
        string s = "";
        for(int i=0;i<user_ids.size();i++) {
            if(check[i] == 1) s += user_ids[i];
        }
        answer.insert(s);
        return;
    }
    // 불가능한 경우
    if(index > banned_ids.size()) {
        return;
    }

    // 다음 경우
    // 나 포함, 포함 안하는 경우는 for문 안의 다른 경우를 위해 원복시켜주기
    string pattern = banned_ids[index];
    // * -> . 으로 바꾸기
    replace( pattern.begin(), pattern.end(), '*', '.'); // replace all 'x' to 'y'
    // printf("%s\n", p.c_str());
    regex re(pattern);

    for(int i=0;i<user_ids.size();i++) {
        // 정규식 만족하고, 아직 체크 안했으면
        if(regex_match(user_ids[i], re) && check[i]==0) {
            // 체크하고 다음으로 넘어가기
            check[i] = 1;
            solve(index+1);
            // for문안의 다른 경우를 위해 체크 해제(백트래킹)
            check[i] = 0;
        }

    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    // 전역변수로 vector 복사
    user_ids.assign(user_id.begin(), user_id.end());
    banned_ids.assign(banned_id.begin(), banned_id.end());

    // 완전 탐색
    solve(0);

    // 정답 리턴
    return answer.size();
}

int main(){
    vector<string> user_id = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
    vector<string> banned_id = {"*rodo", "*rodo", "******"};

    cout << solution(user_id, banned_id);
}