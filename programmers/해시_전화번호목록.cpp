/* Programmers - 해시 - 전화번호 목록 
더 나은 풀이 : 정렬해서 앞뒤 서로 비교하는 방법도 있음
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool solution(vector<string> phone_book) {
    // 접두어인 경우가 있으면 false, 그렇지않으면 true
    bool answer = true;

    int len = phone_book.size();
    for(int i=0;i<len;i++) {
        for(int j=0;j<len;j++) {
            if(i==j)    continue;
            string temp = phone_book[j].substr(0, phone_book[i].size());
            // 접두사이면
            if(temp == phone_book[i]) {
                return false;
            }
        }
    }
    return true;
}

int main(){
    string arr[] = {"12","123","1235","567","88"};
    // string arr2[] = {"stanko", "ana", "mislav"};

    vector<string> test;
    for(int i=0;i<5;i++) {
        test.push_back(arr[i]);
    }
    // printf("%s\n",solution(test1, test2));
    cout << solution(test) ;
}