/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmaxime- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 11:06:18 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/02/22 18:22:11 by mmaxime-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** SYNOPSIS: create new list
** LIBRARY: N/A
** DESC: Allocates (with malloc(3)) and returns a new element. The variable
** ’content’ is initialized with the value of the parameter ’content’. The
** variable ’next’ is initialized to NULL.
*/

#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (0);
	new->content = content;
	new->index = -1;
	new->next = NULL;
	return (new);
}
