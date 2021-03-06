//MERGE SORT IMPLEMENTATION
#include <iostream>
using namespace std;
int count=0;

void merge(int arr[], int low, int mid, int high)
{
    int n1=mid - low + 1;
    int n2=high - mid;

    int L[n1], R[n2];

    for(int i = 0; i < n1; i++)
        L[i] = arr[low + i];
    for(int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i=0,j=0,k=low;

    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
            arr[k]=L[i],i++;
        else
            arr[k]=R[j],j++;

        count++;
        k++;
    }

    while (i < n1)
    {
        arr[k]=L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[],int low,int high){
    if(low>=high)
        return;

    int m=low+(high-low)/2;
    mergeSort(arr,low,m);
    mergeSort(arr,m+1,high);
    merge(arr,low,m,high);
}


int main()
{
    int size;
    cout<<"Enter The Size Of Array : ";
    cin>>size;
    int arr[size];
    cout<<"\nEnter the Elements : ";
    for(int i=0; i<size; i++)
        cin>>arr[i];
    mergeSort(arr, 0, size - 1);
    cout << "\nSorted Array Is : ";
    for (int i = 0; i<size; i++){
        if(i>0 && i<size)
			cout<<",";
        cout << arr[i] << " ";
    }
    cout<<"\nNo. of comparisons made: "<<count<<endl;
    return 0;
}