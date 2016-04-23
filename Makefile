event_timeout:event_timeout.c
	gcc -o $@ $^ -I/usr/local/libevent/include -L/usr/local/libevent/lib -levent #-static
.PHONY:clean
clean:
	rm -f event_timeout
