/*
 * Copyright 2014 CyberVision, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef KAA_MEM_H_
#define KAA_MEM_H_

#ifdef KAA_TRACE_MEMORY_ALLOCATIONS

#include "utilities/kaa_log.h"

#ifdef __cplusplus
extern "C" {
#endif

void *  kaa_trace_memory_allocs_malloc(size_t s, const char *file, int line);
void *  kaa_trace_memory_allocs_calloc(size_t n, size_t s, const char *file, int line);
void    kaa_trace_memory_allocs_free(void * p, const char *file, int line);
void    kaa_trace_memory_allocs_set_logger(kaa_logger_t *logger);

#define KAA_MALLOC(S)           kaa_trace_memory_allocs_malloc(S, __FILE__, __LINE__)
#define KAA_CALLOC(N,S)         kaa_trace_memory_allocs_calloc((N), (S), __FILE__, __LINE__)
#define KAA_FREE(P)             kaa_trace_memory_allocs_free((P), __FILE__, __LINE__)

#ifdef __cplusplus
} // extern "C"
#endif

#else // defined KAA_TRACE_MEMORY_ALLOCATIONS

#include <stdlib.h>

#ifndef KAA_MALLOC
#define KAA_MALLOC(S)           malloc(S)
#endif

#ifndef KAA_CALLOC
#define KAA_CALLOC(N,S)         calloc(N, S)
#endif

#ifndef KAA_FREE
#define KAA_FREE(P)             free(P)
#endif

#endif // defined KAA_TRACE_MEMORY_ALLOCATIONS

#endif /* KAA_MEM_H_ */