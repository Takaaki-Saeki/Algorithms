// 二分探索

#include<iostream>

using namespace std;

// カウンタ変数の宣言
int counter = 0;

int n;
int* S = new int[n];
int q;
int* T = new int[q];


void binary_search(int key, int n)
{
	int left = 0;
	int right = n;
	while (left < right) {

		int mid = (left + right) / 2;

		if (S[mid] == key) {
			counter++;
		}

		else if (S[mid] > key) {
			right = mid;
		}

		else {
			left = mid + 1;
		}
	}
}

int main()
{
	cout << "nを入力してください:";
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> S[i];
	}
	cout << "qを入力してください:";
	cin >> q;
	for (int j = 0; j < q; j++) {
		cin >> T[j];
	}

	for (int j = 0; j < q; j++) {
		int key = T[j];
		binary_search(key, n);
	}

	cout << counter;
}
