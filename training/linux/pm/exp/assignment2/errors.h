#ifndef _alarm_head_
#define _alarm_head_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>


#ifndef DEBUG
#define DPRINTF (arg) printf arg
#else
#define DPRINT (arg)
#endif

//fun return error no then use it
#define err_abort(code, text) do {\
		fprintf(stderr, "%s at  %s : %d : %s\n",\
				text, __FILE__, __LINE__, strerror(code) );\
		abort();\
	} while(0)

//function set error no then use it
#define errno_abort(text) do {\
		fprintf(stderr, "%s at  %s : %d : %s\n",\
				text, __FILE__, __LINE__, strerror(errno) );\
		abort();\
	} while(0)


#endif
