/*
LeetCode - 15. 3 Sum
- 중복검사를 신경써줘야하는게 조금 힘들었다.
- 중복 아닐때까지 찾을 때 left < right 안넣어줘서 틀렸다.
*/
#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        // 예외처리 : 3개 미만인 경우 []리턴
        if(nums.size() < 3) {
            return ans;
        }

        // 일단 정렬
        sort(nums.begin(), nums.end());

        // 주의! 이전에 검사한 값과 달라야 한다.
        // 하나를 선택하고, 나머지 2개는 two pointer로 찾는다.
        for(int i=0;i<nums.size();i++) {
            // 이전에 검사한 인덱스와 중복이면, 또 검사할 필요가 없다.
            if(i>0 && nums[i-1] == nums[i]) continue;

            // 나머지 모든 경우에, two pointer로 합이 0인 경우를 찾는다.
            int left = i+1;
            int right = nums.size() -1;

            while(left < right) {
                // 현재 상태에서 조건에 맞는지 검사한다.
                printf("i:%d left:%d right:%d\n", nums[i], nums[left], nums[right]);
                if(nums[i] + nums[left] + nums[right] == 0) {
                    // 조건이 맞으면 답에 넣는다.
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    printf("==>%d %d %d\n", nums[i], nums[left], nums[right]);
                    ans.push_back(temp);

                    // 또 다른 경우를 위해 이동해준다.
                    left++; right--;

                    // 중복된 조합을 만들어낼 수 있으므로, 아얘 다른 멤버가 나올 때 까지 이동해야 한다.
                    while(left < right && nums[left-1] == nums[left]) 
                        left++;
                    
                    while(left < right && nums[right] == nums[right+1]) 
                        right--;
                    
                } else if(nums[i] + nums[left] + nums[right] > 0) { // 합이 더 크면, 줄여야함
                    right--;
                } else { // 합이 더 작으면, 키워야 함
                    left++;
                }
            }
        }

        return ans;
    }
};

int main(){
    Solution s;
    vector<int> nums =  {-1,0,0,0,1,2,-1,-4};
    // vector<int> nums = {0,1};
    // cout << s.threeSum(nums).size();
    s.threeSum(nums);
}
