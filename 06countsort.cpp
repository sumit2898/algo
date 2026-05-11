#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void countingsort( vector <int>& arr){
    if( arr.empty() )   return ;

    int maxVal = *max_element(arr.begin(), arr.end());

    vector <int> count( maxVal + 1, 0);
    vector <int> output(arr.size());

    for( int num : arr){
        count[num]++;
    }

    for( int i =1 ; i <= maxVal ; i++){
        count[i] += count[i-1];
    }

    for(int i = arr.size() -1 ; i >= 0 ; i--){
        output[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }

    arr = output;
}

int main(){
    vector <int> data = {4,2,2,8,3,3,1};
    countingsort(data);

    cout<<" Sorted Array : ";
    for( int val : data){

        cout << val << " " ;
    }
    return 0;
}