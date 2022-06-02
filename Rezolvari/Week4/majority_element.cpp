#include<iostream>

using namespace std;

int main(){


    int n;
    cin>>n;

    int count=n/2;
    int max;

    int v[n];
    
    for(int i=0 ; i<n ; i++)
    cin>>v[i];

    max=v[0];
    for(int i=0 ; i<n ; i++){

        if(v[i]>max)
        max=v[i];

    }

    //cout<<max<<"\n";


    int *freq;
    freq=(int *)calloc(1000000 , sizeof(int));

    for(int i=0 ; i<n ; i++){

        freq[v[i]]++;

    }

    // for(int i=0 ; i<=max ; i++){

    //     cout<<freq[i]<<" ";

    // }

    int flag=0;
    for(int i=0 ; i<=1000000 ; i++){
        
        if(freq[i]>count)
        flag=1;
    }

    if(flag==1)
    cout<<1;
    else
    cout<<0;

    return 0;
}