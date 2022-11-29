#include<iostream>
using namespace std;
int AP(int n){
    int ap =((3*n)+7);
    return ap;
}
int main(){
    int n;
    cin>>n;
    int ans =AP(n);
    cout<<"the ap is"<<ans;
    return 0;
}
