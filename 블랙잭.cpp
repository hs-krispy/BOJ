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
}//3���� ī�带 �̾����� �߻��ϴ� ��� ����� ���� �迭�� �־��ִ� �Լ�
int check(int m, int* arr2, int count)
{
	int i1, i2=0, temp1, temp2;
	for (i1 = 0; i1 < count; i1++)
	{
		temp1 = m - arr2[i1];//������ ��ġ�� ī���� ���� 3�� ī�� ���� ��
		if (i1 == 0 && temp1 < 0)
			temp1 = -temp1;
		if (temp1 >= 0)//���� ������ 0�̰ų� ���������
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
	return arr2[i2];//������ ��ġ�� ī���� ���� ���� ����� ��
}//m�� ���尡��� ���� �����ϴ� �Լ�
int main()
{
	int i, n, m, val;
	cin >> n >> m;//ī���� ������ ������ ��ġ�� ī���� �� �Է�
	if (n < 3 || n>100 || m < 10 || m>300000)
	{
		cin >> n >> m;
	}
	int count = n * (n - 1) * (n - 2) / 6;//n���� ī���� 3���� �̴� ���
	int* arr = new int[n];//ī���� ���� ũ�⸸ŭ�� �迭 ��������
	int* arr2 = new int[count];//3���� ī�� ���� �־�� �迭 ��������
	for (i = 0; i < n; i++)
	{
		cin >> val;//ī���� ������ŭ ī�尪 �Է�
		arr[i] = val;//arr�迭�� ������ ī�尪 �־���
	}
	black(arr, arr2, n);
	cout << check(m, arr2, count);
}