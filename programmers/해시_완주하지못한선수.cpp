/* Programmers - 해시 - 완주하지 못한 선수
더 나은 풀이 : 그냥 map으로 하고, 동명이인 처리를 위해 int로 갯수를 저장한 다음, 완주 목록 나올때마다 --를 해서 0보다 작은애가 정답이다
그리고 어차피 auto 쓸거면 벡터 순회할 때 아래와 같이 하자
    for(auto item : completion)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// 참여한 선수들, 완주한 선수들
// 딱 한명 완주하지 못한 선수의 이름 리턴
// 동명이인 있음
string solution(vector<string> participant, vector<string> completion) { 
    string answer = "";

    multimap<string, bool> m; // 키 중복되므로 multimap 사용
    // 참가자 다 넣기
    int len = participant.size();
    for(int i=0;i<len;i++) {
        m.insert(make_pair(participant[i], false));
    }

    // 완주하면 체크하기
    len = completion.size();
    for(int i=0;i<len;i++) {
        // 하나도 없으면 거르기
        if(m.find(completion[i]) == m.end())   continue;

        // 여러개 있을 수 있으니 루프 돌면서 false인 값을 체크
        auto iter_pair = m.equal_range(completion[i]);
        for(auto iter = iter_pair.first; iter != iter_pair.second ; ++iter) {
            // printf("%s\n", iter->first.c_str());
            if(iter->first == completion[i] && iter->second == false) {
                iter->second = true;
                break;
            }
        }
        
    }

    // 아직 false인 애 있으면 걔가 답
    for(auto iter = m.begin() ; iter != m.end() ; iter++) {
        if(iter->second == false) {
            return iter->first;
        }
    }
}

int main(){
    string arr1[] = {"mislav", "stanko", "mislav", "ana"};
    string arr2[] = {"stanko", "ana", "mislav"};

    vector<string> test1, test2;
    for(int i=0;i<3;i++) {
        test1.push_back(arr1[i]);
        test2.push_back(arr2[i]);
    }
    test1.push_back(arr1[3]);

    // printf("%s\n",solution(test1, test2));
    cout << solution(test1, test2) ;
}