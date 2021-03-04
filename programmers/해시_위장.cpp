/* Programmers - 해시 - 위장
더 나은 풀이 : map은 처음 들어오는 key가 있으면, 디폴트로 0으로 들어간다. find 굳이 안해도 되는듯
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// 서로 다른 옷의 조합의 수
// 최소 하나는 입어야 함
int solution(vector<vector<string>> clothes) {
    int len = clothes.size();
    map<string, int> m; // 의상 종류, 갯수

    for(int i=0;i<len;i++) {
        // {의상의 이름, 의상의 종류}
        // 이 종류가 들어온 적 없으면
        if(m.find(clothes[i][1]) == m.end()) {
            m.insert(make_pair(clothes[i][1], 1));
            m[clothes[i][1]]++; // 아얘 안입은 경우를 위해 하나 추가
        } else {
            m[clothes[i][1]]++;
        }
    }

    // 모든 경우의 수 계산
    int answer = 1;
    for(auto iter = m.begin() ; iter != m.end() ; iter++) {
        answer *= iter->second;
    }

    answer--; // 공집합 하나 빼기
    
    return answer;
}

int main(){
    string arr[] = {"12","123","1235","567","88"};
    // string arr2[] = {"stanko", "ana", "mislav"};

    vector<string> test;
    for(int i=0;i<5;i++) {
        test.push_back(arr[i]);
    }
    // printf("%s\n",solution(test1, test2));
    cout << solution(test) ;
}