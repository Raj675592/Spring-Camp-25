#include <bits/stdc++.h>
using namespace std;
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef set<int> s;
typedef long long ll;
#define sz(a) int((a).size())
#define pb push_back
#define all(c) (c).begin(), (c).end()
#define present(c, x) ((c).find(x) != (c).end())
vector<ll> num;
vector<ll> tree;
void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
}

void build(int index,int l, int r){
    if(l==r){
        tree[index] = num[l];
        return;
    }
    int mid = (l+r)/2;
    build(2*index+1,l,mid);
    build(2*index+2,mid+1,r);
    tree[index] = (tree[2*index+1] + tree[2*index+2]);
}

void update(int node, int l, int r, int index, ll val){
    if(l==r){
        tree[node] = val;
        return;
    }
    int mid = (l+r)/2;
    if(index<=mid) update(2*node+1,l,mid,index,val);
    else update(2*node+2,mid+1,r,index,val);

    tree[node] = tree[2*node+1] + tree[2*node+2];

}

long long query(int node, int l , int r, int start, int end){
    if(start>r || end<l) return 0;
    if(start>=l && end<=r) return tree[node];

    int mid = (start+end)/2;
    return query(2*node+1,l,r,start,mid) + query(2*node+2,l,r,mid+1,end);

}

int main() {
    fast_io();

    int test = 1;
    // cin >> test; 
    while(test--) {
        int n,q;
        cin>>n>>q;
        num.resize(n+1);
        tree.resize(4*n+1);
        for(int i = 0; i<n; i++){
            cin>>num[i];
        }
        build(0,0,n-1);
        for(int i = 0; i<q; i++){
            int a,b;
            ll c;
            cin>>a>>b>>c;
            if(a==1){
                update(0,0,n-1,b-1,c);
            }
            else{
                cout<<query(0,b-1,c-1,0,n-1)<<endl;
            }
        }
    }

    return 0;
}



