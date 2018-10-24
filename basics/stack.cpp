// スタックの実装

#include<iostream>

using namespace std;

int top;
int S[1000];

void push(int x) {
	// topを+1してから、その位置に要素を追加
	S[++top] = x;
}

int pop() {
	// topを-1し、もともとのtopの位置の要素を返す
	top--;
	return S[top + 1];
}

int main() {
	int a, b;
	top = 0;
	char s[100];


	cin >> s;
	while(s[0] != EOF ){
		if (s[0] == '+') {
			a = pop();
			b = pop();
			push(a + b);
		}
		else if (s[0] == '-') {
			a = pop();
			b = pop();
			push(b - a);
		}
		else if (s[0] == '*') {
			a = pop();
			b = pop();
			push(a*b);
		}
		else {
			push(atoi(s));
		}
		cin >> s;
	}
	cout << pop();
}
