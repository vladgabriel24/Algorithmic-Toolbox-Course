#include <iostream>

using namespace std;

int b_search(int v[] , int low , int high , int key){

    int mid=low+((high-low)/2);

    if(high<low)
    return -1;
    
    if(v[mid]==key)
    return mid;

    else if(key>v[mid])
    return b_search(v , mid+1 , high , key);
    else
    return b_search(v , low , mid-1 , key);
}

int main(){

    int n;
    int m;

    cin>>n;

    int v[n];

    for(int i=0 ; i<n ; ++i)
    cin>>v[i];

    cin>>m;

    int search_items[m];
    for(int i=0 ; i<m ; ++i)
    cin>>search_items[i];

    int index;

    for(int i=0 ; i<m ; i++){
        
        index=b_search(v , 0 , n , search_items[i]);
        cout<<index<<" ";
    }

    return 0;
}