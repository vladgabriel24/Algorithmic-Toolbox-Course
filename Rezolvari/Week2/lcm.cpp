#include <iostream>

using namespace std;

long long cmmdc(long long x , long long y){

    if(x%y==0)
    return y;

    return cmmdc(y , x%y);
}

long long cmmmc_v2(long long x , long long y){


    return (x*y)/cmmdc(x,y);
}

int main(){

    long long x , y;
    cin>>x>>y;

    cout<<cmmmc_v2(x,y);

    return 0;
}