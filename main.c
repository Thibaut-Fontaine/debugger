/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 17:30:28 by tfontain          #+#    #+#             */
/*   Updated: 2017/01/22 15:40:14 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define LINE_COUNTER "\nputnbr(cccounter__++);"
#define LINEHEAD "\n#include <stdlib.h>\nvoid putnbr(int n){char array[11];int k;if (n == -2147483648)ft_putstr(\"-2147483648\");else if (n == 0)ft_putchar('0');else{if (n < 0){n = -n;ft_putchar('-');}k = -1;while (n){array[++k] = n % 10 + '0';n = n / 10;}while (k >= 0)ft_putchar(array[k--]);}}\nint cccounter__ = 1;\n"

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

void		write_in(const int fd, char *s)
{
	write(1, s, strlen(s));
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
	char	*buff;
	char	*name;

	name = malloc(strlen(argv[1]) + strlen("_debug.c"));
	buff = malloc(1);
	strncpy(name, argv[1], strlen(argv[1]) - 2);
	name[strlen(argv[1]) - 2] = 0;
	strcpy(&(name[strlen(name)]), "_debug.c");
	k = 0;
	fd_r = open(argv[1], O_RDONLY);
	fd_c = open(name, O_CREAT | O_WRONLY | S_IRWXO);
	write_in(fd_c, LINEHEAD);
	/*while (read(fd_r, &(buff[k++]), 1))
	{
		if (buff[k] == '\n')
			put_line_counter(fd_c);
		write(fd_c, &(buff[k]), 1);
		realloc_str(buff, k);
	}*/
	close(fd_r);
	close(fd_c);
	return (0);
}
