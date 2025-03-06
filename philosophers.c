/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:11:11 by tbruha            #+#    #+#             */
/*   Updated: 2025/03/06 17:06:38 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// DO NOW NOW: Test gettimeofday function. Settimeofday to 0? PRINT IT

// Make philo struct.
// color code your philo messages
// Check valid input
// table with forks struct??
// mutexes to lock forks
// write atoi
// init func for all the struct and philos. How to store multiple philos? I don't get it.
// create a philo routine
// create death check
// Lot of stuff using size_t why? Why not just int?? Maybe put int everywhere and see.

// notes to research:
// What are the test cases and input that I need to run successfully?
// 5 800 200 200 (7) -> rest of the cases by skvackov
// What is threading? What is mutex? // DONE
// Learn functions: "gettimeofday", "pthread_create", "pthread_detach"
// ditto-> "pthread_join", "pthread_mutex_init", "pthread_mutex_destroy" // DONE
// ditto-> "pthread_mutex_lock", "pthread_mutex_unlock" // DONE
// read up on pipex on gitbook and try to understand it.
// Philosophy -> from Greek, philosophia, literally "love of wisdom".

#include "include/philosophers.h"

// This function will return current time of the simulation.
// NOW IT IS RETURNING TIME FROM EPOCH IN MILISECONDS.
long int	get_time(t_table *main)
{
	long int time;
	
	time = main->start.tv_sec * 1000 + main->start.tv_usec / 1000;
	time = time - (main->start.tv_sec * 1000 - main->start.tv_usec / 1000);
	return (time);
}

// Check if all the input is valid and we can proceed, otherwise exit.
int	check_args(char **argv)
{
	(void)argv;
	return (0);
}

// Initialize the program and structs here.
void	init_program(t_table *main, char **argv)
{
	if (!check_args(argv)) // TO DO
		printf("Args are OK.\n");
	else
		printf("Args are NOT OK.\n");
	gettimeofday(&main->start, NULL); // this will be for start.
}

int main(int argc, char **argv)
{
	t_table		main;
	
	pthread_t		t1;
	pthread_t		t2;
	
	(void)t1;
	(void)t2;
	(void)argc;
	// if (argc < 5 || argc > 6)
	// 	error_args();
	init_program(&main, argv); // TO DO
	
	printf("Time from Linux Epoch in miliseconds: %ld\n", get_time(&main));
	gettimeofday(&main.start, NULL);
	printf("time @ start: %ld\n", main.start.tv_sec);
	sleep(2);
	gettimeofday(&main.now, NULL);
	printf("time now: %ld\n", main.now.tv_sec);
	return (EXIT_SUCCESS);
}

// ----------------------------------------------------------------------------

// gcc -pthread -Wall -Wextra -Werror // DONE
// RTFM -> kidding -> read the subject and go from there. // DONE
// Google and watch some videos to get better broad understanding. // DONE
// Test the "deposit 200 & 300 money test to see how it works." // DONE