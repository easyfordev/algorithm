/*
Leetcode - 11. Container With Most Water

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // 투포인터로 풀자
        int left = 0;
        int right = height.size()-1;
        int ans = 0; // 물 최댓값

        while(left < right) {
            // 현재 상태 정답 계산하기
            int lower = min(height[left],height[right]);
            int temp = lower * (right-left); // 가로 * 세로
            ans = max(ans, temp); // 정답 업데이트

            // 포인터 움직이기 - (이게 핵심 아이디어!)
            // lower로 나온 애는 건드리지 말고, 최적을 찾아서 떠난다.
            if(height[left] > height[right]) { // left가 더 나은 기준이었으면,
                right--;
            } else { // right가 더 나은 기준이었으면,
                left++;
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout << s.maxArea(height);
}