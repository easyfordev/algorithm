/* 그냥 vector로 풀었더니 시간초과
정렬이 되어있어야 하고, 양방향으로 모두 삭제할 수 있어야 하고, 중복을 허용해야하므로 multiset을 사용한다.*/
#include <iostream>
#include <set>
using namespace std;

int tc, com;

int main(){
	scanf("%d", &tc);

	while(tc--) {
		scanf("%d", &com);
		multiset<int> s;
		char ch;
		int num;

		for(int k=0;k<com;k++) {
			getchar();
			scanf("%c", &ch);
			scanf("%d", &num);

			if(ch == 'I') {
				s.insert(num);
			} else if(ch == 'D') {
				// 비어있는데 삭제하라고하면 무시
				if(s.empty())
					continue;
				
				if(num == 1) { // 최댓값 삭제
					auto iter = s.end(); // 맨 뒤의 다음을 가리키므로 하나 빼야 함
					iter--;
					s.erase(iter);
				} else if(num == -1) { // 최솟값 삭제
					auto iter = s.begin();
					s.erase(iter);
				}
			}
			
		}
		// 비어있으면 EMPTY 출력
		if(s.empty())
			printf("EMPTY\n");
		else {	// 그렇지 않으면, 최댓값과 최솟값 출력
			auto end = s.end();
			end--;
			printf("%d %d\n", *end, *s.begin());
		}
	
	}
}
