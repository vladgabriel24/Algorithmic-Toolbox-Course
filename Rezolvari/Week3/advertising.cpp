#include <iostream>
typedef long long ll;

using namespace std;

int main(){

    int n;
    cin>>n;

    int profit[n];
    int clicks[n];

    for(int i=0 ; i<n ; i++){

        cin>>profit[i];
    }

    for(int i=0 ; i<n ; i++){

        cin>>clicks[i];
    }

    ll max1;
    ll max2;

    int index1 , index2;

    ll sum=0;

    for(int j=0 ; j<n ; j++){ // O(n)

        max1=profit[0];
        index1=0;
        for(int i=0 ; i<n ; i++){ // O(n)

            if((profit[i]>max1)&&(profit[i]!=-1000000)){
                
                max1=profit[i];
                index1=i;
            }
        }

        max2=clicks[0];
        index2=0;
        for(int i=0 ; i<n ; i++){ // O(n)

            if((clicks[i]>max2)&&(clicks[i]!=-1000000)){
                
                max2=clicks[i];
                index2=i;
            }
        }

        profit[index1]=-1000000;
        clicks[index2]=-1000000;

        sum=sum+(max2*max1);
    }

    // Result: O(2n^2)=O(n^2)

    cout<<sum;

    return 0;
}