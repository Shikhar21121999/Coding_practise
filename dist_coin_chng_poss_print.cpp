#include<bits/stdc++.h>
using namespace std ;

vector < int > coins ;

void print ( vector < int > &v )
{
    for ( auto &val : v )
        cout << val << " " ;

    cout << "\n" ;
}

void f ( int val , vector < int > coins_so_far , int indx )
{
    if ( val < 0 )
        return ;

    if ( indx < 0 )
        return ;

    if ( val == 0 )
    {
        print ( coins_so_far ) ;
        return ;
    }

    if ( indx >= 0 )
        f ( val , coins_so_far , indx - 1 ) ;

    coins_so_far.push_back ( coins[indx] ) ;

    if ( indx >= 0 )
        f ( val - coins[indx] , coins_so_far , indx ) ;
}

int main()
{
ios::sync_with_stdio(0);
cin.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
    int n ; /// number of coins
    cin >> n ;

    coins.resize ( n ) ; /// distinct coin values

    for ( int i=0 ; i < n ; i ++ )
        cin >> coins[i] ;

    int val ; /// target value
    cin >> val ;

    vector < int > ans ;

    f ( val , ans , n - 1 ) ;

    return 0 ;
}
