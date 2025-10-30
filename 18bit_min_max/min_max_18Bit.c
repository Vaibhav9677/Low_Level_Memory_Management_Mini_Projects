#include<stdio.h>

// Define aliases for unsigned types for readability
typedef unsigned int u32;
typedef unsigned short int u16;
typedef unsigned char unchar;

// Define memory buffer size
#define len 1024

#define count len-4					// Tracks how many values have been processed
#define re_min len-8				// Stores the minimum extracted value
#define re_max len-12				// Stores the maximum extracted value
#define idx len-14					// Index pointer for reading data
#define shift mem[len-15]			// Current bit shift for unpacking

// Macros to read 16-bit and 32-bit values from the memory buffer
#define R16(x) (*(u16*)&mem[x])
#define R32(x) (*(u32*)&mem[x])

// Macro to extract an 18-bit value from a given memory location using bit shift
#define R18(x,shift) ((R32(x)<<14-shift)>>14)

int main()
{
	unchar mem[len] = {0x4,0,0,0,0x80,0,0,1,0,0x10,0x80,0x19,0};

	// Set initial maximum to 0	
	R32(re_max) = 0;
	// Set initial minimum to maximum possible value (~0)
	R32(re_min) = ~0;
	// Start index after the 4-byte count
	R16(idx) = 4;

	// Initial shift is 0
	shift = 0;

	// Outer loop: continue until 'count' reaches the total number of values

	printf("Numbers : \n");
	while(R32(count) < R32(0))
	{
		// Inner loop: read values from the buffer until shift reaches 8 bits
		while(R32(count) < R32(0) && shift < 8)
		{
			// Extract the 18-bit value from current index with current shift

			// Update minimum if current value is smaller

			printf("%d : %d\n",R32(count)+1,R18(R16(idx),shift));
			if(R18(R16(idx),shift) < R32(re_min))
			{
				R32(re_min) = R18(R16(idx),shift);
			}
			
			// Update maximum if current value is larger
			if(R18(R16(idx),shift) > R32(re_max))
			{
				R32(re_max) = R18(R16(idx),shift);
			}

			// Move to the next 18-bit field in the same word
			R16(idx) = R16(idx) + 2;		// Advance index by 2 bytes (next word)
			R32(count) = R32(count) + 1;	// Increment processed count
			shift = shift +2;				// Increase shift to access next field
		}
		R16(idx) = R16(idx) + 1;			//increament count for number
		shift = 0;
	}

	// Print the result
	printf("Minmun : %d\n",R32(re_min));
	printf("Maximun : %d\n",R32(re_max));
	return 0;
}
