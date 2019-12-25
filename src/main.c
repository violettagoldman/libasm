#include <stdio.h>
#include <string.h>
#include <libc.h>
#include <stdlib.h>

int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(char *s1, char *s2);
int		ft_write(int fd, const void *buffer, size_t count);
int		ft_read(int fd, const void *buffer, size_t count);
char	*ft_strdup(const char *src);

int main(void)
{
	printf("\n** Testing ft_strdup:\n");
	char *src2 = "Hello world!";
	char *res = ft_strdup(src2);
	printf("|%p %p %s %lu|\n", src2, res, res, strlen(res));
	free(res);
	res = strdup(src2);
	printf("|%p %p %s %lu|\n", src2, res, res, strlen(res));
	free(res);
	return (0);
}
