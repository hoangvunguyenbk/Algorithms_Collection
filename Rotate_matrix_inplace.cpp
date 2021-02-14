#include <iostream>
#include <vector>

using namespace std;

typedef std::vector<std::vector<int>> matrix;

/* ----Rotate matrix in place algorithm -------
Idea: 
1. Notice that the each element of matrix will be 
return to it originel position after rotate 360 degrees
a[row][col]--90--a[row1][col1]--180--a[row2][col2]--270--a[row3][col3]--360--a[row][col]

So determind where the element of matrix will be placed 
when matrix rotates 90 degree, for example:
original position: a[row][col] -- a[row1][col1] -- a[row2][col2] -- a[row3][col3]
new position:      a[row3][col3] -- a[row][col] -- a[row1][col1] -- a[row2][col2]
-> can use 3 swap statement to achieve and only iterate through 1/4 of the matrix.
----------------------------------------------*/

matrix Rotate_90_clockwise(matrix& a){

	int n = a.size();
	for(int i=0; i<n; i++){
		for(int j=i; j<n-1-i; j++){
			std::swap(a[i][j], a[j][n-1-i]);
			std::swap(a[i][j], a[n-1-i][n-1-j]);
			std::swap(a[i][j], a[n-1-j][i]);
		}
	}
	return a;
}

void PrintMatrix(const matrix a){

	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a[0].size(); j++){
			std::cout << a[i][j] << " ";
		}
		std::cout << endl;
	}
	cout << "-------------------------" << endl;
}


int main(){

    std::vector<int> v(5,0);
	matrix a(5, v);
	int count=0;

	for(int i=0; i<a.size(); i++){
		for(int j=0; j<a[0].size(); j++){
			a[i][j] = count++;
		}
	}

	cout << "--------Original----------" << endl;
	PrintMatrix(a);
	Rotate_90_clockwise(a);

	cout << "---------Rotated---------" <<endl;
	PrintMatrix(a);
	return 0;
}
