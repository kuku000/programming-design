#include <iostream>


using namespace std;


void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int *arr, int front, int end){
    int pivot = arr[end];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}
void QuickSort(int *arr, int front, int end){
    if (front < end) {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}
int binarySearch( int a[], int v, int l, int r)
{
    if(l>r)
        return -1;
    int mid=(l+r)/2;
    if(a[mid] == v)
        return mid;
    if (v < a[mid])
        return binarySearch(a,v,l,mid-1);
    else
        return binarySearch(a,v,mid+1,r);
    
}

int main()
{
    int searchKey;
    cout<<"Please enter 20 integers"<<endl;
    int a[20];
    for(int i=0;i<20;i++)
    {
        cin>>a[i];
    }
    QuickSort(a,0,19);
    cin>>searchKey;
    int element=binarySearch(a,searchKey,0,19);
    if(element!=-1)
        cout<<"Found value in element after sorting "<<element<<endl;
    else
        cout<<"Value not found "<<endl;
}
