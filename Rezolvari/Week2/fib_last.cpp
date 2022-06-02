#include <iostream>
#include <stdlib.h>

typedef long long ll;

using namespace std;


ll fib(ll n){
   
    ll *f;
    f=(ll*)malloc(n*sizeof(ll));
    
    f[0]=0;
    f[1]=1;
    
    if(n==0)
    return 0;
    
    if(n==1)
    return 1;
    
    for(ll i=2 ; i<=n ; i++)
    f[i]=(f[i-1]+f[i-2])%10;
    
    return f[n];

}


int main(){
    
    ll x;

    cin>>x;
    
    cout<<fib(x)<<"\n";

    return 0;
}