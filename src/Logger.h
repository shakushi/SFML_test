#pragma once

#define ACTIVATE_DEBUG_LOG 1
#define ACTIVATE_INFO_LOG 1
#define ACTIVATE_WARN_LOG 1
#define ACTIVATE_ERROR_LOG 1

#ifdef ACTIVATE_DEBUG_LOG
#define SIMPLE_LOG_DEBUG(FORMAT, ...) printf(FORMAT, ##__VA_ARGS__)
#else
#define SIMPLE_LOG_DEBUG(FORMAT, ...)
#endif

#ifdef ACTIVATE_INFO_LOG
#define SIMPLE_LOG_INFO(FORMAT, ...) printf(FORMAT, ##__VA_ARGS__)
#else
#define SIMPLE_LOG_INFO(FORMAT, ...)
#endif

#ifdef ACTIVATE_WARN_LOG
#define SIMPLE_LOG_WARN(FORMAT, ...) printf(FORMAT, ##__VA_ARGS__)
#else
#define SIMPLE_LOG_WARN(FORMAT, ...)
#endif

#ifdef ACTIVATE_ERROR_LOG
#define SIMPLE_LOG_ERROR(FORMAT, ...) printf(FORMAT, ##__VA_ARGS__)
#else
#define SIMPLE_LOG_ERROR(FORMAT, ...)
#endif

