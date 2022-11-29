#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int row =1;
    
    while (row<=n)
    {
       //space print karlo
       int space = n-row;
       while (space)
       {
        cout<<" ";
        space= space -1;

       }
       // 1st for triangle
       int col =1;
       int star =n-row;
       while (col<=row)
       {
        cout<<col;
        star=star+1;
        col=col+1;
        
       }
       //for 2nd triangle
       int start = row-1;
       while (start)
       {
        cout<<start;
        start=start+1;
       }
       
       cout<<endl;
       row=row+1;
    }
    
}