/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmount <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:03:49 by ihogben           #+#    #+#             */
/*   Updated: 2023/11/24 14:58:01 by rmount           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief	Frees an environment structure, including all allocated pointers.
 * ! Need to evaluate what has to be freed here.
 * ! Might need to pass by reference
**/
void	free_env(t_list **lst)
{
	t_env	*env;
	t_list	*current;

	current = *lst;
	env = current->content;
	free(env->env_var);
	free(env->key);
	free(env->value);
	free(env);
}

/**
 * @brief   Free Shell User Inputs
 *
 * This function frees the memory allocated for the user inputs in the shell
 * program structure. It iterates through the user inputs, frees each element,
 * and then frees the array itself. If the user inputs array is already NULL,
 * the function does nothing.
 *
 * @param   shell   Pointer to the shell program structure.
 */
void	free_inputs(t_prog *shell)
{
	int	i;

	if (!shell->user_inputs)
		return ;
	i = 0;
	while (shell->user_inputs[i])
	{
		free(shell->user_inputs[i]);
		shell->user_inputs[i] = NULL;
		i++;
	}
	free(shell->user_inputs);
	shell->user_inputs = NULL;
}

/**
 * @brief   Free Full Environment Variables List
 *
 * This function frees the entire linked list of environment variables in the
 * shell program structure. It iterates through the linked list, freeing each
 * environment variable entry and the list nodes themselves.
 *
 * @param   shell   Pointer to the shell program structure.
 */
void	free_full_env(t_prog *shell)
{
	t_list	*lst;

	lst = shell->env_vars;
	while (lst)
	{
		free_env(&lst);
		lst = lst->next;
	}
}

/**
 * @brief   Free String Array
 *
 * This function frees the memory allocated for a string array. It iterates
 * through the array, frees each string element, and then frees the array itself.
 * If the array is already NULL, the function does nothing.
 *
 * @param   arr     The string array to be freed.
 */
void	free_array(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i] != NULL)
		free(arr[i++]);
	free(arr);
}

/**
 * @brief   Free Linked List
 *
 * This function frees the memory allocated for a linked list. It iterates
 * through the linked list, freeing each list node, and the data associated
 * with each node. If the linked list is already NULL, the function does nothing.
 *
 * @param   list    The linked list to be freed.
 */
void	freelist(t_list *list)
{
	t_list	*current;

	while (list)
	{
		current = list;
		list = list->next;
		free(current);
	}
}
