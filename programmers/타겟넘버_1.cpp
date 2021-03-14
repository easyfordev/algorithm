/* Programmers - DFS/BFS - 타겟 넘버
완전탐색으로 풀어볼까? true면 -, false면 +하도록

- 처음엔 좀 지저분하게 풀었었는데(그래도 답은 맞음), 다른사람 풀이 보고 조금 더 깔끔하게 풀어보자.
- sum(지금까지의 합)을 들고가면 되잖아
- 매개변수로 vector 값까지 다 넘기는 방법 알아두기 -> &를 붙이면 된다

*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int ans = 0;
vector<bool> check;
vector<int> nums; // numbers 복사

int calc() {
    int len = nums.size();

    // 초기값
    int result = 0;
    if(check[0] == true)    result = -1 * nums[0];
    else if(check[0] == false) result = 1 * nums[0];

    for(int i=1;i<len;i++) {
        // check가 true면 -, false면 + 하도록
        if(check[i] == true)    result += -1 * nums[i];
        else if(check[i] == false) result += 1 * nums[i];
    }

    return result;
}

void go(int index, int target) {
    // 정답을 찾은 경우
    if(index == nums.size()) {
        // 계산하고, 타겟 넘버를 만들 수 있으면
        if(calc() == target)    ans++;
        return;
    }

    // 불가능한 경우
    if(index > nums.size()) {
        return;
    }

    // 다음 경우
    // 나를 포함
    check[index] = true;
    go(index+1, target);

    // 나 포함 X
    check[index] = false;
    go(index+1, target);
}

int solution(vector<int> numbers, int target) {
    // n개의 자연수, 타겟넘버도 자연수
    // 적절히 더하거나 빼서 타겟넘버를 만듦
    // -1+1+1+1+1 = 3
    // 타겟넘버를 만드는 방법의 수 리턴
    check.resize(numbers.size());

    nums.insert(nums.begin(), numbers.begin(), numbers.end());

    go(0, target);

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