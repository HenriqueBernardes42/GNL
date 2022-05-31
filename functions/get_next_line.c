char *get_next_line(int fd)
{
	int		saida;
	char	*buff;

	buff = calloc(50, 1);

	saida = read(fd, buff , 1200);

	return buff;
}