/*
 * FreeRTOS Kernel V10.3.0
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

#ifndef DEMO_CONFIG_H
#define DEMO_CONFIG_H

/**************************************************/
/******* DO NOT CHANGE the following order ********/
/**************************************************/

/* Include logging header files and define logging macros in the following order:
 * 1. Include the header file "logging_levels.h".
 * 2. Define the LIBRARY_LOG_NAME and LIBRARY_LOG_LEVEL macros depending on
 * the logging configuration for DEMO.
 * 3. Include the header file "logging_stack.h", if logging is enabled for DEMO.
 */

#include "logging_levels.h"

/* Logging configuration for the Demo. */
#ifndef LIBRARY_LOG_NAME
    #define LIBRARY_LOG_NAME    "MQTTDemo"
#endif

#ifndef LIBRARY_LOG_LEVEL
    #define LIBRARY_LOG_LEVEL    LOG_INFO
#endif
#include "logging_stack.h"

/************ End of logging configuration ****************/

/**
 * @brief The MQTT client identifier used in this example.  Each client identifier
 * must be unique so edit as required to ensure no two clients connecting to the
 * same broker use the same client identifier.
 *
 * #define democonfigCLIENT_IDENTIFIER              "insert here."
 */


/**
 * @brief MQTT broker end point to connect to.
 *
 * @note For running this demo an MQTT broker, which can be run locally on
 * the same host is recommended. Any MQTT broker, which can be run on a Windows
 * host can be used for this demo. However, the instructions below are for
 * setting up a local Mosquitto broker on a Windows host.
 * 1. Download Mosquitto from https://mosquitto.org/download/
 * 2. Install Mosquitto as a Windows service by running the installer.
 * More details about installing as a Windows service can be found at
 * https://github.com/eclipse/mosquitto/blob/master/readme-windows.txt and
 * https://github.com/eclipse/mosquitto/blob/master/readme.md
 * 3. Verify that Mosquitto server is running locally and listening on port
 * 8883 by following the steps below.
 *     a. Open Power Shell.
 *     b. Type in command `netstat -a -p TCP | grep 8883` to check if there
 *        is an active connection listening on port 8883.
 *     c. Verify that there is an output as shown below
 *        `TCP    0.0.0.0:8883           <HOST-NAME>:0       LISTENING`
 *     d. If there is no output on step c,go through the Mosquitto documentation
 *        listed above to check if the installation was successful.
 *
 * As an alternative option, a publicly hosted Mosquitto broker can also be
 * used as an MQTT broker end point. This can be done by updating the config
 * democonfigMQTT_BROKER_ENDPOINT to "test.mosquitto.org". However, this is not
 * recommended due the possible downtimes of the broker as indicated by the
 * documentation in https://test.mosquitto.org/.
 *
 * #define democonfigMQTT_BROKER_ENDPOINT               "insert here."
 */


/**
 * @brief Server's root CA certificate.
 *
 * For AWS IoT MQTT broker, this certificate is used to identify the AWS IoT
 * server and is publicly available. Refer to the AWS documentation available
 * in the link below.
 * https://docs.aws.amazon.com/iot/latest/developerguide/server-authentication.html#server-authentication-certs
 *
 * @note This certificate should be PEM-encoded.
 *
 * Must include the PEM header and footer:
 * "-----BEGIN CERTIFICATE-----\n"\
 * "...base64 data...\n"\
 * "-----END CERTIFICATE-----\n"
 *
 * #define democonfigROOT_CA_PEM    "...insert here..."
 */


/**
 * @brief The port to use for the demo.
 *
 * #define democonfigMQTT_BROKER_PORT                   ( insert here. )
 */


/**
 * @brief Set the stack size of the main demo task.
 *
 * In the Windows port, this stack only holds a structure. The actual
 * stack is created by an operating system thread.
 */
#define democonfigDEMO_STACKSIZE    configMINIMAL_STACK_SIZE

#endif /* DEMO_CONFIG_H */
