#include <iostream>

using namespace std;

int main(){

    int distance;
    int capacity;

    cin>>distance;

    cin>>capacity;

    int number_of_gas_stations;
    cin>>number_of_gas_stations;

    int stations[number_of_gas_stations];
    for(int i=0 ; i<number_of_gas_stations ; i++)
    cin>>stations[i];

    int car=0; // A
    int reach=car+capacity; // where the car can reach from A
    int stops=0;

    int station; // tmp value for station

    while(reach<distance){ // O(d/c)=O(1)

        for(int i=0 ; i<number_of_gas_stations ; i++){  // O(n)

            if(stations[i]<=reach)
            station=stations[i];
        }
            
        if(station==car){

            if(station+capacity>=distance){
            
                cout<<stops;
                exit(0);
            }
                
            cout<<-1;
            exit(0);
        }
        

        car=station;
        stops++;
        reach=car+capacity;
    }

    // Results:  O(n)

    cout<<stops;

    return 0;
}