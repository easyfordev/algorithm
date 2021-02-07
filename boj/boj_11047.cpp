#include <iostream>
#include <vector>
using namespace std;
int n, k;
vector<int> v;

int main(void) {
    scanf("%d %d", &n, &k);
    v.resize(n);

    for(int i=0;i<n;i++) {
        scanf("%d", &v[i]);
    }

    // K원을 만드는데 필요한 동전 개수의 최솟값
    int ans = 0;

    for(int i=n-1;i>=0;i--) {
        int coin = v[i];
        if(coin > k)    continue;
        ans += k/coin;
        k %= coin;
    }

    printf("%d\n", ans);
    return 0;
}