#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class MaxMin {
    public:
    int max;
    int min;

    MaxMin() {
        max = INT_MIN;
        min = INT_MAX;
    }

    // Divide and Conquer Approach of finding max-min of the array
    MaxMin findMaxMin(vector<int> &a, int l, int h) {
        MaxMin res;

        // when array has only one element
        if(l==h) {
            res.max = res.min = a[l];
        }

        // when array has two elements
        else if(l==h-1) {
            if(a[l] < a[h]) {
                res.max = a[h];
                res.min = a[l];
            }
            else {
                res.max = a[l];
                res.min = a[h];
            }
        }

        // when array has more than two elements
        else {
            int mid = (l+h)/2;
            MaxMin x, y;

            // divide the array from mid and find max-min of both sub-arrays
            x = findMaxMin(a, l, mid);
            y = findMaxMin(a, mid+1, h);

            // assign the maximum and minimum of both to res
            if(x.max > y.max)
                res.max = x.max;
            else
                res.max = y.max;
            if(x.min < y.min)
                res.min = x.min;
            else
                res.min = y.min;
        }

        return res;
    }
};

int main() {
    int n;
    cin>>n;

    vector<int> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }

    MaxMin obj;
    obj = obj.findMaxMin(v, 0, n-1);

    cout<<"Output : \n";
    cout<<"Max : "<<obj.max;
    cout<<"\nMin : "<<obj.min;

}
