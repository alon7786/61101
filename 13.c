void merge_sort( int *a, int first, int last )

int *merge_arrays( int *a, int *b, int size_of_a, int size_of_b )
{
	int *c = ( int* )malloc( ( size_of_a + size_of_b ) * sizeof( int ) );
	int index_of_a = 0, index_of_b = 0, index_of_c = 0;
	while( ( index_of_a < size_of_a )
		&& ( index_of_b < size_of_b ) )
	{
		if( a[ index_of_a ] < b[ index_of_b ] )
			c[ index_of_c++ ] = a[ index_of_a++ ];
		else
			c[ index_of_c++ ] = b[ index_of_b++ ];
	}
	while( index_of_a < size_of_a )
		c[ index_of_c++ ] = a[ index_of_a++ ];
	while( index_of_b < size_of_b )
		c[ index_of_c++ ] = b[ index_of_b++ ];
	return c;
}

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