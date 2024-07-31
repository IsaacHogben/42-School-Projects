/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 21:13:02 by rmount            #+#    #+#             */
/*   Updated: 2023/12/03 19:35:54 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
  @brief   Build Shell Prompt
 
  This function constructs the shell prompt based on user-defined preferences
  or default values. It first checks for a user-defined prompt (PS1 environment
  variable) and uses it if not blank. If the user-defined prompt is blank, the
  function constructs a default prompt using the LOGNAME, current working 
  directory, and custom formatting. The resulting prompt is then colorized 
  using ANSI escape codes for better readability.
 
  @param   shell   Pointer to the shell program structure.
*/
/*
- If there is any existing value in the shell's prompt, free it.
- Appends '@minishell' to the env var 'logname' and assigns this
  to prompt.
- Sets prompt so far to be cyan with the prettify function
- Makes the next part of the prompt assigning the value of the
  PWD env var to temp_prompt and make it magenta
- Adds the last part of the prompt and makes it yellow
- Sets the finished prompt to the shell's prompt attribute
*/
void	build_prompt(t_prog *shell)
{
	char	*prompt;
	char	*temp_prompt;

	if (shell->prompt)
		free(shell->prompt);
	prompt = free_join(find_env_var(shell, "LOGNAME"),
			ft_strdup("@minishell "));
	temp_prompt = prompt;
	prompt = prettify(prompt, CYAN);
	free(temp_prompt);
	temp_prompt = find_env_var(shell, "PWD");
	prompt = free_join(prompt, prettify(temp_prompt, MAGENTA));
	free(temp_prompt);
	prompt = free_join(prompt, prettify(" $ ", YELLOW));
	shell->prompt = prompt;
}
