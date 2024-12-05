#include<iostream>
#include<vector>
#include <concepts>
#include<map>
#include<fstream>
#include<algorithm>
#include<string>
#include<sstream>

using namespace std;

void printRow(vector<int>& row, int x);

template<integral V>
void printRow(vector<V>& row);

template <typename K, typename V>
V map_get(const map<K, V>& m, const K& key, const V& fallback);

template<typename K, integral V>
void print_map(map<K, V> m);

template<typename K, integral V>
void print_map(map<K, vector<V>> m);