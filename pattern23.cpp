#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int row =1;
    while (row<=n)
    {
       //space print karlo
       int star = n-row+1;
       while (star)
       {
        cout<<"*";
        star=star-1;

       }
       cout<<endl;
       row=row+1;
    }
    
}