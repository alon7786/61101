int factorial( int n )
{
	if( n <= 1 )
		return 1;
	return n * factorial( n - 1 );
}

double sum_powers_2( double a, int n )
{
	double sum = a;
	unsigned int index;
	for( index = 2; index <= n; index++ )
		sum = a + a * sum;
	return sum;
}

int gcd_rec( int a, int b )
{
	if( b == 0 )
		return a;
	return gcd_rec( b, a % b );
}

void write_rev()
{
	char ch;
	if( ( ch = getchar() ) != '*' )
	{
		write_rev();
		putchar( ch );
	}
}