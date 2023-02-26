.PHONY: clean generate build 01 02 03 04 05 06 07 08 09 10

clean:
	rm -rf build

generate:
	cmake -S . -B build/

silent-build:
	cmake --build build/

build:
	@make -s silent-build 

01:
	ln -sf 01/input.txt ./input.txt
	./build/01/01
	rm ./input.txt

02:
	./build/02/02

03:
	./build/03/03

04:
	./build/04/04
	
05:
	./build/05/05
	
06:
	./build/06/06

07:
	./build/07/07

08:
	./build/08/08

09:
	./build/09/09

10:
	./build/10/10
