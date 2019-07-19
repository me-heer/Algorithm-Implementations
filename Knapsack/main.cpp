#include <iostream>

using namespace std;

void SelectionSort(float ratio[],int w[], int v[],int size)
{
    int i,j,max_index;
    for(i=0;i<size;i++)
    {
        max_index=i;
        for(j=i+1;j<5;j++)
        {
            if(ratio[max_index] < ratio[j])
            {
             max_index=j;
            }
        }
        float temp=ratio[max_index];
        int tempW = w[max_index];
        int tempV = v[max_index];

        ratio[max_index]=ratio[i];
        w[max_index] = w[i];
        v[max_index] = v[i];

        ratio[i]=temp;
        w[i]=tempW;
        v[i]=tempV;
    }

}

int main()
{
    int size;
    cout << "Enter size of the array: "; cin >> size;
    cout << "Enter the weight array: " << endl;
    int w[size],v[size];
    for(int i = 0; i < size; i++)
        cin >> w[i];
    cout << "Enter the value array: " << endl;
    for(int i = 0; i < size; i++)
        cin >> v[i];
    float ratio[size];
    for(int i = 0; i < size; i++)
        ratio[i] = (float)v[i]/w[i];
    SelectionSort(ratio,w,v,size);
    int weightLimit;
    cout << "Enter weight limit: ";  cin >> weightLimit;
    int currentWeight = 0, currentValue = 0, i = -1;
    while( (currentWeight <= weightLimit) &&  (i++ < size) )
    {
        if( (w[i] + currentWeight) <= weightLimit )
        {
            currentWeight = currentWeight + w[i];
            currentValue = currentValue + v[i];
        }
        else
            break;
    }
    int tempWeight = weightLimit - currentWeight;
    float tempValue = ( (float)v[i]/(float)w[i] ) * tempWeight;
    tempValue += currentValue;
    cout << "Total Value: " << tempValue << endl;
}

