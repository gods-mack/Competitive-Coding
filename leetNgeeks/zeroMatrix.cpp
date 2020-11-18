
#include<bits/stdc++.h>
using namespace std;



void printMatrix(vector<vector<int>> mat)
{
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
			cout << mat[i][j] << "  ";
		cout << '\n';
	}
	cout << '\n';
}


void convertRowColumn(vector<vector<int>> &mat,int x,int y) {

	int m = mat.size();
	int n = mat[0].size();

	// row
	for(int i = 0; i < m; i++){ 
		if(mat[i][y] != 0){
			mat[i][y] = -1;
		}
	}

	// column
	for(int i = 0; i < n; i++){ 
		if(mat[x][i] != 0){
			mat[x][i] = -1;
		}
	}
}

void convert(vector<vector<int>> &mat,int m,int n) {

	for(int i = 0; i < m; i++) {
		for(int j = 0; j < n; j++) {
			if(mat[i][j] == 0) {
				convertRowColumn(mat,i,j);
			}
		}
	}

	// traverse the matrix once again and replace cells having
	// value -1 with 0
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			if (mat[i][j] == -1){
				mat[i][j] = 0;
			}
		}
	}

	printMatrix(mat);

}

int main() {
	int m; cin>>m;
	int n; cin>>n;
	vector<vector<int> > mat(m);

	for(int i = 0; i < m; i++) {
		mat[i].resize(n);
		for(int j = 0; j < n; j++){
			cin>>mat[i][j];
		}
	}

	convert(mat,m,n);
}