#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a1,b1,a2,b2;
        cin>>a1>>b1>>a2>>b2;
        bool k;
        k = (a1>b1)^(a2>b2);
        if(!k)cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
}