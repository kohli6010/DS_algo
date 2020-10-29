#include<bits/stdc++.h>
using namespace std;

int circularArrayMaxSum(int arr[], int n){
	int index = 0;
	int largest = INT_MIN;
	for (int i = 0; i < n; i++){
		if(arr[i] > largest){
			largest = arr[i];
			index = i;
		}
	}
	int sum = 0, max = 0;
	for (int i = index; i >= 0; i--){
		sum += arr[i];
		if(sum > max){
			max = sum;
		}
	}

	for (int i = n-1; i > index; i--){
		sum += arr[i];
		if(sum > max){
			max = sum;
		}
	}

	return max;
}

int main(){
	int arr[] = {-1, 40, -14, 7, 6, 5, -4, -1};
	int size = sizeof(arr) / sizeof(arr[0]);
	int num = circularArrayMaxSum(arr, size);
	cout << num;
	return 0;
}