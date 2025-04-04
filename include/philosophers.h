/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:08:33 by tbruha            #+#    #+#             */
/*   Updated: 2025/04/04 15:38:43 by tbruha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// HEADERS

# include <stddef.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <pthread.h>
# include <sys/time.h>

// ENUMS

typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	FORK,
	DEAD
}			t_state;

// STRUCTS

typedef struct s_philo
{
	pthread_t		philo;
	int     		index;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			last_meal_ms; // if current - last > time_to_die == DEAD. Check by waiter.
	pthread_mutex_t	mutex_fork_left; // nbr same as index
	pthread_mutex_t	mutex_fork_right; // nbr index + 1 % total number of philos, I don't know number of philos here..
	size_t			times_eaten;
}					t_philo;

typedef struct s_table
{
	size_t			nbr_of_philos;
	t_philo			*philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	bool			bon_appetit;
	pthread_mutex_t	*forks_mutex;
	pthread_t		waiter; // monitor thread -> checking if philos are dead and if they ate enough.
	pthread_mutex_t	meal_lock; // not sure why.
	pthread_mutex_t	write_lock;
	long int		start;
	int     		nbr_to_eat; // array?
	bool			dead_flag;
}					t_table;

// FUNCTIONS

// init.c
void		init_philos(t_table *table);
void		init_program(t_table *table, char **argv);

// utils.c
void		error_args();
long int	get_time(t_table *table);
size_t		ft_atoi(char *str);
int			check_args(char **argv);

// philosophers.c
void		*routine(void *arg);

#endif
