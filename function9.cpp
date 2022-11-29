#include<iostream>
using namespace std;
int fib(int n){
    int prevnum=0;
    int num=1;
    int i=1;
    while(i<=n-2){
        int newnum=num+prevnum;
        prevnum=num;
        num=newnum;
        i++;
    }
    return num;
}

int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"0";
    }
    else if (n==2)
    {
        cout<<"1";
    }
    
    else if (n>=3)
    {
        cout<<fib(n);
    }
}