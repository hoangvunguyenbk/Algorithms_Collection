/*-------------------------
 * File name: hashTable.cpp
 * Author : Vu Nguen
 * Date: 07/07/2018
 * -----------------------*/
#include <iostream>
#include <bits/stdc++.h>

#define HASH_ARRAY_SIZE 20

using namespace std;

template<typename Key, typename Value>
//Hashnode class
class HashNode{

	public:
		HashNode(Key key, Value value){
			this->m_key = key;
			this->m_value = value;
		}
		virtual ~HashNode(){};
		Key getKey(){
			return this->m_key;
		}
		Value getValue(){
			return this->m_value;
		}
	private:
		Key m_key;
		Value m_value;	
};

template<typename Key, typename Value>
class HashMap{

	public:
		//Constructor
		HashMap();
		virtual ~HashMap(){};
		void display();
		void insertNode(Key key, Value value);
		void removeNode(Key key);
		int hashCode(Key key);
		Value searchValue(Key key);

		//Hash element array
		HashNode<Key, Value>** arr;
		HashNode<Key, Value>* dummy;
		int capacity;
		int currentSize;
};

template<typename Key, typename Value>
HashMap<Key, Value>::HashMap() {

	//Init capacity of hash array
	capacity = HASH_ARRAY_SIZE;
	currentSize = 0;
	arr = new HashNode<Key,Value>*[capacity];
	//Init all elements of arrays as NULL
	for(int i=0;i<capacity; i++){
		arr[i] = NULL;
	}
	//Create dummy node
		dummy = new HashNode<Key,Value>(-1,-1);
}

//hash function
template<typename Key, typename Value>
int HashMap<Key, Value>::hashCode(Key key){

	return key%capacity;
}

//Insert hash node
template<typename Key, typename Value>
void HashMap<Key, Value>::insertNode(Key key, Value value){

		HashNode<Key, Value>* temp = new HashNode<Key, Value>(key, value);
		//Calculate hash index
		int hashIndex = HashMap::hashCode(key);

		//find next free space
		while(arr[hashIndex]!=NULL && arr[hashIndex]->getKey()!=key && arr[hashIndex]->getKey() != -1){
			hashIndex++;
			hashIndex %= capacity;
		}

		//if new node to be inserted, increase the current size
		if(arr[hashIndex]==NULL || arr[hashIndex]->getKey() == -1){
			currentSize++;
			arr[hashIndex] = temp;
			cout << hashIndex;
		}
		
		//insert new Node
		//arr[hashIndex] = temp;
		//std::cout<<hashIndex;
}

template<typename Key, typename Value>
void HashMap<Key, Value>::removeNode(Key key){

	//Calculate hash index
	int hashIndex = HashMap::hashCode(key);

	//find appropriate Node
	while(arr[hashIndex]!=NULL){
		if(arr[hashIndex]->getKey() == key){
			//Insert a dummy Node
			arr[hashIndex] = dummy;
			//reduce sie
			currentSize--;
		}
		// if not found, increase hash Index
		hashIndex++;
		hashIndex%capacity;		
	}
}

template<typename Key, typename Value>
Value HashMap<Key, Value>::searchValue(Key key){

	//Calculate hash index
	int hashIndex = HashMap::hashCode(key);
	//find node with given key
	while(arr[hashIndex]!=NULL){
		if(arr[hashIndex]->getKey()==key && arr[hashIndex]->getKey()!=-1){
			return arr[hashIndex]->getValue();
		}
	}
}

//display all element stored in table
template<typename Key, typename Value>
void HashMap<Key, Value>::display(){
	
	std::cout << "**** HASH TABLE **** "<< std::endl;
	for(int i=0;i<=capacity; i++){
		if(arr[i]!=NULL && arr[i]->getKey()!=-1){
			std::cout << arr[i]->getKey() << ":" << '\t' << arr[i]->getValue() << std::endl;
		}
	}
	std::cout <<"********************" << std::endl;
}

int main(){

    HashMap<int, int> *h = new HashMap<int, int>;
    h->insertNode(1,1);
    h->insertNode(2,2);
    h->insertNode(17,3);
    h->insertNode(37,4);
    cout << h->searchValue(2);
    cout << h->currentSize;
    h->display();
    
   return 0;		
}

