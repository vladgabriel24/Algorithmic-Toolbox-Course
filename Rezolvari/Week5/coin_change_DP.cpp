#include <iostream>

void print_arr(int arr[] , int n){

    for(int i=0 ; i<n ; i++)
    std::cout<<arr[i]<<" ";

}

int change(int coins[] , int n , int money , int DP[]){

    if(money==0)
    return 0;

    if(DP[money]!=0)
    return DP[money];

    int number_coins;
    int min=999;
    
    for(int i=0 ; i<n ;i++){

        if(money>=coins[i]){

            number_coins=change(coins , n , money-coins[i] , DP)+1;

            if(number_coins<min)
            min=number_coins;

        }
    }

    DP[money]=min;

    return min;
}

int main(){

    int coins[]={1,3,4};

    int n=sizeof(coins)/sizeof(int);

    int money;
  
    std::cin>>money;

    int DP[money+1];
    for(int i=0 ; i<=money ; i++)
    DP[i]=0;

    std::cout<<change(coins , n , money , DP)<<"\n";
    //print_arr(DP , money+1);


    return 0;
}