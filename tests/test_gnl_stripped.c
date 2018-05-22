#include <printf.h>
#include <fcntl.h>
#include "gnls.h"

int main(int ac, char **av)
{
	int ret;
	char *line = NULL;
	int fd_from = open(av[1], O_RDONLY);
	int fd_to = open(av[2], O_WRONLY|O_CREAT, 0644);
	while ((ret = ft_usgnl(fd_from, &line)) > 0)
	{
		write(1, line, ft_slen(line));
		write(1, "\n", 1);
	}
	ft_dprintf(2, "It works!\n");
	system("leaks test_gnl_stripped");
	close(fd_from);
	close(fd_to);
	return (0);
}