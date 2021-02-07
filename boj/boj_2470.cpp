#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int arr[100001];

int main() {
    int n;
    scanf("%d", &n);

    for(int i=0;i<n;i++) {
        scanf("%d", &arr[i]);
    }

    sort(arr, arr+n);

    // 투포인터 알고리즘
    int left = 0, right = n-1;
    int al =  arr[left], ar = arr[right];
    int ans = al + ar ;

    while(left < right) { // 크거나 같다로 주면 틀린다 !!!! 같아지면 무조건 빠져나와야지. 이건 '서로 다른' 두 수의 합이니까
        int temp = arr[left] + arr[right];

        if(abs(temp) < abs(ans)) { // 정답 업데이트
            ans = temp;
            al = arr[left];
            ar = arr[right];
        }

        // 포인터 이동 
        if(temp >= 0) { // 기준점인 0보다 값이 크면, 합을 줄여야 함
            right--;
        } else {
            left++;
        }
    }

    printf("%d %d\n", al, ar);
    
}