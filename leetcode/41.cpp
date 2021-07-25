/*
Leetcode - 41. First Missing Positive
- 일단 정렬을 하고 -> 기준을 잡고 루프를 돌면서 비교하고 아니면 바로 정답 -> 이런 아이디어가 중요한 것 같다.
- vector 중복 제거 하는 문법 알아두기
    sort() -> unique() : 중복된 원소를 맨 뒤로 보내고 그게 시작하는 iter 리턴 -> erase() : 중복 쓰레기 시작점부터 끝까지 삭제
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // 일단 정렬
        sort(nums.begin(), nums.end());
        // 중복 제거
        nums.erase( unique(nums.begin(), nums.end()), nums.end() );

        int len = nums.size();
        int check = 1;
        for(int i=0;i<len;i++) {
            // 음수는 검사 안함
            if(nums[i] <= 0) continue;
            // 1부터 쭉 검사
            if(nums[i] != check)  {                
                break;
            }
            check++;
        }

        return check;
    }
};

int main(){
    Solution s;
    vector<int> nums = {7,8,9,11,12};
    s.firstMissingPositive(nums);
}