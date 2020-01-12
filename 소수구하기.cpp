#include <iostream>
using namespace std;

void eratos(int n, int m)
{
	int i,j;
	int* arr = new int [m+1];//2부터 M까지의 숫자들을 넣기위한 배열(인덱스 번호 0,1은 사용X)
	for (i=2; i < m+1; i++)
	{
		arr[i] = i;
	}//arr초기화
	bool* arr2 = new bool [m+1] ();//해당 인덱스의 숫자가 소수인지 아닌지 판별, 배열 0으로 초기화
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
	cin >> N >> M;//입력값 2개
	eratos(N, M);
	return 0;
} 
