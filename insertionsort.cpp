#include <iostream>
#include <vector>
using namespace std;

void insertionSort(int arr[], int n){
    int shift, comparision = 0;

    for(int i =1 ; i< n ; i++){
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 ){
            comparision++;
            if(arr[j] > key){
                arr[j + 1] = arr[j];
                shift++;
                j--;
            }
            else{
                break;
            }
        }
        arr[j + 1] = key;
    }
    cout << "Number of shifts: " << shift << endl;
    cout << "Number of comparisons: " << comparision << endl;
}

int main(){
    int n ;
    cout <<"Enter the size of the aray : ";
    cin >>  n ;

    int * arr =  new int[n];
    for(int i = 0 ; i < n ; i++){
        cout <<"Enter element " << i+1 << " : ";
        cin >> arr[i];
    }

    insertionSort(arr , n);
    cout <<"Sorted array is : ";
    for(int i = 0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}