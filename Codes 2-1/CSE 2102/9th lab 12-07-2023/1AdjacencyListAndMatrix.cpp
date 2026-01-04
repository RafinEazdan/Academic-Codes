#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int a[100][100]{0};
	set<int> vertexes;
	for(int i=0;i<n;i++){
		int n1,n2;
		cin >> n1 >> n2;
		a[n1-1][n2-1] = 1;
		a[n2-1][n1-1] = 1;
		vertexes.insert(n1);
		vertexes.insert(n2);
	}
	for(int i=0;i<vertexes.size();i++){
		for(int j=0;j<vertexes.size();j++){
			cout<<a[i][j] << " ";
		}
		cout << endl;
	}

	//list
	int v=vertexes.size();
	vector<vector<int>> adjList(v);
	for(int i=0;i<v;i++){
		for(int j=0;j<v;j++){
			if (a[i][j] == 1) {
				adjList[i].push_back(j+1); 
			}
		} 
	}
	cout << endl;
	// for (auto row : adjList) {
	// 	for (int col : row) {
	// 		cout << col << " ";
	// 	}
	// 	cout << endl;
	// }
	for (int i=0;i<v;i++) {
		cout<<i+1<<"=>";
		for (int j=0;j<adjList[i].size();j++) {
			cout << adjList[i][j] << " ";
			
		}
		cout << endl;
	}




	return 0;
}
/*
8
1 2
1 5
1 3
1 4
5 2
5 4
4 3
2 3
*/