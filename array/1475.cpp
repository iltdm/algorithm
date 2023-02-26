/*
방 번호(실버 V)

다솜이는 은진이의 옆집에 새로 이사왔다. 다솜이는 자기 방 번호를 예쁜 플라스틱 숫자로 문에 붙이려고 한다.

다솜이의 옆집에서는 플라스틱 숫자를 한 세트로 판다. 한 세트에는 0번부터 9번까지 숫자가 하나씩 들어있다. 

다솜이의 방 번호가 주어졌을 때, 필요한 세트의 개수의 최솟값을 출력하시오. 
(6은 9를 뒤집어서 이용할 수 있고, 9는 6을 뒤집어서 이용할 수 있다.)
*/

#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int set = 1;
	int number;
	int arr[10] = { 0, };

	cin >> number;

	while (number > 0) {
		arr[number % 10]++;
		number /= 10;
	}

	for (int i = 0; i < 10; i++) {
		if (i == 6 || i == 9)
			continue;
		set = max(set, arr[i]);
	}

	// arr[6] + arr[9] = 4일 경우, 5 / 2는 결국 2임
	// (arr[6] + arr[9] + 1) / 2 가 이미 정해진 set보다 적을 경우 영향력이 없으므로 무시하면 되는 것
	set = max(set, (arr[6] + arr[9] + 1) / 2);
	cout << set;

	return 0;
}