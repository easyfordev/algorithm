/* Programmers - 완전탐색 - 카펫
- 문제 상황을 그림을 그려보며 잘 이해하자
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> solution(int brown, int yellow) {

    // yellow를 만드는 모든 경우의 수 탐색
    int i, j;

    int limit;
    if(yellow < 2)
        limit = yellow;
    else
        limit = yellow/2;
            // printf("limit : %d \n", limit);

    for(i=1;i<=limit;i++) {
        // printf("i : %d \n", i);

        if(yellow % i == 0) { // 나누어 떨어지면
            j = yellow / i;

            // 테두리 타일 갯수 == brwon 갯수이면 이게 정답
            int cnt = 2 * (i + j + 2);
            // printf("i : %d, j : %d, cnt: %d\n", i,j, cnt);

            if (cnt == brown)
                break;
        }
    }

    // 가로 >= 세로 바꾸기
    int a, b;
    // printf(">>>>i : %d, j : %d\n", i,j);

    if(i >= j) {
        a = i;  b = j;
    } else {
        a = j; b = i;
    }

    vector<int> answer;
    answer.push_back(a+2);
    answer.push_back(b+2);

    return answer;
}

int main(){
    // string arr[] = {"classic", "pop", "classic", "classic", "pop"};
    // int arr[] = {3, 0, 6, 1, 5};
    vector<int> test{1, 2, 3, 4, 5};
    // string test = "17";
    // vector<int> test;

    // vector<vector<int>> test2;
    // for(int i=0;i<5;i++) {
    //     test.push_back(arr[i]);
    // }
    vector<int> ans = solution(24,24);

    printf("답 : %d %d", ans[0], ans[1]);
}