// Generated by `wit-bindgen` 0.26.0. DO NOT EDIT!
#include "something.h"
#include <stdlib.h>
#include <string.h>

// Imported Functions from `wasi:logging/logging`

__attribute__((__import_module__("wasi:logging/logging"), __import_name__("log")))
extern void __wasm_import_wasi_logging_logging_log(int32_t, uint8_t *, size_t, uint8_t *, size_t);

// Imported Functions from `component:wasm-app/wow@0.1.0`

__attribute__((__import_module__("component:wasm-app/wow@0.1.0"), __import_name__("hello-world")))
extern void __wasm_import_component_wasm_app_wow_hello_world(uint8_t *);

__attribute__((__import_module__("component:wasm-app/wow@0.1.0"), __import_name__("add")))
extern int32_t __wasm_import_component_wasm_app_wow_add(int32_t, int32_t);

// Exported Functions from `something`


// Canonical ABI intrinsics

__attribute__((__weak__, __export_name__("cabi_realloc")))
void *cabi_realloc(void *ptr, size_t old_size, size_t align, size_t new_size) {
  (void) old_size;
  if (new_size == 0) return (void*) align;
  void *ret = realloc(ptr, new_size);
  if (!ret) abort();
  return ret;
}

// Helper Functions

void something_string_set(something_string_t *ret, const char*s) {
  ret->ptr = (uint8_t*) s;
  ret->len = strlen(s);
}

void something_string_dup(something_string_t *ret, const char*s) {
  ret->len = strlen(s);
  ret->ptr = (uint8_t*) cabi_realloc(NULL, 0, 1, ret->len * 1);
  memcpy(ret->ptr, s, ret->len * 1);
}

void something_string_free(something_string_t *ret) {
  if (ret->len > 0) {
    free(ret->ptr);
  }
  ret->ptr = NULL;
  ret->len = 0;
}

// Component Adapters

void wasi_logging_logging_log(wasi_logging_logging_level_t level, something_string_t *context, something_string_t *message) {
  __wasm_import_wasi_logging_logging_log((int32_t) level, (uint8_t *) (*context).ptr, (*context).len, (uint8_t *) (*message).ptr, (*message).len);
}

void component_wasm_app_wow_hello_world(something_string_t *ret) {
  __attribute__((__aligned__(4)))
  uint8_t ret_area[8];
  uint8_t *ptr = (uint8_t *) &ret_area;
  __wasm_import_component_wasm_app_wow_hello_world(ptr);
  *ret = (something_string_t) { (uint8_t*)(*((uint8_t **) (ptr + 0))), (*((size_t*) (ptr + 4))) };
}

int32_t component_wasm_app_wow_add(int32_t a, int32_t b) {
  int32_t ret = __wasm_import_component_wasm_app_wow_add(a, b);
  return ret;
}

__attribute__((__export_name__("start")))
void __wasm_export_something_start(void) {
  something_start();
}

// Ensure that the *_component_type.o object is linked in

extern void __component_type_object_force_link_something(void);
void __component_type_object_force_link_something_public_use_in_this_compilation_unit(void) {
  __component_type_object_force_link_something();
}
