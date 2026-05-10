#include <iostream>
#include <vector>
using namespace std;

void merge(vector <int> &nums,int st, int mid, int end){
    vector <int> temp;

    int i = st , j = mid+1;

    while ( i<=mid && j<=end){
        if( nums[i]<= nums[j]){
            temp.push_back(nums[i]);
            i++;
        }else{
            temp.push_back(nums[j]);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(nums[i]);
            i++;

    }

    while( j<=end){
        temp.push_back(nums[j]);
            j++;
    }

    for( int idx = 0 ; idx < temp.size() ; idx ++){
        nums[st+idx] = temp[idx];
    }



}

void mergesort(vector <int> & nums, int st, int end){
    if( st < end){
        int mid = st + (end - st )/2;

        mergesort(nums,st,mid);
        mergesort(nums,mid+1,end);

        merge(nums,st,mid,end);
    }

}

void print(vector <int> & nums){
 for ( int i =0 ; i < nums.size() ; i ++){
    cout<< nums[i]<<" ";
 }
}

int main(){
    vector <int> nums  = {5,4,3,2,1};
   
    

    mergesort(nums, 0 , nums.size() -1);
    print(nums);
}

