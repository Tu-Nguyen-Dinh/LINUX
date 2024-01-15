.PHONY: all clean

CC := gcc

all:
	$(CC) -o con consumer.c -lrt 
	$(CC) -o pro producer.c -lrt 

clean:
	rm -rf  con pro 