/*
두 수의 합 (실버 III)
n개의 서로 다른 양의 정수 a1, a2, ..., an으로 이루어진 수열이 있다. ai의 값은 1보다 크거나 같고, 
1000000보다 작거나 같은 자연수이다. 자연수 x가 주어졌을 때, ai + aj = x (1 ≤ i < j ≤ n)을 만족하는 (ai, aj)쌍의 수를 구하는 프로그램을 작성하시오.

첫째 줄에 수열의 크기 n이 주어진다. 다음 줄에는 수열에 포함되는 수가 주어진다. 셋째 줄에는 x가 주어진다. (1 ≤ n ≤ 100000, 1 ≤ x ≤ 2000000)

문제의 조건을 만족하는 쌍의 개수를 출력한다.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int arr[2000001] = {0, };

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, num, x, pair = 0;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num;
		v.push_back(num);
		arr[num] = 1;
	}

	cin >> x;
	while (!v.empty()) {
		int temp = v.back();
		v.pop_back();
		if (temp > x)
			continue;

		if (arr[x-temp]!= 0) {
			pair++;
		}
	}
	
	cout << pair/2;

	return 0;
}