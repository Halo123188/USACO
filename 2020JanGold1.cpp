#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <string>
#include <queue>
#include <bitset>

using namespace std;
int n,m,c;
int w[1030],f[1005][1005];
vector<int> ro[1005];
int ans;
int main(int argc, const char * argv[]) {
    freopen("time.in", "r", stdin);
    freopen("time.out", "w", stdout);
    
    cin>>n>>m>>c;
    for(int i = 1;i<=n;i++){
        cin>>w[i];
    }
    
    for(int i = 0;i<m;i++){
        int a,b;
        cin>>a>>b;
        ro[a].push_back(b);
    }
    memset(f, -0x3f, sizeof f);
    f[0][1] = 0;
    for(int i = 0;i<=1003;i++){
        for(int j = 1;j<=n;j++){
            for(int k:ro[j]){
                f[i+1][k] = max(f[i+1][k], f[i][j]+w[k]-(i+1)*(i+1)*c+i*i*c);
            }
        }
        ans = max(ans, f[i][1]);
    }
    
    cout<<ans;
    return 0;
}

