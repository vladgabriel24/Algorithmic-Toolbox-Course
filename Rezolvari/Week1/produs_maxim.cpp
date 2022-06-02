#include <iostream>

using namespace std;

void max_product(int n){
      
      long long v[n];
      for(int i=0 ; i<n ; i++)
      cin>>v[i];
      
      int first_max=0;
      long long max=-1;
      for(int i=0 ; i<n ; i++){
            
            if(v[i]>max){
            
                  max=v[i];
                  first_max=i;
            }     
      }
      
      long long max2=-1;
      for(int i=0 ; i<n ; i++){
            
            // pt ca noi cautam 2 cele mai mari valori , iar pt ca am gasit deja una
            // pe a doua nu vrem sa fie tot acea gasita , dar atentie ,
            // aici vb de index , caci daca la alt index gasesc cv egal cu ce am gasit deja
            // si ala e maximul (pt ca in rest nu s altele mai mari) , pe ala il iau
            // deci noi nu ferim cautarea de valoare , ci doar de index ul la care am extras deja
            if((v[i]>max2)&&(i!=first_max))
            max2=v[i];
      }
      
      long long product=max2*max;
      
      cout<<product;     
}

int main(){
      
      int n;
      cin>>n;
      
      max_product(n);
      
      
      
      
      return 0;
}