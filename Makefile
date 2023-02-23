.PHONY: clean generate build 01 02 03 04 05

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
