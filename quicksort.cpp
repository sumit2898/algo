#include <iostream>
#include <vector>
using namespace std ;

int partition(vector <int> & nums , int st ,int end){

    int idx = st-1 , pivot = nums[end];

    for(int i = st ; i < end ; i++){
        if( pivot >= nums[i]){
            idx++;
            swap(nums[idx],nums[i]);

        }
    }
    idx++;
    swap(nums[idx],nums[end]);
    return idx;
}

void quicksort(vector <int> & nums , int st , int end){

    if( st < end){
        int pivotidx = partition( nums, st , end );

        quicksort(nums, st , pivotidx-1);
        quicksort(nums,pivotidx +1 ,end);
    }

}
void print(vector <int> nums){
    for( int i = 0 ; i < nums.size();i++){
        cout<< nums[i]<<" ";
    }
}
int main(){
    vector <int> nums = {5,4,3,2,1};

    quicksort(nums, 0 , nums.size() -1);
    print(nums);

    return 0;

}