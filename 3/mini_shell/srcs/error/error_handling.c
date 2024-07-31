/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:58:45 by rmount            #+#    #+#             */
/*   Updated: 2023/11/27 11:29:40 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief   Get Error Code String
 *
 * This function converts the global exit status variable (`g_exit_status`)
 * into a corresponding error code string. The mapping is based on common
 * shell exit status conventions.
 *
 * @return  A dynamically allocated string representing the error code.
 *          The caller is responsible for freeing the allocated memory.
 */
char	*error_code(void)
{
	if (g_exit_status == 256)
		return (ft_strdup("127"));
	if (g_exit_status == 512)
		return (ft_strdup("2"));
	if (g_exit_status == 2)
		return (ft_strdup("130"));
	if (g_exit_status == 9)
		return (ft_strdup("131"));
	return (ft_itoa(g_exit_status));
}

/**
 * @brief   Free Resources and Exit the Shell
 *
 * This function performs cleanup by freeing allocated resources in the shell
 * program and then exits the program with the specified exit code.
 *
 * @param   shell   Pointer to the shell program structure.
 * @param   code    The exit code to be returned to the operating system.
 *
 * @return  This function does not return a value directly. It frees allocated
 *          resources and exits the shell program with the specified code.
 */
void	free_exit(t_prog *shell, int code)
{
	free_full_env(shell);
	free(shell->envp);
	freelist(shell->env_vars);
	free_array(shell->user_inputs);
	free(shell->prompt);
	free_array(shell->paths);
	exit(code);
}

/*
 * @brief	Modifies the exit status to an appropriate exit code when exiting
 * from a sub-process. This ensures that the main process will recieve the
 * correct exit code.
 * ! Add more as required
*/

void	normalise_exit(void)
{
	if (g_exit_status == 256)
		g_exit_status = 1;
	if (g_exit_status == 512)
		g_exit_status = 2;
}

/*
 * @brief	Log a message to standard error
 */
int	log_err(char *input, char *message, int ret)
{
	ft_putstr_fd("minishell: ", 2);
	if (input != NULL)
		ft_putstr_fd(input, 2);
	ft_putendl_fd(message, 2);
	return (ret);
}
