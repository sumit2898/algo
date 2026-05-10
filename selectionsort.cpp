#include <iostream>
#include <vector>
using namespace std;

void selectionsort(vector <int> & nums ){
    for ( int i =0 ; i< nums.size()-1 ; i++){
        int min_index = i ;
        for ( int j = i+1 ; j < nums.size() ; j++){
            if ( nums[j] < nums[min_index]){
                min_index = j ;
            }
        }
        swap(nums[i], nums[min_index]);
    }
}

void print ( vector <int> & nums ){
    for ( int i = 0 ; i < nums.size() ; i++){
        cout << nums[i] << " ";
    }
}

 int main (){
    vector <int> nums = {3,2,1,5,4};
    selectionsort(nums);
    print(nums);

    return 0;
 }
 