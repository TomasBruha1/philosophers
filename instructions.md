13.2.2025
Lets put instructions and other stuff here once it gets crowded with the code.

Instructions:
One or more philo are siting at a table.
Large bowl of spaghetti in the middle of the table.
philos alternatively EAT -> THINK -> SLEEP.
While DOING one thing, they are NOT DOING the other two.
There are forks on the table, ONE FOR EACH PHILO.
A philo will take their right and left fork to eat.
When a philo finishes eating -> they put forks back on the table ->
-> then start sleeping -> once awake they start thinking.
Simulation is over once philo dies of starvation.
Every philo needs to eat and should never starve.
Philos don't speak with each other.
Philos don't know if another philo is about to die.
No need to say that philos should avoid dying!

Global rules: 1 program for mandatory part and 1 for bonus part.
Global variables are forbidden!
Your(s) program(s) should take the following arguments:

number_of_philosophers: The number of philos and also the number of forks.

time_to_die (in milliseconds): If a philo didn't start eating time_to_die
milliseconds since the beginning of their last meal or the beginning of the
simulation, they die.

time_to_eat (in milliseconds): The time it takes for a philosoher to eat.
During that time, they will need to hold two forks.

time_to_sleep (in milliseconds): The time a philo will spend sleeping.

numbers_of_times_each_philosopher_must_eat (optional argument): If all philos
have eaten at least number_of_times_each_philosopther_must_eat times, the
simulation stops. If not specified, the simulation stops when a philo dies.

Each philo has a number ranging from 1 to number_of_philosophers.
Philo number 1 sits next to philo number number_of_philosophers. Any other
philo number N sits between philo number N-1 and philo nnumber N + 1.
About the logs off your program:
Any state change of a philosopher must be formatted as follows:
		timestamp_in_ms X has taken a fork
    	timestamp_in_ms X is eating
		timestamp_in_ms X is sleeping
		timestamp_in_ms X is thinking
		timestamp_in_ms X died
Replace timestamp_in_ms with the current timestamp in milliseconds
and X with the philo number.
A displayed state message should not be mixed up with another message.
A message announcing a philosopher died should be displayed no more
than 10 ms after the actual death of the philo.
Again, philos should avoid dying!
!!! Your program must not have any data races. !!!
NO LIBFT
Each philo should be a thread.
There is one fork between each pair of philos. Therefore, if there are several 
philos, each philo has a fork on their left side and a fork on their right side.
If there is only one philo, there should be only one fork on the table.
To prevent philos from duplicating forks, you should protect the forks state
with a mutex for each of them.

BONUS TIME -> has to oblige with the mandatory rules plus couple extras:
All the forks are put in the middle of the table.
They have no states in memory but the number of available forks is
represented by a semaphore.
Each philo should be a process. But the main process should not be a philo.
