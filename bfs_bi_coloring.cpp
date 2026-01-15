#include<bits/stdc++.h>
#include<chrono>
using namespace std;

template<typename F, typename S> ostream& operator<<(ostream& os, const pair<F, S>& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template<typename T> ostream& operator<<(ostream& os, const vector<T>& v) { os << "{"; for (auto it = v.begin(); it != v.end(); ++it) { if (it != v.begin()) os << ", "; os << *it; } return os << "}"; }
template<typename T> ostream& operator<<(ostream& os, const set<T>& v) { os << "["; for (auto it = v.begin(); it != v.end(); ++it) { if (it != v.begin()) os << ", "; os << *it; } return os << "]"; }
template<typename T> ostream& operator<<(ostream& os, const multiset<T>& v) { os << "["; for (auto it = v.begin(); it != v.end(); ++it) { if (it != v.begin()) os << ", "; os << *it; } return os << "]"; }
template<typename F, typename S> ostream& operator<<(ostream& os, const map<F, S>& v) { os << "["; for (auto it = v.begin(); it != v.end(); ++it) { if (it != v.begin()) os << ", "; os << it->first << " = " << it->second; } return os << "]"; }

#define dbg(args...) do { cerr << #args << " : "; faltu(args); } while(0)
void faltu() { cerr << endl; }
template<typename T> void faltu(T a[], int n) { for (int i = 0; i < n; ++i) cerr << a[i] << ' '; cerr << endl; }
template<typename T, typename ...hello> void faltu(T arg, const hello&... rest) { cerr << arg << ' '; faltu(rest...); }

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
const int inf = 2e9, MAXN = 2e6 + 5;
const ll infLL = 9e18;
#define MOD 1000000007
#define mx_int_prime 999999937

#define all(a) (a).begin(), (a).end()
#define sz(x) (int)x.size()
#define mid(l,r) ((r+l)/2)
#define left(node) (node*2)
#define right(node) (node*2+1)
#define mem(a,b) memset(a, b, sizeof(a))
#define gcd(a,b) __gcd(a,b)
#define sqr(a) ((a)*(a))
#define nll cout<<'\n'
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

#define srt(m) sort(all(m))
#define srtr(m) sort(m.rbegin(), m.rend())
#define rev(m) reverse(all(m))
#define pb push_back
#define ff first
#define ss second
#define mp make_pair
#define fr(m) for(int i = 0; i < m; i++)
#define fro(m) for(int i = 1; i <= m; i++)
#define _ "\n"
#define int long long

vector<int>adj[MAXN],col(MAXN);

void always(){
    int n,m; cin>>n>>m;
    int pos=1;
    for(int i =0;i<=n;i++){
        adj[i].clear();
        col[i]=0;
    }
    for(int i=1;i<=m;i++){
        int u,v; cin>>u>>v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for(int i =1;i<=n && pos;i++){
        if(col[i] != 0) continue;
        queue<int>q;
        q.push(i);
        col[i]=1;
        while(!q.empty() && pos){
            int u = q.front();
            q.pop();
            for(auto v:adj[u]){
                if(col[v] ==0) {
                    col[v]= 3-col[u];
                    q.push(v);
                }else if(col[v]==col[u]){
                    pos =0;
                    break;
                }
            }
        }
    }
    if(!pos){
        cout<<"Suspicious bugs found!";
    }
    else cout<<"No suspicious bugs found!";
    nll;
}

int32_t main() {
    optimize();
    // sieve()
    auto start = chrono::high_resolution_clock::now();
    int t =1;
    cin >> t;
    // freopen("closing.in", "r", stdin);
    // freopen("closing.out", "w", stdout);

    for(int i =1;i<=t;i++){
        cout<<"Scenario #"<<i<<':'<<_;
        always();
    }
            
    auto end = chrono::high_resolution_clock::now();
    cerr << "Time taken: " << chrono::duration<double>(end - start).count() << " seconds\n";
                
}
