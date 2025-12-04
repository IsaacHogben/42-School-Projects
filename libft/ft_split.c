/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:31:28 by ihogben           #+#    #+#             */
/*   Updated: 2023/07/13 16:31:31 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns an array
// of strings obtained by splitting ’s’ using the
// character ’c’ as a delimiter. The array must end
// with a NULL pointer.

// static int	ft_wordcount(char *str, char c)
// {
// 	int	words;
// 	int	i;

// 	words = 0;
// 	i = 0;
// 	while (str[i])
// 	{
// 		if (str[i] != c)
// 		{
// 			words++;
// 			while (str[i] != c && str[i])
// 				i++;
// 			if (str[i] == '\0')
// 				return (words);
// 		}
// 		i++;
// 	}
// 	return (words);
// }

// static int	*ft_wordpos(char *str, char c, int wordcount)
// {
// 	int	i;
// 	int	words;
// 	int	*locations;

// 	locations = (malloc(sizeof(int) * (wordcount - 1)));
// 	i = 0;
// 	words = 0;
// 	while (str[i])
// 	{
// 		if (str[i] != c)
// 		{
// 			locations[words] = i;
// 			words++;
// 			while (str[i] != c && str[i])
// 				i++;
// 			if (str[i] == '\0')
// 				return (locations);
// 		}
// 		i++;
// 	}
// 	return (locations);
// }

// char	*ft_stralloc(char *str, char c, int *wordpos, int word)
// {
// 	int		j;
// 	int		l;
// 	char	*retstr;

// 	j = 0;
// 	l = 0;
// 	while (str[wordpos[word] + j] != c && str[wordpos[word] + j] != '\0')
// 		j++;
// 	retstr = malloc(sizeof(char) * (j + 1));
// 	if (retstr == NULL)
// 		return (NULL);
// 	while (l < j && str[wordpos[word] + l])
// 	{
// 		ft_strlcpy(retstr, &str[wordpos[word]], j + 1);
// 		l++;
// 	}
// 	return (retstr);
// }

// // static void	ft_free(char *strs)
// // {
// // 	int	i;

// // 	i = 0;
// // 	while (strs[i])
// // 	{
// // 		free(strs);
// // 		i++;
// // 	}
// // 	free(strs);
// // }

// char	**fst_split(char const *str, char c)
// {
// 	int		*wordlocations;
// 	int		wordcount;
// 	char	**strs;
// 	int		i;

// 	i = 0;
// 	if (str == NULL)
// 		return (NULL);
// 	wordcount = ft_wordcount((char *)str, c);
// 	if (wordcount)
// 		wordlocations = ft_wordpos((char *)str, c, wordcount);
// 	strs = malloc(sizeof(char *) * (wordcount + 1));
// 	if (strs == NULL)
// 		return (NULL);
// 	while (i < wordcount)
// 	{
// 		strs[i] = ft_stralloc((char *)str, c, wordlocations, i);
// 		i++;
// 	}
// 	strs[i] = NULL;
// 	return (strs);
// }

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	count;

	if (!*s)
		return (0);
	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s != c && *s)
			s++;
	}
	return (count);
}

char	**ft_split(char const *str, char c)
{
	char	**retchr;
	size_t	word_len;
	int		i;

	retchr = (char **)malloc((ft_wordcount(str, c) + 1) * sizeof(char *));
	if (!str || !retchr)
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str)
		{
			if (!ft_strchr(str, c))
				word_len = ft_strlen(str);
			else
				word_len = ft_strchr(str, c) - str;
			retchr[i++] = ft_substr(str, 0, word_len);
			str += word_len;
		}
	}
	retchr[i] = NULL;
	return (retchr);
}

// int	main()
// {
// 	char	**strs;
// 	strs = ft_split("word", ' ');

// }