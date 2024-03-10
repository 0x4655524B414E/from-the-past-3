#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n, q;
    cin >> n >> q;
    int *row[n];
    for (int i = 0; i < n; i++) 
    {
        int k;
        cin >> k;
        int *column[k];
        row[i] = *column;
        for (int j = 0; j < k; j++) 
        {
            int hold;
            cin >> hold;
            row[i][j] = hold; 
        }
    }
    int solut[q];
    for (int i = 0; i < q; i++)
    {
        int hold1;
        int hold2;
        cin >> hold1 >> hold2;
        solut[i] = row[hold1][hold2]; 
    }
    for (int i = 0; i < q; i++) 
    {
        cout << solut[i] << endl;
    }
    return 0;
}
