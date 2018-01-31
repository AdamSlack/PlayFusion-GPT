# Compiler to use:
CC=g++

# Flags to pass to compiler:
CFLAGS=-c -Wall -std=c++11

# Linker flags to pass to compiler:
LDFLAGS= 

# Sources to compile:
SOURCES= main.cpp matcher.cpp

# Compile sources to object files, replacing .cpp with .o:
OBJECTS=$(SOURCES:.cpp=.o)

# Name of the reslucing executable:
EXECUTABLE=lightseekers

##
## Make All
##
all: $(SOURCES) $(EXECUTABLE)

# $@ is the name of the file being generated
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

# $< is the prerequisite file
.cpp.o:
	$(CC) $(CFLAGS) $< -o $@


##
## Make Clean
##

clean:
	rm $(OBJECTS) $(EXECUTABLE)
