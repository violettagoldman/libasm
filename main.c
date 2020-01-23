#include "libftprintf.h"

int		ft_strlen(const char *s);
char	*ft_stpcpy(char *dst, const char * src);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_write(int fildes, const void *buf, size_t nbyte);
int		ft_read(int fildes, void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

int		ft_assert(int a, int b)
{
	if (a == b)
		printf("\033");
	else
		printf();
}

int		main(void)
{
	ft_printf("\033[1;33mft_strlen\n");
	
	ft_printf("\033[1;33mft_strcpy\n");

	ft_printf("\033[1;33mft_strdup\n");

	ft_printf("\033[1;33mft_write\n");

	ft_printf("\033[1;33mft_read\n");
	return (0);
}
