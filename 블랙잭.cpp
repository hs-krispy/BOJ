#include<iostream>
using namespace std;
void black(int * arr, int * arr2, int n)
{
	int i1,i2,i3,c=0;
	for (i1=0; i1 < n-2; i1++)
	{
		for (i2 = i1+1; i2 < n-1; i2++)
		{
			for (i3 = i2+1; i3 < n; i3++)
			{
				arr2[c] = arr[i1] + arr[i2] + arr[i3];
				c++;
			}
		}
	}
}//3가지 카드를 뽑았을때 발생하는 모든 경우의 수를 배열에 넣어주는 함수
int check(int m, int* arr2, int count)
{
	int i1, i2=0, temp1, temp2;
	for (i1 = 0; i1 < count; i1++)
	{
		temp1 = m - arr2[i1];//딜러가 외치는 카드의 값과 3개 카드 합의 차
		if (i1 == 0 && temp1 < 0)
			temp1 = -temp1;
		if (temp1 >= 0)//차가 무조건 0이거나 양수여야함
		{
			if (i1 == 0)
			{
				temp2 = temp1;
			}
			if (temp2 > temp1)
			{
				temp2 = temp1; i2 = i1;
			}
		}
	}
	return arr2[i2];//딜러가 외치는 카드의 값과 가장 가까운 값
}//m과 가장가까운 값을 결정하는 함수
int main()
{
	int i, n, m, val;
	cin >> n >> m;//카드의 개수와 딜러가 외치는 카드의 값 입력
	if (n < 3 || n>100 || m < 10 || m>300000)
	{
		cin >> n >> m;
	}
	int count = n * (n - 1) * (n - 2) / 6;//n개의 카드중 3개를 뽑는 경우
	int* arr = new int[n];//카드의 개수 크기만큼의 배열 동적생성
	int* arr2 = new int[count];//3개의 카드 합을 넣어둘 배열 동적생성
	for (i = 0; i < n; i++)
	{
		cin >> val;//카드의 개수만큼 카드값 입력
		arr[i] = val;//arr배열에 각각의 카드값 넣어줌
	}
	black(arr, arr2, n);
	cout << check(m, arr2, count);
}