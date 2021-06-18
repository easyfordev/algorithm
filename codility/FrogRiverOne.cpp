/* Codility - Counting Elements - FrogRiverOne
*/
#include <iostream>
#include <string>
#include <vector>

#include <set>
using namespace std;

// 처음 위치 0 => x+1로 가고싶
// 가장 빠른 시간 찾기 다.
// A[K] = 초 단위로 측정된 시간 K에서 한 잎이 떨어져있는 위치(N개)

// 1에서 X까지 강건너의 모든 위치에 나타날 때만 건널 수 있음
// 개구리가 반대편으로 갈 수 있는 가장 빠른 시간 리턴
// 개구리가 강 반대편으로 점프할 수 없는 경우 -1 리턴

int solution(int X, vector<int> &A) {
    // set에 들어올 때 마다 넣기
    set<int> s;

    int len = A.size();
    for(int i=0;i<len;i++) {
        s.insert(A[i]);

        // 크기 검사
        if(s.size() >= X)
            return i;
    }

    // 마지막까지 불가능하면, -1 리턴
    return -1;
}

int main(){
    vector<int> test{1,1,1,1,1}; 

    printf("답 : %d\n", solution(5, test));
}