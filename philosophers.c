/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:11:11 by tbruha            #+#    #+#             */
/*   Updated: 2025/03/05 15:27:18 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Philosophy -> from Greek, philosophia, literally "love of wisdom".

// DO NOW NOW: Test gettimeofday function. Settimeofday to 0?

// Make philo struct.
// Check valid input
// table with forks struct??
// mutexes to lock forks

// notes to research:
// What are the test cases and input that I need to run successfully?
// 5 800 200 200 (7)
// What is threading? What is mutex? // DONE
// Learn functions: "gettimeofday", "pthread_create", "pthread_detach"
// ditto-> "pthread_join", "pthread_mutex_init", "pthread_mutex_destroy" // DONE
// ditto-> "pthread_mutex_lock", "pthread_mutex_unlock" // DONE
// read up on pipex on gitbook and try to understand it.

// gcc -pthread -Wall -Wextra -Werror

#include "include/philosophers.h"

int				g_balance;
pthread_mutex_t	g_mutex;

int	read_balance()
{
	usleep(250000);
	return (g_balance);
}

void	*deposit(void *deposit)
{
	pthread_mutex_lock(&g_mutex);
	read_balance();
	usleep(250000);
	g_balance += *(int *)deposit;
	pthread_mutex_unlock(&g_mutex);
	return (NULL);
}

int main(void)
{
	struct timeval	tv;
	
	pthread_t		t1;
	pthread_t		t2;
	int				deposit_1;
	int				deposit_2;

	pthread_mutex_init(&g_mutex, NULL);
	deposit_1 = 300;
	deposit_2 = 200;
	gettimeofday(&tv, NULL);
	printf("time now: %ld\n", tv.tv_sec);
	printf("Balance before deposits is %d\n", g_balance);
	// last argument of pthread_create is argument for "*action".
	if (pthread_create(&t1, NULL, &deposit, &deposit_1) != 0)
		return (2);
	if (pthread_create(&t2, NULL, &deposit, &deposit_2) != 0)
		return (2);
	if (pthread_join(t1, NULL) != 0)
		return (2);
	if (pthread_join(t2, NULL) != 0)
		return (2);
	pthread_mutex_destroy(&g_mutex);
	gettimeofday(&tv, NULL);
	printf("time later: %ld\n", tv.tv_usec);
	printf("Balance after deposits is %d\n", g_balance);
	return (EXIT_SUCCESS);
}

// ----------------------------------------------------------------------------

// RTFM -> kidding -> read the subject and go from there. // DONE
// Google and watch some videos to get better broad understanding. // DONE
// Test the "deposit 200 & 300 money test to see how it works." // DONE