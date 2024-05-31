/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:49:09 by thuy-ngu          #+#    #+#             */
/*   Updated: 2024/05/31 18:30:09 by thuy-ngu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	current[BUFFER_SIZE + 1];
	char		*added;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	added = NULL;
	while (current[0] || read(fd, current, BUFFER_SIZE) > 0)
	{
		added = ft_strjoinline(added, current);
		if (!added)
			return (NULL);
		if (ft_strnewline(current))
			break ;
		if (read(fd, current, BUFFER_SIZE) < 0)
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

// 	fd = open("something.txt", O_RDWR);
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
// 	close(fd);
// }