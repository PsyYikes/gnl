/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgarcia <fgarcia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:54:59 by fgarcia           #+#    #+#             */
/*   Updated: 2024/01/23 15:01:03 by fgarcia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

void	free_join_buffer(char **buffer, char *tmp)
{
	char	*temp;
	int		i;
	int		j;

	temp = malloc(ft_strlen(*buffer) + ft_strlen(tmp) + 1);
	if (!temp)
		return ;
	i = 0;
	while ((*buffer) && (*buffer)[i])
	{
		temp[i] = (*buffer)[i];
		i++;
	}
	j = -1;
	while (tmp[++j])
		temp[i + j] = tmp[j];
	temp[i + j] = '\0';
	if (*buffer)
		free(*buffer);
	*buffer = temp;
}

void	read_line(int fd, char **buffer)
{
	int		len_buffer;
	char	*tmp;

	len_buffer = 1;
	tmp = ft_calloc(1, BUFFER_SIZE + 1);
	while (len_buffer > 0)
	{
		if (*buffer != ft_strchr(*buffer, '\n'))
			break ;
		len_buffer = read(fd, tmp, BUFFER_SIZE);
		if (len_buffer <= 0)
		{
			if (len_buffer == -1)
				*buffer = (free(*buffer), NULL);
			break ;
		}
		tmp[len_buffer] = '\0';
		free_join_buffer(buffer, tmp);
	}
	free(tmp);
}

char	*cpy_nl(char *content, int breakpoint)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_calloc(1, ft_strlen(content) + 1);
	while (i <= breakpoint)
	{
		line[i] = content[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*make_line(int fd, char *content, char **buffer)
{
	int		breakpoint;
	char	*joined;
	char	*line;

	read_line(fd, buffer);
	if (!*buffer || **buffer == '\0')
		return (NULL);
	breakpoint = ft_strchr(*buffer, '\n') - *buffer;
	joined = ft_strjoin(content, *buffer);
	if (!joined)
		return (NULL);
	line = cpy_nl(joined, breakpoint);
	free(joined);
	joined = ft_strdup(*buffer + breakpoint + 1);
	free(*buffer);
	*buffer = joined;
	if (**buffer == '\0')
		*buffer = (free(*buffer), NULL);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*content;
	static char	*buffer = NULL;

	content = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = make_line(fd, content, &buffer);
	if (!line)
		return (NULL);
	return (line);
}
// int main(int argc, char *argv[])
// {
// 	char	*line;

// 	if (argc != 2)
//  		return (1);
//  	int fd = open(argv[1], O_RDONLY);
//  	while ((line = get_next_line(fd)) != NULL)
//  	{
//  		printf("%s", line);
//  		free(line);
//  	}
//  	close(fd);
//  	return (0);
// }
