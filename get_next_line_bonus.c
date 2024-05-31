/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 21:15:37 by thuy-ngu          #+#    #+#             */
/*   Updated: 2023/11/12 16:58:36 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	current[FOPEN_MAX][BUFFER_SIZE + 1];
	char		*added;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FOPEN_MAX)
		return (NULL);
	added = NULL;
	while (current[fd][0] || read(fd, current[fd], BUFFER_SIZE) > 0)
	{
		added = ft_strjoinline(added, current[fd]);
		if (!added)
			return (NULL);
		if (ft_strnewline(current[fd]))
			break ;
		if (read(fd, current[fd], BUFFER_SIZE) < 0)
		{
			free (added);
			return (NULL);
		}
	}
	return (added);
}

// int	main()
// {
// 	int		fd, i;
// 	char	*line;

// 	line = NULL;

// 	fd = open("multiple_nl.txt", O_RDWR);
// 	i = 1;
// 	/*line = get_next_line(fd);
// 	printf("%s\n", line);
// 	write(1, "endline", 7);
// 	free(line);
// 	line = get_next_line(fd);
// 	printf("%s\n", line);
// 	write(1, "endline", 7);
// 	free(line);*/
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("LINE %d:\n", i);
// 		printf("%s\n", line);
// 		free(line);
// 		i++;
// 	}
// 	printf("\nCHECK NULL:\n");
// 	printf("%s\n", line);
// }