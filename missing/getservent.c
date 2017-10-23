/*
 * Copyright (c) 1983, 1993
 *	The Regents of the University of California.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <netdissect-stdinc.h>
#include <net/netdb.h>

void error(const char *fmt, ...) {
	va_list  ap;

	va_start(ap, fmt);
	va_end(ap);
	return;
}

#ifdef _WIN32bbb
static int      pre_env_done = 0;
static char    *s_fn;
static void
pre_env(void)
{
	const char     *cproot;
	const char     *cp = "";

	if (pre_env_done)
		return;
	pre_env_done = 1;

	cp = getenv("SYSTEMROOT");
	cproot = __PATH_ETC_INET;
	s_fn =		(char *)malloc(3 + strlen(cp) + strlen(cproot) + strlen(__PATH_SERVICES));
	if (s_fn)
		sprintf(s_fn, "%s%s%s", cp, cproot, __PATH_SERVICES);
}
#endif


static char SERVDB[] = __PATH_SERVICES;
static FILE *servf = NULL;
static char line[BUFSIZ+1];
static struct servent serv;
static char *serv_aliases[MAXALIASES];
int _serv_stayopen;

/*
* Return path to "%SYSTEMROOT%\System32\drivers\etc\<file>"  (WIN32)
*          or to "%PREFIX%/etc/<file>"                       (The rest)
*/
const char *etc_path(const char *file)
{
	const char *env = getenv(__PATH_SYSROOT);
	static char path[_MAX_PATH];

	if (!env)
//#ifdef _DEBUG
	//	printf("Warning: Environment Variable \"%s\" invalid (GetLastError: %d)\nResorting to [CurrentDirectory]/%s\n"
	//		,__PATH_SYSROOT, GetLastError(), file);
//#endif
		return (file);

//	snprintf(path, sizeof(path), "%s\\system32\\drivers\\etc\\%s", env, file);
	snprintf(path, sizeof(path), "%s%s%s", env, __PATH_ETC_INET, file);
	return (path);
}

void
setservent(f)
	int f;
{
	if (servf == NULL)
//		servf = fopen(SERVDB, "r");
//		if (servf == NULL)
		servf = fopen(etc_path(__PATH_SERVICES), "r");
	else
		rewind(servf);
	_serv_stayopen |= f;
}

void
endservent()
{
	if (servf) {
		fclose(servf);
		servf = NULL;
	}
	_serv_stayopen = 0;
}

struct servent *
getservent()
{
	char *p;
	register char *cp, **q;

	if (servf == NULL && (servf = fopen(etc_path(SERVDB), "r")) == NULL)
//	if (servf == NULL && (servf = fopen(SERVDB, "r")) == NULL)

//	printf("etc_pathSERVDB: %s SERVDB: %s", etc_path(SERVDB), SERVDB);
		return (NULL);

again:
	if ((p = fgets(line, BUFSIZ, servf)) == NULL)
		return (NULL);
	if (*p == '#')
		goto again;
	cp = strpbrk(p, "#\n");
	if (cp == NULL)
		goto again;
	*cp = '\0';
	serv.s_name = p;
	p = strpbrk(p, " \t");
	if (p == NULL)
		goto again;
	*p++ = '\0';
	while (*p == ' ' || *p == '\t')
		p++;
	cp = strpbrk(p, ",/");
	if (cp == NULL)
		goto again;
	*cp++ = '\0';
	serv.s_port = htons((u_short)atoi(p));
	serv.s_proto = cp;
	q = serv.s_aliases = serv_aliases;
	cp = strpbrk(cp, " \t");
	if (cp != NULL)
		*cp++ = '\0';
	while (cp && *cp) {
		if (*cp == ' ' || *cp == '\t') {
			cp++;
			continue;
		}
		if (q < &serv_aliases[MAXALIASES - 1])
			*q++ = cp;
		cp = strpbrk(cp, " \t");
		if (cp != NULL)
			*cp++ = '\0';
	}
	*q = NULL;
	return (&serv);
}
