/* Programmers - 이분탐색 - 입국심사
- 와 처음에 감도 안온다 ... 이걸 어떻게 이분탐색으로 푸는거지?
틀린 이유 2개)
    1) ans 초기화를 최댓값으로 했어야 했는데 이상한걸로 했었다.
    2) int값 * int값 => int 값이 된다는걸 잊지 말았어야지 .. long long으로 형변환 해주자
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> times) {
    // 총 탐색 시간으로 이분탐색 돌림. 1 ~ 최대탐색시간(제일 긴사람 * 명 수)
    int len = times.size();
    sort(times.begin(), times.end());

    long long left = 1;
    long long right = n * (long long)times[len-1];

    long long ans = right; // 최대값으로 답 초기화

    // 이분탐색
    while(left <= right) {
        long long mid = (left + right)/2;
        
        // 모든 심사관들이 이 시간동안 처리할 수 있는 사람의 총 합 구하기
        long long sum = 0;
        for(int i=0;i<len;i++)
            sum += mid / times[i];
        
        // n명을 처리할 수 있으면
        if(n <= sum) {
            // 정답 최솟값으로 업데이트 (가장 처음 값 예외처리)
            ans = min(ans, mid);
            // 더 작은값을 찾아떠나기
            right = mid-1;
        } else { // 그렇지 않으면, 시간 늘려야 함
            left = mid+1;
        }
    }
    return ans;
}

int main(){
    vector<int> test{7, 10};

    printf("답 : %d\n", solution(6, test));
}