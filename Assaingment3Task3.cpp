/*{
Author :: MD. Musfiqur Rahman Sanim
Aust cse 28th Batch
ID:11.02.04.097

Problem ::
    rules:
        statement :- assign_stat | decision_stat | looping_stat
        assign_stat :- id = expn
        expn :- simple_expn eprime
        eprime :- relop simple_expn | null
        decision_stat :- if ( expn ) stat dprime
        dprime :- else stat | null
        looping_stat :- while ( expn ) stat | for ( assign_stat ; expn ; assign_stat ) stat
        relop :- == |!= | <= | >= | > | <

}*/


//{ Template
using namespace std;
//{ headers
#include<bits/stdc++.h>
//}
//{ Loops
#define forab(i,a,b) for (__typeof(b) i = (a); i <= (b); ++i)
#define rep(i,n) forab (i, 0, (n) - 1)
#define For(i,n) forab (i, 1, n)
#define rofba(i,a,b) for (__typeof(b) i = (b); i >= (a); --i)
#define per(i,n) rofba (i, 0, (n) - 1)
#define rof(i,n) rofba (i, 1, n)
#define forstl(i,s) for (__typeof ((s).end ()) i = (s).begin (); i != (s).end (); ++i)
//}
//{ Floating-points
#define EPS 1e-7
#define abs(x) (((x) < 0) ? - (x) : (x))
#define zero(x) (abs (x) < EPS)
#define equal(a,b) (zero ((a) - (b)))
#define PI 2*acos (0.0)
//}
typedef long long int64;
typedef unsigned long long int64u;
#define memo(a,v) memset(a,v,sizeof(a))
#define all(a) a.begin(),a.end()
#define db double
#define pb push_back
#define eb emplace_back
#define pii pair<int ,int >
#define NL puts("")
#define ff first
#define ss second
//{
//Intput_Output
#define gc getchar
#define II ({ int a; read(a); a;})
#define IL ({ int64 a; read(a);  a;})
#define ID ({ db a; scanf("%lf",&a);  a;})
#define IC ({ char a; scanf("%c",&a);  a;})
#define IS ({ string a; cin >> a;  a;})
#define OC printf("Case %d:",cs);
//}
//}
#define _stl(x) {__stl_print__(x);}
#define __(args...) {dbg,args; cerr<<endl;}
template<class T>inline bool read(T &x) {
    int c=gc();
    int sgn=1;
    while(~c&&c<'0'|c>'9') {
        if(c=='-')sgn=-1;
        c=gc();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=gc())x=x*10+c-'0';
    x*=sgn;
    return ~c;
}
struct debugger {
    template<typename T> debugger& operator , (const T& v) {
        cerr<<v<<"    ";
        return *this;
    }
} dbg;
template <class T> void __stl_print__ (T &x) { // for all STL containers
    cerr << "[";
    forstl (i, x) cerr << (i != x.begin () ? ", " : "") << *i;
    cerr << "]" << endl;
}
template <class T, class U> inline T max (T &a, U &b) {
    return a > b ? a : b;
}
template <class T, class U> inline T min (T &a, U &b) {
    return a < b ? a : b;
}
template <class T, class U> inline T swap (T &a, U &b) {
    T tmp = a;
    a = b;
    b = tmp;
}
//int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 Direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[6]={2,1,-1,-2,-1,1};int dy[6]={0,1,1,0,-1,-1}; //Hexagonal Direction

const int64 INF = (1ll)<<50;
const int mx = 1e5 + 7;
const int mod = 1000000007 ;
const db pi = PI;
int EQ(double d) {
    if ( fabs(d) < EPS ) return 0;
    return d > EPS ? 1 : -1 ;
}

map<string , vector<string > >m;

vector<string>Split(string s ) {
    vector<string>ret;
    istringstream ss(s) ;
    string token ;
    while(ss >> token) ret.pb( token ) ;
    return ret;
}

void rules() {
    m["statement"].pb("assign_stat");
    m["statement"].pb("decision_stat");
    m["statement"].pb("looping_stat");

    m["assign_stat"].pb("id = expn");

    m["expn"].pb("simple_expn eprime");

    m["eprime"].pb("relop simple_expn");
    m["eprime"].pb("null");

    m["decision_stat"].pb("if ( expn ) stat dprime");

    m["dprime"].pb("else stat");
    m["dprime"].pb("null");

    m["looping_stat"].pb("while ( expn ) stat");
    m["looping_stat"].pb("for ( assign_stat ; expn ; assign_stat ) stat");

    m["relop"].pb("==");
    m["relop"].pb("<=");
    m["relop"].pb(">=");
    m["relop"].pb("<");
    m["relop"].pb(">");
    m["relop"].pb("!=");
}

char st[mx];
vector<string >d;
map<string ,bool >flag;
bool call() {
    int l = d.size();
    queue<string >Q;
    flag.clear();
    Q.push("statement");
    while(!Q.empty()) {
        string now = Q.front();
        Q.pop();
        vector<string >tmp = Split(now);
        int len = tmp.size(),c = 0;
        if(len == l) {
            while(c<len && c<l) {
                if(tmp[c] != d[c]) break;
                c++;
            }
            if(c == l) return true;
        }
        if(flag.find(now) != flag.end()) continue;
        flag[now] = true;
        int id = 0;
        forstl(it,tmp) {
            if(m.find(*it) != m.end()) {
                break;
            }
            id++;
        }

        if(id < len) {
            forstl(it,m[tmp[id]]) {
                string ss = "";
                rep(i,id) {
                    if(i) ss += " ";
                    ss += tmp[i];
                }
                if(*it != "null") {
                    if(id) ss += " ";
                    ss += *it;
                }
                forab(i,id+1,len-1) {
                    ss += " ";
                    ss += tmp[i];
                }
                Q.push(ss);
            }
        }

    }
    return false;
}

int main() {
#ifdef Sanim
    //geting WA check int64 & int64u
    freopen ("in.txt", "r", stdin);
    // freopen ("output.txt", "w", stdout);
#endif
    while(gets(st)) {
        d = Split(st);
        rules();
        if(call()) cout << "Accepted" << endl;
        else cout << "Not accepted" << endl;
    }
}

/*

id = simple_expn <= simple_expn  :: Accepted
if ( simple_expn != simple_expn ) stat else stat :: Accepted
while ( simple_expn < simple_expn ) stat :: Accepted
while ( simple_expn ) stat :: Accepted
for ( id = simple_expn ; simple_expn >= simple_expn ; id = simple_expn ) stat :: Accepted
for ( id = simple_expn ; simple_expn >= simple_expn ; id = simple_expn ) :: Not accepted

*/
