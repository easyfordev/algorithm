/* Programmers - DFS/BFS - 타겟 넘버
완전탐색으로 풀어볼까? true면 -, false면 +하도록

- 처음엔 좀 지저분하게 풀었었는데(그래도 답은 맞음), 다른사람 풀이 보고 조금 더 깔끔하게 풀어보자.
- check배열을 안쓰고 sum(지금까지의 합)을 들고가면 되잖아
- 매개변수로 vector 값까지 다 넘기는 방법 알아두기 -> &를 붙이면 된다
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int ans = 0;

void go(int index, int sum, vector<int> &numbers, int target) {
    // 정답을 찾은 경우
    if(index == numbers.size()) {
        // 계산하고, 타겟 넘버를 만들 수 있으면
        if(sum == target)    ans++;
        return;
    }

    // 불가능한 경우
    if(index > numbers.size())
        return;

    // 다음 경우
    // +인 경우
    go(index+1, sum + numbers[index], numbers, target);

    // -인 경우
    go(index+1, sum - numbers[index], numbers, target);
}

int solution(vector<int> numbers, int target) {
    // 맨처음값 경우의수 2개 -> +인 경우, -인 경우
    go(1, numbers[0]*1, numbers, target);
    go(1, numbers[0]*-1, numbers, target);

    return ans;
}

int main(){
    // string arr[] = {"classic", "pop", "classic", "classic", "pop"};
    // int arr[] = {3, 0, 6, 1, 5};
    vector<int> numbers{1,1,1,1,1};
    // string test = "17";
    // vector<int> test;

    // vector<vector<int>> test2;
    // for(int i=0;i<5;i++) {
    //     test.push_back(arr[i]);
    // }

    printf("답 : %d\n", solution(numbers, 3));
}