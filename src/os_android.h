/**
 * @file
 * @brief
 *
 * @copyright Copyright (C) 2017-2018 Wind River Systems, Inc. All Rights Reserved.
 *
 * @license Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software distributed
 * under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES
 * OR CONDITIONS OF ANY KIND, either express or implied."
 */
#ifndef OS_ANDROID_H
#define OS_ANDROID_H

/*
 * This file provides the pieces necessary for the OS abstraction layer to
 * function on Android. Most of the functionality is provided by POSIX, but
 * some things are slightly different on Android.
 */

#ifndef OS_H
#error "This file must be included only by os.h"
#endif /* ifndef OS_H */

#define COMMAND_PREFIX           ""
#define SERVICE_SHUTDOWN_CMD     "svc power shutdown"
#define SERVICE_START_CMD        "start %s"
#define SERVICE_STATUS_CMD       "ps | grep %s"
#define SERVICE_STOP_CMD         "stop %s"
#define SERVICE_REBOOT_CMD       "svc power reboot \"rebooting\""
#define OTA_DUP_PATH             "/data/local/tmp"

#define OS_COMMAND_SH            "/system/bin/sh", "sh", "-c"

#define COMMAND_OUTPUT_MAX_LEN   128u

#endif /* ifndef OS_ANDROID_H */

