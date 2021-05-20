#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// class defining a job
class Job {
    public:
      char id;      // job id
      int profit;   // profit from job
      int dead;     // deadline
};

// comparator function for sorting
bool compareJob(Job a, Job b) {
    return (a.profit > b.profit);
}

void jobSequencing(vector<Job> &job, int n) {

    // sort the jobs in descending profit
    sort(job.begin(), job.end(), compareJob);

    // initialize all slots as false
    vector<bool> slot(n, false);

    // result stores id in booked slot
    vector<char> result(n);

    // iterate over all jobs
    for(int i=0; i<n; i++) {

        // find the slot from deadline to start point
        for(int j=job[i].dead-1; j>=0; j--) {

            // if slot  is available book the slot
            if(!slot[j]) {
                result[j] = job[i].id;
                slot[j] = true;
                break;
            }
        }
    }

    // iterate and find all booked slots
    for(int i=0; i<n; i++) {
        // print the sequence
        if(slot[i])
            cout<<"-> "<<result[i]<<" ";
    }
}

int main() {
    int n;
    cin>>n;

    vector<Job> job(n);
    // input profit
    for(int i=0; i<n; i++) {
        job[i].id = 'a' + i;
        cin>>job[i].profit;
    }

    // input deadline
    for(int i=0; i<n; i++)
        cin>>job[i].dead;

    jobSequencing(job, n);
}
