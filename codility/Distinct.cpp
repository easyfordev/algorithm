/* Codility - sort - Distinct
*/
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    set<int> s;

    int len = A.size();
    for(int i=0;i<len;i++) {
        s.insert(A[i]);
    }

    return s.size();
}

int main(){
    vector<int> test{2, 1, 1, 2, 3, 1};

    printf("답 : %d\n", solution(test));
}