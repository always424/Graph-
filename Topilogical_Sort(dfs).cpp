/*============================================================*
 ||                                                           ||
 ||                                                           ||
 ||   In the name of ALLAH — The Most Merciful, The Most Wise ||
 ||                                                           ||
 ||   Author: Nafis Abdullah                                  ||
 ||   Handle: always_424                                      ||
 ||   Platform: Codeforces                                    ||
 ||                                                           ||
 *============================================================*/
#include<bits/stdc++.h>
#include<chrono>
using namespace std;

template<typename F, typename S> ostream& operator<<(ostream& os, const pair<F, S>& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "{"; for (auto it = v.begin(); it != v.end(); ++it) { if (it != v.begin()) os << ", "; os << *it; } return os << "}"; }
template<typename T> ostream& operator<<(ostream& os, const set<T>& v) { os << "["; for (auto it = v.begin(); it != v.end(); ++it) { if (it != v.begin()) os << ", "; os << *it; } return os << "]"; }
template<typename T> ostream& operator<<(ostream& os, const multiset<T>& v) { os << "["; for (auto it = v.begin(); it != v.end(); ++it) { if (it != v.begin()) os << ", "; os << *it; } return os << "]"; }
template<typename F, typename S> ostream& operator<<(ostream& os, const map<F, S>& v) { os << "["; for (auto it = v.begin(); it != v.end(); ++it) { if (it != v.begin()) os << ", "; os << it->first << " = " << it->second; } return os << "]"; }

#define dbg(args...) do { cerr << #args << " : "; bug(args); } while(0)
void bug() { cerr << endl; }
template<typename T> void bug(T a[], int n) { for (int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl; }
template<typename T, typename ...hello> void bug(T arg, const hello&... rest) { cerr << arg << ' '; bug(rest...); }

typedef long long ll;
typedef double dl;
typedef pair<ll, ll> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<pii> vii;
typedef vector<pdd> vpDD;
typedef vector<vector<pii>> vvpii;

const double PI = acos(-1), eps = 1e-9;
const int inf = 2e9, MAXN = 1e6 + 5;
const ll infLL = 9e18;
#define MOD 1000000007
#define mx_int_prime 999999937
#define all_0(x)    memset(x,0,sizeof(x))
#define all_neg(x)  memset(x,-1,sizeof(x))
#define all_1(x)    memset(x,1,sizeof(x))
#define all(a) (a).begin(), (a).end()
#define sz(x) (int)x.size()
#define mid(l,r) ((r+l)/2)
#define left(node) (node*2)
#define right(node) (node*2+1)
#define mem(a,b) memset(a, b, sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define sqr(a) ((a)*(a))
#define nll cout<<'\n';
#define optimize() ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed, ios::floatfield)
#define file() freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout)

#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
#define vvd vector<vector<double>>
#define vvld vector<vector<long double>>
#define pld pair<long double, long double>
#define vpld vector<pld>
#define yes cout<<"YES"<<endl;
#define no cout<<"NO"<<endl;

#define srt(m) sort(all(m))
#define srtr(m) sort(m.rbegin(), m.rend())
#define rev(m) reverse(all(m))
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define fr(m) for(int i = 0; i < m; i++)
#define fro(m) for(int i = 1; i < m; i++)
#define _ "\n"

int dx[] = {0, 0, +1, -1};
int dy[] = {+1, -1, 0, 0};
// int dx[] = {+1, 0, -1, 0, +1, +1, -1, -1};
// int dy[] = {0, +1, 0, -1, +1, -1, +1, -1};
bool is_pal(int n){
    int org =n,rev =0;
    while(n>0){
        rev = rev*10+n%10;
        n/=10;
    }
    return org == rev;
}
vector<int> gen_pal(int mx){
    vector<int>pal;
    for(int i =1;i<=mx;i++){
        if(is_pal(i)) pal.pb(i);
    }
    return pal;
}
bool isPal(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return s == t;
}
ll pow(ll a, ll b, ll m) { ll ans = 1; while (b) { if (b & 1) ans = (ans * a) % m; b /= 2; a = (a * a) % m; } return ans; }
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
vector<int>pri={ 2, 3, 5, 7, 11, 13, 17, 19, 23, 29,31, 37, 41, 43, 47, 53};
// #define int long long
vector<int>adj[200005];
vector<int>ans;
int vis[200005];
int n,m; 
int has_cycle=0;
void dfs(int u){
    vis[u]=1;
    for(auto v:adj[u]){
        if(vis[v] == 1) {
            has_cycle =1;
            return;
        }
        if(vis[v]==0) dfs(v);
    }
    vis[u]=2;
    ans.pb(u);
}
void topological_sort(){
    for(int i =1;i<=n;i++){
        if(!vis[i]) dfs(i);
    }
    reverse(all(ans));
}
void always424(int tc){
    cin>>n>>m;
    for(int i =1;i<=m;i++){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
    }
    topological_sort();
    if(has_cycle){
        cout<<"IMPOSSIBLE";
        return;
    }
    for(auto u : ans) cout<<u<<' ';

}


int32_t main() {
    optimize();
    auto start = chrono::high_resolution_clock::now();
    // sieve()
    int t =1;
    // cin >> t;
    for(int i =1;i<=t;i++) always424(i);
            
    auto end = chrono::high_resolution_clock::now();
    cerr << "Time taken: " << chrono::duration<double>(end - start).count() << " seconds\n";
                
}
