#include <iostream>

using namespace std;

void SelectionSort(int *);

int main()
{
    int a[5];
    cout << "Enter 5 values: " << endl;
    for(int i=0; i<5;i++)
    {
        cout << i << ": ";
        cin >> a[i];
    }
    SelectionSort(&a[0]);
    for(int i=0;i<5;i++)
    {
        cout << a[i] << endl;
    }
}

void SelectionSort(int *a)
{
    int i,j,min_index;
    for(i=0;i<5;i++)
    {
        min_index=i;
        for(j=i+1;j<5;j++)
        {
            if(a[min_index] > a[j])
            {
             min_index=j;
            }
        }
        int temp=a[min_index];
        a[min_index]=a[i];
        a[i]=temp;
    }

}
