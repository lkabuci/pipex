#include "libft.h"

void	ft_putc(char c, t_printf_params *p)
{
	p->ret += write(p->fd, &c, 1);
}

static void	parse_formats(va_list ap, t_printf_params *p)
{
	if (p->form == 'c')
		ft_putc(va_arg(ap, int), p);
	else if (p->form == 's')
	 	ft_puts(va_arg(ap, char*), p);
	else if (p->form == 'i' || p->form == 'd')
	 	ft_putn(va_arg(ap, int), p);
	else if (p->form == 'x' || p->form == 'X')
	 	ft_putx(va_arg(ap, unsigned int), p);
	else if (p->form == 'u')
	 	ft_putn((unsigned int)va_arg(ap, int), p);
	else if (p->form == 'p')
		ft_putp(va_arg(ap, void *), p);
	else
		ft_putc('%', p);
}

int	ft_fprintf(int fd, char *s, ...)
{
	va_list		ap;
	t_printf_params	p;

	p.ret = 0;
	p.err = 0;
	p.fd = fd;
	va_start(ap, s);
	while (*s)
	{
		if (*s == '%' && *(s + 1))
		{
			s++;
			p.form = *s;
			parse_formats(ap, &p);
		}
		else if (*s == '%' && !*(s + 1))
			break;
		else
 			ft_putc(*s, &p);
		s++;
	}
	va_end(ap);
	if (p.err == -1)
		return (-1);
	return (p.ret);
}