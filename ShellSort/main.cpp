#include <iostream>

using namespace std;

int main()
{
    int a[10]={0};
    cout << "Enter 10 elements: " << endl;
    for(int i=0;i<10;i++)
    {
        cin >> a[i];
    }
    int interval = 4,j,temp,z=4;
    while(interval > 0)
    {
        for(int m=0;m<10;m++)
        {
            for(int i=0+interval+m;i<10;i=i+interval)
            {
                j=i-interval;
                temp=a[i];
                while( j>=0 && a[j]>temp )
                {
                    a[j+interval]=a[j];
                    j=j-interval;
                }
                a[j+interval] = temp;
            }
        }
        interval = interval / 2;
    }
    for(int i=1;i<10;i++)
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
    cout << "Sorted: " << endl;
    for(int i=0;i<10;i++)
    {
        cout << a[i] <<" ";
    }
}
