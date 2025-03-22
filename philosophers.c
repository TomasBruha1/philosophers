/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:11:11 by tbruha            #+#    #+#             */
/*   Updated: 2025/03/22 16:55:43 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DO NOW: init ft for struct and philos. How to store multiple philos -> array.

// Check valid input
// color code your philo messages
// Don't forget to join threads at the end.
// mutexes to lock forks
// write atoi
// create a philo routine
// create death check
// If I don't use size_t in atoi it will sort out bad input. TO DO.
// How to deal with 5th arg being there and not. NULL / zero what??
// How to differentiate forks, with numbers? I think that left/right won't work.
// When does it start, once I do pthread_create it starts right away? Do I want that?


// notes to research:
// Learn functions: "gettimeofday", "pthread_create", "pthread_detach"
// read up on pipex on gitbook and try to understand it.
// Philosophy -> from Greek, philosophia, literally "love of wisdom".

#include "include/philosophers.h"

// Routine includes philos eating, sleeping and thinking.
void	*routine(void *arg)
{
	t_table	*table = (t_table *)arg;
	(void)table;
	write(1, "Hello\n", 6);
	return (NULL);
}

void	init_philos(t_table *table)
{
	size_t	i;
	
	i = 0;
	// malloc *philos CHECK THIS
	table->philos = malloc(sizeof(t_philo) * table->number_of_philosophers);
	while (i < table->number_of_philosophers)
	{
		// When . and when ->?? I thought array is a pointer.
		if (pthread_create(&table->philos[i].philo, NULL, &routine, &table) != 0)
			exit(EXIT_FAILURE);
		
		i++;
		

		//////////
		
		
		// pthread_t		philo;
		// int     			index;
		// size_t			time_to_die;
		// size_t			time_to_eat;
		// size_t			time_to_sleep;
		// bool			fork_left; // own, 0 = on the table, 1 = in hand
		// bool			fork_right; // borrowed, ditto
		// pthread_mutex_t	mutex_fork_left;
		// pthread_mutex_t	mutex_fork_right;
		// int				times_eaten;
	}
	
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
	usleep(10);
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
	size_t			i;
	
	if (argc < 5 || argc > 6)
		error_args();
	i = 0;
	init_program(&table, argv); // TO DO
	printf("Time from the start: %ld\n", get_time(&table));
	usleep(300000);
	printf("Time from the start: %ld\n", get_time(&table));
	usleep(300000);
	printf("Time from the start: %ld\n", get_time(&table));
	usleep(300000);
	printf("Time from the start: %ld\n", get_time(&table));
	while (i < table.number_of_philosophers)
	{
		if (pthread_join(table.philos[i].philo, NULL) != 0)
			return (2);
	}
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