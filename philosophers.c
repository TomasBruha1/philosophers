/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:11:11 by tbruha            #+#    #+#             */
/*   Updated: 2025/03/27 15:46:39 by tbruha           ###   ########.fr       */
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
	(void)table; // delete later
	// wait while bon_appetit == false; set true after everything is ready.
	// ft think -> odd philo first left fork // even philo right fork
	// ft eat -> ft sleep
	// 
	write(1, "Hello\n", 6);
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