int sum_array( int *ar, int size )
{
	unsigned int index;
	int sum = 0;
	for( index = 0; index < size; index++ )
		sum += p[ i ];
	return sum;
}

int min_ar_rec_3( int *a, int size )
{
	int min_l, min_r;
	if( n == 1 )
		return *a;
	min_l = min_ar_rec_3( a, n / 2 );
	min_r = min_ar_rec_3( a + n / 2, n - n / 2 );
	return min_l < min_r ? min_l : min_r;
}