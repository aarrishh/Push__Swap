/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:46:39 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/11 15:31:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

char	*my_strncpy(char *dest, const char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	foo_sum_tar(char const *s)
{
	int	sum_tar;

	sum_tar = 0;
	while (is_white_space(*s))
		s++;
	while (*s != '\0')
	{
		if (is_white_space(*s))
		{
			return (sum_tar);
		}
		else
		{
			s++;
			sum_tar++;
		}
	}
	return (sum_tar);
}

int	check_(char **arr, const char *s, int count)
{
	int	i;
	int	len_word;

	i = 0;
	while (i < count)
	{
		while (is_white_space(*s))
			s++;
		len_word = foo_sum_tar(s);
		arr[i] = malloc(sizeof(char) * (len_word + 1));
		if (!arr[i])
		{
			while (i >= 0)
				free(arr[i--]);
			free(arr);
			return (1);
		}
		my_strncpy(arr[i], s, len_word);
		arr[i][len_word] = '\0';
		s += (len_word + 1);
		i++;
	}
	return (0);
}

int	func_count_word(const char *s)
{
	int	i;
	int	count;
	int	ban;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (is_white_space(s[i]) && s[i] != '\0')
		{
			i++;
			ban = 0;
		}
		while (!is_white_space(s[i]) && s[i] != '\0')
		{
			i++;
			ban = 1;
		}
		if (ban == 1)
			count++;
	}
	return (count);
}

char	**ft_split(char const *s)
{
	int		count_word;
	char	**arr;

	if (s == NULL)
		return (NULL);
	count_word = func_count_word(s);
	arr = malloc(sizeof(char *) * (count_word + 1));
	if (!arr)
		return (NULL);
	arr[count_word] = NULL;
	if (check_(arr, s, count_word))
		return (NULL);
	return (arr);
}

size_t	ft_strlen1(const char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

// static int	find(char c, char *del)
// {
// 	int	i;

// 	i = 0;
// 	while (del[i] != '\0')
// 	{
// 		if (c == del[i])
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

// static int	getword(char const *s, char *del)
// {
// 	int	i;
// 	int	count_word;
// 	int	len;

// 	i = 0;
// 	count_word = 0;
// 	len = ft_strlen1(s);
// 	while (s && s[i])
// 	{
// 		while (s[i] && find(s[i], del) == 1)
// 			i++;
// 		while (s[i] && find(s[i], del) != 1)
// 			i++;
// 		if (find(s[i - 1], del) == 1 && (i == len))
// 			count_word--;
// 		count_word++;
// 	}
// 	return (count_word);
// }

// static int	malloc_char(char const *s, char *del, int *i, int *start)
// {
// 	int	len;

// 	len = 0;
// 	while (find(s[*i], del) == 1)
// 		(*i)++;
// 	*start = *i;
// 	while (s[*i] && find(s[*i], del) != 1)
// 	{
// 		len++;
// 		(*i)++;
// 	}
// 	return (len);
// }

// static char	*func_copy(char const *s, int len_current_line, int start)
// {
// 	int		j;
// 	char	*line;

// 	j = 0;
// 	line = malloc((len_current_line + 1) * sizeof(char));
// 	while (j < len_current_line)
// 	{
// 		line[j] = s[start + j];
// 		j++;
// 	}
// 	line[j] = '\0';
// 	return (line);
// }

// char	**ft_split(char const *s, char *del)
// {
// 	int		i;
// 	char	**buffer;
// 	int		ind;
// 	int		count_word;
// 	int		start;

// 	i = 0;
// 	ind = -1;
// 	count_word = getword(s, del);
// 	buffer = (char **)malloc((count_word + 1) * sizeof(char *));
// 	if (buffer == NULL)
// 		return (NULL);
// 	buffer[count_word] = NULL;
// 	while (count_word--)
// 	{
// 		buffer[++ind] = func_copy(s, malloc_char(s, del, &i, &start), start);
// 		if (!buffer[ind])
// 		{
// 			while (ind)
// 				free(buffer[--ind]);
// 			free(buffer);
// 			return (NULL);
// 		}
// 	}
// 	return (buffer);
// }
