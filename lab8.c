/*--------------------------------------------------------------*/
/* Cody Wuco         */
/* Lab8 Spring 2019  */

#include <stdio.h>
#include <stdlib.h>

     /* function prototypes */
void bitprint (unsigned num);
int rotate_left(unsigned num, int n);

/*-----------------------------------------*/

int main (void)
{
    int left_count;
    unsigned num;        /* the starting number */
    unsigned shifted_num;
    printf("\nCody Wuco.  Lab 8.\n");

    do
    {
	/* read a unsigned integer */
	printf("\nEnter an unsigned integer value (0 to stop):  ");
	scanf("%u", &num); 

	if (num != 0)
	{
	    printf("\nEnter an integer value for the left shift:  ");
	    scanf("%d", &left_count); 
	    printf("\nOriginal is %i \n", num);
			
	    bitprint(num);
	    shifted_num = rotate_left(num, left_count);
	    bitprint(shifted_num);
	    printf("Shifted it is %i \n", shifted_num);
	}

    } while (num != 0);

    printf("\n\n");
    return EXIT_SUCCESS;		
}

/*--------------------------------------------------------------*/

void bitprint (unsigned num)
{
    unsigned mask;
    int bit, count, nbits;

    /* determine the word size in bits and set the initial mask */
    nbits = 8 * sizeof(unsigned);   /* finds number of bytes in an unsigned 
		                       number and changes it to bits */
    mask = 0x1 << (nbits - 1);	    /* place 1 in left most position 
			               starting place for the mask */

    for(count = 1; count <= nbits; count++)
    {
	bit = (num & mask) ? 1: 0;	/* set display bit on or off */
	printf("%x", bit);		/* print display bit */

	if(count %4 == 0)
	    printf(" ");	/* blank space after every 4th digit */
	mask >>= 1;		/* shift mask 1 position to the right */
    }

    printf("\n");

    return;
}
/*--------------------------------------------------------------*/
int rotate_left(unsigned num, int n)
{
    int count, bit, nbits;
    unsigned mask;

    nbits = 8 * sizeof(unsigned);	/* finds number of bytes in an int 
				           unsigned number and changes it to bits */
    mask = 0x1 << (nbits - 1);		/* place 1 in left most position 
					   starting place for the mask */


    // put the loop here and then the return
    int i;
    for( i = 0; i < n; i++)
    {
        bit = num & mask;
        num = num << 1;
        
        if ( bit != 0){ num += 1;}
    }
    return num;
}


/*--------------------------------------------------------------*/

