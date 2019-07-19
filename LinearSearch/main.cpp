#include <iostream>

using namespace std;

int linearSearch(int arr[],int size,int findElement)
{
    for(int i = 0; i < size; i++)
    {
        if(arr[i] == findElement)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10};
    int size = sizeof(arr)/sizeof(arr[0]);
    int searchIndex = linearSearch(arr,size,7);
    if(searchIndex == -1)
        cout << "Not Found." << endl;
    else
        cout << "Element found at index: " << searchIndex << endl;
}
