/* Programmers - DFS/BFS - 단어 변환

- 처음에 풀어서 맞긴 했다. bfs로 풀었다
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

string change(string str, int index, char c) { // str의 index번째 문자를 c로 바꿈
    string temp = str;
    temp[index] = c;

    return temp;
}

int str_find(vector<string> &words, string target) {
    for(int i=0;i<words.size();i++) {
        if(words[i] == target) {
            return i;
        }
    }

    return -1;
}

int solution(string begin, string target, vector<string> words) {
    // bfs로 풀어보자
    // 초기화
    vector<string> nwords;
    vector<int> check; // i번째 words를 방문했는지 체크 (몇번째로 방문했는지 저장)
    
    // 예외처리 : target이 words안에 없는 경우 -> 변환할 수 없음
    // target이 words안에 있는 경우, index를 저장
    int target_index = str_find(words, target);
    if(target_index == -1) return 0;
    else target_index++; // 시작점 하나 더 넣을거니까

    nwords.push_back(begin);
    nwords.insert(nwords.end(), words.begin(), words.end());
    
    check.resize(nwords.size(), -1); // 0번은 시작, 맨 마지막은 끝

    // 큐에 시작점 넣기
    queue< pair<string, int> > q; // 단어, count
    check[0] = 0;
    q.push(make_pair(begin, 0));

    while(!q.empty()) {
        // 큐에서 하나 꺼내기
        string str = q.front().first;
        int cnt = q.front().second;
        q.pop();

        // 다음 방문할 곳 정하기
        int len = begin.size();
        for(int i=0;i<len;i++){ // 자릿수
            for(int j='a'; j <= 'z' ; j++) { // 영문자 다 바꿔보기
                string temp = change(str, i, j);
                // words 배열에 있고, 아직 걔를 방문 안했으면
                int index = str_find(nwords, temp);
                if (index != -1 && check[index] == -1) {
                    check[index] = cnt + 1;
                    q.push(make_pair(temp, cnt+1)); // 걔를 큐에 넣기
                }
            }
        }
    }

    return check[target_index];
}

int main(){
    vector<string> test{"hot", "dot", "dog", "lot", "log", "cog"};

    printf("답 : %d\n", solution("hit","cog", test));
}