/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 07:02:20 by cfahey            #+#    #+#             */
/*   Updated: 2019/08/04 17:03:37 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_rtv1	*camera_init(char *line, t_rtv1 *rtv1)
{
	if (ft_strchr(line, '}'))
		return (NULL);
	else if (ft_strstr(line, "position"))
		rtv1->o = read_vector(ft_strchr(line, '=') + 1);
	else if (ft_strstr(line, "direction"))
		rtv1->d = read_vector(ft_strchr(line, '=') + 1);
	return (rtv1);
}

void	scene_init(t_rtv1 *rtv1, char *number)
{
	char file_name[15];

	if (!ft_strcmp(number, "1"))
		ft_strcpy(file_name, "scenes/v1.rts");
	else if (!ft_strcmp(number, "2"))
		ft_strcpy(file_name, "scenes/v2.rts");
	else if (!ft_strcmp(number, "3"))
		ft_strcpy(file_name, "scenes/v3.rts");
	else if (!ft_strcmp(number, "4"))
		ft_strcpy(file_name, "scenes/v4.rts");
	else if (!ft_strcmp(number, "5"))
		ft_strcpy(file_name, "scenes/v5.rts");
	else if (!ft_strcmp(number, "6"))
		ft_strcpy(file_name, "scenes/v6.rts");
	else if (!ft_strcmp(number, "7"))
		ft_strcpy(file_name, "scenes/v7.rts");
	else if (!ft_strcmp(number, "8"))
		ft_strcpy(file_name, "scenes/v8.rts");
	else
	{
		ft_putendl("I can read argument from 1 to 8");
		err_exit();
	}
	read_scene(rtv1, file_name);
}
