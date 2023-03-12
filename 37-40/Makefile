.PHONY: clean generate build \
	      37 38 39 40

clean:
	rm -rf build/ .cache/

generate:
	cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -S . -B build/

build:
	cmake --build build/

37:
	./build/37/37
	
38:
	./build/38/38
	
39:
	./build/39/39
	
40:
	./build/40/40
