/* pg: 108 ECP */

/* Using this as a static library
 * Create a corresponding header: 108_static_linker_lib.h
 * Compile this file to generate object file
 * # gcc -c 108_01_static_linker_lib.c -o 108_01_static_linker_lib.o
 * Produce static library
 * # ar rcs libsumthisup.a 108_01_static_linker_lib.o
 * Use this in another program
 * with -L pointed to this directory and -lsumthisup at the rightmost end
 * # gcc -Wall -L./ 108_02_static_linker_use.c -lsumthisup
 */

/*
 * NOTE: if the library is provided BEFORE the symbol table is created,
 * i.e. before the 108_02_static_linker_use.c file in the arg,
 * a linking error to the tune of undefined reference will be generated
 *
 * # gcc -Wall -L./ -lsumthisup 108_02_static_linker_use.c
 * will generate:
 *
 * /tmp/cck4iJ82.o: In function `main':
 * 108_02_static_linker_use.c:(.text+0x29): undefined reference to `sumthisup'
 * collect2: ld returned 1 exit status
 *
 * Only when the linker encounters the .c file
 * (rather the corresponding .o file)
 * will it generate symbol table and start looking for undefined symbols
 * Upon which it will look at all the "following" library files!
 */

int sumthisup(int a, int b)
{
	return (a + b);
}
