/*
    Task:

    Given a few digits, to arrange them in the largest possible number.
*/

#include <iostream>

typedef long long ll;

using namespace std;

int largest_number(const int n){

    int digits[n];

    for(int i=0 ; i<n ; i++)
    cin>>digits[i];

    int number;
    int max;
    int counter=0;
    int index;

    while(counter<n){

        for(int i=0 ; i<n ; i++){

            if(digits[i]!=-1){

                max=digits[i];
                index=i;
                break;
            }
        }

        for(int i=0 ; i<n ; i++){

            if((digits[i]>max)&&(digits[i]!=-1)){
                
                max=digits[i];
                index=i;

            }
        }

        digits[index]=-1;

        number=number+max;
        number=number*10;

        counter++; 
    }

    return number/10;
}


int main(){

    int n; // number of digits
    cin>>n;

    cout<<largest_number(n);
    
    return  0;
}