#include <bits/stdc++.h>
using namespace std;

bool check(int R,int C,vector<vector<int>>& A,int val){
	vector<vector<bool>> vu(R,vector<bool>(C));
	queue<pair<int,int>> q;
	q.emplace(0,0);
	vu[0][0] = true;
	while(!q.empty()){
   	auto p = q.front();
      q.pop();
      int x = p.first, y = p.second;
      if(x > 0 and !vu[x-1][y] and A[x-1][y] >= val){
         q.emplace(x-1,y);
         vu[x-1][y] = true;
      }
      if(y > 0 and !vu[x][y-1] and A[x][y-1] >= val){
         q.emplace(x,y-1);
         vu[x][y-1] = true;
      }
      if(x < R-1 and !vu[x+1][y] and A[x+1][y] >= val){
         q.emplace(x+1,y);
         vu[x+1][y] = true;
      }
      if(y < C-1 and !vu[x][y+1] and A[x][y+1] >= val){
         q.emplace(x,y+1);
         vu[x][y+1] = true;
      }
    }
   return vu[R-1][C-1];
}

int maximumMinimumPath(vector<vector<int>>& A){
   int R = A.size(),C = A[0].size();
   int vm = min(A[0][0],A[R-1][C-1]);
   set<int> vs;
   vector<int> vals;
   for(int i = 0; i < R; ++i){
      for(int j = 0; j < C; ++j){
         if(A[i][j] < vm) vs.insert(A[i][j]);
      }
   }
   for(int i : vs) vals.push_back(i);
   vals.push_back(vm);
   sort(begin(vals),end(vals));
   int b = 0, e = vals.size()-1;
   while(b+1 < e){
      int m = (b+e)/2;
      if (check(R,C,A,vals[m])) b = m;
      else e = m-1;
   }
   if(check(R,C,A,vals[e])) return vals[e];
   return vals[b];
}

int main(){
	int r,c;
	cin >> r >> c;
	vector<vector<int>> v(r,vector<int> (c));
	for (int i=0; i<r; ++i){
		for (int j=0; j<c; ++j){
			cin >> v[i][j];
		}
	}
	cout << maximumMinimumPath(v) << '\n';
	return 0;
}
