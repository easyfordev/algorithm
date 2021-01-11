#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<string> v;
int n;

bool cmp(string &a, string &b) {
	// 길이가 짧은 것부터
	// 길이가 같으면 사전순으로
	if(a.length() == b.length()) { // 길이가 같으면
		return a < b;
	} else {
		return a.length() < b.length();
	}
}

int main() {
	scanf("%d", &n);getchar();

	for(int i=0;i<n;i++) {
		string str;
		cin >> str;
		
		// 이미 같은 단어가 있으면, 배열에 넣지 않음
		bool flag = true; // 넣어도 되는지 체크
		for(int j=0;j<v.size();j++) {
			if(v[j] == str) {
				flag = false;
				break;
			}
		}

		if(flag)	v.push_back(str);
	}

	sort(v.begin(), v.end(), cmp);

	for(int i=0;i<v.size();i++) {
		cout << v[i] << "\n";
	}

}
