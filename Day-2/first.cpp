#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

int isSafe(vector<int>& row){
    bool isIncreasing = false;
    bool isSet = false;
    int i = 0;

    while (i+1 < row.size()){
        if (!isSet){
            isSet = true;
            isIncreasing = row[i] < row[i+1];
        }
        
        if(abs(row[i] - row[i+1]) < 1 || abs(row[i] - row[i+1]) > 3){
            return 0;
        }

        if((isIncreasing && row[i] > row[i+1]) || (!isIncreasing && row[i] < row[i+1])){
            return 0;
        }
        ++i;
    }

    return 1;
}

int main(){
int sum = 0;
ifstream file("input.txt");
    string line;
    while (getline(file, line)) {
        vector<int> row;
        int num;
        stringstream nums(line);
        while (nums >> num){
            row.push_back(num);
        }
        sum += isSafe(row);
    }
cout << sum << endl;
return 0;
}