/* Programmers - 정렬 - 가장 큰 수
(처음에 TC 하나 빼고 다 틀렸음) - next_permutation()을 썼는데, 얘가 O(N)이라서 n^2이면 10만*10만 = 100만이라서 시간복잡도 터짐
=> 정렬로 다시 풀어야 함
=> sort()할건데, cmp함수로 우위를 정할 때 a와 b를 string으로 합 해서 결과가 더 큰애를 앞에 둬야 함
(중요) 모두 0인경우 예외처리 - 정렬 후 arr[0]가 0이라는건, 0이 제일 큰수라는 것 -> 0을 그냥 리턴해줘야 함
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string &a, const string &b) {
    return stoi(a + b) > stoi(b + a);
}

// numbers에 담긴 수를 재배치하여 만들 수 있는 가장 큰 수를 문자열로 바꾸어 리턴
string solution(vector<int> numbers) {
    // string으로 치환하기
    vector<string> v;
    for(int i=0;i<numbers.size();i++) {
        v.push_back(to_string(numbers[i]));
    }

    sort(v.begin(), v.end(), cmp);

    // 모두 0인경우 예외처리
    if(v[0] == "0") return "0";

    string answer = "";
    // 숫자 다 이어붙이기
    for(int i=0;i<v.size();i++) {
        answer += v[i];
    }

    return answer;
}

int main(){
    // string arr[] = {"classic", "pop", "classic", "classic", "pop"};
    int arr[] = {0, 5, 10, 15, 20};

    vector<int> test{6,10,2};
    // vector<vector<int>> test2;
    // for(int i=0;i<7;i++) {
    //     test.push_back(arr[i]);
    // }
    cout << solution(test);
}