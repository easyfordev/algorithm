/* Programmers - 해쉬 - 베스트앨범 */
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Song {
public:
    int number, play;
    Song (int number, int play) {
        this->number = number;
        this->play = play;
    }
};

bool cmp1(const pair<string, int> &a, const pair<string, int> &b) { // 총 재생횟수 높은 순으로 정렬
    return a.second > b.second;
}

bool cmp2(const Song &a, const Song &b) { // 장르 내에서 많이 재생된 노래 => 재생횟수 같으면 고유번호 낮은 노래
    if(a.play == b.play) {
        return a.number < b.number;
    } else
        return a.play > b.play;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    // 많이 재생된 장르 고르기
    int len = genres.size();
    map<string, int> m1; // 장르명, 총 재생횟수
    map<string, vector<Song> > m2; // 장르명, 노래(곡번호, play수)

    for(int i=0;i<len;i++) {
        m1[genres[i]] += plays[i];

        if(m2.find(genres[i]) == m2.end()) { // 처음 들어왔으면
            vector<Song> temp;
            temp.push_back(Song(i, plays[i]));

            m2.insert(make_pair(genres[i], temp));
        } else {
            m2[genres[i]].push_back(Song(i, plays[i]));
        }
    }

    // 총 재생횟수로 장르별로 정렬
    vector< pair<string, int> > gens (m1.begin(), m1.end());
    sort(gens.begin(), gens.end(), cmp1);

    // 각 장르마다 노래 순서대로 정렬해서 넣기
    vector<int> answer;

    len = gens.size();
    for(int i=0;i<len;i++) {
        // 장르별로 정렬
        vector<Song> temp = m2[gens[i].first];
        sort(temp.begin(), temp.end(), cmp2);
        
        if(temp.size() == 1) { // 곡이 하나면 하나만 선택
            answer.push_back(temp[0].number);
        } else { // 딱 2개만 꺼내기
            answer.push_back(temp[0].number);
            answer.push_back(temp[1].number);
        }
    }

    return answer;
}

int main(){
    string arr[] = {"classic", "pop", "classic", "classic", "pop"};
    int arr2[] = {500, 600, 150, 800, 2500};

    vector<string> test;
    vector<int> test2;
    for(int i=0;i<5;i++) {
        test.push_back(arr[i]);
        test2.push_back(arr2[i]);
    }
    // printf("%s\n",solution(test1, test2));
    vector<int> ans = solution(test, test2) ;

    for(auto item : ans) {
        printf("%d ", item);
    }
}