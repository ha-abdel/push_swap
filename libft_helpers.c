#include "push_swap.h"

int	ft_atoi(const char *str)
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
		nb = nb * 10 + str[i] - '0';
		i++;
	}
	nb = nb * sign;
	return (nb);
}

static char	*ft_checksep(const char *s, char c, int *index)
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

static size_t	ft_count_words(char const *s, char c)
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

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**arr;
	int		index;

	if (!s)
		return (NULL);
	i = 0;
	index = 0;
	arr = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	while (i < ft_count_words(s, c))
	{
		arr[i] = ft_checksep(s, c, &index);
		if (!arr[i])
		{
			while (i > 0)
				free(arr[--i]);
			free(arr);
			return (NULL);
		}
		i++;
	}
	arr[i] = NULL;
	return (arr);
}