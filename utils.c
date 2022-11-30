#include "pipex.h"

void	ft_putstr_fd(int fd, char *str)
{
	while (str && *str)
		write(fd, str++, 1);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len])
		len++;
	return (len);
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	size_t	index;

	index = -1;
	if (dst == src || !n)
		return (dst);
	while (++index < n)
		*(char *)(dst + index) = *(char *)(src + index);
	return (dst);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	if (!n)
		return (0);
	while (n--)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		if (!*s1 && !*s2)
			return (0);
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*buffer;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	buffer = (char *) malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (!buffer)
		return (NULL);
	ft_memcpy(buffer, s1, s1_len);
	ft_memcpy(buffer + s1_len, s2, s2_len);
	return (buffer);
}

int	ft_strchr(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}