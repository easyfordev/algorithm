/* Programmers - 정렬 - K번째수 
처음에 TC 답 하나 틀렸었음 - 배열 slice를 이상하게 했음
(더 나은 풀이) - 그냥 temp에 vector 복사하고, i부터 j까지만 sort하고, 그 k-i번째 index값을 리턴함
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// i~j까지 자르고 정렬했을 때 k번째 수
// command는 여러개 - [i, j, k]가 여러개

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for(int t=0;t<commands.size();t++) {
        int i = commands[t][0];
        int j = commands[t][1];
        int k = commands[t][2];

        // vector slice 이렇게! assign 함수 이용하기
        vector<int> v;
        auto start = array.begin() + (i-1);
        auto end = array.begin() + (j-1) + 1; // copy하면 start ~ end -1까지 하니까
    
        v.assign(start, end); 
        // 정렬 후 k번째 수 구하기
        sort(v.begin(), v.end());
        // printf("%d ", v[k-1]);

        answer.push_back(v[k-1]);
    }

    return answer;
}

int main(){
    // string arr[] = {"classic", "pop", "classic", "classic", "pop"};
    int arr[] = {1, 5, 2, 6, 3, 7, 4};
    int arr2[] = {2, 5, 3};
    int arr3[] = {4, 4, 1};
    int arr4[] = {1, 7, 3};

    vector<int> test{1, 5, 2, 6, 3, 7, 4};
    vector<vector<int>> test2{{2, 5, 3}, {4, 4, 1}, {1, 7, 3}};
    // vector<vector<int>> test2;
    // for(int i=0;i<7;i++) {
    //     test.push_back(arr[i]);
    // }

    // test2.push_back();
    // // printf("%s\n",solution(test1, test2));
    // vector<int> ans = solution(test, test2) ;

    // for(auto item : ans) {
    //     printf("%d ", item);
    // }
    solution(test, test2);
}