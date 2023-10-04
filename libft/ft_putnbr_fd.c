/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kade-sou <kade-sou@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 19:38:08 by kade-sou          #+#    #+#             */
/*   Updated: 2022/06/30 16:15:14 by kade-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int	div;
	int	mod;

	div = n / 10;
	mod = n % 10;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		div = div * -1;
		mod = mod * -1;
	}
	if (div > 0)
		ft_putnbr_fd(div, fd);
	ft_putchar_fd(mod + '0', fd);
}
