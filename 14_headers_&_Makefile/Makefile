#Makefile is very whitespace sensiive
BINARY=main
CODEDIRS=. lib
INCDIRS=. ./include/

PATCH_NAME=patch

CC=gcc
OPT=
# dependencies flags for compiler 
# so that make can recompile program when dependencies chane
DEPFLAGS=-MP -MD
# for each var D iterate through all include dirs and add prefix I
CFLAGS=-Wall $(foreach D,$(INCDIRS),-I$(D)) $(OPT) $(DEPFLAGS)
# automatically generate list of .c files
CFILES=$(foreach D,$(CODEDIRS),$(wildcard $(D)/*.c))
# pattern substitution (.c convert .c into .o / .d respectively)
OBJECTS=$(patsubst %.c,%.o,$(CFILES))
DEPFILES=$(patsubst %.c,%.d,$(CFILES))

all: $(BINARY) #standard rule / make without args
							 #can recursively call makefile

# $@: The filename representing the target.
# $%: The filename element of an archive member specification.
# $<: The filename of the first prerequisite.
# $?: The names of all prerequisites that are newer than the target, separated by spaces.
# $^: The filenames of all the prerequisites, separated by spaces. This list has duplicate filenames removed since for most uses, such as compiling, copying, etc., duplicates are not wanted.
# $+: Similar to $^, this is the names of all the prerequisites separated by spaces, except that $+ includes duplicates. This variable was created for specific situations such as arguments to linkers where duplicate values have meaning.
# $*: The stem of the target filename. A stem is typically a filename without its suffix. Its use outside of pattern rules is discouraged.

$(BINARY): $(OBJECTS)
	$(CC) -o $@ $^
	#you can call makefiles recursively

# % -> *.o 
# if .o file is already created and .c unchanged it won't run
# makefile wouldn't know about dependencies that .c files can rely on
%.o:%.c
	# $@ left side : right side of the rule 
	# (left side ~ file <-> right side ~ script used to create it)

	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm $(BINARY) $(OBJECTS) $(DEPFILES)

# git functionality from within makefile
# @silences printing of the command
diff:
	$(info The status of repository, and the volume of pe-file changes:)
	@git status
	@git diff --stat
patch:
	# make patch PATCH_NAME="...." -> to simply override default patch name
	@git diff -p > "$(PATCH_NAME).diff"

-include $(DEPFILES)
