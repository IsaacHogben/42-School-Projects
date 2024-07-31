/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 22:03:42 by rmount            #+#    #+#             */
/*   Updated: 2023/12/03 19:20:49 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

int	g_exit_status;

void	restore_term_settings(struct termios *original_attr)
{
	tcsetattr(STDIN_FILENO, TCSANOW, original_attr);
}

/*
- Called by ctrl_handler
This function makes use of the termios struct defined in termios.h
We first get the terminal attributes (printing an error if it fails),
clearing the ECHOCTL flag so that the control character isn't echoed,
then we set the attributes of the termios to update it. 
*/
void	silence_c(void)
{
	struct termios	new_termios;

	if (tcgetattr(0, &new_termios))
		perror("minishell: tcsetattr");
	new_termios.c_lflag &= ~ECHOCTL;
	if (tcsetattr(0, 0, &new_termios))
		perror("minishell: tcsetattr");
}

void	backslash_handler(int sig)
{
	if (sig == SIGQUIT)
		g_exit_status = 131;
}

/*
Called whenever the SIGINT signal is received. Updates our 
exit status and makes a new line. 
rl_on_new_line tells readline that we have moved onto a new
(empty) line.
rl_replace_line replaces the contents of the rl_line_bufer with
empty spaces.
rl_redisplay refreshes the onscreen display to reflect the contents
of the rl_line_buffer (now empty spaces).
Also calls silence_c to suppress the display of '^C' on the screen
when the ctrl + C key combo is input.
*/
void	ctrl_handler(int sig)
{
	silence_c();
	if (sig == SIGINT)
	{
		g_exit_status = 130;
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

/*
- Called by shell_loop
Calls the signal function to set the action/function to be 
called when the relevant signals are sent. In this case, we
have to tell the program to activate the ctrl_handler function
when SIGINT (ctrl + C)is received, and to ignore the signal 
when SIGQUIT (ctrl + \) is received.
*/
void	set_sig_handler(void)
{
	signal(SIGINT, ctrl_handler);
	signal(SIGQUIT, SIG_IGN);
}
