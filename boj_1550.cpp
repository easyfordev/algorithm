/* string의 index와 16진수의 자릿수가 반대라는 것 유의! */
#include <iostream>
#include <cmath>
using namespace std;
string str;

int main(){
	cin >> str;

	int sum = 0;
	int len = (int)str.length();

	for(int i=len-1;i>=0;i--) {
		char ch = str[i];
		int digit = len -1 -i;
		int num;
		if(ch == 'A')	num = 10;
		else if(ch == 'B')	num = 11;
		else if(ch == 'C')	num = 12;
		else if(ch == 'D')	num = 13;
		else if(ch == 'E')	num = 14;
		else if(ch == 'F')	num = 15;
		else	num = ch - '0';

		sum += (num * (int)pow(16, digit) );
	}
	printf("%d\n", sum);
}