
// Kiem tra lien thong manh ?

#include<iostream>
using namespace std;
int n, a[100][100], chuaxet[100];
void BFS(int u)
{
	int queue[100];
	int left = 1, right = 1;
		int v;
	queue[left] = u; 		chuaxet[u] = 0;
	while(left <= right)
	{
		u = queue[left];		left++;
	//	cout << u << " ";
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
int test(int u) // kiem tra BFS(u) voi tap dinh V
{
	BFS(u);
	for(int i=1; i<=n; i++)
	{
		if(chuaxet[i] == 1)	return 0;
	}
	return 1;
}
int Strong_Conected()
{
	nhap(); reinit();
	for(int u= 1; u<=n; u++)
	{
		if(test(u)==0) return 0;
		else reinit();
	}
	return 1;
}

int main()
{
	if(Strong_Conected()) cout << "\nStrong conected.!" << endl;
	else cout << "\nNo." << endl;
	return 0;
}
		
