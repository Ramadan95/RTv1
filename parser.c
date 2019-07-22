//
// Created by Calista Fahey on 2019-07-18.
//

#include <fcntl.h>
#include "rtv1.h"
#include "parser.h"

int 	g_nbline = 0;

void	parse_error(int numb)
{
	if (numb == ALL_GOOD)
		return;
	if (numb == USAGE)
		ft_putendl("Usage: ./RTv1[filename]");
	if (numb == NO_OBJ_DATA)
		ft_putendl("No found objects in the file");
	if (numb == NO_LIGHT_DATA)
		ft_putendl("Total light intensity equals 0 -> nothing can be seen");
	if (numb >= NO_OBJ_DATA)
		exit(0);
	ft_putstr("ERROR: (line ");
	ft_putnbr(g_nbline);
	if (numb == NB_TOO_BIG)
		ft_putendl(" ) Wrong number format");
	if (numb == NOT_ENOUGH_DATA)
		ft_putendl(") Not enough data");
	if (numb == WRONG_CHARACTER)
		ft_putendl(") Wrong character");
	if (numb == WRONG_COL_FORMAT)
		ft_putendl(") Wrong color format");
	exit(0);
}

void	obj_push_back(t_rtv1 *rtv1, char **obj)
{

}

void	parse_line(t_rtv1 *rtv1, char **obj)
{
	if (ft_strequ(obj[0], "sphere:") || ft_strequ(obj[0], "cylinder:") ||
		ft_strequ(obj[0], "cone:") || ft_strequ(obj[0], "plane:"))
		obj_push_back(rtv1, obj);
}

void	default_rtv1(t_rtv1 *rtv1)
{
	rtv1->objcount = 0;
	rtv1->obj = 0;
}

void	put_error(char *s)
{
	perror(s);
	exit(1);
}


void	free_double_string(char **obj)
{
	int 	i;

	i = -1;
	while  (obj[++i])
		free(obj[i]);
	free(obj);
	obj = NULL;
}

void	parse_file(t_rtv1 *rtv1, char *filename)
{
	int 	fd;
	char 	*line;
	char	**obj;
	int 	ret;

	default_rtv1(rtv1);
	if ((fd = open(filename, O_RDONLY)) < 0)
		put_error("Cannot open the file");
	while ((ret = get_next_line(fd, &line)))
	{
		if (ret < 0)
			put_error("Reading error");
		if (!(obj = ft_strsplit(line, ' ')))
			put_error("Memory allocation error");
		g_nbline++;
		parse_line(rtv1, obj);
		free_double_string(obj);
		free(line);
	}
	close(fd);
	if (rtv1->objcount == 0)
		parse_error(NO_OBJ_DATA);
}
