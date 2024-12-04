#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

const vector<char> steps = {'X', 'M', 'A', 'S'};

bool check_arms(char c, vector<vector<char>> &grid, int rownum, int colnum, int &maxrow, int &maxcol){
    if (rownum >= maxrow || rownum < 0)
        return false;

    if (colnum >= maxcol || colnum < 0)
        return false;

    return grid[rownum][colnum] == c;
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
            if (grid[rownum][colnum] == 'A'){
                if(((check_arms('M', grid, rownum-1, colnum-1, maxrow, maxcol) && check_arms('S', grid, rownum+1, colnum+1, maxrow, maxcol)) || (check_arms('S', grid, rownum-1, colnum-1, maxrow, maxcol) && check_arms('M', grid, rownum+1, colnum+1, maxrow, maxcol)))
                
                &&
                
                ((check_arms('M', grid, rownum+1, colnum-1, maxrow, maxcol) && check_arms('S', grid, rownum-1, colnum+1, maxrow, maxcol)) || (check_arms('S', grid, rownum+1, colnum-1, maxrow, maxcol) && check_arms('M', grid, rownum-1, colnum+1, maxrow, maxcol))) )
                {
                    ++ret;
                }
            }
    }
    }
    cout << ret << endl;
    return 0;
}