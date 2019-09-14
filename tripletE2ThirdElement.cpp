#include <iostream>
#include <vector>
#include <algorithm>
//Note: complie with C++ 11 standard
using namespace std;

/*Given an array of integers you have to find three numbers such that sum of two elements equals the third element
Input  : {5, 32, 1, 7, 10, 50, 19, 21, 2}
Output : 21, 2, 19 */


void findTriplet(std::vector<int> v){
	std::sort(v.begin(), v.end());
	//iterate from greatest element of three from back
	bool isExist = false; //flag to check whether triplet exist in vector
	for(int i=v.size()-1; 0<=i; i--){
		int j = 0, k = i-1;
		while( j<k ){
			int  sum = v[j] + v[k];
			if( sum == v[i]){
				cout << "Triplet: " << v[j] << v[k] << v[i] << endl;
				isExist = true; 
				break;
			}else if( sum < v[i] ){
				j++;
			}else{
				k--;
			}
		}
	}
	if( !isExist ) cout << "Not found" << endl; 
}

int main(){

	std::vector<int> v{5, 32, 1, 7, 10, 50, 19, 21, 2};
	findTriplet(v);
	return 0;
}