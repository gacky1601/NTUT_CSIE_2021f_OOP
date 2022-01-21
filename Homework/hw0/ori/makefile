# This is the default target, which will be built when you invoke make
.PHONY: all
# This rule tells make how to build HelloWorld from HelloWorld.cpp
all: HelloWorld.cpp
	g++ HelloWorld.cpp -o HelloWorld
# This rule tells make to delete hello and hello.o
.PHONY: clean
clean:
	rm -f HelloWorld
	rm -f ut_all