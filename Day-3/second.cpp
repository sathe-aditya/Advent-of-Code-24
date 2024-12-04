#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

using namespace std;

int get_chunk_total(string &line)
{
    int total = 0;
    regex mul_pattern(R"(mul\((\d+),(\d+)\))");
    sregex_iterator begin(line.begin(), line.end(), mul_pattern);
    sregex_iterator end;
    
    for (std::sregex_iterator it = begin; it != end; ++it)
    {
        smatch match = *it;
        total = total + (stoi(match[1]) * stoi(match[2]));
    }

    return total;
}

vector<string> get_splits(string& line, int start = 0){
    bool is_enabled = true; // do is the last command
    vector<string> ret;
    string delimiter = "don't()";
    int end = 0;

    while (end != string::npos){
    end = line.find(delimiter, start);
    // cout << end << endl;
    if(is_enabled){
        delimiter = "do()";
        is_enabled = false;
        ret.push_back(line.substr(start, end-start));
        start = end; // + delimiter.length();
    } else {
        delimiter = "don't()";
        is_enabled = true;
        start = end; // + delimiter.length();
    }
    }
    return ret;
}

int main()
{
    ifstream file("input.txt");

    smatch matches;
    string line;
    int ret = 0;
    while (getline(file, line))
    {
        vector<string> splits = get_splits(line);
        for (auto x: splits){
            cout << x << endl;
            ret += get_chunk_total(x);
        }
    }
    cout << ret << endl;
    return 1;
}