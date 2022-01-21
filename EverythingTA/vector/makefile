.PHONY: all
all: bin/test

bin/vector: src/vector.cpp src/length.h
	g++ src/vector.cpp -o bin/vector

bin/test: test/ut.cpp test/length_test.h bin
	g++ test/ut.cpp -o bin/ut_all -lgtest -lpthread 
# -fno-elide-constructors -g

.PHONY: bin
bin: 
	mkdir -p bin

.PHONY: clean
clean:
	rm -f bin/*