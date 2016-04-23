#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <event.h> //add libevent

struct event _ev;
struct timeval _time_out;

void time_cb(int fd, short event, void *argc)
{
	printf("wake up...\n");
	event_add(&_ev, &_time_out);
}

int main()
{
	struct event_base *base = event_init();
	_time_out.tv_sec  = 1;
	_time_out.tv_usec = 0;
	event_set(&_ev, -1, 0, time_cb, NULL);

	event_add(&_ev, &_time_out);

	event_base_dispatch(base);
}
