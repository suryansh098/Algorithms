#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Data class for storage
class Data {
    public:
     float value; // given value
     float weight; // given quantity
     float avg; // value per quantity

    // constructor
    Data(float val, float wt) {
        value = val;
        weight = wt;
        avg = (val/wt);
    }
};

// comaparator function for sorting
bool compareData(Data *left, Data *right) {
    return (left->avg > right->avg);
}

float fractionalKnapsack(vector<float> &vals, vector<float> &wts, int n, float maxLimit) {
    // declare data
    vector<Data*> data(n);

    // initialize data
    for(int i=0; i<n; i++) {
        data[i] = new Data(vals[i], wts[i]);
    }

    // sort it in descending order
    sort(data.begin(), data.end(), compareData);

    // result
    float total = 0;

    // iterate over data
    for(int i=0; i<n; i++) {

        // if limit == 0 break
        if(maxLimit == 0)
            break;

        Data *curr = data[i];

        // if weight is greater than or equal to maxLimit
        // use it as a whole
        if((maxLimit - curr->weight) >= 0) {
            total += curr->value;
            maxLimit -= curr->weight;
        }
        // otherwise use its fraction
        else {
            total += maxLimit*curr->avg;
            maxLimit = 0;
        }
    }

    // return result
    return total;
}

int main() {
    int n;
    cin>>n;

    // input values
    vector<float> v(n);
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }

    // input weights
    vector<float> w(n);
    for(int i=0; i<n; i++) {
        cin>>w[i];
    }

    // input limit
    float limit;
    cin>>limit;

    // find and print output
    float result = fractionalKnapsack(v, w, n, limit);
    cout<<result;
}
