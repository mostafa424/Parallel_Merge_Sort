#include <bits/stdc++.h>
using namespace std;
void merge_sort(vector<int>&a,int l,int r);
void merge(vector<int>&a,int l,int mid,int r);
int main() {
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    vector<int>a;
    int tmp;
    int thread_num;
    vector<thread>threads;
    cout<<"enter number of processing elements:";
    cin>>thread_num;
    cout<<"Enter array elements:"<<endl;
    for(int i=0;i<n;i++){
        cin>>tmp;
        a.push_back(tmp);
    }
    auto start_sort=[&](const int tid)->void{
        cout<<"thread "<<tid<<" started sorting"<<endl;
        int chunk =n/thread_num;
        int left = tid*chunk;
        int right=(tid+1)*chunk-1;
        merge_sort(a,left,right);
        cout<<"thread "<<tid<<" finished"<<endl;
    };
    for(int i=0;i<thread_num;i++){
      threads.emplace_back(start_sort,i);
    }
    for(auto& t:threads){
        t.join();
    }
    cout<<"array sorted: "<<endl;
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
void merge_sort(vector<int>&a,int l,int r){
    if(r>l){
        int mid = (r+l)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,r);
        merge(a,l,mid,r);
    }
}
void merge(vector<int>&a,int l, int mid, int r){
    vector<int> l_arr(mid-l+1,0);
    vector<int> r_arr(r-mid,0);
    int l_idx=0;
    int r_idx=0;
    int a_idx=l;
    int l_ctr=0,r_ctr=0;
    for(int i=l;i<mid+1;i++){
        l_arr[l_ctr++] = a[i];
    }
    for(int i=mid+1;i<r+1;i++){
        r_arr[r_ctr++] = a[i];
    }
    while(l_idx<l_arr.size() && r_idx<r_arr.size()){
        if(l_arr[l_idx]<r_arr[r_idx]){
            a[a_idx++]=l_arr[l_idx++];
        }
        else{
            a[a_idx++]=r_arr[r_idx++];
        }
    }
    while(l_idx<l_arr.size()){
        a[a_idx++]=l_arr[l_idx++];
    }
    while(r_idx<r_arr.size()){
        a[a_idx++]=r_arr[r_idx++];
    }
}
