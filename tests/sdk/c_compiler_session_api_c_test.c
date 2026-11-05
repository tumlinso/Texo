#include <Texo/sdk/c_compiler_session_api_v1.hh>

#include <assert.h>
#include <string.h>

static int cancelled(void* data) { return *(int*)data; }

int main(void) {
    int cancel = 0;
    texo_compiler_config_v1 config = {
        sizeof(config), "x86_64", "host-c", "default", 0, cancelled, &cancel};
    texo_compiler_session_v1* session =
        texo_compiler_session_create_v1(&config);
    assert(session != 0);
    assert(texo_compiler_session_add_source_buffer_v1(
        session, "sample.texo", "cell x;", strlen("cell x;")));
    assert(texo_compiler_session_add_source_file_v1(session, "other.texo"));
    texo_compiler_output_v1 output = {sizeof(output), 0, 0};
    assert(texo_compiler_session_compile_v1(session, &output));
    assert(output.source_count == 2 && strstr(output.object_identity, "host-c") != 0);
    texo_compiler_session_destroy_v1(session);
    return 0;
}
