/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <rmount@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:21:05 by rmount            #+#    #+#             */
/*   Updated: 2023/12/04 09:24:37 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
- Called by the main function
- Sets these attributes to a default of NULL or false (just in case).
*/
void	init_program(t_prog *shell)
{
	shell->envp = NULL;
	shell->commands = NULL;
	shell->user_inputs = NULL;
	shell->double_quotes = false;
	shell->prompt = NULL;
}
