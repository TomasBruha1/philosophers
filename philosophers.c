/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:11:11 by tbruha            #+#    #+#             */
/*   Updated: 2025/04/08 17:28:49 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DO NOW NOW NOW NOW: Assign mutexes....
// DO NOW NOW NOW: Forks are the mutexes, same array as philos. &fork[i]
// DO Somewhere now here whatever: Where to INIT Forks?
// DO NOW: X is thinking message.

// add start time to each philo as well?
// what is meal_lock for?
// How to start the simulation at the same time -> bon_appetit how? NOT NOW
// Own sleep function.
// Check valid input.
// color code your philo messages
// Don't forget to join threads at the end..
// mutexes to lock forks
// create a philo routine.
// create death check
// If I don't use size_t in atoi it will sort out bad input. TO DO.
// How to handle errors? Fts to FREE everything and exit. (no EXIT though)
// How to differentiate forks, with numbers? I think that left/right won't work.
// When does it start, once I do pthread_create it starts right away? Do I want that?
// Check allowed functions -> no EXIT.
// Make sure you pass 20 450/500 200 200


// notes to research:
// Learn functions: "gettimeofday", "pthread_create", "pthread_detach"
// read up on pipex on gitbook and try to understand it.
// Philosophy -> from Greek, philosophia, literally "love of wisdom".

#include "include/philosophers.h"

void	print_state(t_philo *philo, t_state state)
{
	
	// add time to the message.
	
	if (state == 0)
	printf("%zu - %d is thinking.\n", get_time(&philo->start), philo->index);
	else if (state == 1)
	printf("%zu - %d is eating.\n", get_time(&philo->start), philo->index);
	else if (state == 2)
	printf("%zu - %d is sleeping.\n", get_time(&philo->start), philo->index);
	else if (state == 3)
	printf("%zu - %d has taken a fork.\n", get_time(&philo->start), philo->index);
	else if (state == 4)
	printf("%zu - %d has died.\n", get_time(&philo->start), philo->index);
}

void	eating(t_philo *philo)
{
	(void)philo;
	print_state(philo, EATING);
}

void	thinking(t_philo *philo)
{
	print_state(philo, THINKING);
	
	// x is thinking
	// x has taken fork
	// x has taken the other fork
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
	// 
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
	printf("table start %zu\n", table.start);
	printf("Time from the start: %ld\n", get_time(&table.start));
	usleep(500000);
	printf("Time from the start: %ld\n", get_time(&table.start));
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