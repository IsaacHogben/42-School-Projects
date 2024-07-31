/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_redir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihogben <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 11:31:03 by ihogben           #+#    #+#             */
/*   Updated: 2023/11/12 11:31:04 by ihogben          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief   Handle Error in Redirection
 *
 * This function checks if a specified redirection keyword is present in the
 * user inputs of the shell. If the redirection keyword is not followed by a
 * corresponding value, an error message is printed, and the program exits.
 *
 * @param   redir   The redirection keyword to be checked.
 * @param   shell   Pointer to the shell program structure.
 *
 * @return  This function does not return a value. It prints an error message
 *          and exits the program if the specified redirection is missing.
 */
void	error_redir(char *redir, t_prog *shell)
{
	int	i;

	i = 0;
	while (shell->user_inputs[i]
		&& ft_strcmp(shell->user_inputs[i], redir))
		i++;
	if (!shell->user_inputs[i + 1])
	{
		perror("minishell: Redirect missing!\n");
		free_exit(shell, 2);
	}
}

/*
 * @brief   Remove Redirection and Its Argument from User Inputs
 *
 * This function removes a specified redirection operator and its associated
 * argument from the array of user inputs in the shell program.
 *
 * @param   redir   The redirection operator to be removed.
 * @param   shell   Pointer to the shell program structure.
 */
void	remove_redir(char *redir, t_prog *shell)
{
	char	**new_cmd;
	int		i;
	int		j;

	i = 0;
	while (shell->user_inputs[i])
		i++;
	new_cmd = malloc(sizeof(*new_cmd) * (i - 1));
	i = 0;
	j = 0;
	while (shell->user_inputs[i])
	{
		if (!ft_strcmp(shell->user_inputs[i], redir))
			i += 2;
		if (!shell->user_inputs[i])
			break ;
		new_cmd[j++] = ft_strdup(shell->user_inputs[i++]);
	}
	new_cmd[j] = NULL;
	free_array(shell->user_inputs);
	shell->user_inputs = new_cmd;
}
