#include "utils.h"
void printRow(vector<int>& row, int x){
    for(int v: row){
        cout << v << " ";
    }
    cout << "-> " << x;
    cout << endl;
}

void printRow(vector<int>& row){
    for(int v: row){
        cout << v << " ";
    }
    cout << endl;
}