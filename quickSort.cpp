#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
 
int partition(std::vector<int>& vec, int start, int end){
	int pIndex = start;
	int pivot = vec.at(end);
	for(int i=start; i<end; i++){
		if(vec[i]<=pivot){
			std::swap(vec[i], vec[pIndex]);
			pIndex++;
		}
	}
	std::swap(vec[pIndex], vec.at(end));
	return pIndex;
}

void quickSort(std::vector<int>& vec, int start, int end){
	if(start<end){
                 int pIndex = partition(vec, start, end); // find pIndex, devide array into 2 sub-arrays
                  quickSort(vec, start, pIndex-1); // recursive for left part
                  quickSort(vec, pIndex+1, end); // right part
          }
}

void printVec(std::vector<int> vec){
	for(int i=0; i< vec.size(); i++){
		cout << vec[i] << '\t';
	}
	cout << endl;
}

int main(){
	std::vector<int> myVec({9,8,7,6,5,4,3,2,1,0});
	quickSort(myVec, 0, myVec.size()-1);
	printVec(myVec);
	myVec.clear();
	return 0;
}
