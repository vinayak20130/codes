#include<iostream>
#include<math.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int ans = 0;
    int i = 0;
    while(n != 0){
       if (n&1==1)
       {
        i++;
       }
       n=n>>1;
    }
    cout<<"answer is "<< i<<endl;
}