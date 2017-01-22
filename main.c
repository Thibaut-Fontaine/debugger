/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:30:28 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/22 16:26:40 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#define LINE_COUNTER "\nprintf(\"%d\\n\", "
#define LINEHEAD "\n#include <stdio.h>\nint cccounter__ = 1;\n"

static char		*realloc_str(char *str, size_t size)
{
	char		*r;

	if (str != NULL)
	{
		if ((r = malloc(size + 1)) == NULL)
			return (NULL);
		strncpy(r, str, size);
		r[size] = 0;
		free(str);
	}
	else
		r = NULL;
	return (r);
}

void		write_in(const int fd, char *s, size_t k)
{
	char *tmp = s;
	char *add;

	if (k > 0)
	{
		s = malloc(strlen(tmp) + 10);
		sprintf(s, "%s%d%s", tmp, (int)k, ");");
	}
	write(fd, s, strlen(s));
}

int			main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "usage: ", 8);
		write(1, *argv, strlen(*argv));
		write(1, " source_file\n", 13);
		exit(EXIT_FAILURE);
	}
	int		fd_r;
	int		fd_c;
	size_t	k;
	char	buff[1];
	char	*name;

	name = malloc(strlen(argv[1]) + strlen("_debug.c"));
	strncpy(name, argv[1], strlen(argv[1]) - 2);
	name[strlen(argv[1]) - 2] = 0;
	strcpy(&(name[strlen(name)]), "_debug.c");
	k = 0;
	fd_r = open(argv[1], O_RDONLY);
	fd_c = open(name, O_WRONLY | O_CREAT, 0666);
	write_in(fd_c, LINEHEAD, 0);

	int		crochet;

	crochet = 0;
	while (read(fd_r, buff, 1))
	{
		if (*buff == '{')
			++crochet;
		if (*buff == '}')
			--crochet;
		if (*buff == '\n')
			++k;
		if (*buff == '\n' && crochet > 0)
			write_in(fd_c, LINE_COUNTER, k);
		write(fd_c, buff, 1);
	}
	close(fd_r);
	close(fd_c);
	return (0);
}
