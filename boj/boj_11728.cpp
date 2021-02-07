#include <iostream>
using namespace std;

int n, m;
int a[1000000+1], b[1000000+1];
int c[2000000+2];

int main() {
    scanf("%d %d", &n, &m);

    for(int i=0;i<n;i++)
        scanf("%d", &a[i]);
    

    for(int i=0;i<m;i++)
        scanf("%d", &b[i]);
    
    // 정렬되어있다고 했으니까 ,,,
    int index1=0, index2=0;
    int index = 0;

    while(index1 < n && index2 < m) {
        if(a[index1] < b[index2]) { // a가 더 작으면,
            c[index] = a[index1];
            index++;
            index1++;
        } else if( a[index1] >= b[index2]) {
            c[index] = b[index2];
            index++;
            index2++;
        }
    }

    // A에서 남은거 처리
    if(index1 < n) {
        for(int i=index1;i<n;i++) {
            c[index] = a[i];
            index++;
        }
    }

    // B에서 남은거 처리
    if(index2 < m) {
         for(int i=index2;i<m;i++) {
            c[index] = b[i];
            index++;
        }
    }

    // 결과 출력
    for(int i=0;i<index;i++) {
        printf("%d ", c[i]);
    }
    
}