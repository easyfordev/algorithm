/* Programmers - 스택/큐 - 기능개발 */
#include <iostream>
#include <string>
#include <vector>

#include <queue>
using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    int len = progresses.size();

    // 일단 각 기능마다 필요한 날 수 구해서 저장
    queue<int> q;
    for(int i=0 ; i<len ; i++) {
        int remain = 100 - progresses[i];
        int d; // 더 똑똑한 수식 : day = (99 - progresses[i]) / speeds[i] + 1;
        if(remain%speeds[i] == 0)   d = remain / speeds[i];
        else    d = remain / speeds[i] + 1;

        q.push(d);
    }

    // 맨 앞부터 빼서, 이번 아이템보다 필요한 날짜가 작으면 계속 pop
    vector<int> ans;

    while(!q.empty()) {
        int cnt = 1;

        // 큐에서 하나 빼기
        int days = q.front();
        q.pop();

        // 이 값보다 작거나 같으면 계속 빼기
        while(!q.empty()) {
            int t = q.front();
            if(t <= days) {
                q.pop();
                cnt++;
            } else {
                break;
            }
        }

        ans.push_back(cnt);
    }

    return ans;
}

int main(){
    vector<int> test{95, 90, 99, 99, 80, 99};
    vector<int> test2{1, 1, 1, 1, 1, 1};

    string t = "...."; // "X.XXXXX.X" , ".X..X", "XX.XXX"
    printf("답 : %d\n", solution(test, test2));
}

