#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int simulate(int D) 
{
    int n = (1 << D); 
    vector<bool> node(n, false); 

    int pos = 1; 
    for (int i = 0; i < D - 1; ++i) 
    { 
        if (!node[pos]) 
        {
            node[pos] = true;      
            pos = pos * 2;         
        }
        else 
        {
            node[pos] = false;     
            pos = pos * 2 + 1;     
        }
    }
    return pos;
}

int main() 
{
    int T; 
    cin >> T;
    while (T--) 
    {
        int D, I; 
        cin >> D >> I;
        int result = 0;
        for (int i = 0; i < I; ++i) 
        {
            result = simulate(D);
        }
        cout << result << endl;
    }
    return 0;
}
