typedef unsigned char byte;
#include <stdio.h>
typedef union {
	byte Byte;
	struct {
		byte b0 : 1;//the constant-expression (1) specifies the width of the field in bits
		byte b1 : 1;
		byte b2 : 1;
		byte b3 : 1;
	} Bits;
} Control;

void main()
{
	Control z;
	z.Byte = 4;
	printf("Bits: %d %d %d %d\n", z.Bits.b3, z.Bits.b2, z.Bits.b1, z.Bits.b0);
}

