strlen( char *str )
strcpy( char *dest, char *source )
strcmp( char *str1, char *str2)

char *input_long()
{
	char tempstr[ 80 ], *longnum;
	printf( "enter logn number\n" );
	gets( tempstr );
	longnum = ( char* )malloc( ( strlen( tempstr ) + 1 ) * sizeof( char ) );
	strcpy( longnum, tempstr );
	return longnum;
}