#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const vector<char> steps = {'X', 'M', 'A', 'S'};

void backtrack(vector<vector<char>> &grid, int rownum, int colnum, int &maxrow, int &maxcol, int step, int& stepX, int& stepY, int &total_found)
{
    if (rownum >= maxrow || rownum < 0)
        return;

    if (colnum >= maxcol || colnum < 0)
        return;

    if (grid[rownum][colnum] == steps[step]){
        if (step == 3){
            ++total_found;
            return;
        }
        
        backtrack(grid, rownum+stepX, colnum+stepY, maxrow, maxcol, step+1, stepX, stepY, total_found);
    }
    return;
}

int main()
{
    int ret = 0;
    vector<vector<char>> grid;
    ifstream file("input.txt");
    string line;
    while (getline(file, line))
    {
        vector<char> temp;
        for (char x : line)
        {
            temp.push_back(x);
        }
        grid.push_back(temp);
    }

    int maxrow = grid.size();
    int maxcol = grid[0].size();

    int rownum = 0;
    int colnum = 0;
    int step = 0;

    for (rownum = 0; rownum < maxrow; rownum++){
        for (colnum = 0; colnum < maxcol; colnum++){
            if (grid[rownum][colnum] == steps[step]){
                for (int i = -1; i <= 1; i++){
                   for (int j = -1; j <= 1; j++){
                    if(i == 0 && j == 0){
                        continue;
                    }
                    backtrack(grid, rownum, colnum, maxrow, maxcol, step, i, j, ret);
                    }
                }
            }
        }
    }
    cout << ret << endl;
    return 0;
}