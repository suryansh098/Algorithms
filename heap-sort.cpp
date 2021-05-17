#include <iostream>
#include <vector>
using namespace std;

/*

[INFO] : Heap Sort

Time Complexity : O(nlogn)
Not a stable sort

*/
void heapify(vector<int> &a, int n, int i) {
    int root = i;
    int left = i*2;
    int right = i*2+1;

    // if left child is greater than root
    // make it root
    if(left < n && a[left] > a[root])
        root = left;

    // if right child is greater than root
    // make it root
    if(right < n && a[right] > a[root])
        root = right;

    if(root != i) {
        // swap current root (i) with the valid root (root)
        swap(a[i], a[root]);
        // apply heapify on reduced heap
        heapify(a, n, root);
    }
}

void heapSort(vector<int> &a, int n) {

    // convert the array into max-heap
    for(int i=(n-1)/2; i>0; i--)
        heapify(a, n, i);

    for(int i=n-1; i>1; i--) {
        // move current root to end
        swap(a[1], a[i]);
        // maintain the max-heap
        heapify(a, i, 1);
    }
}

int main() {
    int n;
    cin>>n;

    vector<int> v(n+1);
    for(int i=1; i<n+1; i++) {
        cin>>v[i];
    }

    heapSort(v, n+1);
    cout<<"Output : \n";
    for(int i=1; i<n+1; i++) {
        cout<<v[i]<<" ";
    }
}
