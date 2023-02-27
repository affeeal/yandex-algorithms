.PHONY: clean generate build

clean:
	rm -rf build/ .cache/

generate:
	cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -S . -B build/

silent-build:
	cmake --build build/

build:
	@make -s silent-build 

.PHONY: 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15
	
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

11:
	./build/11/11

12:
	./build/12/12

13:
	./build/13/13

14:
	./build/14/14

15:
	./build/15/15
