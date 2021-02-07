/* 자료구조 map(Key, value) */
#include <iostream>
#include <map>
using namespace std; 
int n, m; // 저장된 사이트 수, 비번 찾으려는 사이트 수

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    // 메모장에서 비밀번호 찾아주기
    cin >> n >> m;

    // 사이트 주소, 비밀번호
    map<string, string> map;

    for(int i=0;i<n;i++) {
        string site, pw;
        cin >> site >> pw;

        map.insert(make_pair(site, pw));
    }

    // 비밀번호 찾으려는 사이트
    for(int i=0;i<m;i++) {
        string site;
        cin >> site;

        auto iter = map.find(site);
        cout << iter->second << "\n";
    }

}