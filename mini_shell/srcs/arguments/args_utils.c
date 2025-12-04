/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:43:58 by rmount            #+#    #+#             */
/*   Updated: 2023/12/03 21:08:18 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*sub_quotes(char *str, int *current)
{
	char	end;
	char	*ret;
	int		i;

	i = *current;
	end = str[i];
	i++;
	while (str[i] && str[i] != end)
		i++;
	ret = ft_substr(str, *current, i - *current + 1);
	*current = i + 1;
	return (ret);
}

char	*lst_to_str(char *str, t_list *list)
{
	char	*temp;
	t_list	*head;

	head = list;
	if (list)
	{
		temp = str;
		str = list->content;
		free(temp);
		while (list->next)
		{
			str = free_join(str, list->next->content);
			list = list->next;
		}
		freelist(head);
	}
	return (str);
}

char	*sanitise_tokens(t_prog *shell, t_list **list)
{
	ft_lstall(shell, list, expand_string);
	ft_lstall(shell, list, remove_quotes);
	return (lst_to_str(ft_strdup(""), *list));
}

/*
- Called by make_arg_list
- 
*/
bool	is_bookend(char *str, int *current)
{
	char	bookend;
	int		i;

	i = *current;
	if (str[i] != '\'' && str[i] != '\"')
		return (true);
	if (!str[i + 1])
		return (false);
	bookend = str[i];
	i += 1;
	while (str[i])
	{
		if (str[i] == bookend)
			return (true);
		i++;
	}
	*current += 1;
	return (false);
}

char	*cpy_str(t_prog *shell, char *input, int *current)
{
	t_list	*list;
	int		i;

	list = NULL;
	i = *current;
	while (input[i] && !ft_isspace(input[i]))
	{
		if ((input[i] == '|' || is_bookend(input, &i))
			&& (input[i] == '\'' || input[i] == '\"'))
		{
			ft_lstadd_back(&list,
				ft_lstnew(ft_substr(input, *current, i - *current)));
			*current = i;
			if (input[i] == '|')
				return (sanitise_tokens(shell, &list));
			ft_lstadd_back(&list, ft_lstnew(sub_quotes(input, &i)));
			*current = i;
		}
		else
			i++;
	}
	ft_lstadd_back(&list, ft_lstnew(ft_substr(input, *current, i - *current)));
	*current = i;
	return (sanitise_tokens(shell, &list));
}
