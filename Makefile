build: src/main.c
	zig cc --target=wasm32-wasi component/something.c component/something_component_type.o src/main.c -o core.wasm -mexec-model=reactor -I component/
