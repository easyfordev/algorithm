/*
LeetCode - Daily Temperatures
- 맨 처음에 Time Limit Exceeded 났다.
- 생각해보니까 스택을 쓰긴 했지만, 효율적으로 쓰지 않았다.
- 스택을 안쓰는걸로 고쳤다. 그래도 시간초과 난다.
- 벡터 push가 오래걸리나? 그래도 시간초과다.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // 정답 사이즈 맞게 0으로 초기화
        vector<int> answer(temperatures.size(), 0);
        int len = temperatures.size();

        // index를 넣을 스택
        stack<int> s;
        for(int i=0;i<len;i++) {
            // 현재 index가 더 크면 나보다 따뜻한 날을 만난것이다
            while(!s.empty() && temperatures[s.top()] < temperatures[i] ) {
                answer[s.top()] = i - s.top(); // 이번 index의 정답 업데이트
                s.pop(); // 이 index는 정답 찾았으니까 pop
            }
            
            s.push(i); // 조건 만족 안하면 새로 넣기
        }

        return answer;
    }
};

int main(){
    Solution s;
    vector<int> input = {73,74,75,71,69,72,76,73};
    vector<int> output = s.dailyTemperatures(input);

    for(int item : output)  cout << item  << "\n";
}
