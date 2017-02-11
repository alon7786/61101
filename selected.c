// lecture 5
/*
	further reading 5.c
	1. sum_powers_2
	2. sine
	3. gcd
	4. sum_divisors_1
*/

int gcd( int a, int b );
int sum_divisors_1( int n );

// lecture 6
/*
	further reading 6.c
	1. sum_powers_2
*/

// lecture 7

void swap( int *pa, int *pb );

// lecture 8
/*
	further reading 8.c
	1. min_ar_rec_3
*/

// lecture 9
/*
	further reading 9.c
	1. headers
	2. input_array_dyn_2
*/

// lecture 10
/*
	further reading 10.c
	1. headers
	2. input_long
*/

// lecture 11
/*
	further reading 11.c
	1. headers
	2. rand
	3. isFound
*/

int bin_search( int key, int *a, int n )
{
	int low, high, mid;
	low = 0;
	high = n - 1;
	while(low <= high)
	{
		mid = (low+high)/2;
		if(key==a[mid])
			return mid;
		else if(key< a[mid])
			high=mid-1;
		else // key > a[mid]
			low=mid+1;
	}
	return -1;
}

// return index
int bin_search_rec( int key, int *a, int low, int high )
{
	if( low > high )
		return -1;
	mid = ( low + high ) / 2;
	if( key == a[mid] )
		return mid;
	if( key < a[mid] )
		return bin_search_rec( key, a, low, mid - 1 );
	// else
		return bin_search_rec( key, a, mid + 1, high );
}
// return boolean
int bin_search_rec( int key, int *a, int n )
{
	if( n == 0 )
		return 0;
	if( key == a[ n / 2 ] )
		return 1;
	if( key < a[ n / 2 ] )
		return bin_search_rec( key, a, n / 2 )
	// else
		return bin_search_rec( key, a + n / 2 + 1, n - n / 2 - 1 )
}

int bin_search_first( int key, int *a, int n )
{
	int low, high, mid, result = -1;
	low = 0;
	high = n - 1;
	while( low <= high )
	{
		mid = ( low + high ) / 2;
		if( key < a[ mid ] )
			high = mid - 1;
		else if( key > a[ mid ] )
				low = mid + 1;
		else
		{
			result = mid;
			high = mid - 1;
		}
	}
	return result;
}

int bin_search_last( int key, int *a, int n )
{
	int low, high, mid, result = -1;
	low = 0;
	high = n - 1;
	while( low <= high )
	{
		mid = ( low + high ) / 2;
		if( key < a[ mid ] )
			high = mid - 1;
		else if( key > a[ mid ] )
				low = mid + 1;
		else
		{
			result = mid;
			low = mid + 1;
		}
	}
	return result;
}

// lecture 13

void merge_sort( int *a, int first, int last );

void merge( int *a, int first, int middle, int last )
{
	int left_index = first, right_index = middle + 1, temp_index = 0;
	int *temp = ( int* )malloc( ( last - first + 1 ) * sizeof( int ) );
	while( ( left_index <= middle ) && ( right_index <= last ) )
	{
		if( a[ left_index ] < a[ right_index ] )
			temp[ tmep_index++ ] = a[ left_index++ ];
		else
			temp[ tmep_index++ ] = a[ right_index++ ];
	}
	while( right_index <= last )
		temp[ tmep_index++ ] = a[ right_index++ ];
	while( left_index <= middle )
		temp[ tmep_index++ ] = a[ left_index++ ];
	for( left_index = first, tmep_index = 0; left_index <= last; left_index++, tmep_index++ )
		a[ left_index ] = temp[ tmep_index ];
	free( temp );
}

// lecture 14

void quick_sort( int *a, int first, int last );

int split( int *a, int left, int right )
{
	int i, last = left; // pivot = a[ left ]
	if( left < right )
	{
		for( i = left + 1; i <= right; i++ )
			if( a[ i ] <= a[ left ] )
				swap( a + ( ++last ), a + i );
		swap( a + left, a + last );
	}
	return last;
}

// lecture 22
/*
	further reading
	Couting sort.
*/
