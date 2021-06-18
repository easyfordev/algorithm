/*
프로그래머스 - 2개 이하로 다른 비트
유형 : 없음. 규칙 찾기
- 비트연산자를 잘 쓸 줄 알면 좋을 것 같다.
// input
// [1001,337,0,1,333,673,343,221,898,997,121,1015,665,779,891,421,222,256,512,128,100]
// output
// [1002, 338, 1, 2, 334, 674, 347, 222, 899, 998, 122, 1019, 666, 781, 893, 422, 223, 257, 513, 129, 101]
*/
#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <algorithm>
using namespace std;

string toBinary(long long n) {
    string r;
    while (n != 0){
        r += ( n % 2 == 0 ? "0" : "1" );
        n /= 2;
    }
    reverse(r.begin(), r.end());

    return r;
}

long long toDecimal(string str) {
    reverse(str.begin(), str.end());

    long long r = 0;
    for(int i=0;i<str.size();i++) {
        long long num = str[i] - '0';
        r +=  pow(2, i) * num;
    }
    return r;
}


vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    // f(x) = x보다 크고 x와 비트가 1~2개 다른 수 중에서 제일 작은 수
    for(int i=0;i<numbers.size();i++) { // 각 수마다 f(x) 구하기
        long long num = numbers[i];
        
        // 짝수면, 그냥 +1 (왜냐하면, 0번째 비트가 0이니까, 1로 바꿔주면 되잖아)
        if(num%2 == 0) {
            answer.push_back(num+1);
        } else { // 홀수면
            // 일단 2진수로 바꿔주기
            string binary = toBinary(num);

            // 1) 모든 비트가 1인 경우 (즉 2^k-1인 경우), 맨 앞자리 1을 10으로 바꾼다
            if(binary.find("0") == string::npos) {
                binary = "10" + binary.substr(1);
            } else { // 2) 그 외의 경우, 가장 낮은 0을 1로 바꾸고, 바로 다음에 있는 비트 1을 0으로 바꾼다
                // 이유 : '가장 작은' 수를 찾아야 하니까, 가장 낮은 0을 바꾸는것이다. 1인 비트를 바꾸는건 좋지 않다. 그리고, 더 작은 수를 만들기 위해 이전에 있는
                int pos = binary.find_last_of('0');
                binary[pos] = '1';
                binary[pos+1] = '0';
            }
            // 정답 넣기
            answer.push_back(toDecimal(binary));
        }
    }

    return answer;
}

int main(){
    vector<long long> input = {1001,337,0,1,333,673,343,221,898,997,121,1015,665,779,891,421,222,256,512,128,100};

    solution(input);
}
