#include<iostream>
using namespace std;
int main (){
    int n;
    cin>>n;
    int i=2;
    while(i<n){
        //divide hogya to not prime
        if (n%i==0)
         {
            cout<<"it is a not a prime no. for  "<<i<<endl;
            
                    }
        else
        {
            cout<<"it is a prime number for  "<<i<<endl;

        }
        i=i+1;
    }
}