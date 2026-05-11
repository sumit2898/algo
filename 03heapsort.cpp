#include <iostream>
#include <vector>
using namespace std;

void heapify(vector <int> &nums , int n , int i ){
    int  largest =  i;
    int left = 2*i +1;
    int right = 2*i +2;

    
        if(n> left && nums[left]>nums[largest]){
            largest = left;
        }
        
        if(right < n && nums[right]>nums[largest]){
            largest = right;
        }
    
    if(largest!=i){
        swap(nums[i],nums[largest]);
        heapify(nums,n,largest);
    }

}
void heapsort(vector <int> &nums, int n){
    

    for( int i = (n/2 -1) ; i >= 0 ; i--){
        heapify(nums,n,i);
    }
    for(int i = n-1 ; i >=0 ; i--){
        swap(nums[0],nums[i]);
        heapify(nums,i,0);
    }
}

void print(vector<int> &nums ){
    for( int i = 0 ; i < nums.size(); i++){
        cout<< nums[i];
    }
}
int main(){
    vector <int> nums = {5,4,3,2,1};

    heapsort(nums, nums.size());
    print(nums);

    return 0;

}