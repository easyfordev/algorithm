#include <iostream>
#include <queue>
#include <cmath>
using namespace std; 
int n;

int main() {

    scanf("%d", &n);

    int x;
    // 절대값, 양수 음수 여부(-1이면 음수, 1이면 양수
    // 디폴트는 큰놈부터 나온다. 작은놈부터 나오려면 greater 해줘야 함
    // 절댓값이 가장 작은 값이 여러개일때는, 가장 작은 수를 출력하고 그 값을 배열에서 제거한다 => 그래서 -1, 1을 넣어줬다
    priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > pq; 
    while(n--) {
        scanf("%d", &x);
        if(x == 0) {
            // 배열이 비어있으면, 0출력
            if(pq.empty()) {
                printf("0\n");
                continue;
            }
            // 배열에서 절댓값이 가장 작은 값을 출력하고, 그 값을 배열에서 제거한다
            printf("%d\n", pq.top().first * pq.top().second);
            
            pq.pop();
        } else {
            // x 넣기
            int sign = x < 0 ? -1 : 1;
            pq.push(make_pair(abs(x), sign));
        }
        

    }
}