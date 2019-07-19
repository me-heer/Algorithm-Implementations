#include <iostream>

using namespace std;

int main()
{
    int availableCoins[] = {100,25,10,8,5,3,2,1};
    int acSize = sizeof(availableCoins)/sizeof(availableCoins[0]);
    int chosenCoins[acSize] = {0};
    int amount;
    cout << "Enter the amount: "; cin >> amount;
    int sum = 0, i = 0;
    while(sum != amount)
    {
        if( (sum + availableCoins[i]) <= amount )
        {
            sum = sum + availableCoins[i];
            chosenCoins[i]++;
        }
        else
            i++;
    }
    for(int i = 0; i < acSize; i ++)
        cout << availableCoins[i] << "s : " << chosenCoins[i] << " Total: " << availableCoins[i] * chosenCoins[i] << endl;

}
