#include <stdio.h>
#include "something.h"

void something_start(void) {
    something_string_t context;
    something_string_set(&context, "lmao");
    something_string_t msg;
    something_string_set(&msg, "xd");

    something_string_t helloworld;
    component_wasm_app_wow_hello_world(&helloworld);
    wasi_logging_logging_log(WASI_LOGGING_LOGGING_LEVEL_INFO, &context, &helloworld);

    wasi_logging_logging_log(WASI_LOGGING_LOGGING_LEVEL_INFO, &context, &msg);
}
