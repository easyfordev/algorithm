#include <iostream>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
char str[51];

class book {
public:
    string name;
    int cnt;

    book(string s, int n) {
        this->name = s;
        this->cnt = n;
    }
};

bool cmp(const book &a, const book &b) {
    // cnt가 클수록 앞 => 사전순으로 앞서는 제목
    if(a.cnt == b.cnt) {
        return a.name < b.name;
    } else 
        return a.cnt > b.cnt ;
}

int main(){
    // 가장 많이 팔린 책의 제목 출력
    int n;
    scanf("%d", &n);
    getchar();
    map<string, int> m;
    for(int i=0;i<n;i++) {
        scanf("%s",str);
        string name = str;

        // 아직 없으면 
        if(m.find(name) == m.end()) {
            m.insert(make_pair(name, 0));
        } else {
            m[name]++;
        }
    }

    // 정렬하기위해 벡터로 치환
    vector<book> v;
    for(auto iter = m.begin(); iter != m.end() ; iter++) {
        v.push_back(book(iter->first, iter->second));
    }

    sort(v.begin(), v.end(), cmp);

    printf("%s\n", v[0].name.c_str());

}

