
// tim so TPLT

#include<iostream>
using namespace std;
int a[100][100], chuaxet[100], n, s=0;
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
void DFS(int u)
{
	int stack[100], dau=1 , s, t;
	stack[dau] = u;
	chuaxet[u]= 0;
//	cout << u << " ";
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

void TPLT_DFS()
{
	s=0;
	for(int i=1; i<=n; i++)
	{
		if(chuaxet[i] ==1)
		{
			s++;
			DFS(i);
		}
	}
	cout << "So TPLT= " << s << endl;
}

int main()
{
	nhap();
	TPLT_DFS();
	return 0;
}
