#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*Given an array and a value, find if there is a triplet in array whose sum is equal to given value.
If there is such a triplet present in array, then print the triplet. else print not found 
Ex:
Input : arr = {12,3,4,1,6,9}, x = 24
Output: {12, 3, 9} return true */


void find3Number(std::vector<int> v, int x){
	std::sort(v.begin(), v.end());
	bool exist = false; // flag to check array contain triplet
	for(int i=0; i<v.size()-2; i++){
		int res_l = i+1, res_r = v.size()-1;
		while(res_l < res_r){
			int sum = v[i] + v[res_l] + v[res_r]; 
			if(sum == x){
				cout << "triplet: " << v[i] << v[res_l] << v[res_r] << endl;
				exist = true;
				break;
			}
			else if(sum < x){
				res_l++;
			}else{
				res_r--;
			}
		}
	}
	if(!exist) cout << "not found" << endl;  
}

int main(){

	std::vector<int> v{12, 3, 4, 1, 6, 9};
	std::vector<int> v1{12, 1, 3, 6, 7, 10};
	find3Number(v0, 24); // 3 9 12
	find3Number(v1, 24); // not found

	return 0;
}