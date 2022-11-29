#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int row =1;
   int count=1;
    while(row<=n)
    {   int col = 1;
        int space =n-row+1;
        while (space)
        {
            cout<<col;
            col++;
            space--;
        }
        int star =row-1;
        while (star)
        {
            cout<<"*";
            star--;
        }
        
        int star2= row-1;
        while (star2)
        {
            cout<<"*";
            star2--;
        }

       int no=n-row+1;
       
       while (no)
       {
        cout<<no;
        
        no--;
       }
       
        
        
    
       
       
       cout<<endl;
        row++;
        }
        
    }
