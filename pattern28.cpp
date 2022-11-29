#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int row =1;
    while (row<=n)
    {
       //space print karlo
       int space = n-row-3;
       while (space<=n)
       {
        cout<<" ";
        space= space+1;

       }
       int col =1;
       int star = n-row+1;
       while (star)
       {
        cout<<row;
        star=star-1;
        col=col+1;
       }
       cout<<endl;
       row=row+1;
    }
    
}