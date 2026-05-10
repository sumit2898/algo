#include <iostream>
#include <vector>
using namespace std;

void bubblesort( vector <int> & nums ){

    bool swapped = false;
    for ( int i = 0 ; i < nums.size(); i ++){
       
        for ( int j =0 ; j < (nums.size()-i-1) ; j++){
            if ( nums[j] > nums[j+1]){
                swap(nums[j], nums[j+1]);
                swapped = true;
            }

        }
        if ( swapped == false){
            break;
        }
    }
}

void print ( vector <int> & nums ){
    for ( int i = 0 ; i < nums.size() ; i++){
        cout << nums[i] << " ";
    }
}

int main ( ){
    vector <int> nums = {3,2,1,5,4};
    bubblesort(nums);
    print(nums);

    return 0;
}
