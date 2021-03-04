/* Programmers - 정렬 - H-Index
처음에 아얘 잘못짚었음 ㅋㅋ 로직 걍 틀림 ..
이렇게 짧고 좋은 풀이들도 있다. 나는 너무 복잡하게 풀었다.
좋은 풀이 1 )
int solution(vector<int> citations) {
    sort(citations.begin(), citations.end(), greater<int>());

    for (int i = 0; i < citations.size(); ++i) {
        if (citations[i] < i + 1) {
            return i;
        }
    }

    return citations.size();
}

좋은 풀이 2)
int solution(vector<int> citations) {
    int answer = 0;

    std::sort(citations.begin(), citations.end());
    for (int i = 0; i < citations.size(); i++) {
        if (citations.size() - i <= citations[i]) {
            answer = citations.size() - i;
            break;
        }
    }

    return answer;
}
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 논문 n편 중 h번 이상 인용된 논문이 h편 이상이고, 
// 나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-index
int solution(vector<int> citations) {
    // 최댓값 구하기
    int answer = 0;
    int len = citations.size();

    int maxV = citations[0];
    for(int i=1;i<len;i++) {
        if(citations[i] > maxV)
            maxV = citations[i];
    }

    // 정렬하기
    sort(citations.begin(), citations.end(), greater<int>());

    for(int item : citations) {
        printf("%d ", item);
    }
    // 0~최댓값까지 루프 돌기
    int h = 0;
    
    for(h=maxV;h>=0;h--) {
        bool flag = false;
        for(int i=0;i<len;i++) {
            if( citations[i] >= h && len - i >= h) {
                flag = true;
                break;
            }
        }

        if(flag == true) {
            answer = h;
            break;
        }
    }

    return answer;
}

int main(){
    // string arr[] = {"classic", "pop", "classic", "classic", "pop"};
    int arr[] = {3, 0, 6, 1, 5};

    vector<int> test{1545, 2, 999, 790, 540, 10, 22};
    // vector<int> test;

    // vector<vector<int>> test2;
    // for(int i=0;i<5;i++) {
    //     test.push_back(arr[i]);
    // }
    printf("%d", solution(test));
}