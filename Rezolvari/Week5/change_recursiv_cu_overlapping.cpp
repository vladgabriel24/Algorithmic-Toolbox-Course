#include <iostream>

void print_arr(int arr[] , int n){

    for(int i=0 ; i<n ; i++)
    std::cout<<arr[i]<<" ";

}

int change(int coins[] , int n , int money){

    if(money==0)
    return 0;

    int number_coins;
    int min=999;
    
    for(int i=0 ; i<n ;i++){

        if(money>=coins[i]){

            number_coins=change(coins , n , money-coins[i])+1;

            if(number_coins<min)
            min=number_coins;

        }
    }

    return min;
}

int main(){

    int coins[]={1,3,4};

    int n=sizeof(coins)/sizeof(int);

    int money;
  
    std::cin>>money;

    std::cout<<change(coins , n , money);

    return 0;
}