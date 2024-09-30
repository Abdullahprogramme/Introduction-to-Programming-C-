#include <iostream>
#include <vector>
using namespace std;

void Up_Pyramid( int n ) {
   for (int i = 1; i <= n; i++) {
       for (int j = n - i; j > 0; j--) {
           cout << ' ';
       }
       for (int j = 0; j < i * 2 - 1; j++) {
           cout << '*';
       }
       cout << endl;
   }
} 

void Down_Pyramid( int n ) {
    for (int i = n; i > 0; i--) {
        for (int j = n - i; j > 0; j--) {
            cout << ' ';
        }
        for (int j = 2 * i - 1; j > 0; j--) {
            cout << '*';
        }
        cout << endl;
    }
}

void Floyd_Tri( int n ) {
    int val = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << val << ' ';
            val++;
        }
        cout << endl;
    }
}

void Zig_Zag( int n ) {
    int col = 3 * (n - 1);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= col; j++) {
            if ( (i + j) % 4 == 0 ||  (i == 2 && j & 4 == 2) ) {
                cout << '*';
            } else cout << ' ';
        }
        cout << endl;
    }
}

void Butterfly( int n ) {
    // upper half
    for (int i = 1; i <= n; i++) {
        for (int j = i; j > 0; j--) {
            cout << '*';
        }
        for (int j = (2 * n - 2 * i); j > 0; j--) {
            cout << ' ';
        } 
        for (int j = i; j > 0; j--) {
            cout << '*';
        }
        cout << endl;
    }
     
    // lower half
    for (int i = n - 1; i > 0; i--) {
        for (int j = i; j > 0; j--) {
            cout << '*'; 
        }
        for (int j = (2 * n - 2 * i); j > 0; j--) {
            cout << ' ';
        }
        for (int j = i; j > 0; j--) {
            cout << '*';
        }
        cout << endl;
    }
}

void Binary_Tri( int n ) {
    for (int i = 1; i <= n; i++) {
        int val = i % 2;
        for (int j = 1; j <= i; j++) {
            cout << val << ' ';
            val = 1 - val;
        }
        cout << endl;
    }
}

void Pascal_Tri( int n ) {
    for (int i = 0; i < n; i++) {
        int val = 1;
        for (int j = 1; j < n - i; j++) {
            cout << ' ';
        }
        for (int j = 0; j <= i; j++) {
            cout << val << ' ';
            val = val * (i - j) / (j + 1);
        }
        cout << endl;
    }
}

void hourglassPattern(int rows) {
    int n = rows;
    
    // Upper part of the hourglass
    for (int i = n; i >= 1; i--) {
        for (int space = n - i; space > 0; space--) {
            cout << " ";
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    // Lower part of the hourglass
    for (int i = 2; i <= n; i++) {
        for (int space = n - i; space > 0; space--) {
            cout << " ";
        }
        for (int j = 1; j <= (2 * i - 1); j++) {
            cout << "*";
        }
        cout << endl;
    }
}

vector<int> spiral_array_reader( vector<vector<int>> spiral) {
    vector<int> result;
    int rows = spiral.size();
    int cols = spiral[0].size();
    int top = 0;
    int bottom = rows - 1;
    int left = 0;
    int right = cols - 1;
    int dir = 0;
    while (top <= bottom && left <= right) {
        if (dir == 0) {
            for (int i = left; i <= right; i++) {
                result.push_back(spiral[top][i]);
            }
            top++;
        } else if (dir == 1) {
            for (int i = top; i <= bottom; i++) {
                result.push_back(spiral[i][right]);
            }
            right--;
        } else if (dir == 2) {
            for (int i = right; i >= left; i--) {
                result.push_back(spiral[bottom][i]);
            }
            bottom--;
        } else if (dir == 3) {
            for (int i = bottom; i >= top; i--) {
                result.push_back(spiral[i][left]);
            }
            left++;
        }
        dir = (dir + 1) % 4;
    }
    return result;
}

#include <vector>
using namespace std;

vector<int> spiral_array_reader_from_middle(vector<vector<int>> spiral) {
    vector<int> result;
    int rows = spiral.size();
    int cols = spiral[0].size();
    
    int mid_row = rows / 2;
    int mid_col = (cols % 2 == 0) ? cols / 2 - 1 : cols / 2;

    int top = mid_row;
    int bottom = mid_row;
    int left = mid_col;
    int right = mid_col;

    int dir = 0;
    result.push_back(spiral[mid_row][mid_col]);

    while (top > 0 || left > 0 || bottom < rows - 1 || right < cols - 1) {
        if (dir == 0) { // Move up
            if (top > 0) {
                top--;
                for (int i = right; i >= left; i--) {
                    result.push_back(spiral[top][i]);
                }
            }
        } else if (dir == 1) { // Move right
            if (right < cols - 1) {
                right++;
                for (int i = top; i <= bottom; i++) {
                    result.push_back(spiral[i][right]);
                }
            }
        } else if (dir == 2) { // Move down
            if (bottom < rows - 1) {
                bottom++;
                for (int i = left; i <= right; i++) {
                    result.push_back(spiral[bottom][i]);
                }
            }
        } else if (dir == 3) { // Move left
            if (left > 0) {
                left--;
                for (int i = bottom; i >= top; i--) {
                    result.push_back(spiral[i][left]);
                }
            }
        }
        dir = (dir + 1) % 4;
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the number of rows: ";
    cin >> n;
    Up_Pyramid(n);
    cout << endl;
    Down_Pyramid(n);
    cout << endl;
    Floyd_Tri(n);
    cout << endl;
    Zig_Zag(n);
    cout << endl;
    Butterfly(n);
    cout << endl;
    Binary_Tri(n);
    cout << endl;
    Pascal_Tri(n);
    cout << endl;
    hourglassPattern(n);

    vector<vector<int>> spiral = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    vector<int> result = spiral_array_reader(spiral);
    cout << '[';
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << (i == result.size() - 1 ? "" : ", ");
    }
    cout << ']' << endl;

    vector<int> result2 = spiral_array_reader_from_middle(spiral);
    cout << '[';
    for (int i = 0; i < result2.size(); i++) {
        cout << result2[i] << (i == result2.size() - 1 ? "" : ", ");
    }
    cout << ']' << endl;


    return 0;
}