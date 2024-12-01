#include<iostream>
#include<fstream>
#include<map>
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
template <typename T, typename U>
U map_get(const map<T, U>& m, const T& key, const U& fallback){
    auto it = m.find(key);
    if (it != m.end()){
        return it->second;
    }
    return fallback;
}

int main(){
vector<int> left, right;
map<int, int> counts;
readfile(left, right);

for(int v: right){
    counts[v] = map_get(counts, v, 0) + 1;
}

int sum = 0;

for(int v: left){
    sum += v * map_get(counts, v, 0);
}

cout << sum << endl;
return 0;
}