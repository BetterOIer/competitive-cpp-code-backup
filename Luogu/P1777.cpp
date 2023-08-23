#include<iostream>
#include<algorithm>
using namespace std;
int a[5000005];
void QuickSort(int array[], int low, int high) {
    if (low < high) {
        int i   = low;
        int j   = high;
        int key = array[i];
        while (i < j) {
            while (i < j && array[j] >= key) {
                j--;
            }
            if (i < j) {
                array[i] = array[j];
            }
            while (i < j && array[i] <= key) {
                i++;
            }
            if (i < j) {
                array[j] = array[i];
            }
        }
        array[i] = key;
        QuickSort(array, low, i - 1);
        QuickSort(array, i + 1, high);
    }
}
int main(){
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        cin>>a[i];
    }
    QuickSort(a,1,n);
    for(int i = 1;i<=n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
} 