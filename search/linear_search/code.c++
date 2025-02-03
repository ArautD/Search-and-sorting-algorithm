#include <iostream>

using namespace std;

int main(){

    int arr[100],n,key,i;

    cout<<"Enter the number of elements of array: "<<endl;

    cin>>n;

    cout<<"Enter the elements of array: "<<endl;

    for(i=0;i<n;i++){

    cin>>arr[i];
    }

    cout<<"Enter the key to find from array: "<<endl;

    cin>>key;

    for(i=0;i<n;i++){

        if(arr[i]==key){

            cout<<"The key is present in array and it is at position "<<i+1;

            break;
        }
    }

    if(i==n){

        cout<<"The key is not present in array";

    }

    return 0;
}