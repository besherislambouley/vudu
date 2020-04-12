/*
 * By subtracting the value P from each number , we reduce the problem to find the number of consecutive
subsequences such that their sum is non-negative 
*/ 
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
    #include <bits/stdc++.h>
    using namespace std;
    #define sqr 340
    #define mid (l+r)/2
    #define pb push_back
    #define ppb pop_back
    #define fi first
    #define se second
    #define lb lower_bound
    #define ub upper_bound
    #define ins insert
    #define era erase
    #define C continue
    #define mem(dp,i) memset(dp,i,sizeof(dp))
    #define mset multiset
    typedef long long ll;
    typedef short int si;
    typedef long double ld;
    typedef pair<int,int> pi;
    typedef pair<ll,ll> pll;
    typedef vector<int> vi;
    typedef vector<ll> vll;
    typedef vector<pi> vpi;
    typedef vector<pll> vpll;
    const ll inf=1e18;
    const ld pai=acos(-1);
    int N,n,p;
    ll a[1000009],id[1000009];
    pll ret[1000009];
    int tree[4000009];
    void upd(int node,int l,int r,int k){
            if(l==r){
                    tree[node]++;
                    return ;
            }
            if(k<=mid)upd(node*2,l,mid,k);
            else upd(node*2+1,mid+1,r,k);
            tree[node]=tree[node*2]+tree[node*2+1];
    }
    int query(int node,int l,int r,int s,int e){
            if(s>r || e<l ) return 0 ;
            if(s<=l && e>=r )return tree[node];
            return query(node*2,l,mid,s,e)+query(node*2+1,mid+1,r,s,e);
    }
    int main(){
            scanf("%d",&n);
            for(int i=1;i<=n;i++)scanf("%d",&a[i]);
            scanf("%d",&p);
            for(int i=1;i<=n;i++)a[i]-=p;
            for ( int i = 1 ; i <= n ;i ++ ){
                    a[i]+=a[i-1];
                    ret[i]={a[i],i};
            }
            sort(ret,ret+n+1);
            int crnt = 0 ;
            for ( int i=1 ;i<=n ;i ++ ){
                    crnt += ( ret[i].fi != ret[i-1].fi ) ;
                    id [ret[i].se]=crnt;
            }
            ll ans=0;
            for(int i=0;i<=n;i++){
                    ans+=query(1,0,n,0,id[i]);
                    upd(1,0,n,id[i]);
            }
            printf("%lld\n",ans);
    }
