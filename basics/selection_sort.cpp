// 選択ソート

#include<iostream>

using namespace std;

int main()
{
	int n;
	int* a_heap;

	cin >> n;

	a_heap = new int[n];

	for (int i = 0; i < n; i++) {
		cin >> a_heap[i];
	}

	int i;
	int count = 0;
	for (i = 0; i < n; i++) {
		int minj = i;
		for (int j = i; j < n; j++) {
			if (a_heap[j] < a_heap[minj]) minj = j;
		}
		int t = a_heap[i];
		a_heap[i] = a_heap[minj];
		a_heap[minj] = t;
		count += 1;
	}
	for (int k = 0; k < n - 1; k++) {
		cout << a_heap[k];
		cout << " ";
	}
	cout << a_heap[n - 1];
	cout << "\n";
	cout << count;
	delete[] a_heap;
}
