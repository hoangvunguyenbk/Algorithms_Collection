#include <iostream>

using namespace std;

/* Given a sorted array having N integers, find if there exists any pair of elements
such that their sum is equal to X */


std::string isPairSum(int *arr, int N, int sum){
	int i = 0, j = N - 1;
	while(i<j){
		int temp = arr[i] + arr[j];
		if( temp == sum ) return "Yes";
		if( temp < sum ) i++; // increase pointer i if temp smaller than sum
		else j--; // otherwise decrease j
	}
	return "No";
}

int main(){

	//test function isPairSum
	int arr[5] = {1, 2, 3, 5, 4};
	cout << "is array contain pair equal to 10 : " << isPairSum(arr, sizeof(arr)/sizeof(arr[0]), 10) << endl;
	cout << "is array contain pair equal to 5 : " << isPairSum(arr, sizeof(arr)/sizeof(arr[0]) , 5) << endl;
	return 0;
}