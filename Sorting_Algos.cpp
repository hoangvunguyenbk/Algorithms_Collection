#include <iostream>
#include <vector>
#include <chrono>
#include <thread>

#define START_TIMER(start) std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now(); 

#define END_TIMER(duration, start) auto duration = std::chrono::high_resolution_clock::now() - start; \
							std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << endl;

using namespace std;

/*********************
	Insertion sort

best-case: O(n)
worse-case: O(n2)
average-case: O(n2)
**********************/

void InsertionSort(std::vector<int> vec){

	for(int i=1; i<vec.size(); ++i){
		int hole = i;
		int value = vec[i];

		while(hole>0 && vec[hole-1]>value){
			vec[hole]=vec[hole-1]; // insert vec[hole-1] at index hole
			hole--; //decrease hole value
		}
		vec[hole]=value; //insert value after fulfill
	}
}

/********************
	Quick sort

best-case: O(n*log n)
worse-case: O(n2)
average-case: O(n*log n)
*********************/

int Partition(std::vector<int> &vec, int start, int end) {

	int pIndex = start;
	int pivot = vec.at(end);

	for(int i=start; i<end; ++i){
		//move the element smaller than pivot to the left
		if(vec[i]<=pivot){
			std::swap(vec[i], vec[pIndex]);
			pIndex++;
		}
	}

	//finally, swap pivot with pIndex
	std::swap(vec[pIndex], vec.at(end));
	return pIndex;
}

void QuickSort(std::vector<int> vec, int start, int end) {

	if(start<end){

        int pIndex = Partition(vec, start, end); // find pIndex, divide array into 2 sub-arrays
        QuickSort(vec, start, pIndex-1); // recursive for left part
        QuickSort(vec, pIndex+1, end); // recursive for left part
    }
}

/*********************
	Merge sort

best-case: O(n*log n)
worse-case: O(n*log n)
average-case: O(n*log n)
**********************/
void Merge(std::vector<int> &vec, int start, int end, int mid) {

	int n1 = mid - start + 1;
	int n2 = end - mid;

	//create temp array
	int L[n1], R[n2];

	//copy data to temp arrays
	for(int i = 0; i < n1; i++) {
		L[i] = vec[start+i];
	}
	for(int j = 0; j < n1; j++) {

		R[j] = vec[mid+1+j];
	}

	//merge temp arrays back to original array
	int i=0, j=0, k = start;

	while(i < n1 && j < n2) {
		if(L[i] <= R[j]) {
			vec[k] = L[i];
			i++;
		}else {
			vec[k] = R[j];
			j++;
		}
		k++;
	}

	//copy remaining item
	while(i < n1) {
		vec[k] = L[i];
		i++;
		k++;
	}

	while(j < n2) {
		vec[k] = R[j];
		j++;
		k++;
	}	
}

void MergeSort(std::vector<int> vec, int start, int end) {

	int mid; 
	if(start < end) {
		//pivot element is in the middle
		mid = (start + end - 1)/2;

		//merge sort left part
		MergeSort(vec, start, mid);
		//merge sort right part
		MergeSort(vec, mid+1, end);

		//merge 2 parts
		Merge(vec, start, end, mid);
	}
}


/*********************
	Selection sort

best-case: O(n2)
worse-case: O(n2)
average-case: O(n2)
**********************/
void SelectionSort(std::vector<int> vec)  
{  
    int i, j, min_idx;
    int n = vec.size();  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (vec[j] < vec[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        std::swap(vec[min_idx], vec[i]);  
    }  
}


int main(int argc, char** argv) {

	//Large input data, pass to Constructor by value to use for different algo.
	vector<int> data;
	for(unsigned short i = 20000; 0 < i; --i) {
		data.push_back(i);
	}

	cout << "Sorting vector integer " << "[" << 20000 << " : " << 1 << "]\n";

	START_TIMER(timer1)
	InsertionSort(data);
	cout << "InsertionSort: ";
	END_TIMER(duration1, timer1)

	START_TIMER(timer2)
	QuickSort(data, 0, data.size()-1);
	cout << "QuickSort: ";
	END_TIMER(duration2, timer2)

	START_TIMER(timer3)
	MergeSort(data, 0, data.size()-1);
	cout << "MergeSort: ";
	END_TIMER(duration3, timer3)

	START_TIMER(timer4)
	SelectionSort(data);
	cout << "SelectionSort: ";
	END_TIMER(duration4, timer4)

	return 0;
}

