
#include <bits/stdc++.h>
# define C continue
# define R return
 
# define D double
# define I insert
# define ll long long
# define ld long double
 
# define ull unsigned long long
# define ui unsigned int
 
# define pb push_back
# define pf push_front
 
# define vi vector < int >
# define vc vector < char >
# define vs vector < string >
# define vb vector < bool >
# define vd vector < D >
# define vll vector < ll >
# define vull vector < ull >
# define vld vector < ld >
# define PQ priority_queue
 
# define vvi vector < vector < int > >
# define vvb vector < vector < bool > >
# define vvc vector < vector < char > >
# define vvll vector < vector < ll > >
# define vvd vector < vector < D > >
# define vvld vector < vector < ld > >
 
# define all(v) (v).begin() , (v).end()
# define allrev(v) (v).rbegin() , (v).rend()
# define allcomp(v) v.begin() , v.end() , comp
# define allrevcomp(v) v.rbegin() , v.rend() , comp
 
# define pii pair < int , int >
# define pll pair < ll , ll >
# define pld pair < ld , ld >
# define pDD pair < D , D >
# define pipii pair<int, pii >
# define pcpii pair<char,pii>
 
# define vpld vector < pld >
# define vpii vector < pii >
# define vpll vector < pll >
# define vpDD vector < pDD >
 
# define vvpii vector < vector < pii > >
# define vpipii vector< pipii >
 
# define F first
# define S second
# define mp make_pair
 
# define unm unordered_map
# define unmii unm< int , int >
# define unmll unm< ll , ll >
# define unms unm<string,int>
# define unmci unm<char,int>
 
# define sortvia sort(a.begin(),a.end());
# define sortvib sort(b.begin(),b.end());
# define revsorta sort(a.begin(), a.end(), greater <int>());
# define revsortb sort(b.begin(), b.end(), greater <>());
# define loop(q,n) for(int i=q;i<n;i++)
# define loop2(q,n) for(int j=q;j<n;j++)
# define test int t;cin >> t;while(t--)
# define nextline "\n"
# define tab "\t"
# define space " "
# define get_arr_size_n int n;cin>>n;int arr[n];loop(0,n)cin>>arr[i];
//vector<vector<int> > vec( n , vector<int> (m, 0));
//YES
//NO
//cout
//true
//false
//yes
//no
 
const ll mod9=1e9+7;
const ll maxsize=2e9+1;
// const ll mod =998244353;
const ll mod2=1073741824;
const ll INF=1e18L+5;
const int IINF=1e9+5;
const int two_pow_fiv=200008;
using namespace std;

vector <int> ans;

class Node{
    public:
    int data ;
    Node* next;
}*first=NULL,*last=NULL,*second=NULL,*Lulz=NULL,*hello=NULL;

void create(int a[],int n)
{
    for(int i=1;i<n;i++)
    {
        Node*t=new Node();
        t->data=a[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
    //last->next=first; //for loop or circular linked list 
}

void display(Node *p) //display LL
{
    while(p!=NULL)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
}
//vector<int> v;

void insertend(int x)
{
    Node *c=new Node();
    c->data=x;
    c->next=NULL;
    Lulz->next=c;
    Lulz=c;
}

void intersectionoftwoLL(Node *p,Node *q)
{
    Node *z =new Node();
    z->data=0;
    z->next=NULL;
    Lulz=z;
    hello=z;
    while(q!=NULL and p!=NULL)
    {
        if(p->data==q->data)
        {
            insertend(q->data);
            p=p->next;
            q=q->next;
        }
        else if(p->data < q->data)
        {
            p=p->next;
        } 
        else q=q->next;
    }
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
  int n,m;
  cin>>n>>m;
  int A[n],B[m];
  for(int i=0;i<n;i++) cin>>A[i];
  first=new Node();
    first->data=A[0];
    first->next=NULL;
    last=first;
  create(A,n);
  
  for(int i=0;i<m;i++) cin>>B[i];
   second=new Node();
    second->data=B[0];
    second->next=NULL;
    last=second;
  create(B,m);
  Node *third =new Node();


  intersectionoftwoLL(first,second);
  display(hello);
} 
  
  
  
  