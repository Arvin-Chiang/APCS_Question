#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<vector<int>> matrix(n, vector<int>(n));
        vector<int> rowSum(n, 0), colSum(n, 0);

    
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                cin >> matrix[i][j];
                rowSum[i] += matrix[i][j];
                colSum[j] += matrix[i][j];
            }

        int rowErr = -1, colErr = -1;
        for (int i = 0; i < n; ++i) {
            if (rowSum[i] % 2 != 0) {
                if (rowErr == -1) rowErr = i;
                else rowErr = -2;
            }
            if (colSum[i] % 2 != 0) {
                if (colErr == -1) colErr = i;
                else colErr = -2; 
            }
        }

        
        if (rowErr == -1 && colErr == -1) {
            cout << "OK" << endl;
        }
        else if (rowErr >= 0 && colErr >= 0) {
            cout << "Change bit (" << rowErr + 1 << "," << colErr + 1 << ")" << endl;
        }
        else {
            cout << "Corrupt" << endl;
        }
    }

    return 0;
}

