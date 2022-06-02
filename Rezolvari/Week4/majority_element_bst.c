#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

struct tree{

    ll x;
    ll multiplicity;
    struct tree *left;
    struct tree *right;
};

typedef struct tree BST;

BST *create_node(ll x){

    BST *new_node=malloc(sizeof(BST));
    
    new_node->x=x;

    new_node->multiplicity=1;

    new_node->left=NULL;
    new_node->right=NULL;

    return new_node;

}

BST *insert_node(BST *tree , ll x){

    if(tree==NULL)
    return create_node(x);

        if(x == tree->x)
        tree->multiplicity++;

        else if(x < tree->x )
        tree->left=insert_node(tree->left , x);
        
        else if (x > tree->x )
        tree->right=insert_node(tree->right , x);

    return tree;

}

void traversal(BST *tree , ll n , int *flag){

    if(tree==NULL)
    return ;

    if(tree->multiplicity > n)
    *flag=1;

    traversal(tree->left ,n ,flag);
    traversal(tree->right ,n, flag);

}

void inorder(BST *tree , ll n , int *flag){

    if(tree==NULL)
    return;

    
    printf("%lld " , tree->x);
    printf("%d\n" , tree->multiplicity);
    inorder(tree->left ,n ,flag);
    inorder(tree->right ,n, flag);

}


int main(){

    ll n;
    scanf("%lld" , &n);

    ll m=n/2;

    int flag=0;

    BST *tree=NULL;

    ll x;
    for(ll i=0 ; i<n ; i++){
        
        scanf("%lld" , &x);
        tree=insert_node(tree , x);
    }

    traversal(tree , m , &flag);

    printf("%d" , flag);

    //inordine(tree , m , &flag);







    return 0;
}