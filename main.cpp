#include <bits/stdc++.h>
using namespace std;
void merge_sort(vector<int>&a,int l,int r);
void merge(vector<int>&a,int l,int mid,int r);
int main() {
    int t;
    // open a file in write mode.
    ofstream outfile;
    outfile.open("/home/mostafaeltawy/college/3rd year/term 2/Parallel/Lab4/output");
    ofstream logfile;
    logfile.open("/home/mostafaeltawy/college/3rd year/term 2/Parallel/Lab4/logs");

    // open a file in read mode.
    ifstream infile;
    infile.open("/home/mostafaeltawy/college/3rd year/term 2/Parallel/Lab4/input");
    infile>>t;
    outfile<<"number of sample runs = "<<t<<endl;
    while(t--) {
        int n;vector<int>a;
        int padding=0;int tmp;
        int thread_num;
        vector<thread>threads;
        infile >> n;
        //taking (p) from user
        infile >> thread_num;
        //taking data
        for (int i = 0; i < n; i++) {
            infile >> tmp;
            a.push_back(tmp);
        }
        //if n is not divisible by number of threads
        // use padding
        if (n % thread_num != 0) {
            padding = (n / thread_num + 1) * thread_num - n;
            int padded_element = *max_element(a.begin(), a.end()) + 1;
            for (int i = 0; i < padding; i++) {
                a.push_back(padded_element);
            }
        }
        //computing chunk size of each tread
        int chunk = (n + padding) / thread_num;
        //lamda used to assign each thread to
        // it's respective part of array
        //taking all elements of scope by reference
        // @parameter tid--> thread id
        // used to know which part of array he will sort
        auto start_sort = [&](const int tid) -> void {
            logfile << "thread " << tid << " started sorting" << endl;
            int left = tid * chunk;
            int right = (tid + 1) * chunk - 1;
            //start merge sort for each thread
            merge_sort(a, left, right);
            logfile << "thread " << tid << " finished" << endl;
        };
        //passing lamda function and parameter thread id
        for (int i = 0; i < thread_num; i++) {
            threads.emplace_back(start_sort, i);
        }
        //waiting for all threads to finish
        for (auto &thread: threads) {
            thread.join();
        }
        //merging final results
        for (int i = 1; i < thread_num; i++) {
            merge(a, 0, chunk * i - 1,  chunk * (i+1) - 1);
        }
        //output array
        outfile << "n= " << n << endl << "p= " << thread_num << endl;
        outfile << "array sorted: " << endl;
        for (int i = 0; i < n; i++) {
            outfile << a[i] << " ";
        }
        outfile << endl << endl;
    }
    infile.close();outfile.close();logfile.close();
    return 0;
}
void merge_sort(vector<int>&a,int l,int r){
    //check if end>begin i.e if it can be divided more
    if(r>l){
        //recursively divide array
        // into left and right section
        int mid = (r+l)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,r);
        //merge subarrays
        merge(a,l,mid,r);
    }
}
void merge(vector<int>&a,int l, int mid, int r){
    //initalize left and right subarray
    vector<int> l_arr(mid-l+1,0);
    vector<int> r_arr(r-mid,0);
    int l_idx=0;
    int r_idx=0;
    int a_idx=l;
    int l_ctr=0,r_ctr=0;
    //filling vectors from original vector a
    for(int i=l;i<mid+1;i++){
        l_arr[l_ctr++] = a[i];
    }
    for(int i=mid+1;i<r+1;i++){
        r_arr[r_ctr++] = a[i];
    }
    //for each element in a
    // put min(l_arr[l_idx],r_arr[r_idx])
    while(l_idx<l_arr.size() && r_idx<r_arr.size()){
        if(l_arr[l_idx]<r_arr[r_idx]){
            a[a_idx++]=l_arr[l_idx++];
        }
        else{
            a[a_idx++]=r_arr[r_idx++];
        }
    }
    //put remaining elements
    while(l_idx<l_arr.size()){
        a[a_idx++]=l_arr[l_idx++];
    }
    while(r_idx<r_arr.size()){
        a[a_idx++]=r_arr[r_idx++];
    }
}
