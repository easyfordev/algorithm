#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Point{
public:
	int x,y;
	Point(int x, int y) {
		this->x = x; this->y = y;
	}
};

bool cmp(Point &a, Point &b) {
	// x좌표가 증가하는 순, x좌표가 같으면 y좌표가 증가하는 순
	if(a.x == b.x) {
		return a.y < b.y;
	} else 
		return a.x < b.x;
}

int n;
vector<Point> v;

int main() {
	scanf("%d", &n);
	
	for(int i=0;i<n;i++) {
		int a,b;
		scanf("%d %d", &a, &b);
		v.push_back(Point(a,b));
	}

	sort(v.begin(), v.end(), cmp);

	for(int i=0;i<n;i++) {
		printf("%d %d\n", v[i].x, v[i].y);
	}

}