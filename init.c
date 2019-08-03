/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 07:02:20 by cfahey            #+#    #+#             */
/*   Updated: 2019/08/03 07:02:21 by cfahey           ###   ########.fr       */
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

void	set_start_angles(t_rtv1 *scene)
{
	t_vect vector_yz;
	t_vect vector_xz;
	t_vect main_dir;

	vector_yz = scene->camera.dir;
	vector_yz.x = 0;
	vector_xz = scene->camera.dir;
	vector_xz.y = 0;
	main_dir = vec(0, 0, 1);
	scene->sphere->view_alpha = acos(dot(vector_yz, main_dir) /
			(v_length(vector_yz) * v_length(main_dir)));
	scene->sphere->view_beta = acos(dot(vector_xz, main_dir) /
			(v_length(vector_xz) * v_length(main_dir)));
	if (scene->sphere->view_alpha > M_PI / 2)
		scene->sphere->view_alpha = M_PI - scene->sphere->view_alpha;
	if (vector_yz.y < 0)
		scene->sphere->view_alpha *= (-1);
	if (vector_xz.x < 0)
		scene->sphere->view_beta *= (-1);
	scene->sphere->view_beta = -1 * scene->sphere->view_beta;
}

void	scene_init(t_rtv1 *rtv1, char *number)
{
	char file_name[100];

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
		ft_putendl("can't read scene");
		err_exit();
	}
	read_scene(rtv1, file_name);
}
