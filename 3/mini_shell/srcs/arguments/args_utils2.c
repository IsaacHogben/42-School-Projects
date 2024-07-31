/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:19:31 by rmount            #+#    #+#             */
/*   Updated: 2023/11/24 14:49:29 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_quotes(char *str)
{
	if (str[0] == '\'' || str[0] == '\"')
		return (true);
	return (false);
}

char	*expand_string(t_prog *shell, char *str)
{
	int		i;
	int		j;
	t_list	*strings;

	i = 0;
	j = 0;
	if (is_quotes(str) && !shell->double_quotes)
		return (str);
	shell->double_quotes = false;
	strings = NULL;
	while (str[i])
	{
		if (str[i] == '$')
		{
			ft_lstadd_back(&strings, ft_lstnew(ft_substr(str, j, i - j)));
			j = i;
			ft_lstadd_back(&strings, ft_lstnew(get_env_var(shell,
						str, &i, &j)));
			j = i + 1;
		}
		i++;
	}
	if (j <= i)
		ft_lstadd_back(&strings, ft_lstnew(ft_substr(str, j, i - j)));
	return (lst_to_str(str, strings));
}

void	ft_lstall(t_prog *shell, t_list **head,
			char *(*f)(struct s_prog *, char *))
{
	t_list	*list;

	list = *head;
	while (list != NULL)
	{
		list->content = f(shell, list->content);
		list = list->next;
	}
}
