/*
LeetCode -  Subsets
- 재귀로 완탐했다
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool check[11]; // i번째 index를 포함하는지
    vector<vector<int>> answer;
    // 전역변수화
    vector<int> numbers;
    int len = 0;

    void solve(int index) {
        // 정답을 찾은 경우
        if(index == len) {
            // 현재 체크된 애들로 subset 만들기
            vector<int> temp;
            for(int i=0;i<11;i++) {
                if(check[i])    temp.push_back(numbers[i]);
            }
            // 정답에 추가
            answer.push_back(temp);
            return;
        }
        // 불가능한 경우
        if(index>len)   return;

        // 다음 경우
        // 나를 포함
        check[index] = true;
        solve(index+1);

        // 나를 포함하지 않음
        check[index] = false;
        solve(index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        numbers = nums;
        len = nums.size();
        solve(0);

        return answer;
    }
};

int main(){
    Solution s;
    vector<int> input = {0};
    // string input = "";

     vector<vector<int>> output = s.subsets(input);

     cout << output.size() << "\n";
}
