#include "push_swap.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isdigit_or_sign(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '-' && s[i] != '+')
			return (0);
		if ((s[i] == '-' || s[i] == '+') && (i != 0 || !ft_isdigit(s[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

int	ft_is_empty(char *s)
{
	int i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}