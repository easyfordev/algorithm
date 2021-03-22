/* BOJ - 11659. 구간 합 구하기 4
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    vector<int> v(n);

    // v[0] = 0;

    for(int i=0;i<n;i++) {
        scanf("%d", &v[i]);
    }

    // Prefix Sum 구하기
    vector<int> psum;

    psum.push_back(0);
    int sum = 0;
    for(int i=0;i<n;i++) {
        sum += v[i];
        psum.push_back(sum);
    }

    // 정답 출력
    for(int tc=0;tc<m;tc++) {
        int l, r;
        scanf("%d %d", &l, &r);

        printf("%d\n", psum[r] - psum[l-1]);
    }

}

