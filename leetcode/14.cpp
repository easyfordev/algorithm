/*
LeetCode - Longest Common Prefix
- 이중 for문을 도는게 최선일까 ..?
*/
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        
        string str = strs[0];

        // 첫번째꺼 기준으로 한글자씩 줄여가면서 탐색
        for(int i=0;i< str.size();i++) {
            string prefix = str.substr(0, str.size()-i); // 시작점, 길이
            // 다른 모든 멤버 탐색
            bool flag = false;
            for(int j=1;j<strs.size();j++) {
                string item = strs[j];

                // 전체 길이가 이 prefix보다 짧으면 안된다
                int s1 = item.size();
                int s2 = prefix.size();
                
                if(s1 < s2) break;
            
                // 'pre'fix이므로 이걸로 시작해야한다.
                string temp = item.substr(0, prefix.size());
                if(temp != prefix) break;
                
                // 끝까지 다 같으면 true로 변경
                int len = strs.size();
                if(j == len -1) flag = true;
            }
            
            // Longest니까 한번이라도 끝까지 탐색했으면 true 리턴
            if(flag)    return prefix;
        }

        // 여기까지 왔는데 없으면, common prefix가 없는 것
        return "";
    }
};

int main(){
    Solution s;
    vector<string> input = {"dog","racecar","car"};

    cout << s.longestCommonPrefix(input);
}
