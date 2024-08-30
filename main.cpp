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
        if(tabla->exist(key)){
            if(tabla->get(key)==1){
                devuelvo++;
            }else if (tabla->get(key)>1){
                devuelvo--;
            }
        }
        tabla->add(key,1);
    }
    cout << devuelvo << endl;
    return 0;
}