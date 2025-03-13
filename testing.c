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
	// last argument of pthread_create is argument for "&deposit".
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