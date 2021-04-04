
//BFS:

#include<bits/stdc++.h>
using namespace std;
int a[100][100], n, chuaxet[100];
void BFS(int u)
{
	int queue[100];
	int left = 1, right = 1;int v;
	queue[left] = u; 		
	chuaxet[u] = 0;
	while(left <= right)
	{
		u = queue[left];		left++;
		cout << u << " ";
		for(v= 1; v<= n; v++) 
		{
			if(a[u][v] != 0 && chuaxet[v] == 1) 
			{	
				right++;
				queue[right] = v;		
				chuaxet[v] = 0;
			}
		}
	}
}
	
int main()
{
	int u;
	cout << "Nhap so dinh: n= ";
	cin >> n;
	for(int i= 1; i<=n; i++)
	{
		chuaxet[i] = 1;
	}
	cout << "Nhap ma tran: " << endl;
	for(int i=1; i<= n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin >> a[i][j];
		}
	}
	cout << "Nhap dinh bat dau: u= ";
	cin >> u;
	cout << "Ket qua duyet: " << endl;
	BFS(u);
	
	return 0;
}
