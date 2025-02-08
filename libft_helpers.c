#include "push_swap.h"

int ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len] != '\0')
	{
		len++;
	}
	return len;
}

void	atoi_clean(char **numbers)
{
	free_all(numbers);
	printf("Error: Invalid number\n");
    exit(1);
}
long	ft_atoi(char *str, char **numbers)
{
	long	nb;
	int		sign;
	int		i;

	nb = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		nb = nb * 10 + str[i++] - '0';
		if((nb > INT_MAX && sign == 1) || (sign == -1 && nb < INT_MIN))
			atoi_clean(numbers);
	}
	if((str[i] == '-' || str[i] == '+') && (nb == 0 || ft_isdigit(str[i + 1]) || ft_isdigit(str[i - 1]) || str[i + 1] == '\0'))
		atoi_clean(numbers);
	nb = nb * sign;
	return (nb);
}

char	*ft_checksep(const char *s, char c, int *index)
{
	int		start;
	int		i;
	int		end;
	char	*ptr;

	start = *index;
	while (s[start] && s[start] == c)
		start++;
	end = start;
	while (s[end] && s[end] != c)
		end++;
	*index = end + 1;
	if (start >= end)
		return (NULL);
	ptr = (char *)malloc(end - start + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (start < end)
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_count_words(char *s, char c)
{
	size_t	count;
	size_t	i;
	int		inword;

	count = 0;
	i = 0;
	inword = 0;
	while (s[i])
	{
		if (!inword && s[i] != c)
		{
			inword = 1;
			count++;
		}
		if (inword && s[i] == c)
			inword = 0;
		i++;
	}
	return (count);
}

void	ft_split(char *s, char c, char **arr)
{
	static size_t	i;
	int		index;
	size_t count = 0;

	if (!s)
		return ;
	index = 0;
	while (count < ft_count_words(s, c))
	{
		arr[i] = ft_checksep(s, c, &index);
		if (!arr[i])
		{
			while (i > 0)
				free(arr[--i]);
			free(arr);
			return ;
		}
		i++;
		count++;
	}
	arr[i] = NULL;
	// return (arr + i);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isdigit_or_sign(char *s)
{
	int i = 0;
	while (s[i])
	{
		if ((s[i] < '0' || s[i] > '9') && s[i] != '-' && s[i] != '+')
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


