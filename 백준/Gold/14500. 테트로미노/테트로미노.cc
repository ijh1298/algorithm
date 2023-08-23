#include <iostream>

using namespace std;

int findMax(int** map, int row, int col) {
	int i, j, x, y;
	int cur = 0;
	int max = 0;
	for (i = 0; i < row; i++) //1 - 1
		for (j = 0; j < col; j++) {
			if (i - 1 >= 0 && i + 1 < row && j + 1 < col)
				cur = map[i][j] + map[i + 1][j] + map[i - 1][j + 1] + map[i][j + 1];
			if (cur > max)
				max = cur;
		}

	for (i = 0; i < row; i++) // 1 - 2
		for (j = 0; j < col; j++) {
			if (i + 1 < row && j + 1 < col)
				cur = map[i][j] + map[i + 1][j] + map[i][j + 1] + map[i + 1][j + 1];
			if (cur > max)
				max = cur;
		}

	for (i = 0; i < row; i++) // 1 - 3
		for (j = 0; j < col; j++) {
			if (i + 2 < row && j + 1 < col)
				cur = map[i][j] + map[i + 1][j] + map[i + 1][j + 1] + map[i + 2][j + 1];
			if (cur > max)
				max = cur;
		}

	for (i = 0; i < row; i++) // 1 - 4
		for (j = 0; j < col; j++) {
			if (i + 1 < row && j - 1 >= 0 && j + 1 < col)
				cur = map[i][j] + map[i][j + 1] + map[i + 1][j - 1] + map[i + 1][j];
			if (cur > max)
				max = cur;
		}

	for (i = 0; i < row; i++) // 1 - 6
		for (j = 0; j < col; j++) {
			if (i + 1 < row && j + 2 < col)
				cur = map[i][j] + map[i][j + 1] + map[i + 1][j + 1] + map[i + 1][j + 2];
			if (cur > max)
				max = cur;
		}

	for (i = 0; i < row; i++) // 2 - 1 ~
		for (j = 0; j < col; j++) {
			if (i + 2 < row && j + 1 < col)
				cur = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j + 1];
			if (cur > max)
				max = cur;
		}

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			if (i + 2 < row && j + 1 < col)
				cur = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j + 1];
			if (cur > max)
				max = cur;
		}

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			if (i + 2 < row && j + 1 < col)
				cur = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j + 1];
			if (cur > max)
				max = cur;
		}

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			if (i + 2 < row && j - 1 >= 0)
				cur = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i][j - 1];
			if (cur > max)
				max = cur;
		}

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			if (i + 2 < row && j - 1 >= 0)
				cur = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 1][j - 1];
			if (cur > max)
				max = cur;
		}

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			if (i + 2 < row && j - 1 >= 0)
				cur = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 2][j - 1];
			if (cur > max)
				max = cur;
		}

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			if (i + 3 < row)
				cur = map[i][j] + map[i + 1][j] + map[i + 2][j] + map[i + 3][j];
			if (cur > max)
				max = cur;
		}

	for (i = 0; i < row; i++) // 2 - 2 ~
		for (j = 0; j < col; j++) {
			if (j + 2 < col && i - 1 >= 0)
				cur = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j];
			if (cur > max)
				max = cur;
		}

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			if (j + 2 < col && i - 1 >= 0)
				cur = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 1];
			if (cur > max)
				max = cur;
		}

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			if (j + 2 < col && i - 1 >= 0)
				cur = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i - 1][j + 2];
			if (cur > max)
				max = cur;
		}
			
	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			if (j + 2 < col && i + 1 < row)
				cur = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j];
			if (cur > max)
				max = cur;
		}

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			if (j + 2 < col && i + 1 < row)
				cur = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 1];
			if (cur > max)
				max = cur;
		}

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			if (j + 2 < col && i + 1 < row)
				cur = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i + 1][j + 2];
			if (cur > max)
				max = cur;
		}

	for (i = 0; i < row; i++)
		for (j = 0; j < col; j++) {
			if (j + 3 < col)
				cur = map[i][j] + map[i][j + 1] + map[i][j + 2] + map[i][j + 3];
			if (cur > max)
				max = cur;
		}

	return max;
}

int main() {
	int row, col;
	cin >> row >> col;

	int** map = new int* [row];
	for (int i = 0; i < row; i++)
		map[i] = new int[col];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> map[i][j];

	cout << findMax(map, row, col) << endl;

	for (int i = 0; i < row; i++)
		delete map[i];
	delete map;

	return 0;
}