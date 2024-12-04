#include<iostream>
#include<fstream>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<regex>

using namespace std;

int main(){
int total = 0;
ifstream file("input.txt");

regex mul_pattern(R"(mul\((\d+),(\d+)\))");
smatch matches;
    string line;
    while (getline(file, line)) {
        sregex_iterator begin(line.begin(), line.end(), mul_pattern);
        sregex_iterator end;
        for (std::sregex_iterator it = begin; it != end; ++it){
            smatch match = *it;
            total = total + (stoi(match[1]) * stoi(match[2]));
        }
        // cout << endl;
    }
cout << total << endl;
return 0;
}