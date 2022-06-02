#include <iostream>

using namespace std;

long long change(int coins[] , int n ,long long m){
    
    long long count=0;

    for(int i=0 ; i<n ; i++){  // O(1)

        while(m>=coins[i]){  // O(m/10 + (m%10)/5 + (m%10)%5/1)

            m=m-coins[i];
            count++;
        }
    }

    return count;
}
// Result: O(m/10) adica O(m) deoarece este cea mai costisitoare operatie , ultimile 2 realizandu-se destul de rapid , deci pot fii neglijabile

int main(){

    long long m;
    cin>>m;

    int coins[]={10,8,1};
    int n=sizeof(coins)/sizeof(int);
    
    cout<<change(coins , n ,m);

    return 0;
}