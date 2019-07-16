#include <iostream>

using namespace std;

void insertion_sort(int *);

int main()
{
    int a[5];
    cout << "Enter 5 elements: " << endl;
    for(int i=0;i<5;i++)
    {
        cout << i << ": ";
        cin >> a[i];
    }
    insertion_sort(&a[0]);
    for(int i=0;i<5;i++)
    {
        cout << a[i] <<endl;
    }
}

void insertion_sort(int *a)
{
    int i,j,temp;
    for(i=1;i<5;i++)
    {
        j=i-1;
        temp=a[i];
        while( j>=0 && a[j]>temp )
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1] = temp;
    }
}
