CXX = g++					# compiler
CXXFLAGS = -std=c++14 -g -Wall -MMD	-Werror=vla		# compiler flags
MAKEFILE_NAME = ${firstword ${MAKEFILE_LIST}}	# makefile name

OBJECTS = problem2.o	# object files forming executable
DEPENDS = ${OBJECTS:.o=.d}			# substitute ".o" with ".d"
EXEC = problem2 				# executable name

########## Targets ##########

.PHONY : clean					# not file names

${EXEC} : ${OBJECTS}			# link step
	${CXX} ${CXXFLAGS} $^ -o $@		# additional object files before $^

${OBJECTS} : ${MAKEFILE_NAME}			# OPTIONAL : changes to this file => recompile

# make implicitly generates rules to compile C++ files that generate .o files

-include ${DEPENDS}				# include *.d files containing program dependences

clean :						# remove files that can be regenerated
	rm -f ${DEPENDS} ${OBJECTS} ${EXEC}
