INCLUDE := /home/den/python/include/python2.7
LIBS := /home/den/python/lib

CFLAGS := -std=gnu99 -g -Wall -fPIC -I$(INCLUDE)

CC := gcc

OUT_DIR := result/

.PHONY: all

VPATH = $(OUT_DIR)

unic.so : unitest.o 
	$(CC)  -shared -o $(OUT_DIR)$@ $(OUT_DIR)unitest.o -L$(LIBS)


unitest.o: unitest.c unitest.h
	$(CC) -c $(CFLAGS) -fdata-sections -ffunction-sections -o $(OUT_DIR)$@ unitest.c
