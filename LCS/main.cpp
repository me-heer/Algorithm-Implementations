#include <iostream>

using namespace std;

int main()
{
    string inputString, subsequenceString;
    cout << "Enter Input String: ";
    cin >> inputString;
    cout << "Enter Subsequence String: ";
    cin >> subsequenceString;
    int inputStringLength = inputString.length();
    int subsequenceStringLength = subsequenceString.length();
    int lcsArray[inputStringLength+1][subsequenceStringLength+1] = {0};
    for(int i = 0; i < 1; i++)
        for(int j = 0; j < subsequenceStringLength + 1; j++)
            lcsArray[i][j] = 0;

    for(int i = 0; i < inputStringLength + 1; i++)
            lcsArray[i][0] = 0;
    int i,j;
    for(i = 1; i <= inputStringLength; i++)
    {
        for(j = 1; j <= subsequenceStringLength; j++)
        {
            if(inputString[i-1] == subsequenceString[j-1])
                lcsArray[i][j] = 1 + lcsArray[i-1][j-1];
            else
            {
                if(lcsArray[i-1][j] > lcsArray[i][j-1])
                    lcsArray[i][j] = lcsArray[i-1][j];
                else
                    lcsArray[i][j] = lcsArray[i][j-1];
            }
        }
    }
    bool foundZero = false;
    int lcsIndex = 0;
    string longestCommonSubsequence;
    while(!foundZero)
    {
        if(lcsArray[i][j] == 0)
        {
            foundZero = true;
            break;
        }
        if(inputString[i-1] == subsequenceString[j-1])
        {
            longestCommonSubsequence[lcsIndex++] = inputString[i-1];
            i--; j--;
            continue;
        }
        if(lcsArray[i-1][j] >= lcsArray[i][j-1])
        {
            i--; continue;
        }
        if(lcsArray[i-1][j] < lcsArray[i][j-1])
        {
            j--; continue;
        }
    }

    for(i = lcsIndex - 1; i >= 0; i--)
        cout << longestCommonSubsequence[i];
    /*
    for(int i = 0; i < inputStringLength + 1; i++)
    {
        for(int j = 0; j < subsequenceStringLength + 1; j++)
        {
            cout.width(2);
            cout << lcsArray[i][j];
        }
        cout << endl;
    }
    */

}
