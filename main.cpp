//
//  main.cpp
//  USACO 2015 Dec Silver 2
//
//  Created by 程奕博 on 2021/8/25.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> oppo;
vector<int> b;
int ans;
int main(int argc, const char * argv[]) {
    
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        oppo.push_back(temp);
    }
    sort(oppo.begin(),oppo.end());
    int temp = 0;
    for(int i=1;i<=n*2;i++){ 
        if(temp < n && i == oppo[temp]){
            temp++;
            continue;
        }
        if(temp < n && i != oppo[temp]){
            b.push_back(i);
            continue;
        }
        if(temp >= n){
            b.push_back(i);
            continue;
        }
    }
    int temp2 = 0;
    for(int i=0;i<n;i++){
        for(int j = temp2;j<n;j++){
            if(b[j] > oppo[i]){
                temp2++;
                ans++;
                break;
            }
            else{
                temp2++;
            }
        }
    }
    cout<<ans;
    
    return 0;
}
