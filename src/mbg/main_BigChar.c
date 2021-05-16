#include "myBigChar.h"
#include "../mt/myTerm.h"
#include "../msc/mySimpleComputer.h"

#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <unistd.h>


int main()
{
    int n, m;
    // int s[2] = {0xFF8080F8, 0x80808080}; 
    int s[2] = {0x0, 0x0}; 


    BC_SIZE = 2;

    int fd;
    int result;
    int c;

    mt_clrscr();
    mt_getscreensize(&n, &m);
    bc_box(10, 10, 10, 10);
    bc_box(10, 30, 10, 10);
    bc_box(10, 50, 10, 10);

    mt_gotoXY(10, 13); printf("Value");
    mt_gotoXY(10, 33); printf("File");
    mt_gotoXY(10, 53); printf("Bit");

    bc_initBigChar(s, '6');
    bc_printbigchar(s, 11, 11, DEFAULT, DEFAULT);

    fd = open("file_bin/test.txt", O_WRONLY);
    result = bc_bigcharwrite(fd, s, 1);
    close(fd);

    fd = open("file_bin/test.txt", O_RDONLY);
    result = bc_bigcharread(fd, s, 1, &c);
    bc_printbigchar(s, 11, 31, DEFAULT, DEFAULT);
    
    close(fd);

    bc_setbigcharpos(s, 5, 3, 1);
    bc_setbigcharpos(s, 5, 4, 1);
	bc_printbigchar(s, 11, 51, DEFAULT, DEFAULT);

	bc_getbigcharpos(s, 5, 3, &c);

	bc_getbigcharpos(s, 5, 4, &c);

    printf("\nValue in [5, 3] = %d\n", c);
	printf("Value in [5, 4] = %d\n", c);
    printf("Result of writing: %d\n", result);
    printf("Result: %d\n  c: %d\n  descryptor: %d\n", result, c, fd);

    return 0;
}