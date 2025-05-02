/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:11:11 by tbruha            #+#    #+#             */
/*   Updated: 2025/05/02 15:00:35 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DO NOW: Create and make to work the fifth argument...

// Check valid input.
// What if two philos die at the same time?
// Free everything if all of them ate enough.
// How to handle freeing upon "ctrl + c" if no philo should die?
// If philo dies during meal or sleep, does he finished meal/sleep and die...
// ... or does he needs to die right away.

// What if waiter write's the message and the program finished after he is awake/dead
// add start time to each philo as well?
// How to start the simulation at the same time -> bon_appetit how? NOT NOW
// what is meal_lock for? // lock when checking the last meal eaten meals_eaten++ maybe?
// If I don't use size_t in atoi it will sort out bad input. TO DO.
// How to handle errors? Fts to FREE everything and exit. (no EXIT though)
// When does it start, once I do pthread_create it starts right away? Do I want that?
// Check allowed functions -> no EXIT.
// 20 450/500 200 200 // 1 800 200 200 (doesnt exit) // 5 800 200 200
// 5 800 200 200 7 // 4 410 200 200 // 4 310 200 100

// BUGS:
// Only philo have both mutaxes pointing to the same fork.

// notes to research:
// Philosophy -> from Greek, philosophia, literally "love of wisdom".

#include "include/philosophers.h"

void	print_state(t_philo *philo, t_state state)
{
	pthread_mutex_lock(philo->write_mutex);
	if (philo->dead == false)
	{
		if (state == 0)
		printf("%5zu ms -> %d is thinking.\n", get_time(&philo->start), philo->id);
		else if (state == 1)
		printf("%5zu ms -> %d is eating.\n", get_time(&philo->start), philo->id);
		else if (state == 2)
		printf("%5zu ms -> %d is sleeping.\n", get_time(&philo->start), philo->id);
		else if (state == 3)
		printf("%5zu ms -> %d has taken a fork.\n", get_time(&philo->start), philo->id);
		else if (state == 4)
		printf("%5zu ms -> %d is "RED"DEAD"RESET".\n", get_time(&philo->start), philo->id);
	}
	pthread_mutex_unlock(philo->write_mutex);
}

void	sleeping(t_philo *philo)
{
	print_state(philo, SLEEPING);
	ft_milisleep(philo->time_to_sleep, philo->dead);
}

// It prints that philo is sleeping and puts him to sleep and incr times_eaten.
void	eating(t_philo *philo)
{
	print_state(philo, EATING);
	philo->last_meal_ms = get_time(&philo->start);
	ft_milisleep(philo->time_to_eat, philo->dead);
	philo->times_eaten++;
}

void	thinking(t_philo *philo)
{
	print_state(philo, THINKING);
}
// 
// routine for odd id philos
void	odd_routine(t_philo *philo)
{
	while (philo->dead == false)
	{
		thinking(philo);
		pthread_mutex_lock(philo->fork_right_mutex);
		{
			print_state(philo, FORK);
			pthread_mutex_lock(philo->fork_left_mutex);
			{
				print_state(philo, FORK);
				eating(philo);
			}
			pthread_mutex_unlock(philo->fork_left_mutex);
		}
		pthread_mutex_unlock(philo->fork_right_mutex);
		sleeping(philo);
	}
}

// routine for even id philos
void	even_routine(t_philo *philo)
{
	while (philo->dead == false)
	{
		thinking(philo);
		pthread_mutex_lock(philo->fork_left_mutex);
		{
			print_state(philo, FORK);
			pthread_mutex_lock(philo->fork_right_mutex);
			{
				print_state(philo, FORK);
				eating(philo);
			}
			pthread_mutex_unlock(philo->fork_right_mutex);
		}
		pthread_mutex_unlock(philo->fork_left_mutex);
		sleeping(philo);
	}	
}

// Routine includes philos eating, sleeping and thinking.
void	*routine(void *arg)
{
	t_philo	*philo = (t_philo *)arg;
	// wait while bon_appetit == false; set true after everything is ready.
	
	if (philo->id % 2 == 1)
	ft_milisleep(1, false);
	if (philo->id % 2 == 0)
	even_routine(philo);
	else
	odd_routine(philo);
	return (NULL);
}

int main(int argc, char **argv)
{
	t_table		table;
	size_t			i;
	
	if (argc < 5 || argc > 6)
	error_args();
	i = 0;
	init_program(&table, argv);
	while (i < table.nbr_of_philos)
	{
		if (pthread_join(table.philos[i].philo, NULL) != 0)
		return (2);
		i++;
	}
	pthread_mutex_destroy(table.fork_mutex);
	pthread_mutex_destroy(&table.write_mutex);
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
// Own ft_usleep function. // DONE
// Create a philo routine. // DONE
// Don't forget to join threads at the end.. // DONE
// Separate odd/even routines in code. // DONE
// Create death check by waiter, because philo might be sleeping. // DONE
// How to change color for DEAD message. // DONE
// Sim now finishes round. How to correctly finish it once DEAD state. // DONE