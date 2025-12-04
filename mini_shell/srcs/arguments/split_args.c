/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 10:07:46 by rmount            #+#    #+#             */
/*   Updated: 2023/12/03 20:07:36 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
 * @brief   Free Linked List with Malloced Content
 *
 * This function frees a linked list that has malloced content. It iterates 
 * through the linked list, frees the content of each node (assuming it was 
 * malloced), and then frees the node itself.
 *
 * @param   env_var_list    Pointer to the head of the linked list.
 */
void	freelist_malloc(t_list *env_var_list)
{
	t_list	*current;

	while (env_var_list)
	{
		free(env_var_list->content);
		current = env_var_list;
		env_var_list = env_var_list->next;
		free(current);
	}
}

/*
- Called by make_arg_list

*/
void	add_interp_token(t_list **lst, int *i, char *s1, char *s2)
{
	int	len;

	len = ft_strlen(s2);
	if (!ft_strncmp(&s1[*i], s2, len))
	{
		ft_lstadd_back(lst, ft_lstnew(ft_strdup(s2)));
		*i += len;
	}
}

/**
 * @brief   Make Argument List from Input String
 *
 * This function creates a linked list of arguments from the input string. It
 * iterates through the input string, identifying arguments separated by spaces
 * or special characters, and adds each argument to the linked list.
 *
 * @param   shell   Pointer to the shell program structure.
 * @param   inputs  Pointer to the head of the linked list to store arguments.
 * @param   input   The input string to parse and extract arguments from.
 *
 * @return  A pointer to the head of the updated linked list.
 */

/*
- Called by split_args

*/
t_list	*make_arg_list(t_prog *shell, t_list *inputs, char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		while (input[i] && ft_isspace(input[i]))
			i++;
		if (input[i] == '|')
			add_interp_token(&inputs, &i, input, "|");
		if (input[i] && !ft_isspace(input[i]) && is_bookend(input, &i))
			ft_lstadd_back(&inputs, ft_lstnew(cpy_str(shell, input, &i)));
	}
	return (inputs);
}

/**
 * @brief   Split Input String into Arguments
 *
 * This function splits an input string into an array of arguments. It creates a
 * linked list of arguments using the make_arg_list function, then allocates
 * memory for an array and copies the arguments into it.
 *
 * @param   shell   Pointer to the shell program structure.
 * @param   input   The input string to split into arguments.
 */
/*
- Called by shell_loop
- Takes in shell and input (the text input by the user)

*/
void	split_args(t_prog *shell, char *input)
{
	int		i;
	char	**args;
	t_list	*inputs;
	t_list	*head;

	i = 0;
	inputs = ft_lstnew(ft_strdup("Head"));
	head = make_arg_list(shell, inputs, input);
	free(input);
	args = malloc(sizeof(*args) * (ft_lstsize(inputs) + 1));
	while (inputs ->next)
	{
		if (ft_strcmp("\\", inputs->next->content))
			args[i] = ft_strdup(inputs->next->content);
		else
			i--;
		inputs = inputs->next;
		i++;
	}
	add_env_var(shell, "_=", args[i - 1]);
	args[i] = NULL;
	freelist_malloc(head);
	shell->user_inputs = args;
}
