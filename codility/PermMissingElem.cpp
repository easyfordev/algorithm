/* Codility - Time Complexity - PermMissingElem

틀린 이유 : empty list 들어왔을때 답이 틀렀었다. 0이 아니라 1을 리턴했어야 했다!
*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> &A) {
    int len = A.size();

    // 예외처리 - empty list
    if(len == 0)    return 1;
    vector<int> check(100000+1+1);

    // 모든 수 체크하면서 최댓값도 찾기
    int maxV = -1;
    for(int i=0;i<len;i++) {
        check[A[i]] = 1;
        
        if(A[i]>maxV)   maxV = A[i];
    }

    // 이렇게 찾으면 O(n)인데 ...
    for(int i=1;i<=maxV;i++) {
        if(check[i] == 0)   return i;
    }
}

int main(){
    vector<int> test{}; 

    printf("답 : %d\n", solution(test));
}