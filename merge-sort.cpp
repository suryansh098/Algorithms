#include <vector>
#include <iostream>
using namespace std;

void mergeArray(vector<int> &arr, int low, int mid, int high) {
    int i=low, j=mid+1, k=low;
    vector<int> temp(arr.size());

    // merged left and right sub-arrays in sorted manner
    while(i<=mid && j<=high) {
        // if left has smaller element, add it to temp
        if(arr[i] < arr[j]) {
            temp[k] = arr[i];
            i++;
        }
        // else if right has smaller element, add it to temp
        else {
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    // if left sub-array still has some elements
    // this is the case when left sub-array has more elements than right sub-array
    while(i <= mid) {
        temp[k] = arr[i];
        i++;
        k++;
    }

    // if right sub-array still has some elements
    // this is the case when right sub-array has more elements than left sub-array
    while(j <= high) {
        temp[k] = arr[j];
        j++;
        k++;
    }

    // finally update changes in the original array
    for(int s=low; s<=high; s++) {
        arr[s] = temp[s];
    }
}

void mergeSort(vector<int> &arr, int low, int high) {
    int mid;

    if(low < high) {
        // find mid
        mid = (low+high)/2;

        // keep dividing array till it has only one element
        // since a single elemnet is always sorted
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);

        // start merging array such that the merged array is sorted
        mergeArray(arr, low, mid, high);
    }
}

int main() {
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }

    mergeSort(v, 0, n-1);
    cout<<"Output : \n";
    for(int i=0; i<n; i++) {
        cout<<v[i]<<" ";
    }
}
