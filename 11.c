#include <stdlib.h>
#include <time.h>

srand( time( NULL ) );
( rand() % DOMAIN ) + OFFSET;

int isFound( int *ar, int n, int key )
{
	int i;
	for(i=0;i<n;i++)
		if(ar[i]==key)
			return 1; // i
	return 0; // -1
}

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
}