#include <iostream>
using namespace std;

void eratos(int n, int m)
{
	int i,j;
	int* arr = new int [m+1];//2���� M������ ���ڵ��� �ֱ����� �迭(�ε��� ��ȣ 0,1�� ���X)
	for (i=2; i < m+1; i++)
	{
		arr[i] = i;
	}//arr�ʱ�ȭ
	bool* arr2 = new bool [m+1] ();//�ش� �ε����� ���ڰ� �Ҽ����� �ƴ��� �Ǻ�, �迭 0���� �ʱ�ȭ
	for (i=2; i < m+1; i++)
	{
		for (j = i+i; j<=m+1 ; j+=i) 
		{
			arr2[j] = 1;
		}
	}
	for (i = 2; i < m+1; i++)
	{
		if (arr2[i] == 0 && arr[i]>=n)
		{
			cout << arr[i] << "\n";
		}
	}
	delete[] arr;
	delete[] arr2;
}
int main()
{
	int N, M;
	cin >> N >> M;//�Է°� 2��
	eratos(N, M);
	return 0;
}