/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefeuvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 11:49:47 by blefeuvr          #+#    #+#             */
/*   Updated: 2018/03/14 12:48:43 by cmaxime          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*add_line(char *line, t_read *save)
{
	int		end;
	char	*buff;
	char	*str;

	str = save->buff;
	end = save->pos;
	while (str[end] != '\0' && str[end] != '\n' && str[end] != EOF)
		end++;
	buff = ft_strsub(save->buff, save->pos, end - save->pos);
	line = ft_realloc(line, buff);
	free(buff);
	save->pos = end;
	return (line);
}

static t_read	init_save(char *buff, t_read save)
{
	int		i;

	save.pos = 0;
	i = 0;
	while (i < BUFF_SIZE)
	{
		save.buff[i] = buff[i];
		i++;
	}
	save.buff[i] = '\0';
	return (save);
}

static int		ft_logique(int fd, char *str, t_read *save)
{
	int		ret;
	char	buff[BUFF_SIZE + 1];

	if ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		*save = init_save(buff, *save);
	}
	else
	{
		if (ft_strlen(str) > 0)
			return (1);
		return (ret);
	}
	return (2);
}

int				ft_gnl(const int fd, char **line)
{
	static t_read	save[2148473647];
	int				ret;
	char			*str;

	if (!line || fd < 0 || !(str = (char*)ft_memalloc(1)))
		return (-1);
	*line = str;
	while (save[fd].buff[save[fd].pos] != '\n'
			&& save[fd].buff[save[fd].pos] != EOF)
	{
		if (save[fd].pos >= BUFF_SIZE || save[fd].pos <= 0
				|| ft_strlen(save[fd].buff) == (size_t)save[fd].pos)
		{
			if ((ret = ft_logique(fd, str, &save[fd])) != 2)
				return (ret);
		}
		if (!(str = add_line(str, &save[fd])))
			return (-1);
		*line = str;
	}
	save[fd].pos++;
	return (1);
}
