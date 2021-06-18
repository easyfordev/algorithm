/*
LeetCode -  Longest Substring Without Repeating Characters
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // 영문자, 숫자, 특수문자, 공백
        map<char, int> m; // 특정 문자가 몇 번 나왔는지 체크

        // 투포인터, 조건을 만족하는 '최대길이'를 찾는 것이므로, 인덱스를 점점 벌린다.
        int left=0, right=0;
        int ans = 0; // 정답 초기화 (빈 문자열일 경우 고려. -1 하면 안된다)
        int len = s.size();

        while(right < len) { // 종료 조건
            // 현재 상태 검사
            m[s[right]]++;

            // 현재 right가 이미 있는데 또 들어온거면, left를 줄여서 중복이 없도록 만든다.
            if(m[s[right]] > 1) {
                while(m[s[right]] > 1) {
                    m[s[left]]--; // 현재 left 를 빼버리고
                    left++; // 옮긴다
                }
            }

            // 조건을 만족하는 left와 right를 찾았다. 정답 업데이트
            ans = max(ans, right-left+1);

            // 포인터 이동
            right++;
        }

        return ans;
    }
};

int main(){
    Solution s;
    // vector<int> input = {73,74,75,71,69,72,76,73};
    string input = "";

    cout << s.lengthOfLongestSubstring(input)  << "\n";
}
