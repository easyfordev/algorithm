/* Programmers - 그리디 - 체육복

- 이것도 처음에 어떻게 푸는지 잘 모르겠다. 근데 진짜 그냥 처음에 생각한대로 풀면 되는거였다.
- (헤맨 포인트) 앞, 뒤 둘중에 어떤걸 빌려올지 어떻게 알아? -> 그냥 앞사람부터 먼저 보고, 없으면 뒷사람. 계속 뒤로 넘어가니까!
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    vector<int> check(n, 1);

    for(int i=0;i<reserve.size();i++)
        check[reserve[i]-1]++; // 번호 1부터니까 꼭 빼주기!
    
    for(int i=0;i<lost.size();i++)
        check[lost[i]-1]--;
    
    // 체육복 없으면, 바로 앞 or 바로 뒤 애한테 빌려오기
    for(int i=0;i<n;i++) {
        if(check[i] == 0) {
            // 앞 학생에게 빌려오기 (범위 예외처리)
            if(check[i-1] == 2 && i-1 >= 0) {
                check[i-1]--;
                check[i]++;
            } else if(check[i+1] == 2 && i+1 < n) { // 뒤 학생에게 빌려오기 (범위 예외처리)
                check[i+1]--;
                check[i]++;
            }
            
        }
    }

    // 체육수업 들을 수 있는 학생 수 구하기
    int answer = 0;
    for(int i=0;i<n;i++)
        if(check[i] != 0)   answer++;
    
    return answer;
}

int main(){
    vector<int> test{7, 10};

    printf("답 : %d\n", solution(6, test));
}