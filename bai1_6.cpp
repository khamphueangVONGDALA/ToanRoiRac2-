
// Canh cau:

#include<iostream>
using namespace std;
int n, a[100][100], chuaxet[100];
void DFS(int u)
{
	int stack[100], dau=1 , s, t;
	stack[dau] = u;
	chuaxet[u]= 0;
	//cout << u << " ";
	while(dau > 0)
	{
		s = stack[dau];
		dau--;
		for(int t= 1; t <= n; t++)
		{
			if(chuaxet[t] == 1 && a[s][t] != 0)
			{
				//cout << t << " ";
				chuaxet[t] = 0;
				dau++;
				stack[dau] = s;
				dau++;
				stack[dau] = t;
				break;
			}
		}
	}
}
void nhap()
{
	cout << "Nhap so dinh: n= ";
	cin >> n;
	cout << "Nhap ma tran ke: "<< endl;
	for(int i=1; i<=n; i++)
	{
		chuaxet[i] = 1;
		for(int j=1; j<=n; j++)
		{
			cin >> a[i][j];
		}
	}
	
}
void reinit()
{
	for(int i=1; i<=n; i++)
	{
		chuaxet[i] = 1;
	}
}
int test(int u) // so sanh DFS(u) voi tap dinh V
{
	DFS(u);
	for(int i=1; i<=n; i++)
	{
		if(chuaxet[i] == 1)	return 0;
	}
	return 1;
}
void Duyet_Cau_DFS()
{
	nhap(); reinit();   cout << "Canh cau: " ;
	for(int u= 1; u<n; u++)
	{
		for(int v= u+1; v<=n; v++)
		{
			if(a[u][v] ==1)
			{
				a[u][v] = 0;   a[v][u] = 0;// loai canh
				if(test(1)==0)
				{
					cout << "\n(" << u << " , " << v << ")" ;
				}
				a[u][v] =1;   a[v][u] = 1;
				reinit();
			}
		}
	}
}
int main()
{
	Duyet_Cau_DFS();
	return 0;
}
/*
0 1 1 1 0 0 0 0 0 0 0 0 0
1 0 1 1 0 0 0 0 0 0 0 0 0
1 1 0 1 1 0 0 0 0 0 0 0 0
1 1 1 0 0 0 0 0 0 0 0 0 0
0 0 1 0 0 1 1 1 1 0 0 0 0
0 0 0 0 1 0 1 0 1 0 0 0 0
0 0 0 0 1 1 0 1 0 0 0 0 0
0 0 0 0 1 0 1 0 1 0 0 0 0
0 0 0 0 1 1 0 1 0 1 0 0 0
0 0 0 0 0 0 0 0 1 0 1 1 1
0 0 0 0 0 0 0 0 0 1 0 1 1
0 0 0 0 0 0 0 0 0 1 1 0 1
0 0 0 0 0 0 0 0 0 1 1 1 0
*/
