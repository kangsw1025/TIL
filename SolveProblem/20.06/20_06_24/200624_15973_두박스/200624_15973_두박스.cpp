#include<iostream>
#include<algorithm>
using namespace std;

struct rec {
	long long x1, y1;
	long long x2, y2;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	rec r1, r2;

	cin >> r1.x1 >> r1.y1 >> r1.x2 >> r1.y2;
	cin >> r2.x1 >> r2.y1 >> r2.x2 >> r2.y2;

	if (r1.x1 == r2.x2 || r1.x2 == r2.x1)
	{
		if (r1.y1 == r2.y2 || r1.y2 == r2.y1)
			printf("POINT");
		else if ((r1.y2 - r1.y1) + (r2.y2 - r2.y1) > max(r2.y2 - r1.y1, r1.y2 - r2.y1))
			printf("LINE");
		else
			printf("NULL");
	}
	else if ((r1.x2 - r1.x1) + (r2.x2 - r2.x1) > max(r2.x2 - r1.x1, r1.x2 - r2.x1))
	{
		if (r1.y1 == r2.y2 || r1.y2 == r2.y1)
			printf("LINE");
		else if ((r1.y2 - r1.y1) + (r2.y2 - r2.y1) > max(r2.y2 - r1.y1, r1.y2 - r2.y1))
			printf("FACE");
		else
			printf("NULL");
	}
	else
		printf("NULL");

	return 0;
}