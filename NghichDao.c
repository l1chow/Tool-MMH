#include <stdio.h>
#include <math.h>
//euclide mo rong

long long inverse(long long a, long long b)
{
	long long tmp = b;
	long long x1, x2, y1, y2, q, r, x, y;
	x1 = 0, x2 = 1, y1 = 1, y2 = 0;
	
	while(b > 0)
	{
		q = a / b;
		r = a - q * b;
		x = x2 - q * x1;
		y = y2 - q * y1;
		a = b;
		b = r;
		x2 = x1;
		x1 = x;
		y2 = y1;
		y1 = y;		
	}
	if(x2 < 0)
		return x2 + tmp;
	else
		return x2;
}

long long gcd (long long a, long long b)
{
	while(b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	long long a, p;
	printf("Nhap a va truong Fp: ");
	scanf("%lld%lld", &a, &p);
	if(gcd(a, p) != 1)
		printf("Khong ton tai nghich dao cua a\n");
	else
		printf("Nghich dao cua a trong truong Fp = %lld", inverse(a,p));
	
	return 0;
}