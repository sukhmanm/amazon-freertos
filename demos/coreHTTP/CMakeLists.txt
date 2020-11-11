# FreeRTOS coreHTTP demos
afr_demo_module(core_http)

# Set the default demo that is enabled in the downloaded package.
afr_set_demo_metadata(ID "CORE_HTTP_MUTUAL_AUTH_DEMO")
afr_set_demo_metadata(DESCRIPTION "Examples that demonstrate the HTTP library")
afr_set_demo_metadata(DISPLAY_NAME "coreHTTP Demos")

afr_module_sources(
    ${AFR_CURRENT_MODULE}
    INTERFACE
        "${CMAKE_CURRENT_LIST_DIR}/http_demo_mutual_auth.c"
        ${CMAKE_CURRENT_LIST_DIR}/CMakeLists.txt
)

afr_module_include_dirs(
    ${AFR_CURRENT_MODULE}
    INTERFACE
        ${AFR_DEMOS_DIR}/coreHTTP/http_common
)

afr_module_dependencies(
    ${AFR_CURRENT_MODULE}
    INTERFACE
        AFR::http_common
        AFR::core_http
        AFR::retry_utils
        AFR::transport_interface_secure_sockets
        AFR::secure_sockets
        # Add dependency on the core_http_demo_dependencies metadata module 
        # so that FreeRTOS console shows this demo ONLY when the core HTTP library
        # is selected on the console.
        AFR::core_http_demo_dependencies
)
