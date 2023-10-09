#include <iostream>
#include <ctime>

using namespace std;

int **createMatrix(int n, int m);
void inputMatrix(int **rows, int n, int m);
void outputMatrix(int **rows, int n, int m);
nullptr_t destroyMatrix(int **rows, int n);

int main() {
	srand(time(NULL));

	int n, m;

	cout << "Input row size:" << endl;
	cin >> n;
	cout << "Input col size:" << endl;
	cin >> m;

	int **rows = createMatrix(n, m);
	inputMatrix(rows, n, m);
	outputMatrix(rows, n, m);
	rows = destroyMatrix(rows, n);
}

int **createMatrix(int n, int m) {
	int **rows = new int *[n];
	for (int i = 0; i < n; i++) {
		rows[i] = new int[m];
	}

	return rows;
}

void inputMatrix(int **rows, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			rows[i][j] = rand() % 90;
		}
	}
}

void outputMatrix(int **rows, int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << rows[i][j] << "\t";
		}
		cout << endl;
	}
}

nullptr_t destroyMatrix(int **rows, int n) {
	for (int i = 0; i < n; i++) {
		delete[] rows[i];
	}

	delete[] rows;

	return nullptr;
}