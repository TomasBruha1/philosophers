/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:11:11 by tbruha            #+#    #+#             */
/*   Updated: 2025/04/10 16:56:47 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DO NOW: Own sleep function. WHY? Because regular usleep doesn't wake up quick enough.
// Check valid input.


// add start time to each philo as well?
// How to start the simulation at the same time -> bon_appetit how? NOT NOW
// what is meal_lock for? // lock when checking the last meal eaten
// color code your philo messages
// Don't forget to join threads at the end..
// create a philo routine.
// create death check
// If I don't use size_t in atoi it will sort out bad input. TO DO.
// How to handle errors? Fts to FREE everything and exit. (no EXIT though)
// When does it start, once I do pthread_create it starts right away? Do I want that?
// Check allowed functions -> no EXIT.
// Make sure you pass 20 450/500 200 200
// Check on pthread_mutex_destroy.


// notes to research:
// Learn functions: "pthread_detach", makefile flag "thread sanitizer"
// read up on pipex on gitbook and try to understand it.
// Philosophy -> from Greek, philosophia, literally "love of wisdom".

#include "include/philosophers.h"

void	print_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(philo->write_mutex);
	if (state == 0)
	printf("%zu ms -> %d is thinking.\n", get_time(&philo->start), philo->index);
	else if (state == 1)
	printf("%zu ms -> %d is eating.\n", get_time(&philo->start), philo->index);
	else if (state == 2)
	printf("%zu ms -> %d is sleeping.\n", get_time(&philo->start), philo->index);
	else if (state == 3)
	printf("%zu ms -> %d has taken a fork.\n", get_time(&philo->start), philo->index);
	else if (state == 4)
	printf("%zu ms -> %d has died.\n", get_time(&philo->start), philo->index);
	pthread_mutex_unlock(philo->write_mutex);
}

void	eating(t_philo *philo)
{
	// write lock
	print_state(philo, EATING);
	philo->times_eaten++;
//	printf("%d has eaten %zu time(s).\n", philo->index, philo->times_eaten);
	// eating counter goes up
}

void	thinking(t_philo *philo)
{
	// write lock
	print_state(philo, THINKING);
	
	// x is thinking
	// x has taken fork
	// x has taken fork
	// exit and go to eating
}

// Routine includes philos eating, sleeping and thinking.
void	*routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;
	// wait while bon_appetit == false; set true after everything is ready.
	thinking(philo);
	// ft think -> odd philo first left fork // even philo right fork
	// ft eat -> ft sleep
	
		if (philo->index % 2 == 0)
		{
			ft_usleep(1000);
			pthread_mutex_lock(philo->fork_left_mutex);
			{
				print_state(philo, FORK);
				pthread_mutex_lock(philo->fork_right_mutex);
				// LOT OF CODE HERE //
				print_state(philo, FORK);
				pthread_mutex_unlock(philo->fork_right_mutex);
			}
			pthread_mutex_unlock(philo->fork_left_mutex);
		}
		else
		{
			print_state(philo, FORK);
			pthread_mutex_lock(philo->fork_right_mutex);
			{
				print_state(philo, FORK);
				pthread_mutex_lock(philo->fork_left_mutex);
				// LOT OF CODE HERE //
				pthread_mutex_unlock(philo->fork_left_mutex);
			}
			pthread_mutex_unlock(philo->fork_right_mutex);
		}
		eating(philo);	
	
	return (NULL);
}

int main(int argc, char **argv)
{
	t_table		table;
	size_t			i;
	
	if (argc < 5 || argc > 6)
	error_args();
	i = 0;
	init_program(&table, argv); // TO DO
	printf("Time from the start: %ld\n", get_time(&table.start));
	usleep(500000);
	printf("Time from the start: %ld\n", get_time(&table.start));
	pthread_mutex_destroy(table.fork_mutex);
	pthread_mutex_destroy(&table.write_mutex);
	while (i < table.nbr_of_philos)
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
// write atoi // DONE
// Init ft for struct and philos. How to store multiple philos -> array. // DONE
// How to deal with 5th arg being there and not. NULL / zero what?? // DONE
// Fix the UNIX Epoch time. // DONE
// X is thinking message. // DONE
// Forks are the mutexes, same array as philos. &fork[i] // DONE
// mutexes to lock forks // DONE
// How to differentiate forks, with numbers? I think that left/right won't work. // DONE
// DO Somewhere now here whatever: Where to INIT Forks? // DONE
// Assign write_mutex // DONE