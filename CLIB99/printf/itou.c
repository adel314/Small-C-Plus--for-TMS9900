/*
 * itou -- convert nbr to unsigned decimal string of width sz
 *	       right adjusted, blank filled ; returns str
 *
 *	      if sz > 0 terminate with null byte
 *	      if sz  =  0 find end of string
 *	      if sz < 0 use last byte for data
 */
#include "stdio.h"
itou(nbr, str, sz)
int nbr ;
char str[] ;
int sz ;
{
	int lowbit ;

	if ( sz > 0 )
		str[--sz] = NULL ;
	else if ( sz < 0 )
			sz = -sz ;
		else
			while ( str[sz] != NULL )
				++sz ;
	while ( sz ) {
		lowbit = nbr & 1 ;
		nbr = (nbr >> 1) & 0x7fff ;  /* divide by 2 */
		str[--sz] = ( (nbr%5) << 1 ) + lowbit + '0' ;
		if ( (nbr/=5) == 0 )
			break ;
	}
	while ( sz )
		str[--sz] = ' ' ;
	return str ;
}

