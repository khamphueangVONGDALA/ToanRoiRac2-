
//TPLT BFS:

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
void BFS(int u)
{
	int queue[100];
	int left = 1, right = 1;
		int v;
	queue[left] = u; 		chuaxet[u] = 0;
	while(left <= right)
	{
		u = queue[left];		left++;
		//cout << u << " ";
		for(v= 1; v<= n; v++) 
		{
			if(a[u][v] != 0 && chuaxet[v] == 1) 
			{	
				right++;
				queue[right] = v;		chuaxet[v] = 0;
			}
		}
	}
}

void TPLT_BFS()
{
	s=0;
	for(int i=1; i<=n; i++)
	{
		if(chuaxet[i] ==1)
		{
			s++;
			BFS(i);
		}
	}
	cout << "So TPLT= " << s << endl;
}

int main()
{
	nhap();
	TPLT_BFS();
	return 0;
}
