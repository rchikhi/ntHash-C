all: ntHash/build/libnthash.a libnthashc.so main

ntHash/build/libnthash.a:
	cd ntHash && git submodule init && git submodule update && mkdir -p build && cd build && cmake -DCMAKE_POSITION_INDEPENDENT_CODE=ON .. && make

libnthashc.so: nthashc.cpp
	g++ -shared -o libnthashc.so nthashc.cpp  -lc -LntHash/build -lnthash -IntHash/build/btllib/include/ -IntHash/include/ -fPIC -lbtllib -LntHash/build/btllib/lib/

main: main.c 
	gcc -o main main.c -L. -lnthashc 

clean:
	rm -f libnthashc.so main
