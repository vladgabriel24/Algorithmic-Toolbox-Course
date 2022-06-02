#include <iostream>
#include <cstdlib>
#include <time.h>

void print_matrix(double M[][2] , long long n){

    for(long long i=0 ; i<n ; i++){
        for(long long j=0 ; j<2 ; j++){

            std::cout<<M[i][j]<<" ";

        }
        std::cout<<"\n";
    }
}

long long partition(double arr[][2] , long long left , long long right){

    double tmp;
    double tmp2;

    srand(time(NULL));
    long long random=left+rand()%(right-left);

    tmp=arr[left][0];
    arr[left][0]=arr[random][0];
    arr[random][0]=tmp;

    tmp2=arr[left][1];
    arr[left][1]=arr[random][1];
    arr[random][1]=tmp2;

    double pivot=arr[left][0];
    double pivot2=arr[left][1];

    long long j=left;
    
    for(long long i=left+1 ; i<=right ; i++){

        if(arr[i][0]>=pivot){

            tmp=arr[j+1][0];
            arr[j+1][0]=arr[i][0];
            arr[i][0]=tmp;

            tmp2=arr[j+1][1];
            arr[j+1][1]=arr[i][1];
            arr[i][1]=tmp2;

            j++;
        }
    }

    tmp=arr[j][0];
    arr[j][0]=pivot;
    arr[left][0]=tmp;

    tmp2=arr[j][1];
    arr[j][1]=pivot2;
    arr[left][1]=tmp2;

    return j;
}

void quick_sort(double arr[][2] , long long left , long long right){

    if(left>=right)
    return;

    long long mid=partition(arr ,left ,right);

    quick_sort(arr , left , mid-1);
    quick_sort(arr , mid+1 , right);
}

int main(){

    long long n;
    std::cin>>n;

    long long W;
    std::cin>>W;

    double M[n][2];

    for(long long i=0 ; i<n ; i++){
        for(long long j=0 ; j<2 ; j++){

            std::cin>>M[i][j];

        }

        M[i][0]=M[i][0]/M[i][1];
    }


    quick_sort(M , 0 , n-1);

    double value=0;

    for(long long i=0 ; i<n ; i++){

        if(M[i][1]<=W){

            value+=M[i][1]*M[i][0];
            W-=M[i][1];

        }else{

            value+=W*M[i][0];
            W=0;
        }
    }

    printf("%f" , value);

    return 0;
}