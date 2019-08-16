#include <iostream>

using namespace std;

int main()
{
    int count,noOfCoins;
    cout << "Enter amount: ";
    cin >> count;
    cout << "Enter number of coins: ";
    cin >> noOfCoins;
    int d[noOfCoins];
    for(int i = 0; i < noOfCoins; i++)
        cin >> d[i];
    int c[noOfCoins][count+1];
    for(int i = 0; i < count+1; i++)
        c[0][i] = i;
    for(int i = 1; i < noOfCoins; i++)
    {
        for(int j = 0; j < count+1; j++)
        {
            if( c[i-1][j] < (1 + c[i][j - d[i]]) )
                c[i][j] = c[i-1][j];
            else
                c[i][j] = 1 + c[i][ j - d[i] ];
        }
    }
    for(int i = 0; i < noOfCoins; i++)
    {
        for(int j = 0; j < count+1; j++)
        {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}
