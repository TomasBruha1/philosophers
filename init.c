/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:07:39 by tbruha            #+#    #+#             */
/*   Updated: 2025/04/11 17:49:24 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

// Initialize each philo in philos array.
void	init_philos(t_table *table)
{
	size_t	i;
	
	i = 0;
	table->philos = malloc(sizeof(t_philo) * table->nbr_of_philos);
	while (i < table->nbr_of_philos)
	{
		if (pthread_create(&table->philos[i].philo, NULL, &routine, &table->philos[i]) != 0)
			exit(EXIT_FAILURE); // Can't have exit here.
		table->philos[i].index = i;
		table->philos[i].time_to_die = table->time_to_die;
		table->philos[i].time_to_eat = table->time_to_eat;
		table->philos[i].time_to_sleep = table->time_to_sleep;
		table->philos[i].start = table->start;
		table->philos[i].fork_left_mutex = &table->fork_mutex[i];
		table->philos[i].fork_right_mutex = &table->fork_mutex[(i + 1) % table->nbr_of_philos];
		table->philos[i].times_eaten = 0;
		table->philos[i].write_mutex = &table->write_mutex;
		table->philos[i].dead = false;
		i++;
	}
}

// Initialize the program and structs here.
void	init_program(t_table *table, char **argv)
{
	struct timeval	time;
//	waiter pthread_t here?

if (!check_args(argv)) // TO DO // before or after init? error msgs in the function.
	printf("Args are OK.\n");
else
	printf("Args are NOT OK.\n");
usleep(100);
gettimeofday(&time, NULL); // start time // possible init_time
table->start = time.tv_sec * 1000 + time.tv_usec / 1000; // start time
table->nbr_of_philos = ft_atoi(argv[1]); // send args to init_philo only?
table->time_to_die = ft_atoi(argv[2]);
table->time_to_eat = ft_atoi(argv[3]);
table->time_to_sleep = ft_atoi(argv[4]);
if (argv[5])
table->nbr_to_eat = ft_atoi(argv[5]);
else
table->nbr_to_eat = 0;
table->fork_mutex = malloc(sizeof(pthread_mutex_t) * table->nbr_of_philos);
pthread_mutex_init(table->fork_mutex, NULL);
pthread_mutex_init(&table->write_mutex, NULL);
table->bon_appetit = false;
init_philos(table);
}
