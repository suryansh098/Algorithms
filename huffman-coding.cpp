#include <bits/stdc++.h>
using namespace std;

// This class represents each node of the min heap
class MinHeapNode {
    public:

    char data;  // chararcter
    int freq;   // frequency
    MinHeapNode *left, *right; // left & right child

    // default constructor
    MinHeapNode() {
        data = '$';
        freq = 0;
        left = right = nullptr;
    }

    // initialize value node value
    MinHeapNode(char data, int freq) {
        this->data = data;
        this->freq = freq;
        left = right = nullptr;
    }
};

// This comparator will be used for creating min heap
class compare {
    public:
    bool operator()(MinHeapNode* l, MinHeapNode* r) {
        // if left freq > right freq return true
        // else false
        return (l->freq > r->freq);
    }
};

// utility function for printing heap
void printCodes(MinHeapNode* root, string str) {
    // if root == null then return
    if(!root)
        return;

    // if current node is not a internal node
    // print its code
    if(root->data != '$')
        cout<<root->data<<" : "<<str<<endl;

    // according to huffman code
    // moving left adds 0 to the code
    printCodes(root->left, str + "0");
    // moving right adds 1 to the code
    printCodes(root->right, str + "1");
}

void findHuffmanCodes(vector<char> &data, vector<int> &freq, int n) {
    MinHeapNode *first, *second, *top;

    // initailize priority queue [min-heap]
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> pq;
    for(int i=0; i<n; i++)
        pq.push(new MinHeapNode(data[i], freq[i]));

    // iterate over all nodes
    while(pq.size() != 1) {

        // pop first minimum
        first = pq.top();
        pq.pop();

        // pop second minimum
        second = pq.top();
        pq.pop();

        // make internal node by adding two minimums
        top = new MinHeapNode('$', first->freq + second->freq);
        top->left = first;
        top->right = second;

        // push the node to pq
        pq.push(top);
    }

    // print the codes created using huffman coding
    printCodes(pq.top(), "");
}

int main() {
    int n;
    cin>>n;

    vector<char> data(n);
    vector<int> freq(n);
    for(int i=0; i<n; i++) {
        cin>>data[i];
        cin>>freq[i];
    }

    cout<<"\nOutput :\n";
    findHuffmanCodes(data, freq, n);
}
