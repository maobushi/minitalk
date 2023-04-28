/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobushi <mobushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:28:53 by msys              #+#    #+#             */
/*   Updated: 2023/04/29 04:29:22 by mobushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<libc.h>

void	signal_handler(int signum)
{
	static int				i = 0;
	static unsigned char	output = UCHAR_MAX;
	unsigned char			flag;

	flag = 128;
	if (signum == SIGUSR1)
		i++;
	else if (signum == SIGUSR2)
	{
		output = output ^ (flag >> i);
		i++;
	}
	if (i == 8)
	{
		write(1, &output, 1);
		output = UCHAR_MAX;
		i = 0;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	ln;

	ln = (long long)n;
	if (ln < 0)
	{
		ft_putchar_fd('-', fd);
		ln *= (-1);
	}
	if (9 < ln)
		ft_putnbr_fd(ln / 10, fd);
	ft_putchar_fd((ln % 10) + '0', fd);
}

int	main(void)
{
	ft_putnbr_fd(getpid(), STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
}
