
// thuat toan DFS:

#include<iostream>
using namespace std;

int a[100][100];
int n;
int chuaxet[100];
void nhap()
{
	cout << "Nhap so dinh: n= ";
	cin >> n;
	cout << "Nhap ma tran ke: "<< endl;
	for(int i=1; i<=n; i++)
	{
		for(int j=1; j<=n; j++)
		{
			cin >> a[i][j];
		}
	}
}
void DFS(int u)
{
	int stack[100], dau=1 , s, t;
	stack[dau] = u;
	chuaxet[u]= 0;
	cout << u << " ";
	while(dau > 0) // khi stack chua rong
	{
		s = stack[dau];
		dau--;
		for(int t= 1; t <= n; t++)
		{
			if(chuaxet[t] == 1 && a[s][t] != 0)
			{
				cout << t << " ";
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
int main()
{
	cout << "Thuat toan DFS: " << endl;
	nhap();
	for(int i=1; i<=n; i++)
	{
		chuaxet[i] = 1;
	}
	cout << "Nhap dinh bat dau: ";
	int u;
	cin >> u;
	DFS(u);
	return 0;
}
