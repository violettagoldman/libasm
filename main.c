#include "libftprintf.h"

int		ft_strlen(const char *s);
char	*ft_strcpy(const char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_write(int fildes, const void *buf, size_t nbyte);
int		ft_read(int fildes, const void *buf, size_t nbyte);
char	*ft_strdup(const char *s1);

void	ft_assert(int a, int b)
{
	if (a == b)
		ft_printf("\033[1;32m[OK]\033[0m");
	else
		ft_printf("\033[1;31m[FAIL]\033[0m");
}

/*
 * DISCLAIMER!
 * ALL functions are compared to the ouptput of original functions.
 */

int		main(void)
{
	const char	*src;
	char		*dst;
	char		*res;
	char		*buffer;
	int			i;

	i = 0;
	if (!(dst = (char *)malloc(sizeof(char) * 10)))
		return (0);
	if (!(buffer = (char *)malloc(sizeof(char) * 256000)))
		return (0);
	while (i < 256000)
	{
		buffer[i] = 0;
		i++;
	}

	ft_printf("\033[0;33mft_strlen ");
	//simple test
	ft_assert(ft_strlen("test"), 4);
	//very long test
	ft_assert(ft_strlen("Lorem ipsum dolor sit amet, consectetur adipiscing\
	elit. Integer accumsan nec urna sit amet efficitur. Sed sit amet pulvinar\
	erat, eu interdum velit. Aliquam erat volutpat. Integer nec velit purus.\
	Cras cursus, nibh vel consequat imperdiet, nisl urna venenatis est, nec\
	elementum lacus ligula vitae lectus. Nam massa urna, placerat a mauris\
	eget, gravida volutpat dui. Sed faucibus felis et risus rhoncus, sit amet\
	suscipit magna varius. Donec at turpis mauris. Sed tincidunt, nisl vitae\
	euismod eleifend, magna urna viverra sapien, eget lacinia tortor velit non\
	sapien. Nulla orci risus, eleifend eu interdum at, malesuada in lacus.\
	Aenean consequat facilisis diam a porttitor."), 678);
	//Empty string test
	ft_assert(ft_strlen(""), 0);
	//'\0' test
	ft_assert(ft_strlen("\0FAIL"), 0);

	ft_printf("\n\033[0;33mft_strcpy\033[0m ");
	ft_strcpy(src, "test");
	ft_strcpy(dst, src);
	ft_printf("Src: %s Dst: %s", src, dst);
	free(dst);
	dst = NULL;

	ft_printf("\n\033[0;33mft_strdup \033[0m");
	res = ft_strdup(src);
	ft_printf("Src: %s Res: %s", src, res);
	free(res);
	res = NULL;

	ft_printf("\n\033[0;33mft_read \033[0m");
	ft_read(0, buffer, 256000);

	ft_printf("\033[0;33mft_write \033[0m");
	ft_write(1, buffer, 256000);
	free(buffer);
	buffer = NULL;
	return (0);
}
