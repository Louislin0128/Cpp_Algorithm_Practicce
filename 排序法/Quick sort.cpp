#include<iostream> 
#include<vector>
using namespace std;

void Quicksort(vector<int> &x , int, int);
int  partition(vector<int> &x , int, int);

int main(){
	vector<int> v;
	v.resize(10);
	for(int i=0;i<v.size();i++){
		cin>>v[i];
	}
	Quicksort(v, 0, v.size()-1);
	cout << "After sorted:\n";
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	return 0;
}
void Quicksort(vector<int> &array, int low, int high) {
	if(high - low <= 0) return;

	int k = partition(array, low, high);	//儲存每次與pivot交換的位置 
	Quicksort(array, low, k - 1);			//處理前半部 
	Quicksort(array, k+1, high);			//處理後半部 
	return;
}
int partition(vector<int> &array, int low, int high) {		//divide the int array into two parts
	int pivot = array[low];					
	int i = low + 1;				
	int j = high;					

	while(1) {
		for(; i <= j; i++) {
			if (array[i] >= pivot) break;
		}
		for(; i <= j; j--) {
			if (array[j] < pivot) break;
		}
		if (i < j) {
			int temp = array[i];
			array[i] = array[j];
			array[j] = temp;
		}else {
			array[low] = array[j];			
			array[j] = pivot;
			return j;
		}
	}
}

