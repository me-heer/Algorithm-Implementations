#include <iostream>

using namespace std;

void GreedyActivitySelector(int start[],int end[],int size)
{
    int selectedArr[size] = {0};
    selectedArr[0]++;
    int k = 0;
    for(int i = 1; i < size; i++)
    {
        if(start[i] >= end[k])
        {
            selectedArr[i]++;
            k=i;
        }
    }
    cout << "Selected Activities Indexes: ";
    for(int i = 0; i < size; i++)
        if(selectedArr[i]==1)
            cout << i;
}

int main()
{
    int size;
    cout << "Enter the size: "; cin >> size;
    int start[size] = {0,2,3,5,1,7,9,11};
    int end[size] = {4,6,7,8,8,11,12,13};
    cout << "Enter the starting times: ";
    for(int i = 0; i < size; i++)
        cin >> start[size];
    cout << "Enter the ending times: ";
    for(int i = 0; i < size; i++)
        cin >> end[size];
    GreedyActivitySelector(start,end,size);
}
