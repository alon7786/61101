void quick_sort( int *a, int first, int last )

int partition( int *a, int left, int right )
{
	int first = left;
	int pivot;
	int pos;
	/*
	add to main:
	srand( time( NULL ) );
	*/
	pos = rand() % ( left - right + 1 ) + left;
	swap( a + first, a + pos );
	pivot = a[ first ];
	while( left < right )
	{
		while( a[ right ] > pivot )
			right--;
		while( ( left < right ) && ( a[ left ] <= pivot ) )
			left++;
		if( left < right )
			swap( a + left, a + right );
	}
	pos = right;
	a[ first ] = a[ pos ];
	a[ pos ] = pivot;
	return pos;
}

int split( int *a, int left, int right )
{
	int i, last = left; // pivot = a[ left ]
	if( left < right )
	{
		for( i = left + 1; i < right; i++ )
			if( a[ i ] <= a[ left ] )
				swap( a + ( ++last ), a + i );
		swap( a + left, a + last );
	}
	return last;
}