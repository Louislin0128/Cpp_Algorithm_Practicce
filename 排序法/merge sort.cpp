#include<iostream>
#include<vector>
#define Max 1e9
using namespace std;
void Merge(vector<int> &Array, int left, int mid, int right){
	//������Ӥp�}�C�h����̭����ƭȡA�����¬OArray 
    vector<int> LeftSub(Array.begin()+left, Array.begin()+mid+1);		
    vector<int> RightSub(Array.begin()+mid+1, Array.begin()+right+1);
                     
    LeftSub.insert(LeftSub.end(), Max);     	//�[�JMax����]�O�p�G�p�}�C���@��쩳�F�A�Ʀr���|�W�L1e9�A����N���ݭn�h�g�P�_ 
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
int MergeSort(vector<int> &array, int left, int right){				//�G�� 
	if (left < right) {   					//�}�C�d��O�q����k              
        int mid = (left+right)/2;         
        MergeSort(array, left, mid);   		//�~��divide�}�C���e�b�qsubarray
        MergeSort(array, mid+1, right);     //�~��divide�}�C����b�qsubarray
        Merge(array, left, mid, right);   	//�N���subarray�����, �æX�֥X�Ƨǫ᪺�}�C 
    }
}
int main(){
	//merge sort �q�p�ƨ�j 
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
