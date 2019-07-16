#include <iostream>

using namespace std;

int Partition(int arr[],int p, int r)
{
    int temp = 0;
    int X = arr[r];
    int i = p-1;
    for(int j=p;j<=r-1;j++)
    {
        if(arr[j]<X)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = X;
    arr[r] = temp;
    return i+1;
}

void QuickSort(int arr[],int p,int r)
{
    if(p < r)
    {
        int q = Partition(arr,p,r);
        QuickSort(arr,p,q-1);
        QuickSort(arr,q+1,r);
    }
}


int main()
{
    int arr[] = {13,19,9,5,12,8,7,4,21,2,6,11};
    int arrSize = sizeof(arr)/sizeof(arr[0]);
    QuickSort(arr,0,arrSize-1);
    for(int i=0;i<arrSize;i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
