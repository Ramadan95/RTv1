/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_scene1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfahey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 10:30:38 by cfahey            #+#    #+#             */
/*   Updated: 2019/08/03 10:31:26 by cfahey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vect	read_vector(char *str)
{
	t_vect ret;

	while (*str == ' ' || *str == '\t' || *str == '(')
		str++;
	ret.x = ft_atof(str);
	str = ft_strchr(str, ',') + 1;
	ret.y = ft_atof(str);
	str = ft_strchr(str, ',') + 1;
	ret.z = ft_atof(str);
	return (ret);
}

void	new_object(t_rtv1 *rtv1, t_rtv1 **obj, int *i)
{
	*i = (*i) + 1;
	*obj = (t_rtv1 *)&(rtv1->sphere[*i]);
}

void	new_light(t_rtv1 *rtv1, t_rtv1 **light, int *i)
{
	*i = (*i) + 1;
	*light = (t_rtv1 *)&(rtv1->light[*i]);
}

void	read_line_set_scene(char *line, t_rtv1 *rtv1)
{
	static int			i = -1;
	static int			j = -1;
	static t_sphere		*obj = NULL;
	static t_light		*light = NULL;
	static t_rtv1		*camera = NULL;

	if (ft_strstr(line, "camera_init"))
		camera = camera_init(line, rtv1);
	if (obj)
		obj = (t_sphere *)read_obj_parameters(line, (t_rtv1 **)&obj);
	else if (light)
		light = read_light_parameters(line, &light);
	else if (camera)
		camera = camera_init(line, camera);
	else if (ft_strstr(line, "new") && ft_strstr(line, "object"))
		new_object(rtv1, (t_rtv1 **)&obj, &i);
	else if (ft_strstr(line, "new") && ft_strstr(line, "light"))
		new_light(rtv1, (t_rtv1 **)&light, &j);
	else if (!ft_strcmp(line, "end"))
	{
		rtv1->objcount = i + 1;
		rtv1->lightcount = j + 1;
	}
}

void	read_scene(t_rtv1 *rtv1, char *file_name)
{
	int		fd;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		err_exit();
	while ((get_next_line(fd, &line)))
	{
		read_line_set_scene(line, rtv1);
		free(line);
	}
	close(fd);
}
