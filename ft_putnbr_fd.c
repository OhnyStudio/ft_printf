/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:20:42 by jsavard           #+#    #+#             */
/*   Updated: 2022/11/01 16:12:42 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_fd(long long n, int fd)
{
	char	temp;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		temp = (n % 10) + 48;
		ft_putchar_fd(temp, fd);
	}
	else if (n >= 0)
	{
		temp = (n % 10) + 48;
		ft_putchar_fd(temp, fd);
	}
}

void	ft_putnbr_u_fd(long long n, int fd)
{
	char	temp;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n > 9)
	{
		ft_putnbr_fd(n / 10, fd);
		temp = (n % 10) + 48;
		ft_putchar_fd(temp, fd);
	}
	else if (n >= 0)
	{
		temp = (n % 10) + 48;
		ft_putchar_fd(temp, fd);
	}
}
