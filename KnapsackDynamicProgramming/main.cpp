#include <iostream>

using namespace std;


int main()
{
    int size;
    cout << "Enter size of the array: "; cin >> size;
    cout << "Enter the weight array: " << endl;
    int w[size],v[size];
    for(int i = 0; i < size; i++)
        cin >> w[i];
    cout << "Enter the value array: " << endl;
    for(int i = 0; i < size; i++)
        cin >> v[i];
    int weightLimit;
    cout << "Enter weight limit: ";  cin >> weightLimit;
    int knapsack[size+1][weightLimit+1];
    for(int i = 0; i < weightLimit + 1; i++)
        knapsack[0][i] = 0;
    for(int i = 0; i < size+1; i++)
        knapsack[i][0] = 0;
    for(int i = 1; i < size+1; i++)
    {
        for(int j = 1; j < weightLimit + 1; j++)
        {
            if(j >= w[i-1]) //if our currentWeight is eligible to be picked up
            {
                if( knapsack[i-1][j] > (v[i-1] + knapsack[i-1][j - w[i-1]]) )
                {
                    knapsack[i][j] = knapsack[i-1][j];
                }
                else
                    knapsack[i][j] = v[i-1] + knapsack[i-1][ j - w[i-1] ];
            }
            else
                knapsack[i][j] = knapsack[i-1][j];
        }
    }
    //print the whole thing
    for(int i = 0; i < size+1; i++)
    {
        for(int j = 0; j < weightLimit + 1; j++)
        {
            cout << knapsack[i][j] << " ";
        }
        cout << endl;
    }
}
