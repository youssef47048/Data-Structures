#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void counting_sort(int A[] , int k , int n ){
    int B[n];
    int c[k+1];
    for(int i = 0 ; i < k ; i++) c[i] = 0;//
    for(int i = 0 ; i < n ; i++) c[A[i]] = c[A[i]] + 1;
    for(int i = 1 ; i <= k ; i++) c[i] = c[i] + c[i-1];
    for(int i = n-1 ; i >= 0 ; --i){
        B[c[A[i]]-1] = A[i];
        c[A[i]] = c[A[i]]-1 ;
    }
    for(int i = 0 ; i < n ; i++) cout << B[i] << " ";

}

int main()
{
   int n , k ;
   cin >> n;
   int arr[n];
   for (int i = 0 ; i < n ;i++) cin >> arr[i];
   k = *max_element(arr,arr+n);
   counting_sort(arr , k , n);
    return 0;
}
//void counting_sort(vector <int> &v, int mx) {
//
//    int n = v.size();
//
//    vector <int> sorted(n);
//
//    vector <int> temp(mx+1, 0);
//
//
//
//    for(int i = 0; i < n; i ++) {
//
//        temp[v[i]] ++;
//
//    }
//
//    for(int i = 1; i <= mx; i ++) {
//
//        temp[i] += temp[i-1];
//
//    }
//
//
//
//    for(int i = n-1; i >= 0; --i) {
//
//        sorted[temp[v[i]]-1] = v[i]; // the -1 is for zero indexed array
//
//        temp[v[i]] --;
//
//    }
//
//
//
//    v = sorted;
//
//}
//
//
//
//int main() {
//
//    int n;
//
//    cin >> n;
//
//
//
//    vector <int> v(n);
//
//    int mx = 0;
//
//    for(int i = 0; i < n; i ++) {
//
//        cin >> v[i];
//
//        mx = max(mx, v[i]);
//
//    }
//
//
//
//    counting_sort(v, mx);
//
//
//
//    for(auto i: v) cout << i << " ";
//
//    cout << "\n";
//
//}
