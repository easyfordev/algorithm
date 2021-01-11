#include <iostream>
using namespace std;

int main() {
	int arr[9];

	for(int i=1;i<=8;i++) {
		scanf("%d", &arr[i]);
	}

	bool flag = true;
	// ascending 검사
	for(int i=1;i<=8;i++) {
		if(i == arr[i])
			continue;
		else {
			flag = false;
			break;
		}
	}

	if(flag) {
		printf("ascending\n");
		return 0;
	}

	flag = true;
	// descending 검사
	for(int i=1;i<=8;i++) {
		if(i == 9-arr[i])
			continue;
		else {
			flag = false;
			break;
		}
	}

	if(flag) {
		printf("descending\n");
		return 0;
	}

	printf("mixed\n");
}