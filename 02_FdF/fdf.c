/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miam <miam@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 11:23:03 by mmaxime-          #+#    #+#             */
/*   Updated: 2022/03/23 19:43:18 by miam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_param(t_fdf *param)
{
	param.x = 0;
}

int	main(int argc, char **argv)
{
	t_fdf	vars;
	
	if (argc != 2)
		ft_perror("Usage: ./fdf map.fdf");
	set_default(&vars);
	return (0);
}