#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int row =1;
    int count =1;
    while (row<=n)
    {
       //space print karlo
       int space = n-row;
       while (space)
       {
        cout<<" ";
        space= space -1;

       }
       int col =1;
       int star =n-row;
       while (col<=row)
       {
        cout<<count;
        star=star+1;
        col=col+1;
        count=count+1;
       }
       cout<<endl;
       row=row+1;
    }
    
}