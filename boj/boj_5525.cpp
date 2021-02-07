/* 처음에 substr로 풀었는데 시간초과났다.
매번 substr을 만들지않고, O(N)으로 풀어야 한다
- Pn에 대한 접근 자체를 'IOI'가 n개인 문자열로 접근한다.
- IOI가 반복될때마다 cnt를 증가시킨다
- cnt가 n이 되면, 정답을 하나 증가시키고,
- IOI의 cnt를 1 감소시킨다(다시 검사하기 위해)

외워서 풀면 절대 안돼 ... 이해하고 스스로 알고리즘을 짤 줄 알아야지 !! 

*/
#include <iostream>
using namespace std;

char temp[1000000+1];
int n, m;

int main(void) {
    // 입력받기
    scanf("%d", &n);
    scanf("%d", &m);
    getchar();
    scanf("%s", temp);
    string str = temp;

    int cnt = 0; // IOI 패턴 카운트
    int ans = 0; // Pn(정답) 갯수 카운트
    for(int i=1;i<m-1;i++) {
        if(str[i-1]=='I' && str[i] == 'O' && str[i+1] == 'I') {
            cnt++;
            if(cnt == n) {
                ans++;
                cnt--;
            }
            i++; // for문에 있는 i++, 여기서 i++해서 2개 건너뛴다
        } else
            cnt = 0; // IOI가 아니면 카운트를 0으로 바꾼다
    }

    printf("%d\n", ans);
}