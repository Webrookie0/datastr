#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
long long  dp[20][2][11][2];
long long a;
string x;
string y;
long long sizee;
long long solve( long long ind, bool tight, bool lead , long long prev , string&s){
	if(ind == s.size()){
		return 1;
	}
	if(dp[ind][tight][prev][lead]!=-1){
		return dp[ind][tight][prev][lead];
	}
	long long lb=0;
	long long next =0;
	long long res=0;
	next = (tight ==true) ? s[ind]-'0' : 9;
	
	for(long long i=lb; i<=next; i++){

		if(i == prev && !lead )continue;
		
		res+=solve(ind+1, (tight && i==next)?true : false, (lead && (i==0)), i, s);
		
		
	}
	return dp[ind][tight][prev][lead]= res;
}
int main(){
	long long a;
	long long b;
	cin>>a;
	cin>>b;
	x= to_string(a-1);
	y = to_string(b);
	sizee = size(to_string(b));
	memset(dp , -1 , sizeof(dp));
	
	long long res =solve(0 , true , true, 10 , x);
	memset(dp , -1, sizeof(dp));
	long long exc = solve(0, true , true, 10 , y);
	cout<<exc-res;
}