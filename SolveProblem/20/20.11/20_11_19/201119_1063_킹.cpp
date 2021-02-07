#include<iostream>
#include<string>
using namespace std;

int king_x, king_y;
int rock_x, rock_y;

bool same() {
	return (king_x == rock_x) && (king_y == rock_y);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string a, b;
	int T;
	cin >> a >> b >> T;
	
	king_y = a[0] - 'A';
	king_x = a[1] - '1';
	rock_y = b[0] - 'A';
	rock_x = b[1] - '1';
	while (T--) {
		string op;
		cin >> op;
		if (op == "R") {
			if (king_y < 7) {
				king_y++;
				if (same()) {
					if (rock_y < 7) rock_y++;
					else king_y--;
				}
			}
		}
		else if (op == "L") {
			if (king_y > 0) {
				king_y--;
				if (same()) {
					if (rock_y > 0) rock_y--;
					else king_y++;
				}
			}
		}
		else if (op == "T") {
			if (king_x < 7) {
				king_x++;
				if (same()) {
					if (rock_x < 7) rock_x++;
					else king_x--;
				}
			}
		}
		else if (op == "B") {
			if (king_x > 0) {
				king_x--;
				if (same()) {
					if (rock_x > 0) rock_x--;
					else king_x++;
				}
			}
		}
		else if (op == "RB") {
			if (king_y < 7 && king_x > 0) {
				king_y++;
				king_x--;
				if (same()) {
					if (rock_y < 7 && rock_x >0) {
						rock_y++;
						rock_x--;
					}
					else {
						king_y--;
						king_x++;
					}
				}
			}
		}
		else if (op == "LB") {
			if (king_y > 0 && king_x > 0) {
				king_y--;
				king_x--;
				if (same()) {
					if (rock_y > 0 && rock_x > 0) {
						rock_y--;
						rock_x--;
					}
					else {
						king_y++;
						king_x++;
					}
				}
			}
		}
		else if (op == "RT") {
			if (king_y < 7 && king_x < 7) {
				king_y++;
				king_x++;
				if (same()) {
					if (rock_y < 7 && rock_x < 7) {
						rock_y++;
						rock_x++;
					}
					else {
						king_y--;
						king_x--;
					}
				}
			}
		}
		else if (op == "LT") {
			if (king_y > 0 && king_x < 7) {
				king_y--;
				king_x++;
				if (same()) {
					if (rock_y > 0 && rock_x < 7) {
						rock_y--;
						rock_x++;
					}
					else {
						king_y++;
						king_x--;
					}
				}
			}
		}
	}
	cout << char(king_y + 'A') << king_x + 1 << "\n" << char(rock_y + 'A') << rock_x + 1;
	return 0;
}