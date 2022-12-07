#include "libft.h"

static void	putNbrBase(unsigned long nbr, char *base, int baseLen, t_printf_params *p)
{
	if (nbr >= (unsigned long)baseLen)
		putNbrBase(nbr / baseLen, base, baseLen, p);
	ft_putc(base[nbr % baseLen], p);
}


void	ft_puts(char *s, t_printf_params *p)
{
	if (!s)
		ft_puts("(null)", p);
	else
		while (*s)
			ft_putc(*s++, p);
}

void	ft_putn(long nbr, t_printf_params *p)
{
	if (nbr < 0)
	{
		nbr *= -1;
		ft_putc('-', p);
	}
	putNbrBase(nbr, "0123456789", 10, p);
}

void	ft_putx(unsigned long nbr, t_printf_params *p)
{
	char *low_hex;
	char *upp_hex;

	low_hex = "0123456789abcdef";
	upp_hex = "0123456789ABCDEF";
	if (p->form == 'x')
		putNbrBase((unsigned int)nbr, low_hex, 16, p);
	else if (p->form == 'X')
		putNbrBase((unsigned int)nbr, upp_hex, 16, p);
	else
		putNbrBase((unsigned long)nbr, low_hex, 16, p);
}

void	ft_putp(void *nbr, t_printf_params *p)
{
	ft_puts("0x", p);
	ft_putx((unsigned long)nbr, p);
}