#include <iostream>
#include <math.h>

typedef long long ll;

using namespace std;

void fibonacci_modulated( ll m , ll n){
    
    if(n > (pow(2,63)-1)){
        
        printf("Too big!");
        exit(0);
    }
    
    if(m==0);
    
    if(m==1);
    
    ll *F;
    F=(ll*)calloc(n,sizeof(ll));
    if(F==NULL){
        printf("Error at allocation!");
        exit(0);
    }
    
    F[0]=0%m;
    F[1]=1%m;

    ll i=2;
    for(i=2 ; i<=n ; i++){
        
        F[i]=(F[i-1]+F[i-2])%m;

        if((F[i]%m)==0){  
            
            if((F[i-1]%m)==1)
            break;
        }
    }
    
    ll rest;
    
    rest=n%i;
    
    if(n<i)
    //cout<<"For n="<<n<<" , we have: "<<F[n]<<"\n";
    cout<<F[n];
    else
    //cout<<"For n="<<n<<" , we have: "<<F[rest]<<"\n";
    cout<<F[rest];
    
    free(F);
}

int main(){
    
    ll m, n;
    
    cin>>n>>m;
     
    fibonacci_modulated(m , n);
    
    return 0;
}