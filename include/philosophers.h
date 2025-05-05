/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbruha <tbruha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 15:08:33 by tbruha            #+#    #+#             */
/*   Updated: 2025/05/05 13:56:29 by tbruha           ###   ########.fr       */
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

// DEFINES

# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define RESET	"\033[0m"

// ENUMS

typedef enum e_state
{
	THINKING,
	EATING,
	SLEEPING,
	FORK,
	DEAD,
	FULL
}			t_state;

// STRUCTS

typedef struct s_philo
{
	pthread_t		philo;
	int				id;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			last_meal_ms;
	size_t			start;
	pthread_mutex_t	*fork_left_mutex;
	pthread_mutex_t	*fork_right_mutex;
	pthread_mutex_t	*write_mutex;
	pthread_mutex_t	*meal_mutex;
	size_t			times_eaten;
	bool			dead;
}					t_philo;

typedef struct s_table
{
	size_t			nbr_of_philos;
	t_philo			*philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	bool			bon_appetit;
	pthread_mutex_t	*fork_mutex;
	pthread_t		waiter;
	pthread_mutex_t	meal_mutex; // not sure why. to check last meal??
	pthread_mutex_t	write_mutex;
	size_t			start;
	size_t			nbr_to_eat;
	bool			sim;
}					t_table;

// FUNCTIONS

// init.c
void		init_philos(t_table *table);
void		init_program(t_table *table, char **argv);
int			init_waiter(t_table *table);

// utils.c
void		error_args(void);
size_t		get_time(void *arg);
size_t		ft_atoi(char *str);
int			check_args(char **argv);
int			ft_milisleep(size_t milisec, t_philo *philo);

// utils_2.c
void		*waiter_routine(void *arg);

// philosophers.c
void		*routine(void *arg);
void		print_state(t_philo *philo, t_state state);

#endif
