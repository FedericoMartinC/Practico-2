#ifndef TABLA_HASH
#define TABLA_HASH
#include <cassert>
#include <string>
#include <iostream>
using namespace std;

// TODO:
// - Implementar la Tabla de hash

class HashTable
{
private:
    struct ClaveValor
    {
        string key;
        int value;
        ClaveValor(string unKey,int unValue): key(unKey) , value(unValue){}
    };

    bool* aux;

    ClaveValor **arr;

    int buckets;

    int cantElem;

    
    int hash(string key) {
        int h = 0;
        for (int i = 0; i < key.length(); i++)
            h = 31 * h + int(key[i]);
        return h;
    }

    int getBucket(string key,int i){
        int n=this->hash(key);
        return abs((n + i) % this->buckets);
    }

    void addRec(int i,string key,int value){
        int bucket = getBucket(key, i);
        if (arr[bucket] == NULL)
        {
            arr[bucket] = new ClaveValor(key, value);
        }
        else if (arr[bucket]->key == key)
        {
            arr[bucket]->value++;
        }
        else
        {
            addRec(i + 1, key, value);
        }

    }

    int getRec(int i, string key)
    {
        int bucket = getBucket(key, i);
        if (arr[bucket]->key == key)
        {
            return arr[bucket]->value;
        }
        else
        {
            return getRec(i + 1, key);
        }
    }

    bool existRec(int i, string key)
    {
        int bucket = getBucket(key, i);
        if (arr[bucket] == NULL)
        {
            return false;
        }
        else if (arr[bucket]->key == key)
        {
            return true;
        }
        else
        {
            return existRec(i + 1, key);
        }
    }

    void removeRec (int i,string key){
        int bucket=getBucket(key, i);
        if(arr[bucket]->key==key){
            ClaveValor *aBorrar=arr[bucket];
            arr[bucket]=NULL;
            delete aBorrar;
            aux[bucket]=true;
        }else{
            removeRec(i+1,key);
        }
    }
    
public:
    HashTable(int size)
    {
        this->arr = new ClaveValor *[size]();
        this->aux = new bool[size];
        for (int i = 0; i <size ; i++)
        {
            arr[i] = NULL;
            aux[i]=false;
        }
        this->buckets = size;
    }
    ~HashTable()
    {
        // TODO
    }
    void add(string clave, int valor)
    {
        this->addRec(0,clave,valor);
    }
    void remove(string clave)
    {
        assert(this->exist(clave));
        this->removeRec(0,clave);
    }
    int get(string clave)
    {
        assert(this->exist(clave));
        return this->getRec(0, clave);
    }
    bool exist(string clave)
    {
        return this->existRec(0, clave);
    }
};

#endif