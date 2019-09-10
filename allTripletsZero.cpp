#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/* Given an array of distinct elements. Find triplets in array whose sum is zero *
Input : arr[] = {0, -1, 2, -3, 1}
Output: 0 -1 1 
		2 -3 1 

Input : arr[] = {1, -2, 1, , 5}
Output: 1 -2 1 */

void triplets(std::vector<int> v){
	//sort array 
	std::sort(v.begin(), v.end());
	//loop through index 0 to index n-2
	for(int i=0; i<v.size()-2; i++){
		//init 2 pointers to begin and end of list
		int l = i+1, r = v.size()-1;
		while(l<r){
			int sum = v[i] + v[l] + v[r];
			if( sum == 0){
				cout << "triplet: " << v[i] << "\t" << v[l] << "\t" << v[r] << endl;
				break;
			}else if( sum < 0 ){
				l++;
			}else{
				r--;
			}
		} 
	}
}


int main(){

	std::vector<int> v{0, -1, 2, -3, 1};
	std::vector<int> v1{1, -2, 1, 0, 5};
	triplets(v1);
	return 0;
}