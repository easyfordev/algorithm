/* Programmers - 이분탐색 - 징검다리

그냥 문제에서 설명한 로직대로 구현하면 무조건 터진다.

무엇을 기준으로 이분탐색을 돌려야하나? - 돌 사이 거리의 최솟값
최소 1 ~ 최대 distance

'최소 거리'를 지정 => 최소 거리에 맞게 돌을 제거
돌을 몇 개 제거할 수 있는지 확인 => n개가 된다면 - n개를 만족하는 더 큰 거리를 찾아 떠난다. / n개 넘게 지워야 한다면 - 거리를 더 줄인다.

후앙 헷갈려

*/
#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    sort(rocks.begin(),rocks.end());

    // 이분탐색
    int left=1, right = distance;
    int ans = 0; // 거리의 최솟값

    while(left <= right) {
        // 돌 사이 최소 거리
        int mid = (left+right)/2;

        // 지정한 최소거리보다 가까우면 그 돌 삭제
        int cnt = 0; // 제거한 돌 수
        int prev = 0;
        for(int i=0;i<rocks.size();i++) {
            int dist = rocks[i] - prev;

            if(dist < mid) { // 가까우면 삭제
                cnt++;
            } else { // 최소 거리 넘으면, 다음 거리 계산
                prev = rocks[i];
            }
        }

        // 맨 마지막 거리도 계산해준다
        int dist = distance - prev;
        if(dist < mid)  cnt++;

        // n개 넘게 지워야하면, 거리를 줄인다.
        if(cnt > n) {
            right = mid-1; // 최적의 답을 찾아 떠난다
        } else { // 만족하면, 거리를 늘려본다.
            ans = mid > ans ? mid : ans; // 정답 업데이트
            left = mid+1;
        }
    }

    return ans;
}

int main(){
    vector<int> test{2, 14, 11, 21, 17};
    printf("답 : %d\n", solution(25, test, 2));
}

