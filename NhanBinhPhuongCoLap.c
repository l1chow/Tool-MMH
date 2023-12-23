#include <stdio.h>
#include <math.h>
#define true 1
#define false 0
#define MAX 100

int isPrime(int n)
{
	if(n < 2)
		return 0;
	for(int i=2; i<=sqrt(n); i++)
	{
		if(n % i == 0)
			return 0;
	}
	return 1;
}

int power(int a, int k, int m)
{
	int b = 1;
	long long A = a;
	if(k % 2 == 1)
		b = a;
	k /= 2;
	while(k > 0)
	{
		A = (A * A) % m;
		if(k % 2 == 1)
			b = (b * A) % m;
		k /= 2;
	}
	return b;
}

int main()
{
	int a,k,n;
	printf("Nhap lan luot a, k, n: ");
	scanf("%d%d%d", &a, &k, &n);
	if(isPrime(power(a,k,n)))
		printf("%d^%d mod %d = %d la SNT", a, k, n, power(a,k,n));
	else
		printf("%d^%d mod %d = %d\n%d khong la SNT", a, k, n, power(a,k,n), power(a,k,n));

	return 0;
}