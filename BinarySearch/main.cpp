#include <iostream>

using namespace std;

int BinarySearch(int arr[],int left, int right,int findElement)
{
    if(left < right)
    {
//      int mid = (left + right)/2; (dont use as overflow from int might happen)
        int mid = left + ((right - left)/2);
        int elementIndex;
        if(findElement == arr[mid])
            return mid;
        else if( findElement < arr[mid])
            elementIndex = BinarySearch(arr,left,mid-1,findElement);
        else
            elementIndex = BinarySearch(arr,mid+1,right,findElement);
    }
    else
        cout << "NOT FOUND." << endl;
}

int main()
{
    int arr[] = {11,12,13,14,15,16,17,18,19,20};
    int size = sizeof(arr)/sizeof(arr[0]);
    int index = BinarySearch(arr,0,size-1,15);
    if(index >=0 && index <=(size-1))
        cout << "Element found at : " << index << endl;
}
