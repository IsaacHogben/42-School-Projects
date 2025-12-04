/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handling_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 14:26:43 by rmount            #+#    #+#             */
/*   Updated: 2023/11/24 15:52:21 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
Allocates memory for an integer array
Returns a int variable that now can be used as the signal status
*/
int	*heredoc_signal_get(void)
{
	static int	*trigger;

	if (!trigger)
	{
		trigger = (int *)malloc(sizeof(int));
		*trigger = 0;
	}
	return (trigger);
}

/*
A handler for when heredoc is activated and you want to exit using ctl c
*/
void	heredoc_handler(int sig)
{
	int	*flag;

	flag = heredoc_signal_get();
	if (sig == SIGINT)
	{
		*flag = 1;
		signal(SIGINT, heredoc_handler);
	}
}

//same as ctrl_handler but doesnt re-display
void	ctrl_handler_subprocess(int sig)
{
	if (sig == SIGINT)
		g_exit_status = 130;
}
