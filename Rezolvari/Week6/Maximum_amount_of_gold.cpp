#include <iostream>
#include <vector>

using std::vector;

// am folosit std::vector pt ca aveam signal 11 , adica segm violation pt ca
// alocam in stack si aveam stack overflow

// Alocarea dinamica nu rezolva chestia asta ??


/*
Input:

4 10

30 6
14 3
16 4
9 2

*/

void print_matrix(int M[][100] , int n , int m){

    for(int i=0 ; i<=n ; ++i){
        for(int j=0 ; j<=m ; ++j)
        std::cout<<M[i][j]<<" ";

        std::cout<<"\n";
    }

    std::cout<<"\n\n";
}

int knapsack_without_rep( vector<int>arr , int n , int W){

    vector< vector< int> >  DP(n + 1,vector< int>(W + 1));

    //int DP[n+1][W+1];

    //int *DP;

    //DP=(int *)malloc((n+1)*(W+1)*sizeof(int));

    for(int i=0 ; i<=n ; ++i)
    DP[i][0]=0;
    //*(DP+i*n+0)=0;

    for(int i=0 ; i<=W ; ++i)
    DP[0][i]=0;
    //*(DP+0+i)=0;

    int value;

    for(int i=1 ; i<=n ; ++i){

        for(int j=1 ; j<=W ; ++j){
            DP[i][j]=DP[i-1][j];
            //*(DP+i*W+j)=*(DP+(i-1)*W+j);

            if( arr[i-1] <= j ){

                value=DP[i-1][j-arr[i-1]]+arr[i-1];
                //value=*(DP+(i-1)*W+(j-arr[i-1]))+arr[i-1];

                if(value > DP[i][j])
                //if(value > *(DP+i*W+j))
                DP[i][j]=value;
                //*(DP+i*W+j)=value;

            }
        }
    }

    return DP[n][W];
    //return  *(DP+n*W+W);
}

int main(){

    int W;
    std::cin>>W;

    int n;
    std::cin>>n;

    vector<int> arr(n);

    //int *arr;

    //arr=(int *)malloc(n*sizeof(int));
    for(int i=0 ; i<n ; ++i){
        
        std::cin>>arr[i];
        //scanf("%d," , &arr[i]);
        
    }

    std::cout<<knapsack_without_rep(arr , n ,W);

    return 0;
}