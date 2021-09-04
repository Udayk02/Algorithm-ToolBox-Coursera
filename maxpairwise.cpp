#include<iostream>
#include<vector>

using namespace std;

void max_pair_wise(vector<long long> arr){
    long long max1, max2;
    int i, j;
    max1 = 0;
    for(i = 0;i<arr.size();++i){
        if(arr[max1] < arr[i]){
            max1 = i;
        }
    }
    if(max1==0){ max2 = 1; }
    else { max2 = 0; }
    for ( j = 0; j < arr.size(); ++j)
    {
        if(j != max1 && arr[max2] < arr[j]){
            max2 = j;
        }
    }
    cout<<arr[max1]*arr[max2];
}

int main(){
    long long n;
    cin>>n;
    vector<long long> arr(n);
    for(long long i = 0;i<n;++i){
        cin>>arr[i];
    }
    max_pair_wise(arr);
}