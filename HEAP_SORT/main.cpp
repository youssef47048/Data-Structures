#include <iostream>
#include<bits/stdc++.h>
using namespace std;
int main(){
int n ,t;
cin >>t;
for(int i = 0 ; i < t ; i++){
    cin >> n;
    int  arr[n];
    int l = 0 , r = n-1 , flag = 0 , mn = INT_MAX   ;
    for(int i = 0 ; i < n ; i++) {
            cin >> arr[i];
            if(arr[i] < mn ){
                flag = i ;
                mn = arr[i] ;
            }
    }
    l = flag+1 ;
    while(l != n-1){

        if(arr[l]<arr[r]){
            ++flag;
            ++l;
        }else --r;
        if(r == l) {
            ++l;
            continue;
        }
    }
    cout << flag << endl;
}
 return 0;
}