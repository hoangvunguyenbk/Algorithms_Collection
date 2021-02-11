#include <iostream>
#include <vector>
#include <chrono>
#include <functional>

using namespace std;

class MeasureExecutionTimeSorting {

private:
	std::chrono::high_resolution_clock::time_point m_begin;
	std::function<void(std::vector<int> &)> m_f1;
	std::function<void(std::vector<int> &, int, int)> m_f2;
	std::string m_caller;

public:

	MeasureExecutionTimeSorting(const std::string &caller, std::function<void(std::vector<int> &)> algo_func, std::vector<int> &data)
	: m_caller(caller), m_f1(algo_func), m_begin(std::chrono::high_resolution_clock::now()) {

		//std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(m_begin);
		m_f1(data);
	}

	MeasureExecutionTimeSorting(const std::string &caller, std::function<void(std::vector<int> &, int, int)> algo_func, std::vector<int> &data, int start, int end)
	: m_caller(caller), m_f2(algo_func), m_begin(std::chrono::high_resolution_clock::now()) {

		m_f2(data, start, end);
	}

	~MeasureExecutionTimeSorting() {
		std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
		auto duration = end - m_begin;
		cout << m_caller << " : " << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << " ms\n";
	}
};

/*********************
	Insertion sort

best-case: O(n)
worse-case: O(n2)
average-case: O(n2)
**********************/

void InsertionSort(std::vector<int> &vec){

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

void QuickSort(std::vector<int> &vec, int start, int end) {

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
	Shell sort

best-case: 
worse-case:
average-case:
**********************/



/*********************
	Selection sort

best-case: 
worse-case:
average-case:
**********************/



/*********************
	Heap sort

best-case: 
worse-case:
average-case:
**********************/

int main(int argc, char** argv) {

	//Large input data, pass to Constructor by value to use for different algo.
	vector<int> data, data1;
	for(unsigned short i = 20000; 0 < i; --i) {
		data.push_back(i);
		data1.push_back(i);
	}

	cout << "Sorting vector integer " << "[" << 20000 << " : " << 1 << "]\n";

	//MeasureExecutionTimeSorting insertion_sort("Insertion sort", InsertionSort, data);
	//MeasureExecutionTimeSorting insertion_sort1("Insertion sort 1", InsertionSort, data);
	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();
	MeasureExecutionTimeSorting quick_sort("Quick sort", QuickSort, data, 0, data.size()-1);
	std::chrono::high_resolution_clock::time_point end = std::chrono::high_resolution_clock::now();
	std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << endl;

	//std::chrono::high_resolution_clock::time_point start1 = std::chrono::high_resolution_clock::now();
	//MeasureExecutionTimeSorting quick_sort1("Quick sort 1", QuickSort, data1, 0, data1.size()-1);
	//std::chrono::high_resolution_clock::time_point end1 = std::chrono::high_resolution_clock::now();
	//std::cout << std::chrono::duration_cast<std::chrono::milliseconds>(end1 - start1).count() << endl;
	//MeasureExecutionTimeSorting quick_sort1("Quick sort 1", QuickSort, data, 0, data.size()-1);

	//MeasureExecutionTimeSorting merge_sort("MergeSort sort", MergeSort, data, 0, data.size()-1);
	//MeasureExecutionTimeSorting merge_sort1("MergeSort sort 1", MergeSort, data, 0, data.size()-1);

	return 0;
}

