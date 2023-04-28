/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mobushi <mobushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:28:51 by mobushi           #+#    #+#             */
/*   Updated: 2023/04/29 04:29:15 by mobushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>
#include <stdbool.h>
#include <stdint.h>

size_t	print_error(void)
{
	write(STDOUT_FILENO, "Error\n", 6);
	return (1);
}

int32_t	ft_atoi(const char *str)
{
	int64_t		ln;
	uint32_t	n;
	int32_t		sign;

	sign = 1;
	ln = 0;
	n = 0;
	while (str[n] == 32 || (9 <= str[n] && str[n] <= 13))
		n++;
	if (str[n] == '-')
		sign *= -1;
	if (str[n] == '+' || str[n] == '-')
		n++;
	while ('0' <= str[n] && str[n] <= '9')
	{
		if (ln != ((ln * 10) + (str[n] - '0') * sign) / 10 && sign > 0)
			return ((int32_t)LONG_MAX);
		if (ln != ((ln * 10) + (str[n] - '0') * sign) / 10 && sign < 0)
			return ((int32_t)LONG_MIN);
		ln = (ln * 10) + (str[n] - '0') * sign;
		n++;
	}
	return (ln);
}

bool	check_input(char *str, int8_t argc)
{
	if (argc != 3)
		return (false);
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (false);
		str++;
	}
	return (true);
}

void	send_signal(int32_t pid, char *str)
{
	uint8_t	flag;
	size_t	i;

	while (*str != '\0')
	{
		i = 0;
		flag = 128;
		while (i < 8)
		{
			if (*str & (flag >> i))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(1000);
			i++;
		}
		usleep(1000);
		str++;
	}
}

int32_t	main(int32_t argc, char **argv)
{
	pid_t	pid;

	pid = 0;
	if (!check_input(argv[1], argc))
		return (print_error());
	else
	{
		pid = (pid_t)ft_atoi(argv[1]);
		send_signal(pid, argv[2]);
		return (0);
	}
}
