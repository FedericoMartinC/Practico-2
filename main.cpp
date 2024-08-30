#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "./datastructures/HashTable.cpp"
using namespace std;

int main()
{
    int devuelvo=0;
    int N;
    cin >> N;
    HashTable* tabla= new HashTable(N);
    for (int i=0;i<N;i++){
        string key;
        cin >> key;
        if(tabla->exist(key)==true){
            int oc=tabla->get(key);
            if(oc==1){
                devuelvo=devuelvo+1;
            }else if (oc==2){
                devuelvo=devuelvo-1;
            }
        }
        tabla->add(key,1);
    }
    cout << devuelvo ;
    return 0;
}