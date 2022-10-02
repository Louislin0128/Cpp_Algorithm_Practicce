#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> array;
	array.resize(10);
	for(int i=0;i<array.size();i++){
		cin>>array[i];
	}
	for (int i=1;i<array.size();i++) {
        int key=array[i];
        int j=i-1;
        while(key < array[j] && j>=0) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1]=key;
    }
	cout<<"After sort: \n";
	for(int i=0;i<array.size();i++){
		cout<<array[i]<<" ";
	}
	return 0;
} 
