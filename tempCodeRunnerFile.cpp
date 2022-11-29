#include<iostream>
using namespace std;
int one(int n){
    int count=0;
    while(n!=0){
        
        if (n&1)
        {
            count++;
        }
        n=n>>1;
        
    }
     return count;
}
    int main()
    {
        int a;
        int b;
        cin>>a>>b;
        int ans1=one(a);
        int ans2=one(b);
        cout<<ans1+ans2<<endl;
        return 0;
        
    }
    

