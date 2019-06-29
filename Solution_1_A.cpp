#include <bits/stdc++.h>
using namespace std;

int maximumMinimumPath(vector<vector<int>>& v) {
	int r=v.size(),c=v[0].size();
	vector<vector<int>> vu(r,vector<int> (c));
	priority_queue<tuple<int,int,int>> q; // val x y
	q.emplace(v[0][0],0,0);
	vu[0][0]=v[0][0];
	vector<pair<int,int>> dir={{0,1},{1,0},{-1,0},{0,-1}};
	while (!q.empty()){
		auto f=q.top();
		q.pop();
		int val,x,y;
		tie(val,x,y) = f;
		if (x == r-1 and y == c-1) continue;
		for (auto& i:dir){
			int nx=x+i.first,ny=y+i.second;
			if (nx < r and ny < c and nx >= 0 and ny >= 0){
				if (val > vu[nx][ny]){
					vu[nx][ny] = val;
					q.emplace(min(val,v[nx][ny]),nx,ny);
				}
			}
		}
	}
	return min(v[r-1][c-1],vu[r-1][c-1]);
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
