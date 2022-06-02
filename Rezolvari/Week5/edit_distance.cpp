#include <iostream>

int minimum(int x , int y , int z){

    int v[]={x , y , z};

    int min=v[0];
    for(int i=1 ; i<3 ; i++){

        if(v[i]<min)
        min=v[i];
    }

    return min;
}

void print_matrix(int M[101][101] , int n , int m){

    for(int i=0 ; i<=n ; i++){
        for(int j=0 ; j<=m ; j++){

            printf("%d " , M[i][j]);
        }
        printf("\n");
    }
}

int str_l(char str[]){

    int i;
    for(i=0 ; str[i]!='\0' ; i++);

    return i;
}

void edit_dist(char str1[] , char str2[] , int n , int m){

    int D[101][101];

    // Important!: On lines i have str1 and on columns i have str2
    // In other words:  n is for str1 and m is for str2

    for(int i=1 ; i<=n ; i++)
    D[i][0]=i;

    for(int i=1 ; i<=m ; i++)
    D[0][i]=i;

    for(int i=1 ; i<=n ; i++){
        for(int j=1 ; j<=m ; j++){

            int insertion=D[i][j-1]+1;
            int deletion=D[i-1][j]+1;
            
            if(str1[i-1]==str2[j-1]){  
                
                // We subtract 1 bcs the strings are still indexed from 0 , not 1 like i do with lines and colums of the matrix

                int match=D[i-1][j-1];
                D[i][j]=match;
            }
            else{
                
                int mismatch=D[i-1][j-1]+1;
                D[i][j]=minimum(insertion , deletion , mismatch);
            }

        }
    }
    printf("%d" , D[n][m]);

}

int main(){

    char str1[101] , str2[101];

    scanf("%s" , str1);
    scanf("%s" , str2);

    int n , m;

    n=str_l(str1);
    m=str_l(str2);
    
    edit_dist(str1 ,str2 , n ,m);

    return 0;
}