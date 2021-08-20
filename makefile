prog	=math

classes	=$(shell find incsrc -name *.cpp)
objects	=$(patsubst incsrc/%,bld/%,$(classes:.cpp=.o))

all:	directories $(prog)

directories:
	@mkdir -p bld
	@mkdir -p bin

$(prog):	$(objects)
	@echo " BUILDING  ...   ( ͠❛₃ ͡❛)"
	g++ -o bin/$@ $^ -Iincsrc
	@ctags -R *

bld/%.o:	incsrc/%.cpp
	@echo " COMPILING "
	g++ -o $@ -c $< 

clean:
	@rm -rf bld
	@echo "Cleaning complete"

purge: clean
	@rm -rf bin
	@echo "This is  SPARTA !!!!!!"
	@echo "KICK"

