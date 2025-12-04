/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 15:39:19 by ihogben           #+#    #+#             */
/*   Updated: 2023/11/24 16:21:37 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	builtin_pwd(t_prog *shell)
{
	char	*pwd;

	pwd = find_env_var(shell, "PWD");
	printf("%s\n", pwd);
	free(pwd);
	return (true);
}

bool	builtin_env(t_prog *shell)
{
	t_env	*current;
	t_list	*lst;

	lst = shell->env_vars;
	while (lst)
	{
		current = lst->content;
		printf("%s\n", current->env_var);
		lst = lst->next;
	}
	return (true);
}

bool	builtin_echo(t_prog *shell)
{
	bool	newline;
	int		i;

	i = 0;
	newline = true;
	if (shell->commands[1] && !ft_strcmp(shell->commands[1], "-n"))
	{
		newline = false;
		i++;
	}
	i++;
	while (shell->commands[i])
	{
		printf("%s", shell->commands[i]);
		i++;
		if (shell->commands[i])
			printf(" ");
	}
	if (newline)
		printf("\n");
	return (true);
}

bool	builtin_export(t_prog *shell)
{
	if (!shell->user_inputs[1])
		return (builtin_env(shell));
	add_env_var_full(shell, shell->user_inputs[1]);
	return (true);
}

bool	builtin_unset(t_prog *shell)
{
	remove_env(shell, shell->user_inputs[1]);
	return (true);
}
