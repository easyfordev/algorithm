/* Programmers - DFS/BFS - 여행경로

*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> solution(vector<vector<string>> tickets) {
    // 알파벳순으로 정렬하고, 백트래킹을 해야 함
    // 티켓을 visit 리스트로 관리해야 한다. 도시는 여러번 나올 수 있기 때문에 애매함.
    // 주어진 항공권은 모두 사용해야 한다. => cnt를 세서 모두 check가 아니면 안되는 케이스로 분류하고 다시 찾음

    vector<string> answer;
    return answer;
}

int main(){
    vector<string> test{"hot", "dot", "dog", "lot", "log", "cog"};

    printf("답 : %d\n", solution("hit","cog", test));
}