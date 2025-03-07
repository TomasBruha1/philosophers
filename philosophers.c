/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:11:11 by tbruha            #+#    #+#             */
/*   Updated: 2025/03/07 16:43:51 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DO NOW: init ft for struct and philos. How to store multiple philos -> array.

// Check valid input
// color code your philo messages
// mutexes to lock forks
// write atoi
// create a philo routine
// create death check

// notes to research:
// Learn functions: "gettimeofday", "pthread_create", "pthread_detach"
// read up on pipex on gitbook and try to understand it.
// Philosophy -> from Greek, philosophia, literally "love of wisdom".

#include "include/philosophers.h"

// Routine includes philos eating, sleeping and thinking.
void	routine(t_table *table)
{
	(void)table;
}

void	init_philos(t_table *table)
{
	// int	i;
	
	// i = 0;
	// // malloc *philos CHECK THIS
	// table->philos = malloc(sizeof(t_philo) * table->number_of_philosophers);
	// while (i < table->number_of_philosophers)
	// {
	// 	table->philos[i] = t_philo;
		
	// 	i++;
	// }
	
	(void)table;
}

// Check if all the input is valid and we can proceed, otherwise exit.
int	check_args(char **argv)
{
	(void)argv;
	return (0);
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
	init_philos(table);
	if (!check_args(argv)) // TO DO // before or after init?
		printf("Args are OK.\n");
	else
		printf("Args are NOT OK.\n");
	gettimeofday(&time, NULL); // start time // possible init_time
	table->start = time.tv_sec * 1000 + time.tv_usec / 1000; // start time
}

int main(int argc, char **argv)
{
	t_table		table;
	
	(void)argc;
	// if (argc < 5 || argc > 6)
	// 	error_args();
	init_program(&table, argv); // TO DO
	printf("Time from the start: %ld\n", get_time(&table));
	usleep(300000);
	printf("Time from the start: %ld\n", get_time(&table));
	usleep(300000);
	printf("Time from the start: %ld\n", get_time(&table));
	usleep(300000);
	printf("Time from the start: %ld\n", get_time(&table));
	return (EXIT_SUCCESS);
}

// ----------------------------------------------------------------------------

// gcc -pthread -Wall -Wextra -Werror // DONE
// RTFM -> kidding -> read the subject and go from there. // DONE
// Google and watch some videos to get better broad understanding. // DONE
// Test the "deposit 200 & 300 money test to see how it works." // DONE
// Test gettimeofday function. Settimeofday to 0? PRINT IT // DONE
// What are the test cases and input that I need to run successfully? // DONE
// 5 800 200 200 (7) -> rest of the cases by skvackov // DONE
// What is threading? What is mutex? // DONE
// ditto-> "pthread_join", "pthread_mutex_init", "pthread_mutex_destroy" // DONE
// ditto-> "pthread_mutex_lock", "pthread_mutex_unlock" // DONE
// Make philo struct. // DONE
// Lot of stuff using size_t why? Why not just int?? // DONE