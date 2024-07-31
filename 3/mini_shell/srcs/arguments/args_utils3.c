/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:50:36 by rmount            #+#    #+#             */
/*   Updated: 2023/11/24 14:50:52 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*remove_quotes(t_prog *shell, char *str)
{
	char	end;
	char	*ret;
	int		i;

	i = 0;
	if (!is_quotes(str))
		return (str);
	end = str[i];
	i++;
	while (str[i] && str[i] != end)
		i++;
	ret = ft_substr(str, 1, i - 1);
	free(str);
	if (end == '\"')
	{
		shell->double_quotes = true;
		return (expand_string(shell, ret));
	}
	return (ret);
}

char	*get_env_var(t_prog *shell, char *str, int *i, int *j)
{
	char	*env_var;
	char	*temp;

	*i = *i + 1;
	while (str[*i] && (!ft_isspace(str[*i]) && str[*i] != '$')
		&& str[*i] != '\'')
	{
		*i = *i + 1;
	}
	if (str[*j + 1] == '?' && *j + 2 == *i)
	{
		*i = *i - 1;
		return (error_code());
	}
	*i = *i - 1;
	temp = ft_substr(str, *j + 1, *i - *j);
	env_var = find_env_var(shell, temp);
	free(temp);
	return (env_var);
}
