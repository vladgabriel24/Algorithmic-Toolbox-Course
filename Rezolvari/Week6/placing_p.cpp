#include <iostream>
#include <limits.h>

typedef long long ll;

ll minimum(ll a , ll b , ll c , ll d , ll min){

    ll v[]={a,b,c,d};

    ll minim=min;

    for(int i=0 ; i<4 ; i++){

        if(v[i]<minim)
        minim=v[i]; 
    }
    
    return minim;
}

ll maximum(ll a , ll b , ll c , ll d , ll max){

    ll v[]={a,b,c,d};

    ll maxim=max;

    for(int i=0 ; i<4 ; i++){

        if(v[i]>maxim)
        maxim=v[i];
    }
    
    return maxim;
}

int strlength(char str[]){

    int i;
    for(i=0 ; str[i]!='\0' ; i++);

    return i;
}

ll evaluate(ll a , ll b , char op){

    switch (op){

    case '+':
        
        return a+b;
        break;
    
    case '-':

        return a-b;
        break;

    case '*':

        return a*b;
        break;

    default:
        break;
    }

    return 0;
}

ll maximum_value(char string[] , int n){

    int len=(n+1)/2;

    ll M[len+1][len+1];
    ll m[len+1][len+1];

    for(int i=0 ; i<=len ; i++){
        for(int j=0 ; j<=len ; j++)
        M[i][j]=0;  
    }

    for(int i=0 ; i<=len ; i++){
        for(int j=0 ; j<=len ; j++)
        m[i][j]=0;  
    }

    for(int i=1 ; i<=len ; i++)
    M[i][i]=(ll)string[2*(i-1)]-48;

    for(int i=1 ; i<=len ; i++)
    m[i][i]=(ll)string[2*(i-1)]-48;

    int j;
    ll a,b,c,d;
    ll minim , maxim;

    for(int s=1 ; s<=len-1 ; s++ ){
        for(int i=1 ; i<=len-s ; i++){

            j=i+s;

            minim=LLONG_MAX;
            maxim=LLONG_MIN;

            for(int k=i ; k<=j-1 ; k++){

                a=evaluate(M[i][k] , M[k+1][j] , string[2*(k-1)+1]);
                b=evaluate(M[i][k] , m[k+1][j] , string[2*(k-1)+1]);
                c=evaluate(m[i][k] , M[k+1][j] , string[2*(k-1)+1]);
                d=evaluate(m[i][k] , m[k+1][j] , string[2*(k-1)+1]);

                minim=minimum(a,b,c,d,minim);
                maxim=maximum(a,b,c,d,maxim);
            }

            m[i][j]=minim;
            M[i][j]=maxim;
        }
    }

    return M[1][len];
}

int main(){

    char string[30];

    scanf("%s" , string);

    int n=strlength(string);

    std::cout<<maximum_value(string ,n);

    return 0;
}