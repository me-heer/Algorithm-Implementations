#include <iostream>

using namespace std;

void Combine(int arr[],int p,int q,int r)
{
    int i,j,k;
    int n1 = q-p+1;
    int n2 = r - q;
    int L[n1],R[n2];
    for(i=0; i < n1; i++)
    {
        L[i] = arr[p+i];
    }
    for(j=0; j < n2; j++)
    {
        R[j] = arr[q+j+1];
    }
    i=0; j=0;

    for(k = p;k <= r ; k++)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
    }
}


void MergeSort(int arr[],int p,int r)
{
    if(p<r)
    {
        int q = (p+r)/2;
        MergeSort(arr,p,q);
        MergeSort(arr,q+1,r);
        Combine(arr,p,q,r);
    }

}

int main()
{
    int arr[10];
    for(int i=0;i<10;i++)
    {
        cin >> arr[i];
    }
    MergeSort(arr,0,9);
    for(int i=0;i<10;i++)
    {
        cout << arr[i] << " ";
    }
}
