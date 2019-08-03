/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 05:29:15 by cfahey            #+#    #+#             */
/*   Updated: 2019/08/03 05:29:16 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		color_to_rgb(int color)
{
	t_color	rgb;

	rgb.r = color >> 16;
	rgb.g = (color & 0x00ff00) >> 8;
	rgb.b = color & 0x0000ff;
	return (rgb);
}

void		set_obj_type(char *line, t_rtv1 *rtv1)
{
	if (ft_strstr(line, "sphere"))
		rtv1->sphere->type = sphere;
	else if (ft_strstr(line, "cylinder"))
		rtv1->sphere->type = cylinder;
	else if (ft_strstr(line, "cone"))
		rtv1->sphere->type = cone;
	else if (ft_strstr(line, "plane"))
		rtv1->sphere->type = plane;
	else
		err_exit();
}

void		set_light_type(char *line, t_light *light)
{
	if (ft_strstr(line, "point"))
		light->type = point;
	else if (ft_strstr(line, "directional"))
		light->type = directional;
	else if (ft_strstr(line, "ambient"))
		light->type = ambient;
	else
		err_exit();
}

t_rtv1		*read_obj_parameters(char *line, t_rtv1 **obj)
{
	if (ft_strchr(line, '}'))
		return (NULL);
	else if (ft_strstr(line, "type"))
		set_obj_type(line, *obj);
	else if (ft_strstr(line, "position"))
		(*obj)->sphere->center = read_vector(ft_strchr(line, '=') + 1);
	else if (ft_strstr(line, "radius"))
		(*obj)->sphere->radius = ft_atof(ft_strchr(line, '=') + 1);
	else if (ft_strstr(line, "color"))
		(*obj)->sphere->rgb = color_to_rgb(ft_atoi(ft_strchr(line, '=') + 1));
	else if (ft_strstr(line, "angle"))
		(*obj)->sphere->angle = ft_atof(ft_strchr(line, '=') + 1);
	else if (ft_strstr(line, "direction"))
		(*obj)->sphere->dir = norm(read_vector(ft_strchr(line, '=') + 1));
	else if (ft_strstr(line, "specular"))
		(*obj)->sphere->specular = ft_atof(ft_strchr(line, '=') + 1);
	else if (ft_strstr(line, "reflective"))
		(*obj)->sphere->reflect = ft_atof(ft_strchr(line, '=') + 1);
	return (*obj);
}

t_light		*read_light_parameters(char *line, t_light **light)
{
	if (ft_strchr(line, '}'))
		return (NULL);
	else if (ft_strstr(line, "type"))
		set_light_type(line, *light);
	else if (ft_strstr(line, "position"))
		(*light)->pos = read_vector(ft_strchr(line, '=') + 1);
	else if (ft_strstr(line, "direction"))
		(*light)->direction = norm(read_vector(ft_strchr(line, '=') + 1));
	else if (ft_strstr(line, "intensity"))
		(*light)->intens = ft_atof(ft_strchr(line, '=') + 1);
	return (*light);
}
