/* Programmers - 크레인 인형뽑기 게임 (스택)
악 처음에 2차원 배열 i, j 반대로 생각해서 다 틀렸다 ㅎㅎ
*/
#include <iostream>
#include <string>
#include <vector>

#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int len = moves.size();

    stack<int> s;
    s.push(0); // 일단 바닥에 하나 넣기

    for(int i=0;i<moves.size();i++) {
        int num = moves[i]-1;

        // 가장 위에있는(0이 아닌) 부분 찾기
        int index = -1;
        // for(int j = board.size() -1; j >= 0 ; j--) {
        for(int j = 0 ; j < board[num].size() ; j++) {
            if(board[j][num] != 0) {
                index = j;
                break;
            }
        }
        
        // 인형이 하나도 없으면, 아무것도 안함
        if(index == -1) continue;

        // 꺼내기
        int target =  board[index][num];
        board[index][num] = 0;

        // printf("Target : %d\n", target);

        // 바구니 맨 위랑 같은지 비교
        // printf("스택의 top : %d\n", s.top());
        if(target == s.top()) { // 같으면
            answer += 2;
            s.pop();
        } else { //다르면 그냥 넣음
            s.push(target);
        }
    }

    return answer;
}

int main(){
    vector<vector<int> > test{{0,0,0,0,0}, {0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
    vector<int> test2{1,5,3,5,1,2,1,4};
    printf("답 : %d\n", solution(test, test2));
}

