#include<iostream>
#include<vector>
#define Max 1e9
using namespace std;
void Merge(vector<int> &Array, int left, int mid, int right){
	//分成兩個小陣列去比較裡面的數值，但依舊是Array 
    vector<int> LeftSub(Array.begin()+left, Array.begin()+mid+1);		
    vector<int> RightSub(Array.begin()+mid+1, Array.begin()+right+1);
                     
    LeftSub.insert(LeftSub.end(), Max);     	//加入Max的原因是如果小陣列有一方到底了，數字不會超過1e9，那麼就不需要多寫判斷 
    RightSub.insert(RightSub.end(), Max);    
    //cout<<left<<" "<<right<<endl;
    int idxLeft = 0, idxRight = 0;

    for (int i = left; i <= right; i++) {
        if (LeftSub[idxLeft] <= RightSub[idxRight] ) {
            Array[i] = LeftSub[idxLeft];
            idxLeft++;
        }
        else{
            Array[i] = RightSub[idxRight];
            idxRight++;
        }
    }
}
int MergeSort(vector<int> &array, int left, int right){				//二分 
	if (left < right) {   					//陣列範圍是從左到右              
        int mid = (left+right)/2;         
        MergeSort(array, left, mid);   		//繼續divide陣列的前半段subarray
        MergeSort(array, mid+1, right);     //繼續divide陣列的後半段subarray
        Merge(array, left, mid, right);   	//將兩個subarray做比較, 並合併出排序後的陣列 
    }
}
int main(){
	//merge sort 從小排到大 
	//int array[10]={9,3,1,7,5,2,4,8,6,0};
	vector<int> v;
	v.resize(10);
	for(int i=0;i<v.size();i++){
		cin>>v[i];
	}
	MergeSort(v, 0, v.size()-1);
	cout << "After sorted:\n";
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
} 
