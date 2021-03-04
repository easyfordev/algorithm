/* Codility - OddOccurrenceslnArray */
// you can use includes, for example:
#include <iostream>
#include <map>
#include <vector>
using namespace std;
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int len = A.size();
    map<int, int> m; // key, 갯수
    vector<bool> check(1000000001);

    for(int i=0;i<len;i++) {
        // 없으면 
        // if(m.find(A[i]) == m.end()) {
        if(check[A[i]] == false) {
            m.insert(make_pair(A[i], 1));
            check[A[i]] = true;
        } else {
            m[A[i]]++;
        }
    }

    // map 돌면서 갯수가 홀수인 애 찾아서 리턴
    len = m.size();
    
    for(auto iter=m.begin(); iter != m.end(); iter++) {
        if((iter->second)%2 == 1){
            return iter->first;
        }
    }
}

int main(){
    int arr[5] = {2, 2, 3, 3, 4};
    vector<int> test;
    for(int i=0;i<5;i++) {
        test.push_back(arr[i]);
    }

    printf("%d\n",solution(test));
}
