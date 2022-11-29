#include<iostream>
using namespace std;

//1->prime no.
//0->not prime
bool isPrime(int n){
    for (int i = 2; i < n; i++)
    {
        if (n%i==0)
        {
            return 0;
        }
        
    }
    return 1;
}

int main(){
   int n;
   cin>>n;
   if (isPrime(n))
   {
    cout<<"is a prime no."<<endl;

   }
   else
   {
    cout<<"not a Prime no.";
   }
   
    return 0;
}