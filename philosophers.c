/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:11:11 by tbruha            #+#    #+#             */
/*   Updated: 2025/02/15 21:30:02 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Philosophy -> from Greek, philosophia, literally "love of wisdom".

// DO NOW: Google and watch some videos to get better broad understanding.

// Make philo struct.
// table with forks struct??
// mutaxes to lock forks

// notes to research:
// What is threading? What is mutex?
// Learn functions: "gettimeofday", "pthread_create", "pthread_detach"
// ditto-> "pthread_join", "pthread_mutex_init", "pthread_mutex_destroy"
// ditto-> "pthread_mutex_lock", "pthread_mutex_unlock"
// read up on pipex on gitbook and try to understand it.

// gcc -pthread -Wall -Wextra -Werror

#include "include/philosophers.h"

void	*action(void *arg)
{
	(void)arg;
	printf("Hello from a thread\n");
	sleep(2);
	printf("Process id: %d\n", getpid());
	sleep(2);
	printf("End of thread test\n");
	return NULL;
}

int main(void)
{
	pthread_t	t1;
	pthread_t	t2;
	
	if (pthread_create(&t1, NULL, &action, NULL) != 0)
		return (2);
	if (pthread_create(&t2, NULL, &action, NULL) != 0)
		return (2);
	if (pthread_join(t1, NULL) != 0)
		return (2);
	if (pthread_join(t2, NULL) != 0)
		return (2);
	return (EXIT_SUCCESS);
}

// ----------------------------------------------------------------------------

// RTFM -> kidding -> read the subject and go from there. // DONE