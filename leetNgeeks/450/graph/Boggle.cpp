

// https://www.geeksforgeeks.org/boggle-find-possible-words-board-characters/
#include<bits/stdc++.h>
using namespace std;


int dx[8] = {-1,0,0,1,-1,-1,1,1};
int dy[8] = {0,1,-1,0,1,-1,1,-1};

bool isSafe(int x, int y, int c, int r) {

	if(x>=0&&x<c && y>=0 && y < r){
		return true;
	}
	return false;
}
 

void bfs(vector<pair<int,int>>src,vector<vector<char>>boggle,string str){


	int r = boggle.size();
	int c = boggle[0].size();

	int N = str.length();
	int k = 1;
	string tmp = "";

	queue<pair<int,int>> q;
	auto src_p = src[0];

	q.push({src_p.first, src_p.second});

	while(!q.empty()) {

		auto p = q.front();
		q.pop();
		bool flag = false;
		for(int i = 0; i < 8; i++) {
			int nx = p.first + dx[i];
			int ny = p.second  + dy[i];

			if(isSafe(nx,ny,r,c) and boggle[nx][ny]==str[k]){
				flag = true;
				q.push({nx,ny});
			}
		}
		if(!flag){ cout<<"word doesn't exist\n";return; }
		k++;
		if(k == N) {
			cout<<"Found word\n";
			return;
		}


	}

}

void isWord(vector<string> dic,vector<vector<char>> boggle) {


	//map<char, int> mp;


	string str = "izksqug";
	vector<pair<int,int>> src;
	for(int i = 0; i < boggle.size(); i++) {

		for(int j = 0; j < boggle[0].size(); j++) {
			if(boggle[i][j] == str[0]){
				src.push_back({i,j});
			}
		}
	}

	if(src.size() > 0)
		bfs(src,boggle,str);
	else
		cout<<"ob!, it doesn't exist\n";




}


int main() {
	vector<string> dic;
	dic = {"geeks","for","quiz","go"};

	vector<vector<char>> boggle;

	boggle = {{'g','i','z'},
			  {'u','e','k'},
			  {'q','s','e'}};


    isWord(dic,boggle);


}