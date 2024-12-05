#include "../utils.cpp"

vector<int> split(string& line, char delimiter){
    vector<int> splits;
    istringstream stream(line);
    string token;

    while(getline(stream, token, delimiter)){
        splits.push_back(stoi(token));
    }

    return splits;
}

void parse_pages(vector<vector<int>>& pages){
    ifstream file("pages.txt");
    string line;
    while (getline(file, line)){
        vector<int> tokens = split(line, ',');
        pages.push_back(tokens);
    }
}

void parse_rules(map<int, vector<int>>& rules){
    ifstream file("rules.txt");

    string line;
    while (getline(file, line)){
        vector<int> tokens = split(line, '|');
        vector<int> t;
        vector<int> current_rules = map_get(rules, tokens[0], t);
        current_rules.push_back(tokens[1]);
        rules[tokens[0]] = current_rules;
    }

}

bool isvalid(map<int, vector<int>>& rules, vector<int>& page){
    vector<int> dummy = {-1};
    for(int it = page.size() - 1; it > 0; it--){
        vector<int> prev(page.begin(), page.begin() + it);
        vector<int> rule = map_get(rules, page[it], dummy);
        for(int v: rule){
            auto f = find(prev.begin(), prev.end(), v);
            if (f != prev.end()){
                return false;
            }
        }   
    }
    return true;
}

int main(){
map<int, vector<int>> rules;
vector<vector<int>> pages;

parse_rules(rules);
parse_pages(pages);

int ret = 0;

for(vector<int> page: pages){
    if(isvalid(rules, page)){
        ret += page[(int)((page.size()) / 2)];
    }
}
cout << ret << endl;

}