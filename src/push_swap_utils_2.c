#include "../include/push_swap.h"

int errormsg()
{
	write(2, "Error\n", 6);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		negative;
	size_t	i;

	i = 0;
	negative = 1;
	while ((*str >= 0x09 && *str <= 0x0d) || (*str == 0x20))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			negative *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		i = (i * 10) + (*str - '0');
		if (i > 2147483647 && negative == 1)
			exit(errormsg());
		if (i > 2147483648 && negative == -1)
			exit(errormsg());
		str++;
	}
	return (negative * i);
}
