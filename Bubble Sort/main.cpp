#include <iostream>

using namespace std;

void BubbleSort(int *);

int main()
{
    int a[5];
    cout << "Enter 5 values: " << endl;
    for(int i=0; i<5;i++)
    {
        cout << i << ": ";
        cin >> a[i];
    }
    BubbleSort(&a[0]);
}

void BubbleSort(int *a)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
            if( a[j] > a[j+1] )
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }

    for(int i=0;i<5;i++)
    {
        cout << a[i] << endl;
    }
}
