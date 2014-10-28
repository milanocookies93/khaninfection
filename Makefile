EXENAME = khaninfection

COMPILER = g++
WARNINGS = -Wchar-subscripts -Wparentheses -Wreturn-type -Wmissing-braces -Wundef -Wshadow
COMPILER_OPTS = -c -g -O0 -Wfatal-errors -Werror $(WARNINGS)
LINKER = g++

MAIN_OBJS = main.o
MAIN_DEPS = kauser.h kauser.cpp kagraph.h kagraph.cpp main.cpp

CODE_CLN = *.o $(EXENAME)

all: $(EXENAME)

$(EXENAME) : main.o
	$(LINKER) $(MAIN_OBJS) -o $(EXENAME)

main.o : $(MAIN_DEPS)
	$(COMPILER) $(COMPILER_OPTS) main.cpp

clean:
	-rm -f $(CODE_CLN)