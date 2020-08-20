CC = g++
LD = g++

TARGET = test

INCLUDES = -I ./..  
INCLUDES += -I /usr/local/googletest/include/ 

LIB = -L /usr/local/googletest/lib64/

CFLAGS = -c -g -O0 -std=c++17 -Wall

LDFLAGS = -lgtest -lpthread

SRC := ../base64.c test.cpp main.cpp

OBJS=$(SRC:.cpp=.o)

#$(warning  DEPS: $(DEPS))
.PHONY:all clean

all: $(TARGET)
$(TARGET): $(OBJS)
	$(LD) $^ -o $@ $(LDFLAGS) $(LIB) 

%.o:%.cpp
	$(CC) $(CFLAGS) $< $(INCLUDES) -o $@

clean:
	rm $(TARGET) $(OBJS) 

