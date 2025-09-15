/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomandra <tomandra@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 16:23:57 by tomandra          #+#    #+#             */
/*   Updated: 2025/06/17 15:54:12 by tomandra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	rest[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strjoin(NULL, rest);
	if (!line)
		return (manage_buffer(rest), NULL);
	line = read_and_join_line(fd, line, rest);
	if (!line)
		return (free(line), NULL);
	if (ft_strchr(line, '\n'))
	{
		manage_buffer(rest);
		return (line);
	}
	if (line[0] == '\0')
		return (free(line), NULL);
	rest[0] = '\0';
	return (line);
}

// int main(void)
// {
// 	int fd = open("test.txt", O_RDONLY);
// 	char *line;
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	close(fd);
// }
