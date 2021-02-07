/* 투 포인터
- 처음 런타임 에러 : Inteager Overflow => 에라토스테네스의 체로 소수 구하는 과정에서 발생했음
- 두번째 런타임 에러 : OutOfBounds => while문 돌면서 크기가 딱 맞는 vector에서 문제 발생
*/
#include <iostream>
#include <vector>
#include <cmath>
using namespace std; 

int main() {
    int n;

    scanf("%d", &n);

    // 2 ~ n까지의 소수 구해서 배열에 넣기
    vector<bool> check;
    check.resize(n+1, false);

    for(int i=2;i*i <= n;i++) { //  처음에 그냥 i<=n으로 줘서 Integer Overflow 남
        if(check[i] == false) {
            for(int j=i*i ; j<=n ;j+=i)
                check[j] = true;
        }
    }

    for(int i=2;i<=n;i++)
        check[i] = !check[i];

    // 소수만 배열에 넣기
    vector<int> arr;
    for(int i=2;i<=n;i++) {
        if(check[i])    { 
            arr.push_back(i);
            // printf("%d ",i);
        }
    }
    arr.push_back(0); // 두번째 런타임 에러 해결을 위해 크기 하나 늘려줌
    
    // 투 포인터
    int left=0, right=0;
    long long sum = 0;
    int ans = 0;

    int len = arr.size();
    while(right <= len) {
        // 포인터 움직이기
        if(sum < n) {
            sum += arr[right++];
        } else if (sum >= n) {
            sum -= arr[left++];
        }
        // 정답 체크
        if(sum == n)    ans++;
    }

    printf("%d\n", ans);

}