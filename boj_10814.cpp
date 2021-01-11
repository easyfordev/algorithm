#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Member{
public:
	int age;
	int index;
	string name;

	Member(int age, int index, string name) {
		this->age = age;
		this->index = index;
		this->name = name;
	}

};

bool cmp(Member &a, Member &b) {
	// 나이순, 나이가 같으면 가입한 순
	if(a.age == b.age) {
		return a.index < b.index;
	} else 
		return a.age < b.age; //a < b;
}

int n;
vector<Member> v;

int main() {
	scanf("%d", &n);
	
	int num, order;
	string str;

	for(int i=0;i<n;i++) {
		scanf("%d", &num);
		cin >> str;

		v.push_back(Member(num, i, str));
	}

	sort(v.begin(), v.end(), cmp);

	for(int i=0;i<n;i++) {
		printf("%d ", v[i].age);
		cout << v[i].name << "\n";
	}

}