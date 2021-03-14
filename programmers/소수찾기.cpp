/* Programmers - 완전탐색 - 소수찾기
헤맨 포인트)
    - string[i]의 타입은 char이다. not string
    - 자릿수가 다 다른 소수를 어떻게 만들지? 어차피 문자열을 하나씩 더해가면서 만드니까 그 하나하나를 검사하면 되는거지
*/
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <set>
using namespace std;

bool isPrime(int num) { // num이 소수인지 아닌지 리턴
    bool ans = true;
    if(num == 1 || num == 0 )    return false;
    for(int i=2;i<=sqrt(num);i++) {
        if(num % i == 0) {
            ans = false;
            break;
        }
    }

    return ans;
}

// 종이 조각으로 만들 수 있는 소수가 몇개인지 리턴
int solution(string numbers) {
    vector<int> num;
    set<int> candidates;
    int len = numbers.size();
    
    for(int i=0;i<len;i++)
        num.push_back(numbers[i]-'0');
    
    sort(num.begin(), num.end());

    do {
        // 문자열 다 붙여서 숫자 만들기
        string temp = "";
        for(int i=0;i<len;i++) {
            temp += to_string(num[i]);
            int a = stoi(temp);
            
            if(isPrime(a)) {
                // printf("> %s \n", temp.c_str());
                candidates.insert(a); // 중복 제거해서 넣기
            }
        }
    } while( next_permutation(num.begin(), num.end()));
    
    // int answer = 0;
    return candidates.size();
}

int main(){
    // string arr[] = {"classic", "pop", "classic", "classic", "pop"};
    // int arr[] = {3, 0, 6, 1, 5};
    // vector<int> test{1, 2, 3, 4, 5};
    string test = "17";
    // vector<int> test;

    // vector<vector<int>> test2;
    // for(int i=0;i<5;i++) {
    //     test.push_back(arr[i]);
    // }
    printf("답 : %d", solution(test));
}