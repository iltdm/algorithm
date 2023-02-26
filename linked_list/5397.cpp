/*
키로거(실버 II)
첫째 줄에 테스트 케이스의 개수가 주어진다. 각 테스트 케이스는 한줄로 이루어져 있고, 강산이가 입력한 순서대로 길이가 L인 문자열이 주어진다. 
(1 ≤ L ≤ 1,000,000) 강산이가 백스페이스를 입력했다면, '-'가 주어진다. 이때 커서의 바로 앞에 글자가 존재한다면, 그 글자를 지운다. 화살표의 입력은 '<'와 '>'로 주어진다. 
이때는 커서의 위치를 움직일 수 있다면, 왼쪽 또는 오른쪽으로 1만큼 움직인다. 나머지 문자는 비밀번호의 일부이다. 
물론, 나중에 백스페이스를 통해서 지울 수는 있다. 만약 커서의 위치가 줄의 마지막이 아니라면, 커서 및 커서 오른쪽에 있는 모든 문자는 오른쪽으로 한 칸 이동한다.

각 테스트 케이스에 대해서, 강산이의 비밀번호를 출력한다. 비밀번호의 길이는 항상 0보다 크다.

2
<<BP<A>>Cd-
ThIsIsS3Cr3t

BAPC
ThIsIsS3Cr3t
*/

#include <iostream>
#include <list>
#include <queue>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int L;

	cin >> L;
	while (L--) {
		string s;
		list<char> l = {};
		auto cursor = l.begin();

		cin >> s;
		for (auto c : s) {
			if (c == '<') {
				if (cursor != l.begin()) cursor--;
			}
			else if (c == '>') {
				if (cursor != l.end()) cursor++;
			}
			else if (c == '-') {
				if (cursor != l.begin()) {
					cursor--;
					cursor = l.erase(cursor);
				}
			}
			else
				l.insert(cursor, c);
		}
		for (auto c : l) cout << c;
		cout << '\n';
	}
	
	return 0;
}