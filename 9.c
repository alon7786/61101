int *p = ( int* )malloc( n * sizeof( int ) );
int *p = ( int* )calloc( n, sizeof( int ) );
int *p = ( int* )realloc( p, new_size * sizeof( int ) )
void free( void *ptr )

int *new_copy_array( int *a, int n )
{
	int i, *b;
	b = ( int* )malloc( n * sizeof( int ) );
	if( b )
		for( i = 0; i < n; i++ )
			b[ i ] = a[ i ];
	return b;
}

void input_array_dyn_2( double **pa, int n )
{
	int i;
	*pa = ( double* )malloc( n * sizeof( double ) );
	assert( *pa );
	printf( "enter the array of length %d\n", n );
	for( i = 0; i < n; i++ )
		scanf( "%lf", ( *pa ) + i );
}