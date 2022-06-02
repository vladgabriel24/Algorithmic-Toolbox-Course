#include <iostream>

long long calculator(long long n , long long *DP){

    for(long long i=2 ; i<=n ; i++){

        int operations[]={0,0,0};

        if(i%2==0)
        operations[0]=DP[i/2]+1;

        if(i%3==0)
        operations[1]=DP[i/3]+1;

        operations[2]=DP[i-1]+1;

        long long min=1000001;
        for(int j=0 ; j<3 ; j++){

            if((operations[j]<min)&&(operations[j]!=0))
            min=operations[j];
        }

        DP[i]=min;
    }
    return DP[n];
}

int main(){

    long long n;
    std::cin>>n;

    long long *DP;
    DP=(long long *)malloc((n+1)*sizeof(long long));

    for(int i=0 ; i<=n ; i++)
    DP[i]=0;

    std::cout<<calculator(n , DP)<<"\n";
    
    return 0;
}