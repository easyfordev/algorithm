/* Programmers - 예산
완전탐색밖에 생각이 안나는데...
아니면 그냥 진짜 간단하게 정렬해서 풀거나 => 일단 이걸로 풀어서 맞음
*/
#include <iostream>
#include <string>
#include <vector>

#include <algorithm>
using namespace std;
// 최대한 많은 부서의 물품을 구매해주려고 함 => 정렬해서 작은쪽부터 준다.
// 최대 몇개의 부서에 물품을 지원할 수 있는지 리턴

int solution(vector<int> d, int budget) {
    sort(d.begin(), d.end());
    int sum = 0, cnt = 0;

    int len = d.size();
    for(int i=0;i<len;i++) {
        sum += d[i];
        cnt++;
        if(sum > budget) {
            sum -= d[i];
            cnt--;
            return cnt;
        }
    }

    return cnt;
}

int main(){
    vector<int> test{2,2,3,3};

    printf("답 : %d\n", solution(test, 10));
}

