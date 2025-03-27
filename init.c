/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 12:07:39 by tbruha            #+#    #+#             */
/*   Updated: 2025/03/27 15:08:03 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

// Initialize each philo in philos array.
void	init_philos(t_table *table)
{
	size_t	i;
	
	i = 0;
	table->philos = malloc(sizeof(t_philo) * table->number_of_philosophers);
	while (i < table->number_of_philosophers)
	{
		if (pthread_create(&table->philos[i].philo, NULL, &routine, &table) != 0)
			exit(EXIT_FAILURE);
		table->philos[i].index = i;
		table->philos[i].time_to_die = table->time_to_die;
		table->philos[i].time_to_eat = table->time_to_eat;
		table->philos[i].time_to_sleep = table->time_to_sleep;
			// bool			fork_left; // own, 0 = on the table, 1 = in hand
			// bool			fork_right; // borrowed, ditto
			// pthread_mutex_t	mutex_fork_left;
			// pthread_mutex_t	mutex_fork_right;
		table->philos[i].times_eaten = 0;
		i++;
	}
}

// Initialize the program and structs here.
void	init_program(t_table *table, char **argv)
{
	struct timeval	time;
	
	table->number_of_philosophers = ft_atoi(argv[1]);
	// t_philo			*philos; // array of philos [i] // TO DO
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		table->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		table->number_of_times_each_philosopher_must_eat = 0;
	// pthread_mutex_t	mutex; // just coz
	table->bon_appetit = false;
	init_philos(table);
	usleep(100);
	if (!check_args(argv)) // TO DO // before or after init? error msgs in the function.
		printf("Args are OK.\n");
	else
		printf("Args are NOT OK.\n");
	usleep(100);
	gettimeofday(&time, NULL); // start time // possible init_time
	table->start = time.tv_sec * 1000 + time.tv_usec / 1000; // start time
}
