#include<bits/stdc++.h>
using namespace std;

void boundaryElements(vector<vector<int>> matrix, int lastColumn, int lastRow);

int main(){
	vector<vector<int>> matrix = {
		 {1, 2, 3, 4},
		 {5, 6, 7, 8},
		 {9, 10, 11, 12}};

	boundaryElements(matrix, 4, 3);
	return 0;
}

void boundaryElements(vector<vector<int>> matrix, int lastColumn, int lastRow){
	int i, firstRow = 0, firstColumn = 0, k = lastColumn, l = lastRow;
	while(lastColumn > k -1 && lastRow > l - 1){
		for (int i = firstColumn; i < lastColumn; i++){
			cout << matrix[firstRow][i] << " ";
		}

		firstRow++;
		for (int i = firstRow; i < lastRow; i++){
			cout << matrix[i][lastColumn - 1] << " ";
		}

		lastColumn--;
		if(firstColumn < lastColumn){
			for (int i = lastColumn - 1; i >= firstColumn; --i){
				cout << matrix[lastRow - 1][i] << " ";
			}

			lastRow--;
		}

		if(firstRow < lastRow){
			for (int i = lastRow - 1; i >= firstRow; --i){
				cout << matrix[i][firstColumn] << " ";
			}

			firstColumn++;
		}
	}
}