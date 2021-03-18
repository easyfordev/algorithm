/* Codility - CountSemiprimes
- 아래 코드는, 정확성은 100% 나왔지만, Performance에서 40%만 맞았다. 다시 풀어야 한다.

*/

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// semiprime : 2개의 소수를 곱해서 만들 수 있는 수 (4, 6, 9, 10, 14, ...)
// 1 <= P <= Q <= N 사이의 semiprime의 갯수 구하기
vector<bool> check;
bool isSemiprime(int num) {
    if(num == 1)    return false;
    for(int i=2;i<=sqrt(num);i++) {
        if(num % i == 0) {
            int j = num / i;
            // 두 수 다 소수이면, 이건 Semiprime임
            if(check[i] && check[j])
                return true;
        }
    }

    return false; // 끝까지 검사했는데 아니면, 이건 아닌거지
}

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
    // write your code in C++14 (g++ 6.2.0)
    // 일단 1 ~ N까지의 소수 구하기
    check.resize(N+1);
    for(int i=2;i<=N;i++) {
        if(check[i] == false) { // 아직 검사 안했으면,
            for(int j=i*i;j<=N;j+=i) {
                check[j] = true;
            }
        }
    }
    // 바꾸기
    for(int i=2;i<=N;i++)
        check[i] = !check[i];
    // // 소수 출력
    // for(int i=1;i<=N;i++) {
    //     if(check[i] == true)
    //         printf("%d ", i);
    // }

    // 1~N까지 Semiprime 구하기
    vector<bool> semiprime(N+1);
    for(int i=1;i<=N;i++) {
        semiprime[i] = isSemiprime(i);
    }

    //  세미 소수 출력
    // for(int i=1;i<=N;i++) {
    //     if(semiprime[i] == true)
    //         printf("%d ", i);
    // }
    
    // 정답 구하기
    vector<int> ans;
    int len = P.size();
    for(int t=0;t<len;t++) {
        int sum = 0;
        for(int i=P[t] ; i<=Q[t] ; i++) {
            if(semiprime[i]) sum++;
        }
        // printf("%d\n", sum);
        ans.push_back(sum);
    }

    return ans;
}


int main(){
    vector<int> test{1,4,16};
    vector<int> test2{26,10,20};
    solution(26, test, test2);
    // printf("답 : %d\n", solution(26, test, test2));
}