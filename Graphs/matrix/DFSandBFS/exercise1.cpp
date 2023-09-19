#include <bits/stdc++.h>
using namespace std;
 
#define x first
#define y second
#define all(a) (a).begin(),(a).end()
#define show(a) for(auto p : a) cout << p << " ";
#define rep(a,b,c) for(int i=a; i<b; i+= c)
#define present(c, x) ((c).find(x) != (c).end())
const int INF = 0x3f3f3f3f;

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

unordered_map<string, vector<string>> mp;
unordered_map<string, int> dist;

bool cmp(pair<int,string> &a, pair<int,string> &b){
	if(a.x != b.x){
		return a.x < b.x;
	} else{
		return a.y < b.y;
	}
}

void bfs(){
	queue<string> q; 
	dist["Ahmad"] = 0;
	q.push("Ahmad");
	
	while(!q.empty()){
		string f = q.front(); q.pop();
		for(string s : mp[f]){
			if(!present(dist,s)){
				dist[s] = dist[f] + 1;
				q.push(s);
			}
		}
	}
}

int main(){
	int t; cin >> t;
	
	while(t--){
		int line; cin >> line;
		
		set<string> a;
		
		string n1,n2,n3;
		rep(0,line,1){
			cin >> n1 >> n2 >> n3;
			mp[n1].push_back(n2); mp[n1].push_back(n3);
			mp[n2].push_back(n1); mp[n2].push_back(n3);
			mp[n3].push_back(n1); mp[n3].push_back(n2);
			a.insert(n1); a.insert(n2); a.insert(n3);
		}
	
		bfs();
		
		vector<pair<int,string>> ans, quem_falta;
		for(auto p : dist){
			ans.push_back({p.y, p.x});
		}
		
		for(auto p : a){
			if(!dist[p] && p != "Ahmad"){
				quem_falta.push_back({0,p});
			}
		}
		
		sort(all(ans), cmp);
		sort(all(quem_falta), cmp);
		
		cout << (int)ans.size() + (int)quem_falta.size() << endl;
		
		for(auto i : ans){ cout << i.y << " " << i.x << endl; }	
		for(auto p : quem_falta) cout << p.y << " undefined" << endl;
		
		mp.clear();
		dist.clear();
	}
	return 0;
}