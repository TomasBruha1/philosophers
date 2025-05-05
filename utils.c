/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:14:43 by tbruha            #+#    #+#             */
/*   Updated: 2025/05/05 16:44:30 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

// Check if all the input is valid and we can proceed, otherwise exit.
int	check_args(char **argv)
{
	(void)argv;
	return (0);
}

// Prints error message and exit upon wrong number of inputs.
void	error_args(void)
{
	printf("Wrong number of arguments. Input 4 or 5 values to proceed.\n");
	exit(EXIT_FAILURE); // exit is illegal, fix to return 0/1
}

// char to int, size_t actually which is unsigned int
size_t	ft_atoi(char *str)
{
	int		result;
	int		i;
	int		sign;
	
	result = 0;
	i = 0;
	sign = 1;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || str[i] == '\n' )
		i++;
		if (str[i] == '+' || str[i] == '-')
		{
			if (str[i] == '-')
			sign = -1;
			i++;
		}
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

// This function will return time in miliseconds from the start. *arg is ...->start
size_t	get_time(void *arg)
{
	size_t 			time;
	struct timeval	current;
	size_t			start;

	start = *(size_t *)arg;
	gettimeofday(&current, NULL);
	time = (current.tv_sec * 1000 + current.tv_usec / 1000) - start;
	return (time);
}

// Own implementation of ft usleep. This one wakes faster and is in miliseconds.
int	ft_milisleep(size_t milisec, t_philo *philo)
{
	size_t			time_slept;
	struct timeval	start_tv;
	struct timeval	current;
	size_t			start;
	
	gettimeofday(&start_tv, NULL);
	start = (start_tv.tv_sec * 1000 + start_tv.tv_usec / 1000);
	time_slept = 0;
	while (time_slept < milisec && philo->dead == false)
	{
		gettimeofday(&current, NULL);
		time_slept = ((current.tv_sec * 1000 + current.tv_usec / 1000) - start);
		usleep(500);
	}
	return (0);
}
