BINARY=main
CODEDIRS=. lib
INCDIRS=. ./include/

CC=gcc
OPTS=
#dependencies flags for compiler 
#so that make can recompile program when dependencies chane
DEPFLAGS=-MP -MD 
#for each var D iterate through all include dirs and add prefix I
CFLAGS=-Wall $(foreach D,$(INCDIRS),-I$(D)) $(DEPFLAGS)
#automatically generate list of .c files
CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
#pattern substitution (.c convert .c into .o / .d respectively)
OBJECTS=$(patsubst %.c,%.o,$(CFILES))
DEPFILES=$(patsubst %.c,%.d,$(CFILES))

all: $(BINARY) #standard rule / make without args
							 #can recursively call makefile

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^
	#you can call makefiles recursively

# % -> *.o 
#if .o file is already created and .c unchanged it won't run
#makefile wouldn't know about dependencies that .c files can rely on
%.o:%.c
	# $@ left side : right side of the rule 
	# (left side ~ file <-> right side ~ script used to create it)
	$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	rm $(BINARY) $(OBJECTS) $(DEPFILES)

#git functionality from within makefile
diff:
	$(info The status of repository)
	@git status
	@git diff --stat
-include $(DEPFILES)
