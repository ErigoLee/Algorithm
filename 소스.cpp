#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool find(vector<vector<int>> key, vector<vector<int>> block,int temp_row,int temp_col)
{
    vector<vector<int>> checked_block;

    int block_size = block.size();
    int key_size = key.size();
    for (int i = 0; i < block_size; i++) {
        vector<int> temp;
        for (int j = 0; j < block_size; j++) {
            if ((temp_row <= j && j < temp_row + key_size) && (temp_col <= i && i < temp_col + key_size)) {
                temp.push_back(block[i][j] + key[i - temp_col][j - temp_row]);
            }
            else {
                temp.push_back(block[i][j]);
            }
        }
        checked_block.push_back(temp);
    }

    for (int i = key_size; i < block_size - key_size; i++) {
        for (int j = key_size; j < block_size - key_size; j++) {
            if (checked_block[i][j] == 0 || checked_block[i][j] == 2) {
                
                return false;
            }
               
        }
    }
  
    return true;

}



bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = true;
    int key_size = key.size(); //열

    vector<vector<vector<int>>> key_set;
    key_set.push_back(key);

    //오른쪽 90도
    vector<vector<int>> key_rot90;
    for (int i = key_size-1; i > -1; i--) {
        vector<int> tempo;
        for (int j = 0; j <key_size; j++) {
            tempo.push_back(key[j][i]);
        }
        key_rot90.push_back(tempo);
        tempo.clear();
    }
    key_set.push_back(key_rot90);
    
    //오른쪽 180도
    vector<vector<int>> key_rot180;
    for (int i = key_size - 1; i > -1; i--) {
        vector<int>tempo;
        for (int j = key_size - 1; j > -1; j--) {
            tempo.push_back(key[i][j]);
        }
        key_rot180.push_back(tempo);
        tempo.clear();
    }
    key_set.push_back(key_rot180);
    
    //오른쪽 270도
    vector<vector<int>> key_rot270;
    for (int i = 0; i < key_size; i++) {
        vector<int>tempo;
        for (int j = key_size - 1; j > -1; j--) {
            tempo.push_back(key[j][i]);
        }
        key_rot270.push_back(tempo);
        tempo.clear();
    }
    key_set.push_back(key_rot270);
    
    int lock_size = lock.size();
    vector<vector<int>> block;

    for (int i = 0; i < key_size * 2 + lock_size; i++)
    {
        vector<int> row;
        for (int j = 0; j < key_size * 2 + lock_size; j++) {
            if ((i >= key_size && i <= key_size + lock_size - 1) && (j >= key_size && j <= key_size + lock_size - 1)) {
                row.push_back(lock[i-key_size][j-key_size]);
            }
            else {
                row.push_back(0);
            }
        }
        block.push_back(row);
        row.clear();
    }





    int key_set_size = key_set.size();
    for (int i = 0; i < key_set_size; i++) {
        for (int j = 0; j <= lock_size + key_size; j++) {
            for (int k = 0; k <= lock_size + key_size; k++) {
                answer = find(key_set[i], block, j, k);
                if (answer == true) {
                    return answer;
                }
            }
        }
    }

    return answer;
}

int main() {
    int key_array[3][3] = { {0,0,0},{1,0,0},{0,1,1} };
    int lock_array[3][3] = { {1,1,1},{1,1,0},{1,0,1} };
    vector<vector<int>> key;
    vector<vector<int>> lock;

    for (int i = 0; i < 3; i++) {
        vector<int> row;
        vector<int> row2;
        for (int j = 0; j < 3; j++) {
            row.push_back(key_array[i][j]);
            row2.push_back(lock_array[i][j]);
        }
        key.push_back(row);
        lock.push_back(row2);
        row.clear();
        row2.clear();
    }

    bool answer = solution(key,lock);
    cout << answer << endl;
    return 0;
}