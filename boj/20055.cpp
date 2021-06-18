 /* 20055. 컨베이어 벨트 위의 로봇
틀렸던 이유
- 문제 이해를 잘못하고, move()의 구현도 잘못함
 
시행착오
- TC4번 틀렸다. 답 472인데 479가 나온다.
   - move를 앞에서부터 하는게 아니라 뒤에서부터 거꾸로 검사해서 해야한다......................
   - 평소에 줄 빠지고 옮길 때 생각해봐
   - 그리고 N칸에 오면 무조건 내리기때문에, move하고나서도 N칸에 로봇이 있으면 내려줘야 함
*/
 
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
 
int n, k;
int a[101*2]; // 컨베이어 벨트의 내구도
int check[101];// i번째 컨베이어에 로봇이  있는지. 없으면 0, 있으면 1
int ans = 1;
 
void rotate(){ // 벨트 한 칸 회전
   int a2[101*2], check2[101];
   memcpy(a2, a, sizeof(a));
   memcpy(check2, check, sizeof(check));
 
   // 내구도 회전
   for(int i=1;i<=2*n-1;i++) {
       a[i+1] = a2[i];
   }
   a[1] = a2[2*n];
 
   // check 회전
   for(int i=1;i<=n-1;i++) {
       check[i+1] = check2[i];
   }
   check[1] = 0; // 회전했으니까 아무도 없음
}
 
 
void print(){
   printf("\nA : \n");
   for(int i=1;i<=2*n;i++) {
       printf("%d ", a[i]);
   }
   printf("\ncheck : \n");
   for(int i=1;i<=n;i++) {
       printf("%d ", check[i]);
   }
   printf("\n");
}
 
void move(){
    // 2. 가장 먼저 벨트에 올라간 로봇부터 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다.
   // 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아있어야 한다.
   // 이동할 수 없다면 가만히 있는다.
 
   // 거꾸로 검사를 해줘야하나...?
   // 먼저 내려!
   if(check[n] == 1) check[n] = 0;
 
   for(int i=n-1;i>=1;i--) {
       // 지금 칸에 로봇이 있어야지
       if(check[i] == 1) {
           // 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상이면
           if(check[i+1] == 0 && a[i+1] >= 1) {
               check[i] = 0;
               check[i+1] = 1;
               a[i+1]--;
           }
       }
   }
 
   // N칸에 오면 무조건 내리기때문에, move하고나서도 N칸에 로봇이 있으면 내려줘야 함
   if(check[n] == 1) check[n] = 0;
}
 
int count(){ // 내구도가 0인 칸의 갯수 세기
   int cnt = 0;
 
   for(int i=1;i<=2*n;i++) {
       if(a[i] == 0)   cnt++;
   }
  
   return cnt;
}
 
void solution(){
   while(true) {
       // 1. 벨트 한 칸 회전
       rotate();
 
       // 2. 가장 먼저 벨트에 올라간 로봇부터 벨트가 회전하는 방향으로 한 칸 이동할 수 있다면 이동한다.
       // 로봇이 이동하기 위해서는 이동하려는 칸에 로봇이 없으며, 그 칸의 내구도가 1 이상 남아있어야 한다.
       // 이동할 수 없다면 가만히 있는다.
       move();
 
       // 3. 올라가는 위치에 로봇이 없다면 로봇을 하나 올린다.
       // 내구도가 0인 칸에는 로봇이 올라갈 수 없다.
       // 로봇이 올라가면 즉시 1만큼 감소
       if(check[1] == 0 && a[1] >= 1) {
           check[1] = 1;
           a[1]--;
       }
 
       // 4. 내구도가 0인 칸의 개수가 K개 이상이라면 과정을 종료한다. 그렇지 않으면 1번으로 돌아간다.
       if(count() >= k)    break;
       ans++;
   }
}
 
int main(){
   scanf("%d %d", &n, &k);
   for(int i=1;i<=2*n;i++) {
       scanf("%d", &a[i]);
   }
   solution();
 
   // 종료되었을 때 몇 번째 단계가 진행중이었는지 출력 (가장 처음은 1단계)
   printf("%d\n", ans);
}
