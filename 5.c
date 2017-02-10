// 5th lecture

double power( double base, unsigned int exponent )
{
	unsigned int index;
	double result = 1;
	for( index = 1; i <= exponent; index++ )
		result *= base;
	return result;
}

int max( int a, int b )
{
	if( a > b )
		return a;
	return b;
}

int sum_digits( int n )
{
	int sum = 0;
	while( n > 0 )
	{
		sum += n % 10;
		n /= 10;
	}
	return sum;
}

int sum_squares( int n )
{
	unsigned int sum = 0, index;
	for( index = 0; index <= n; index++ )
		sum += i * i;
	return sum;
}

/*
a^1 + a^2 + ... + a^n
a^k = a^(k-1) * a
*/
double sum_powers_2( double a, int n )
{
	double sum = 0, mult = 1;
	unsigned int index;
	for( index = 1; index <= n; index++ )
	{
		mult *= a;
		sum += mult;
	}
	return sum;
}

/*
sin(x)= x - x^3/3! + x^5/5! - x^7/7! + x^9/9! - ... + (-1)^n (x^(2n+1))/(2n+1)!+-...
*/
double sine( double x, int n )
{
	double last = x, sum = x;
	unsigned int index;
	if( x == 0 )
		return 0;
	for( index = 1; index <= n; index++ )
	{
		last *= -x * x / ( ( 2 * i ) * ( 2 * i + 1 ) );
		sum += last;
	}
	return sum;
}

int gcd( int a, int b )
{
	while( ( a > 0 ) && ( b > 0 ) )
	{
		if( a > b )
			a %= b;
		else
			b %= a;
	}
	return a + b;
}

int is_perfect( int n )
{
	return ( n == sum_divisors( n ) - n );
}

int sum_divisors_1( int n )
{
	unsigned int sum = 1, index;
	if( n == 1 )
		return 1;
	for( index = 2; i * i < n; index++ )
		if( n % i == 0 )
			sum += i + n / i;
	if( i * i == n )
		sum += i;
	return sum + n;
}
