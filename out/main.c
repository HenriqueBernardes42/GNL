#include <stdio.h>
// #include "get_next_line.h"

char	*g_file_name = "./lorem_ipsum.txt";
FILE	*g_fp;

int	main(void)
{
	char	*linha;
	int		i;

	i = 1;
	g_fp = fopen(g_file_name, "r");

	printf("_fileno == %d\n", g_fp->_fileno);
	// while ((linha = get_next_line(g_fp->_fileno)) != NULL)
	// {
	// 	//linha = get_next_line(g_fp->_fileno)
	// 	printf("Linha_%i> %s", i++, linha);
	// 	free(linha);
	// }

	// fclose(g_fp);
	// return (0);
}