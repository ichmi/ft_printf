#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int var = 10;
	int n = ft_printf("%p\n", &var);
	printf("%d\n\n", n);
	int m = printf("%p\n", &var);
	printf("%d\n", m);

	// int n = ft_printf("%x %x\n", 0, -42);
	// printf("%d\n\n", n);
	// int o = ft_printf("%x %x\n", 0, -42);
	// printf("%d\n\n", o);
	// int m = printf("%x %x\n", 0, -42);
	// printf("%d\n", m);

	// %+d / %+i
	// printf("%+d\n", 0);        // +0
	// printf("%+d\n", -0);       // +0
	// printf("%+d\n", -42);      // -42
	// printf("%+d\n", INT_MAX);  // +2147483647
	// printf("%+d\n", INT_MIN);  // -2147483648
	// printf("%+d\n", UINT_MAX); // -1
	// printf("%+d\n", 9223372036854775807LL); // -1

	// %0*d / %0*i -> Left-pads the number with zeroes 
	// printf("%0d\n", 1);         // 0
	// printf("%01d\n", 1);        // 0
	// printf("%02d\n", 1);        // 01
	// printf("%03d\n", 1);        // 001
	// printf("%04d\n", 1);        // 0001
	// printf("%05d\n", 1);        // 00001
	// printf("%01d\n", INT_MAX);  // 2147483647
	// printf("%05d\n", INT_MAX);  // 2147483647
	// printf("%020d\n", INT_MAX); // 00000000002147483647
	// printf("%0d\n", UINT_MAX);  // -1
	// printf("%01d\n", UINT_MAX); // -1
	// printf("%02d\n", UINT_MAX); // -1
	// printf("%03d\n", UINT_MAX); // -01
	// printf("%05d\n", UINT_MAX); // -0001

	// %0*u
	// printf("%0u\n", -1);        // 4294967295
	// printf("%020u\n", -1);      // 00000000004294967295
	// printf("%0u\n", 0);         // 0
	// printf("%0u\n", 1);         // 1
	// printf("%01u\n", 1);        // 1
	// printf("%02u\n", 1);        // 01
	// printf("%03u\n", 1);        // 001
	// printf("%04u\n", 1);        // 0001
	// printf("%05u\n", 1);        // 00001
	// printf("%01u\n", INT_MAX);  // 2147483647
	// printf("%05u\n", INT_MAX);  // 2147483647
	// printf("%020u\n", INT_MAX); // 00000000002147483647
	// printf("%0u\n", UINT_MAX);  // 4294967295
	// printf("%01u\n", UINT_MAX); // 4294967295
	// printf("%02u\n", UINT_MAX); // 4294967295
	// printf("%03u\n", UINT_MAX); // 4294967295
	// printf("%05u\n", UINT_MAX); // 4294967295

	// %0*x / %0*X
	// printf("%0x\n", -1);        // ffffffff
	// printf("%020x\n", -1);      // 000000000000ffffffff
	// printf("%0x\n", 0);         // 0
	// printf("%0x\n", 1);         // 1
	// printf("%01x\n", 10);       // a
	// printf("%02x\n", 10);       // 0a
	// printf("%03x\n", 10);       // 00a
	// printf("%04x\n", 10);       // 000a
	// printf("%05x\n", 10);       // 0000a
	// printf("%01x\n", INT_MAX);  // 7fffffff
	// printf("%05x\n", INT_MAX);  // 7fffffff
	// printf("%020x\n", INT_MAX); // 0000000000007fffffff
	// printf("%0x\n", UINT_MAX);  // ffffffff
	// printf("%01x\n", UINT_MAX); // ffffffff
	// printf("%02x\n", UINT_MAX); // ffffffff
	// printf("%03x\n", UINT_MAX); // ffffffff
	// printf("%05x\n", UINT_MAX); // ffffffff

	// %c
	// printf("%c %c %c\n", '0', 0, '1');   // 0 1
	// printf("%c\n", '0' + 256);           // 0
	// printf("%c\n", '0' - 256);           // 0
	// printf("%c %c %c\n", ' ', ' ', ' '); // ' 'x3

	// %d
	// printf("%d\n", -1);       // -1
	// printf("%d\n", 0);        // 0
	// printf("%d\n", 1);        // 1
	// printf("%d\n", INT_MAX);  // 2147483647
	// printf("%d\n", INT_MIN);  // -2147483648
	// printf("%d\n", UINT_MAX); // -1

	// %.s
	// printf("%.s\n", "");     // ""
	// printf("%.1s\n", "");    // ""
	// printf("%.2s\n", "");    // ""
	// printf("%.5s\n", "");    // ""
	// printf("%.s\n", "foo");  // ""
	// printf("%.1s\n", "foo"); // f
	// printf("%.2s\n", "foo"); // fo
	// printf("%.5s\n", "foo"); // foo
	// printf("%.s\n", "-");    // ""
	// printf("%.1s\n", "-");   // -
	// printf("%.2s\n", "-");   // -

	// %.d / %.i
	// printf("%.d\n", 0);   // ""
	// printf("%.1d\n", 0);  // 0
	// printf("%.2d\n", 0);  // 00
	// printf("%.5d\n", 0);  // 00000
	// printf("%.d\n", 1);   // 1
	// printf("%.1d\n", 1);  // 1
	// printf("%.2d\n", 1);  // 01
	// printf("%.5d\n", 1);  // 00001
	// printf("%.d\n", -1);  // -1
	// printf("%.1d\n", -1); // -1
	// printf("%.2d\n", -1); // -01
	// printf("%.5d\n", -1); // -00001
	// printf("%.2d\n", INT_MAX);  // 2147483647
	// printf("%.20d\n", INT_MAX); // 00000000002147483647
	// printf("%.d\n", UINT_MAX);  // -1
	// printf("%.2d\n", UINT_MAX); // -01

	// %.u
	// printf("%.u\n", 1);    // 1
	// printf("%.1u\n", 1);   // 1
	// printf("%.5u\n", 1);   // 00001
	// printf("%.u\n", -1);   // 4294967295
	// printf("%.1u\n", -1);  // 4294967295
	// printf("%.5u\n", -1);  // 4294967295
	// printf("%.20u\n", -1);       // 00000000004294967295
	// printf("%.u\n", UINT_MAX);   // 4294967295
	// printf("%.2u\n", UINT_MAX);  // 4294967295
	// printf("%.20u\n", UINT_MAX); // 00000000004294967295
	// printf("%.20u\n", LONG_MAX); // 00000000004294967295

	// %.x / %.X
	// printf("%.x\n", 0);    // ""
	// printf("%.1x\n", 0);   // 0
	// printf("%.2x\n", 0);   // 00
	// printf("%.8x\n", 0);   // 00000000
	// printf("%.x\n", 10);   // a
	// printf("%.8x\n", 10);  // 0000000a
	// printf("%.x\n", -10);  // fffffff6
	// printf("%.1x\n", -10);  // fffffff6
	// printf("%.2x\n", -10);  // fffffff6
	// printf("%.8x\n", -10);  // fffffff6
	// printf("%.10x\n", -10); // 00fffffff6
	// printf("%.20x\n", INT_MAX);  // 0000000000007fffffff
	// printf("%.20x\n", UINT_MAX); // 000000000000ffffffff

	// %-*c
	// printf("%-c\n", 0);      // ""
	// printf("%-1c\n", 0);     // ""
	// printf("%-2c\n", 0);     // ""
	// printf("%-cX\n", 0);    // "X"
	// printf("%-1cX\n", 0);   // "X"
	// printf("%-2cX\n", 0);   // " X"
	// printf("%-5cX\n", 0);   // "     X"
	// printf("%-cX\n", '0');   // 0X
	// printf("%-1cX\n", '0');  // 0X
	// printf("%-2cX\n", '0');  // 0 X
	// printf("%-3cX\n", '0');  // 0  X
	// printf("%-5cX\n", '0');  // 0    X
	// printf("%-10cX\n", '0'); // 0         X
	// printf("%-20cX\n", '0'); // 0                   X
	// printf("%-3cfoo%-2cbar%-4cbaz%-2c", 'X', 'Y', 'Z', 'X');  // X  fooY barZ   bazX %

	// %-*s
	// printf("%-sX\n", "");      // "X"
	// printf("%-1sX\n", "");     // " X"
	// printf("%-5sX\n", "");     // "     X"
	// printf("%-sX\n", "foo");   // fooX
	// printf("%-1sX\n", "foo");  // fooX
	// printf("%-2sX\n", "foo");  // fooX
	// printf("%-3sX\n", "foo");  // fooX
	// printf("%-4sX\n", "foo");  // foo X
	// printf("%-5sX\n", "foo");  // foo  X
	// printf("%-20sX\n", "foo"); // foo                 X

	// %-*d / i / x
	// printf("%-dX\n", -1);    // "-1X"
	// printf("%-1dX\n", -1);   // "-1X"
	// printf("%-2dX\n", -1);   // "-1X"
	// printf("%-3dX\n", -1);   // "-1 X"
	// printf("%-dX\n", 0);     // "0X"
	// printf("%-1dX\n", 0);    // "0X"
	// printf("%-2dX\n", 0);    // "0 X"
	// printf("%-3dX\n", 100);  // 100X
	// printf("%-4dX\n", 100);  // 100 X
	// printf("%-3dX\n", -100); // -100X
	// printf("%-4dX\n", -100); // -100X
	// printf("%-5dX\n", -100); // -100 X

	// %p
	// printf("%p\n", NULL);     // (nil)
	// printf("%p\n", 0);        // (nil)
	// printf("%p\n", 1);        // 0x1
	// printf("%p\n", -1);       // 0xffffffff
	// printf("%p\n", 10);       // 0xa
	// printf("%p\n", INT_MAX);  // 0x7fffffff
	// printf("%p\n", INT_MIN);  // 0x80000000
	// printf("%p\n", UINT_MAX); // 0xffffffff
	// printf("%p%p\n", 0, 0);   // (nil)(nil)

	// %s
	// printf("%s\n", "");          // ""
	// printf("%s\n", NULL);        // segfault...
	// printf(" %s\n", NULL);       //  (null)
	// printf("%s \n", NULL);       // (null)
	// printf("%s%s\n", "foo", ""); // foo
	// printf("%s%s\n", "", "foo"); // foo
	// printf("NULL %p NULL\n", NULL); // NULL (null) NULL

	// %#x / %#X  insere (0x) a frente do valor hexadecimal
	// printf("%#x\n", 0);  // 0  (doesnt work)
	// printf("%#x\n", 1);  // 0x1
	// printf("%#x\n", 10); // 0xa
	// printf("%#x\n", 16); // 0x10
	// printf("%#x\n", 17); // 0x11
	// printf("%#x\n", INT_MAX);  // 0x7fffffff
	// printf("%#x\n", INT_MIN);  // 0x80000000
	// printf("%#x\n", UINT_MAX); // 0xffffffff
	// printf("%#x\n", -1);       // 0xffffffff
	// printf("%#x\n", -2);       // 0xfffffffe

	// % s  (space test)
	// printf("% s\n", "");      // ""
	// printf("% s\n", NULL);    // (null)  doesnt fail
	// printf(" % s\n", NULL);   //  (null)
	// printf("% s \n", NULL);   // (null) $
	// printf("% s\n", "foo");       // foo
	// printf("% 5s\n", "foo");      //   foo
	// printf("%     5s\n", "foo");  //   foo

	// % d/i  (space test)
	// printf("%d\n", 0);      // 0  ----> ocupa 1st pos
	// printf("% d\n", 0);     //  0   ----> 2nd pos...
	// printf("%     d\n", 0); //  0
	// printf("% 0d\n", 0);    //  0
	// printf("% 1d\n", 0);    //  0
	// printf("% 2d\n", 0);    //  0
	// printf("% 3d\n", 0);    //   0
	// printf("% 5d\n", 0);    //     0
	// printf("% d\n", -1);    //     0
	// printf("% 1d\n", -1);   // -1  ----> 1st and 2nd pos (-ves)
	// printf("% 2d\n", -1);   // -1
	// printf("% 5d\n", -1);   //    -1
	// printf("% d\n", 42);    //  42 ----> 2nd pos
	// printf("% d\n", -42);   // -42 ----> 1,2,3rd pos

	// %u
	// printf("%u\n", 0);        // 0
	// printf("%u\n", 1);        // 1
	// printf("%u\n", -1);       // 4294967295
	// printf("%u\n", UINT_MAX); // 4294967295
	// printf("%u\n", 9223372036854775807LL); // 4294967295

	// %x / %X
	// printf("%x\n", 0);   // 0
	// printf("%x\n", -1);  // ffffffff
	// printf("%X\n", -2);  // FFFFFFFE
	// printf("%x\n", 1);   // 1
	// printf("%x\n", 10);  // a
	// printf("%X\n", 10);  // A
	// printf("%X\n", 16);  // 10
	// printf("%X\n", 17);  // 11

	// %*s / %*d / qlqer coisa. Apenas faz o padding before
	// printf("%s\n", "foo");    // foo
	// printf("%0s\n", "foo");   // foo
	// printf("%1s\n", "foo");   // foo
	// printf("%2s\n", "foo");   // foo
	// printf("%3s\n", "foo");   // foo
	// printf("%4s\n", "foo");   //  foo
	// printf("%5s\n", "foo");   //   foo
	// printf("%0d\n", 0);   // 0
	// printf("%1d\n", 0);   // 0
	// printf("%2d\n", 0);   //  0
	// printf("%3d\n", 0);   //   0
	// printf("%0d\n", -1);  // -1
	// printf("%1d\n", -1);  // -1
	// printf("%2d\n", -1);  // -1
	// printf("%3d\n", -1);  //  -1
	// printf("%5d\n", -1);  //    -1
	// printf("%0d\n", 1);   // 1
	// printf("%1d\n", 1);   // 1
	// printf("%2d\n", 1);   //  1
	// printf("%4d\n", 1);   //    1


	return (0);
}