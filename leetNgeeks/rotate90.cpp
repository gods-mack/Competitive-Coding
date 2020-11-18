
// 48. Rotate Image
// https://leetcode.com/problems/rotate-image/

#include<bits/stdc++.h>
using namespace std;

void Rotate_matrix() {
	int m; cin>>m;
	int n; cin>>n;

	int matrix[m][n];
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			cin>>matrix[i][j];
		}
	}

	int tmp[m][n];
	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			//cout<<"dd\n";
			tmp[i][j] = 0;
		}
	}


	int i = 0;
	int j = 0;

	int x = 0;
	int y = n;

	while(j < m and x < m) {

		i = 0;
		y = n-1;
		while(i < n and y >= 0) {
			tmp[x][y] = matrix[i][j];
			i++;
			y--;
		}
		j++;
		x++;
	}

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			//cout<<"dd\n";
			cout<<tmp[i][j];
		}
		cout<<endl;
	}
}

int main() {
	

	Rotate_matrix();
}