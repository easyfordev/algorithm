/*
프로그래머스. 파일명 정렬
- 정렬, 문자열
- 그냥 문제 그대로 구현하면 된다
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

class File {
public:
    string name;
    string head;
    int number;
    int index;

    File(string name, string h, int n, int i) {
        this->name = name;
        this->head = h;
        this->number = n;
        this->index = i;
    }
};

bool cmp(const File &a, const File &b) {
    // HEAD 기준 정렬(대소문자 구분  X) -> 같을 경우 NUMBER의 숫자 순으로 정렬(숫자 앞의 0무시) ->  둘 다 같으면 원래 입력에 주어진 순서 유지(stable하게. index 관리)
    if (a.head == b.head) {
        if (a.number == b.number) {
            return a.index < b.index;
        } else 
            return a.number < b.number;
    } else 
        return a.head < b.head; // 사전순으로 더 앞선 글자
}

vector<string> solution(vector<string> files) {
    // 구조체 만들어서 넣기
    vector<File> list;

    for (int i = 0; i < files.size(); i++) {
        string str = files[i];
        int len = str.length();
        int numberStart = -1, numberEnd = -1;

        for(int j=0;j<len;j++) {
            // 처음으로 숫자를 만났으면,
            if(isdigit(str[j]) != 0 && numberStart == -1) {
                numberStart = j;
                continue;
            }

            // 숫자의 끝을 만났으면,
            if(isdigit(str[j]) == 0 && j > numberStart && numberStart != -1) {
                // cout << numberStart <<
                numberEnd = j;
                break;
            }
        }
        // HEAD - 대소문자 구분 X
        string head = str.substr(0, numberStart);
        transform(head.begin(), head.end(), head.begin(), ::tolower);
        // NUMBER - (숫자 앞의 0무시)
        string number = str.substr(numberStart, numberEnd - numberStart);
        // 안정정렬 - index 넣어줘야 함
        list.push_back(File(str, head, stoi(number), i));
    }

    // 정렬
    sort(list.begin(), list.end(), cmp);

    // 정렬 결과 정답에 넣기
    vector<string> answer;
    for(int i=0;i<list.size();i++) {
        // cout << list[i].name << "\n";
        answer.push_back(list[i].name);
    }
    return answer;
}

int main(){
    vector<string> input = {"img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG"};
    solution(input);
}