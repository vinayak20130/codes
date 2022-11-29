#include<iostream>
using namespace std;
int main(){
    int arr[10]={2,3,4,5,6,7,-9,-5,10,-7};
    int count =0;
    for(int i=0;i<=10;i++){
    if(arr[i]){
        count++;
    }
    }
    cout<<count;
}