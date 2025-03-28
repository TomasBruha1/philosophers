/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:11:11 by tbruha            #+#    #+#             */
/*   Updated: 2025/03/28 12:47:04 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DO NOW NOW: Look at fork implementation of opened git.
// DO NOW: X is thinking message.

// How to start the simulation at the same time -> bon_appetit how? NOT NOW
// Check valid input
// color code your philo messages
// Don't forget to join threads at the end.
// mutexes to lock forks
// create a philo routine
// create death check
// If I don't use size_t in atoi it will sort out bad input. TO DO.
// How to deal with 5th arg being there and not. NULL / zero what??
// How to differentiate forks, with numbers? I think that left/right won't work.
// When does it start, once I do pthread_create it starts right away? Do I want that?
// Check allowed functions -> no EXIT.


// notes to research:
// Learn functions: "gettimeofday", "pthread_create", "pthread_detach"
// read up on pipex on gitbook and try to understand it.
// Philosophy -> from Greek, philosophia, literally "love of wisdom".

#include "include/philosophers.h"

void	print_state(int philo, t_state state)
{
	if (state == 0)
		printf("%d is thinking.\n", philo);
	else if (state == 1)
		printf("%d is eating.\n", philo);
	else if (state == 2)
		printf("%d is sleeping.\n", philo);
	else if (state == 3)
		printf("%d has taken a fork.\n", philo);
	else if (state == 4)
		printf("%d has died.\n", philo);
}

void	eating(t_philo *philo)
{
	(void)philo;
}

void	thinking(t_philo *philo)
{
	print_state(philo->index, THINKING);
	
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
	printf("Time from the start: %ld\n", get_time(&table));
	usleep(500000);
	printf("Time from the start: %ld\n", get_time(&table));
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