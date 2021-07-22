/*
BOJ 17609. 회문
- N 제한이 10만(0이 5개)
    - 1초는 1억번(0이 8개) ! 잊지 말자.
        O(N)이면 10만  => 가능
        O(N^2)이면 10만 * 10만 => 0이 10개 => 불가능
    - O(N) ~ O(NlogN) 정도로 풀어야 한다.
- (시도 1) 일단 그냥 O(N^2)으로 짜본다..
    - 역시나 시간초과 ㅎㅎ
- (시도 2) vector를 써서 한글자 뺀 문자열을 구하는 for문을 따로 빼서 N^2으로 만들었다.
    - 메모리 초과..
- (시도 3) 접근 자체를 투포인터로 해야 한다.
- 참고한 블로그 : 
https://velog.io/@jsj3282/%EB%B0%B1%EC%A4%80-17609%EB%B2%88-%ED%9A%8C%EB%AC%B8-%ED%8C%8C%EC%9D%B4%EC%8D%AC

*/
#include <iostream>
#include <string>
using namespace std;

bool isPalindrom(int left, int right, string s) {
    // 지금 들어온 애가 회문인지 검사
    while(left < right) {
        if(s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    // 끝까지 안걸렸으면 회문
    return true;
} 

int isPseudoPalindrom(int left, int right, string s) {
    // 계속 돌면서 회문인지 검사.
    while(left < right) {
        if(s[left] == s[right]) { // 같으면 그냥 포인터 움직이기
            left++;
            right--;
        } else { // 다른게 하나라도 나오면, 유사 회문인지 검사
            // 현재 left를 삭제하거나, 현재 right를 삭제한 애가 회문인지를 검사한다.
            bool result1 = isPalindrom(left+1, right, s);
            bool result2 = isPalindrom(left, right-1, s);
            // 삭제해서 회문이 된다면, 유사회문임
            if(result1 || result2) {
                return 1;
            } else { // 둘다 아니면 2 리턴
                return 2;
            }
        }
    }

    return 0; // 지금까지 한 번도 안걸렸으면 그냥 회문
}

int main(){
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        printf("%d\n", isPseudoPalindrom(0, s.size()-1, s));
    }
}