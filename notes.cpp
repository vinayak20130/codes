#include<iostream>
using namespace std;
int main(){
    int amount;
    cout<<"enter the amount"<<endl;
    cin>>amount;
    while (amount!=0)
    
    {   if (amount/100!=0)
    {
        
        cout<<amount/100<<" 100 notes"<<endl;
        amount=amount%100;
    } 
    if (amount/50!=0)
    {
        
        cout<<amount/50<<" 50 notes"<<endl;
        amount=amount%50;
        
    }
    if (amount/20!=0)
    {
    
        cout<<amount/20<<" 20 notes"<<endl;
        amount=amount%20;
    }
    if (amount/1!=0)
    {
        
        cout<<amount/1<<" 1 notes"<<endl;
        amount=amount%1;
    }
    
        
        
        
        
    }
    
}