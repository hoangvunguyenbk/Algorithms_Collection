#include <iostream>
#include <stdlib.h>
#define INT_MAX 32625

using namespace std;

/*Given two sorted arrays and a number X, find the pair whose sum is closest to X and the pair has an
element from each array 

Ex: Input:  ar1[] = {1, 4, 5, 7};
            ar2[] = {10, 20, 30, 40};
            x = 50      
	Output:  7 and 40 */

std::pair<int, int> closestPair(int v1[], int v2[], int m, int n, int x){
	int i = 0, j = n-1, diff = INT_MAX;
	int res_l, res_r;
	while(i < m && j > 0){
		int sum = v1[i] + v2[j];
		if(abs(sum - x) < diff){ 
			res_l = v1[i];
			res_r = v2[j];
			diff = abs(sum - x);
		}
		if(sum < x){
			i++;
		}
		if(sum > x){
			j--;
		}
	}
	std::pair<int, int> q(res_l, res_r);
	return q;
}	



int main(){

	int v1[4] = {1, 4, 5, 7}; 
    int v2[4] = {10, 20, 30, 40}; 
    std::pair<int, int> res = closestPair(v1, v2, 4, 4, 50);
    cout << "closest pair is: " << res.first << " and " << res.second << endl;
	return 0;
}