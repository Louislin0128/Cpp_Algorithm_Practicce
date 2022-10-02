/*...........由小排到大............*/ 
#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> array;
	array.resize(10);
	for(int i=0;i<array.size();i++){
		cin>>array[i];
	}
	for(int i=0;i<array.size();i++){
		int m=i;
		for(int j=i+1;j<array.size();j++){
			if(array[m] > array[j])
				m=j;
		}
		int temp = array[m];
		array[m] = array[i];
		array[i] = temp;
	}
	for(int i=0;i<array.size();i++){
		cout<<array[i]<<" ";
	}
	return 0;
} 
