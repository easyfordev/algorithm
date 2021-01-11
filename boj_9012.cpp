#include <iostream>
#include <stack>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	getchar();
	while(T--) {
		string str;
		cin >> str;

		int len = str.length();
		stack<int> s;

		bool flag = true;
		for(int i=0;i<len;i++) {
			if(str[i] == '(') {
				s.push(1);
			}  else if(str[i] == ')') {
				if(s.empty()) { // 스택이 비었는데 갑자기 닫는괄호가 들어온다? 그럼 틀린거지
					flag = false;
					break;
				}
				else	s.pop();
			}
		}

		// 다 끝나고 나서 스택이 비어있는지 확인한다
		if(flag== false)
			printf("NO\n");
		else {
			if(s.empty())	printf("YES\n");
			else	printf("NO\n");
		}
		
	}
}