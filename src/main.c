#include "../include/push_swap.h"

int	main(int argc, char **argv)
{
	char *str;
	char **num;

	if (argc < 2)
		return (0);
	str = parse(argv, argc);
	str = stringerror(str);
	num = strspliterror(str);
	printf("%s", str);
	return (0);
}
