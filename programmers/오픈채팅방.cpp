/*
프로그래머스 - 오픈채팅방
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

vector<string> solution(vector<string> record) {
    map<string, string> nicknames; // 유저아이디, 닉네임

    int rlen = record.size();

    for(int i=0;i<rlen;i++) {
        // record 하나씩 split()
        string str=record[i];
        istringstream ss(str);
        string stringBuffer;

        vector<string> x;
        while (getline(ss, stringBuffer, ' ')){
            x.push_back(stringBuffer);
        }

        // x[0]에 따라 닉네임 결정
        // 1) Enter
        if(x[0] == "Enter") {
            if(nicknames.find(x[1]) == nicknames.end()) // 없으면
                nicknames.insert(make_pair(x[1], x[2]));
            else // 이미 있으면, 닉네임 변경해서 들어온거다
                nicknames[x[1]] = x[2];
        }
        // 2) Leave -> 변경에 영향을 주지 않음
        // 3) Change
        else if(x[0] == "Change") {
            nicknames[x[1]] = x[2]; // 그냥 변경
        }
    }

    // 최종적으로 결정된 닉네임에 따라 record -> result로 변환
    vector<string> answer;
    for(int i=0;i<rlen;i++) {
        // record 하나씩 split()
        string str=record[i];
        istringstream ss(str);
        string stringBuffer;

        vector<string> x;
        while (getline(ss, stringBuffer, ' ')){
            x.push_back(stringBuffer);
        }

        // x[0]에 따라 result 결정
        // 1) Enter
        if(x[0] == "Enter") {
            answer.push_back(nicknames[x[1]] + "님이 들어왔습니다.");
        }
        // 2) Leave 
        else if(x[0] == "Leave") {
            answer.push_back(nicknames[x[1]] + "님이 나갔습니다.");
        }
        // 3) Change -> 출력 안함
    }

    return answer;
}

int main(){
    vector<string> record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    solution(record);
}