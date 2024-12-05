#include "utils.h"

void printRow(vector<int>& row, int x){
    for(int v: row){
        cout << v << " ";
    }
    cout << "-> " << x;
    cout << endl;
}

template <integral V>
void printRow(vector<V>& row){
    for(int v: row){
        cout << v << " ";
    }
    cout << endl;
}

template <typename K, typename V>
V map_get(const map<K, V>& m, const K& key, const V& fallback){
    auto it = m.find(key);
    if (it != m.end()){
        return it->second;
    }
    return fallback;
}

template<typename K, integral V>
void print_map(map<K, V> m){
for(auto it = m.begin(); it != m.end(); ++it){
    cout <<"Key: " << it->first << endl << "Value: " << it->second << endl;
}
}

template<typename K, integral V>
void print_map(map<K, vector<V>> m){
for(auto it = m.begin(); it != m.end(); ++it){
    cout <<"Key: " << it->first << endl << "Values: " << endl;
    printRow(it->second);
    cout << endl;
}
}