/* Programmers - 모의테스트 - 직사각형 한 점 찾기
x좌표 중 다른 값 1개, y좌표 중 다른 값 1개 고르면 된다.
*/
#include <iostream>
#include <string>
#include <vector>

#include <map>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;
    map<int, int> x_map;
    map<int, int> y_map;

    for(int i=0;i<3;i++) {
        int x = v[i][0];
        int y = v[i][1];

        if(x_map.find(x) != x_map.end()) // 이미 있으면
            x_map[x]++;
        else
            x_map.insert(make_pair(x, 1));

        if(y_map.find(y) != y_map.end()) // 이미 있으면
            y_map[y]++;
        else
            y_map.insert(make_pair(y, 1));
    }

    // 딱 하나씩만 있는게 답
    for(auto iter = x_map.begin() ; iter != x_map.end() ; iter++) {
        if (iter->second == 1)  ans.push_back(iter->first);
    }

    for(auto iter = y_map.begin() ; iter != y_map.end() ; iter++) {
        if (iter->second == 1)  ans.push_back(iter->first);
    }

    return ans;
}

int main(){
    vector<vector<int>> test{{1, 4}, {3, 4}, {3, 10}};

    vector<int> ans = solution(test);
    printf("답 : %d %d \n", ans[0], ans[1]);
}

