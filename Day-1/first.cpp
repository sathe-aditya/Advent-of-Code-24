#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<sstream>

using namespace std;

void readfile(vector<int>& left, vector<int>& right){
    ifstream file("input.txt");
    string line;
    while (getline(file, line)) {
        stringstream nums(line);
        int num1, num2;

        nums >> num1 >> num2;

        left.push_back(num1);
        right.push_back(num2);
    }
}

int main(){
vector<int> left, right;
readfile(left, right);
sort(left.begin(), left.end());
sort(right.begin(), right.end());
int sum = 0;
while (left.size() > 0){
    sum += abs(left.back() - right.back());
    left.pop_back();
    right.pop_back();
}
cout << sum << endl;
return 0;
}