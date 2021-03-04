/* Codility -  PermCheck */
// you can use includes, for example:
#include <iostream>
#include <vector>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int len = A.size();

    // 최댓값 구하기
    int maxV = A[0];
    for(int i=0;i<len;i++) {
        if(A[i] > maxV)
            maxV = A[i];
    }

    // 예외처리 : 최댓값보다 배열 크기가 작으면, 무조건 permutation 아님
    if(len != maxV)
        return 0;

    vector<int> check(A.size()+1);

    // 일단 다 갯수 세기
    for(int i=0;i<len;i++)
        check[A[i]]++;
    
    // 1개 이상이거나, 중간에 0인거 있나 체크
    // 1 ~ n
    for(int i=1;i<=maxV;i++) {
        if(check[i] != 1) {
            return 0;
        }
    }  

    return 1;
}

int main(){
    int arr[4] = {4,1,3,2};
    // int arr[3] = {4,1,3};
    vector<int> test;
    for(int i=0;i<4;i++) {
        test.push_back(arr[i]);
    }

    printf("%d\n",solution(test));
}
