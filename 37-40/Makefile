.PHONY: clean generate build \
	      37 38 39

clean:
	rm -rf build/

generate:
	cmake -DCMAKE_EXPORT_COMPILE_COMMANDS=1 -S . -B build/

silent-build:
	cmake --build build/

build:
	@make -s silent-build 
	
37:
	./build/37/37
	
38:
	./build/38/38
	
39:
	./build/39/39
