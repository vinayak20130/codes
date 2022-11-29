#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
   cout<<" enter the negative no ";
    cin >> n;
    
    float ans = 0;
    double i = 0;
   int x = 3;
   int big = pow(2,x);
   n = big - n;
    while(n != 0){
       int bit =n&1;
       ans = (bit*pow(10,i)) +ans;
       n=n>>1;
        i++;
        if (bit==1)
       {
        bool ok =1;
          cout<<"1";
       }
       else if (bit==0)
       {
        bool ok =0;
        cout<<"0";
       }
       
        
       }
     
    
    
}
