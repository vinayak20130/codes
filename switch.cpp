#include<iostream>
using namespace std;
int main(){
    char ch ='1';
    int num =1;
    cout<<endl;
    switch(ch){
        case 1:cout<<"first"<<endl;
        case '1':cout<<"character 1"<<endl;       
            break;

        case 2: cout<<"second"<<endl;
               break;
        default: cout<<"it is a default case"<<endl;
    }
    switch(num){
        case 1: cout<<"first"<<endl;
               break;}
    
}
//find about end()