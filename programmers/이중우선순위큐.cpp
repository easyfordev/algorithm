/* Programmers - 힙 - 이중우선수위큐
내가 푼 방법 : 최댓값 큐, 최솟값 큐 2개를 만들어서 관리하고, 멤버 수만 센다
왜 되는거지?

더 나은 풀이) set(multiset)은 자동으로 **정렬**이 되니까.. 이걸 쓰면 완전 간단하다.
set은 iter도 되고. erase도 되니까 완전 좋다.
vector<int> solution(vector<string> arguments) {
    vector<int> answer;
    multiset<int> que;
    multiset<int>::iterator iter;
    string sub;

    for(auto s : arguments) {
        sub =s.substr(0, 2);
        if(sub=="I ") que.insert(stoi(s.substr(2,s.length()-2))); 
        else if(s.substr(2,1)=="1"&&que.size()>0) { que.erase(--que.end()); }
        else if(que.size()>0) { que.erase(que.begin()); }
    }

    if(que.size()==0) { answer.push_back(0); answer.push_back(0); }
    else { 
        iter = --que.end(); answer.push_back(*iter); 
        iter = que.begin(); answer.push_back(*iter);
    }

    return answer;
}
*/
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<string> operations) {
    // 최댓값, 최솟값 큐를 따로 만든다.
    // 최댓값 삭제 => 그 수를 최솟값 큐에서도 삭제 flag를 붙여준다.
    // 일단 풀어보자
    priority_queue<int, vector<int>, greater<int> > min_q; // 최소값 먼저 나오는 큐
    priority_queue<int> max_q; // 최댓값 먼저 나오는 큐
    int cnt = 0; // 현재까지 총 원소 갯수
    
    for(string item : operations) {
        // cnt == 0이면, 큐를 다 비운다
        if(cnt == 0) {
            while(!min_q.empty())   min_q.pop();
            while(!max_q.empty())   max_q.pop();
        }
        // printf("%s\n", item.c_str());
        string cmd = item.substr(0, 2);
        string num = item.substr(2, item.size()-2);
        // cout << cmd << "    " << num << "\n";
        
        if(cmd == "I ") { // 각각 넣기
            min_q.push(stoi(num));
            max_q.push(stoi(num));
            cnt++;
        } else if(cmd == "D ") {
            // 빈 큐에 삭제하라고 하면, 해당 연산 무시
            if(cnt == 0)     continue;
            if(num == "1") { // 최댓값 삭제
                max_q.pop();
            } else if(num == "-1") {
                min_q.pop();
            }
            cnt--;
        }
    }

    vector<int> answer;

    if(cnt == 0) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(max_q.top());
        answer.push_back(min_q.top());
    }

    return answer;
}

int main(){
    // string arr[] = {"classic", "pop", "classic", "classic", "pop"};
    // int arr[] = {3, 0, 6, 1, 5};
    vector<string > test{"I 7","I 5","I -5","D -1"};
    // string test = "17";
    // vector<int> test;

    // vector<vector<int>> test2;
    // for(int i=0;i<5;i++) {
    //     test.push_back(arr[i]);
    // }
    vector<int> ans = solution(test) ;

    printf("답 : %d %d\n", ans[0], ans[1] );
}