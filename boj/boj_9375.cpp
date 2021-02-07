/* 
자료구조 map 쓰는 문제
우왕 어떻게 풀어야할지 감이 잘 안온다 .. ㅎㅎ 차분하게 잘 생각해봐 ~!
*/
#include <iostream>
#include <string>
#include <map> // <key, value> 
using namespace std;
int tc, n;

int main(void) {
    cin >> tc;

    while(tc--) {
        cin >> n;
        
        map<string, int> m; // 의상의 종류, 갯수
        getchar();
        for(int i=0;i<n;i++) {
            string a, b; // 의상의 이름, 종류
            cin >> a >> b; // 종류만 쓴다. 이름은 안중요함

            // map의 find 함수는 있으면 iterator를 return하고 없으면 end()를 return한다
            if(m.find(b) != m.end()) { // 한번이라도 들어왔던 의상 종류면
                m[b]++;
            } else {    // 처음들어오는거면
                m.insert(make_pair(b, 1));
            }
        }

        // 모든 경우의 수 구하기 = (의상의 종류 + 아무것도 안입는 경우) * ... 모두 곱함
        int size = m.size();
        int ans = 1;
        for(auto iter=m.begin() ; iter !=m.end() ; iter++) {
            ans *= (iter->second+1); 
        }
        // for( auto iter : m) { 
        //     ans *= iter.second; // map 순회 이것도 알아두기
        // }

        ans -= 1; // 모든걸 안입는건 안되니까 하나 빼준다

        printf("%d\n", ans);

    }
}