/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 14:37:39 by rmount            #+#    #+#             */
/*   Updated: 2023/12/03 19:40:34 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	
- Called by main function
- After initialisation, shell_loop runs until the program is exited.
- build_prompt: builds the prompt to be displayed in the shell
- Resets the shell struct's pid to 0
- Resets *input to NULL
- Sets signal handling
- Reads the prompt entered by the user into 'input'
- Tests that input exists - if not restart from top of shell_loop.
  If our input is blank at this stage it is because ctrl + d has been pressed
- add_history: Adds the input to the shell's history
  add_history is an inbuilt function in the readline library which will add
  the input to the terminal history
- split_args: validates the input and splits the arguments into separate strings
*/
void	shell_loop(t_prog *shell)
{
	char	*input;

	while (1)
	{
		build_prompt(shell);
		shell->pid = 0;
		input = NULL;
		set_sig_handler();
		input = readline(shell->prompt);
		if (is_blank(input))
			continue ;
		add_history(input);
		split_args(shell, input);
		std_sort(shell);
		if (shell->user_inputs)
			command(shell);
	}
}

/*
- Instantiates the shell struct
- Voids ac and av as we are not using them
- Initialises the program struct's attributes and env vars,
  then enters the main loop of the shell
*/
int	main(int ac, char *av[], char *envp[])
{
	t_prog	shell;

	(void)ac;
	(void)av;
	init_program(&shell);
	init_env_list(&shell, envp);
	convert_envp_to_array(&shell);
	shell_loop(&shell);
	return (0);
}
