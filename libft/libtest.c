#include "libft.h"

int	main()
{
	//isalpatest
	printf("isalpha\ntest 0 = %d", ft_isalpha(64));
	printf("\ntest 1 = %d", ft_isalpha(65));
	//isdigit
	printf("\nisdigit");
	printf("\ntest 0 = %d", ft_isdigit(47));
	printf("\ntest 1 = %d", ft_isdigit(48));
	//isalnum
	printf("\nisalnum");
	printf("\ntest 0 = %d", ft_isalnum(91));
	printf("\ntest 1 = %d", ft_isalnum(90));
	//isascii
	printf("\nisascii");
	printf("\ntest 0 = %d", ft_isascii(128));
	printf("\ntest 1 = %d", ft_isascii(0));
	//isprint
	printf("\nisprint");
	printf("\ntest 0 = %d", ft_isprint(31));
	printf("\ntest 1 = %d", ft_isprint(126));
	//strlen
	printf("\nstrlen");
	printf("\ntest 5 = %zu", ft_strlen("Howdy"));
	printf("\ntest 0 = %zu", ft_strlen(""));
	//memset
	printf("\n\nmemset: Set 4 chars to 0");
	char str[] = "Test String";
	printf("\ntest 0000 String = %s", ft_memset(str, '0', 4));

	//bzero
	char bzero[] = "bzero";
	printf("\n\nbzero: sets number of chars to '/0'");
	ft_bzero(str, 0);
	printf("\nBefore bzero = %s", bzero);
	ft_bzero(str, 1);
	printf("\nAfter = %s", str);

	//memcpy
	printf("\n\nmemcpy: Copy String with ovveride");
	const char memcpy1[] = "Copied String";
	char memcpy2[] = "Destination string";
	printf("\nBefore = %s", memcpy2);
	ft_memcpy(memcpy2, memcpy1, strlen(memcpy1) + 1);
	printf("\nAfter = %s", memcpy2);

	//memmove
	printf("\n\nmemmove: move first 3 chars of string");
	char dest[] = "oldchar[]";
	const char src[]  = "newstring";
	printf("\nBefore memmove dest = %s, src = %s", dest, src);
	ft_memmove(dest, src, 3);
	printf("\nAfter memmove dest = %s, src = %s", dest, src);

	//strlcpy
	printf("\n\nstrlcpy");
	char string[] = "Hello there, Venus";
    char buffer[] = "Test Test Test";
    int r;
    r = ft_strlcpy(buffer,string,5);
    printf("\nCopied '%s' into '%s', length 18 is:  %d\n",
            string,
            buffer,
            r);

	//strlcat
	printf("\nstnlcat\n");
	char first[] = "This is ";
    char last[] = "a potentially long string";
    int r1;
    int size = 16;
    char buffer1[size];
    strcpy(buffer1,first);
    r1 = ft_strlcat(buffer1,last,size);
	printf("Resultant cat, This is a poten: ");
    puts(buffer1);
    printf("Value returned should be 33, is: %d\n",r1);
    if( r1 > size )
        puts("String truncated");
    else
        puts("String was fully copied");

	//toupper
	printf("\ntoupper\n");
	printf("Before: a, After: %c", ft_toupper('a'));
	//tolower
	printf("\n\ntolower\n");
	printf("Before: A, After: %c", ft_tolower('A'));

	//strchr
	printf("\n\nstrchr");
	const char strc[] = "Here Is The Test String";
    const char ch = 'T';
    char *ret;
    ret = ft_strchr(strc, ch);
    printf("\nString after |%c| is - |%s|\n", ch, ret);

	//strrchr
	printf("\nstrrchr");
    ret = ft_strrchr(strc, ch);
    printf("\nString after |%c| is - |%s|\n", ch, ret);

	//strcmp
	printf("\nstrcmp");
	char c1[] = "hello world";
	char c2[] = "hello";
	printf("\nfunction: %d", strncmp(c1, c2, 10));
	printf("\nresult: %d", ft_strncmp(c1, c2, 10));

	//memchr
	printf("\n\nmemchr\n");
    const char strm[] = "012345";
    const int chars[] = {'0', '1'};
    for (size_t i = 0; i < sizeof chars / (sizeof chars[0]); ++i)
    {
        const int c = chars[i];   
        const char *ps = ft_memchr(strm, c, strlen(strm));
        ps ? printf ("character '%c'(%i) found: %s\n", c, c, ps)
           : printf ("character '%c'(%i) not found\n", c, c);
    }

	//memcmp
	printf("\nmemcmp\n");
	char str1[50];
    char str2[50];
    int retc;

    memcpy(str1, "A", 6);
    memcpy(str2, "a", 6);
    retc = ft_memcmp(str1, str2, 5);
   if(retc > 0) {
      printf("str2 is less than str1");
   } else if(retc < 0) {
      printf("str1 is less than str2");
   } else {
      printf("str1 is equal to str2");
   }
   printf("\nResult: %d", retc);

   //strnstr
   printf("\n\nstrnstr");
    memcpy(str1, "Searching for\0 a word", 21);
    memcpy(str2, "ing for", 9);
	printf("\nResult of finding '%s' in '%s'", str2, str1);
	printf("\n'%s'", ft_strnstr(str1, str2, 15));

	
}