#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>
#include "../utils.h"

using namespace std;

int isSafe(vector<int>& row, int iterToSkip=-1){
    bool isIncreasing = false;
    bool isSet = false;
    int i = 0;

    while (i+1 < row.size()){
        if (!isSet){
            isSet = true;
            isIncreasing = row[i] < row[i+1];
        }
        
        if(abs(row[i] - row[i+1]) < 1 || abs(row[i] - row[i+1]) > 3){
            if (iterToSkip < 0){
                vector<int> row1 = row;
                vector<int> row2 = row;

                row1.erase(row1.begin() + i);
                row2.erase(row2.begin() + i + 1);
                if(i > 0){
                    row.erase(row.begin() + i - 1);
                return max(isSafe(row, i-1), max(isSafe(row1, i), isSafe(row2, i+1)));
                }
                return max(isSafe(row1, i), isSafe(row2, i+1));
            }
            return 0;
        }

        if((isIncreasing && (row[i] > row[i+1])) || (!isIncreasing && (row[i] < row[i+1]))){
            if (iterToSkip < 0){
                vector<int> row1 = row;
                vector<int> row2 = row;

                row1.erase(row1.begin() + i);
                row2.erase(row2.begin() + i + 1);
                if(i > 0){
                    row.erase(row.begin() + i - 1);
                return max(isSafe(row, i-1), max(isSafe(row1, i), isSafe(row2, i+1)));
                }
                return max(isSafe(row1, i), isSafe(row2, i+1));
            }
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