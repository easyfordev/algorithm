#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[15000 + 1];

int main() {
    // 두 재료의 고유한 번호를 합쳐서 M이 되면 갑옷
    // 갑옷을 몇개나 만들 수 있는지
    // 정렬 후 양 끝에서 다가온다
    scanf("%d", &n);
    scanf("%d", &m);

    for(int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }

    // 투 포인터 알고리즘
    sort(arr, arr+n);

    int left = 0, right = n-1;
    int ans = 0;

    while(left < right) { // 서로 달라야 함
        int temp =  arr[left] + arr[right];

        // 정답 찾았으면
        if(temp == m) {
            ans++;
        }

        // 포인터 움직이기
        if(temp < m) { // 작으면, 합을 키워줘야 함
            left++;
        } else if(temp >= m) { // 크면, 줄여줘야 함
            right--;
        }
    }

    printf("%d\n", ans);
}