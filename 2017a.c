#include <stdio.h> /* printf */
#include <stdlib.h> /* calloc, free */
#include <string.h> /* strlen */

#define R 4
#define C 3

// solution for ex 1
int is_even( int num, int dig )
{
	if( num < 10 )
		return ( num == dig ) ? 0 : 1;
	return ( ( ( ( num % 10 ) == dig ) ? 1 : 0 ) + is_even( num / 10, dig ) ) % 2;
}
// tester for sol 1
void is_even_tester()
{
	int num = 897076;
	printf( "num: %d, dig: %d, result: %d (should be: %d).\n",
				num, 7, is_even( num, 7 ), 1);
	printf( "num: %d, dig: %d, result: %d (should be: %d).\n",
				num, 9, is_even( num, 9 ), 0);
	printf( "num: %d, dig: %d, result: %d (should be: %d).\n",
				num, 5, is_even( num, 5 ), 1);
	printf( "num: %d, dig: %d, result: %d (should be: %d).\n",
				22, 2, is_even( 22, 2 ), 1);
	printf( "num: %d, dig: %d, result: %d (should be: %d).\n",
				12, 2, is_even( 12, 2 ), 0);
	printf( "num: %d, dig: %d, result: %d (should be: %d).\n",
				0, 0, is_even( 0, 0 ), 0);
}

// solution for ex 2
int missing_max( int *a, int n )
{
	int index, *counts = ( int* )calloc( n + 1, sizeof( int ) );
	for( index = 0; index < n; index++ )
		counts[ a[ index ] ]++;
	for( index = n; index >= 0; index-- )
		if( !counts[ index ] ) // counts[ index ] == 0
			return index;
	free( counts );
}
// tester  for sol 2
void missing_max_tester()
{
	int a[ 7 ] = { 7, 4, 5, 1, 6, 4, 0 };
	printf( "Missing maximum number in domain: [0,%d] is: %d (should be: %d).\n",
												7, missing_max( a, 7 ), 3 );
}

// solution for ex 3
void remove_spaces( char *str )
{
	int index, count = 0;
	for( index = 0; index < strlen( str ); index++ )
		if( str[ index ] == ' ' )
			count++;
		else
			str[ index - count ] = str[ index ];
	str[ strlen( str ) - count ] = '\0';
}
// tester for sol 3
void remove_spaces_tester()
{
	char str[ 30 ] = "I     love      israel";
	printf( "%s without spaces: ", str );
	remove_spaces( str );
	printf( "%s (should be: Iloveisrael).\n", str );
}

// solution for ex 4
void min_distance( int key, int *a, int  n , int *vala, int *valb )
{// find max < key < min
	int min, max, index, first_max = 1, first_min = 1;
	for( index = 0; index < n; index++ )
	{
		if( a[ index ] < key )
		{
			if( first_max )
			{
				max = a[ index ];
				first_max = 0;
			}
			else if( a[ index ] > max )
				max = a[ index ];
		}
		else if( a[ index ] > key )
		{
			if( first_min )
			{
				min = a[ index ];
				first_min = 0;
			}
			else if( a[ index ] < min )
				min = a[ index ];
		}
	}
	if( first_max || first_min ) // min or max not found
	{
		*vala = -1;
		*valb = -1;
	}
	else
	{
		*vala = max;
		*valb = min;
	}
}
// tester for sol 4
void min_distance_tester()
{
	int vala, valb, a[ 3 ] = { 4, 4, 4 }, b[ 9 ] = { 33, 64, -3, 23, 55, 96, 12, 54, 66 };
	min_distance( 4, a, 3, &vala, &valb );
	printf( "a = { 4, 4, 4 }, size = 3, key = 4\n");
	printf( "vala: %d, (should be: -1)\n", vala);
	printf( "valb: %d, (should be: -1)\n", valb);
	min_distance( 65, b, 9, &vala, &valb );
	printf( "b = { 33, 64, -3, 23, 55, 96, 12, 54, 66 }, size = 9, key = 65\n");
	printf( "vala: %d, (should be: 64)\n", vala);
	printf( "valb: %d, (should be: 66)\n", valb);
}

// solution for ex 5
void sum_sub_mat( int a[][ C ], int b[][ C ] )
{
	int col, row, row_sum = 0;
	b[ 0 ][ 0 ] = a[ 0 ][ 0 ];
	for( col = 1; col < C; col++ )
		b[ 0 ][ col ] = a[ 0 ][ col ] + b[ 0 ][ col - 1 ];
	for( row = 1; row < R; row++ )
		b[ row ][ 0 ] = a[ row ][ 0 ] + b[ row - 1 ][ 0 ];
	for( row = 1; row < R; row++ )
	{
		row_sum = a[ row ][ 0 ];
		for( col = 1; col < C; col++ )
		{
			row_sum += a[ row ][ col ];
			b[ row ][ col ] = row_sum + b[ row - 1][ col ];
		}
	}
}
// tester for sol 5
void print_mat( int a[][ C ] )
{
	int col, row;
	for( row = 0; row < R; row++ )
	{
		for( col = 0; col < C; col++ )
			printf( "%3d ", a[ row ][ col ] );
		printf( "\n" );
	}
}
void sum_sub_mat_tester()
{
	int a[ R ][ C ] = {
		{ 3, 8, 34 },
		{ 43, 4, 6 },
		{ 7, 23, 55 },
		{ 2, 5, 0 }
	}, b[ R ][ C ] = { 0 },
	c[ R ][ C ] = {
		{ 3, 11, 45 },
		{ 46, 58, 98 },
		{ 53, 88, 183 },
		{ 53, 95, 190 }
	};
	printf( "mat a:\n" );
	print_mat( a );
	printf( "mat b:\n" );
	print_mat( b );
	sum_sub_mat( a, b );
	printf( "mat b after summation:\n" );
	print_mat( b );
	printf( "mat b should be:\n" );
	print_mat( c );
}

int main()
{
	// ex 1 tester:
	is_even_tester();
	// ex 2 tester:
	missing_max_tester();
	// ex 3 tester:
	remove_spaces_tester();
	// ex 4 tester:
	min_distance_tester();
	// ex 5 tester:
	sum_sub_mat_tester();
	return 0;
}