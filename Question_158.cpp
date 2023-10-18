#include<iostream>
#include<random>
using namespace std;
void fun(int arr[],int size){
    for(int x=0;x<size;x++){
        srand(x);
       int idx = rand()%(size-1);
       swap(arr[x],arr[idx]);
    }
    for(int x=0;x<size;x++){
        cout<<arr[x]<<" ";
    }
    cout<<endl;
}   
int main(){
    int arr[5] = {1,2,3,4,5};
    fun(arr,5);
    
}