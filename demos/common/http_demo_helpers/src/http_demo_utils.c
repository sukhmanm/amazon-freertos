/*
 * FreeRTOS V202011.00
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
 */

/* Standard includes. */
#include <assert.h>

#include "http_demo_utils.h"

/* Retry utilities. */
#include "retry_utils.h"

/* Third party parser utilities. */
#include "http_parser.h"

/*-----------------------------------------------------------*/

BaseType_t connectToServerWithBackoffRetries( TransportConnect_t connectFunction,
                                              NetworkContext_t * pxNetworkContext )
{
    BaseType_t xReturn = pdFAIL;
    /* Status returned by the retry utilities. */
    RetryUtilsStatus_t retryUtilsStatus = RetryUtilsSuccess;
    /* Struct containing the next backoff time. */
    RetryUtilsParams_t reconnectParams;

    assert( connectFunction != NULL );

    /* Initialize reconnect attempts and interval */
    RetryUtils_ParamsReset( &reconnectParams );

    /* Attempt to connect to HTTP server. If connection fails, retry after
     * a timeout. Timeout value will exponentially increase until maximum
     * attempts are reached. */
    do
    {
        xReturn = connectFunction( pxNetworkContext );

        if( xReturn != pdTRUE )
        {
            LogWarn( ( "Connection to the HTTP server failed. "
                       "Retrying connection with backoff and jitter." ) );
            retryUtilsStatus = RetryUtils_BackoffAndSleep( &reconnectParams );
        }
    } while( ( xReturn == pdFAIL ) && ( retryUtilsStatus == RetryUtilsSuccess ) );

    if( xReturn == pdFAIL )
    {
        LogError( ( "Connection to the server failed, all attempts exhausted." ) );
    }

    return xReturn;
}
