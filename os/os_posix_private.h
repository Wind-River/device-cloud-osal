/**
 * @file
 * @brief header file declaring functions & symbols for POSIX systems
 *
 * @copyright Copyright (C) 2016-2017 Wind River Systems, Inc. All Rights Reserved.
 *
 * @license The right to copy, distribute or otherwise make use of this software
 * may be licensed only pursuant to the terms of an applicable Wind River
 * license agreement.  No license to Wind River intellectual property rights is
 * granted herein.  All rights not licensed by Wind River are reserved by Wind
 * River.
 */
#ifndef OS_POSIX_PRIVATE_H
#define OS_POSIX_PRIVATE_H

#include <os.h>
#include <limits.h>      /* for PATH_MAX */
#include <stdio.h>       /* for FILE* */

/* includes for #defined functions */
#include <ctype.h>
#include <dlfcn.h>
#include <errno.h>
#include <limits.h> /* for PATH_MAX */
#include <pthread.h>
#include <stdio.h>  /* for printf */
#include <stdlib.h> /* for malloc */
#include <string.h> /* for bzero, strncmp */
#include <sys/time.h> /* for gettimeofday */
#include <unistd.h> /* for sleep */
#include <time.h>   /* for nanosleep */

#ifndef _WRS_KERNEL
#include <sys/utsname.h> /* for struct utsname */
#endif

#ifndef _WRS_KERNEL
#	include <uuid/uuid.h>   /* osals uuid header, not system, for libuuid functions + uuid_t */
#endif

#ifndef _WRS_KERNEL
/** @brief Maximum length of a host name on POSIX systems */
#ifndef _POSIX_HOST_NAME_MAX
#	define _POSIX_HOST_NAME_MAX 64
#endif
#define OS_HOST_MAX_LEN _POSIX_HOST_NAME_MAX
#endif

#include <arpa/inet.h>  /* for inet_ntoa, inet_htons */
#include <dirent.h>     /* for DIR*, opendir, closedir */
#include <fcntl.h>      /* for open, O_WRONLY, O_CREAT, O_EXCL, S_IRUSR,
                          S_IWUSR, S_IRGRP, S_IROTH */
#include <limits.h>     /* for PATH_MAX */
#include <netdb.h>      /* for struct addrinfo */
#include <pthread.h>    /* for threading support */
#include <signal.h>     /* for siginfo_t */
#include <sys/socket.h> /* for struct addrinfo */

#if defined(__linux__) || defined (_WRS_KERNEL)
#	include <net/if.h>    /* for struct ifconf */
#endif
#include <ifaddrs.h>

/**
 * @brief contains information about a socket
 */
struct os_socket
{
	/** @brief Contains the address host address */
	struct sockaddr addr;
	/** @brief Contains the host port */
	os_uint16_t port;
	/** @brief File descriptor to the open socket */
	int fd;
	/** @brief Socket type */
	int type;
	/** @brief Socket protocol */
	int protocol;
};

/**
 * @brief Structure holding internal adapter list
 */
struct os_adapters
{
	/** @brief Current adapter information (used to obtain mac) */
	struct addrinfo *addr;
	/** @brief Current adapter */
	struct ifaddrs *current;
	/** @brief First adapter */
	struct ifaddrs *first;
};

/**
 * @brief Structure holding directory list information
 */
struct os_dir
{
	/** @brief Handle to the open directory */
	DIR *dir;
	/** @brief Path to the directory */
	const char *path;
};

#endif /* ifndef OS_POSIX_PRIVATE_H */
