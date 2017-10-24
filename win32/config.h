/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Generated from configure.in by autoheader.  */


/* Ignore this "ornament". */
#define _U_

/* 
* Comment these out to not use the timeSetEvent function.
* XXX - This function is obsolete. New applications should use
* CreateTimerQueueTimer to create a timer-queue timer.
*/
#define USE_WIN32_MM_TIMER
#pragma comment (lib,"winmm")       /* multimedia */

/* Some warnings disabled by me + what they stand for. */
#pragma warning(disable: 4996) /* _CRT_SECURE_NO_WARNINGS & _WINSOCK_DEPRECATED_NO_WARNINGS */
#pragma warning(disable: 4305) /* 'initializing': truncation from 'double' to 'const float' in print-802_11.c(818) */
#pragma warning(disable: 4267) /* conversion from 'size_t' to '(u_)int', possible loss of data */
#pragma warning(disable: 4244) /* conversion from '__int64' to 'u_int', possible loss of data */
#pragma warning(disable: 4090) /* 'function': different 'const' qualifiers in print-esp.c */

/* tcpdump must link with these. Statically or otherwise. */
#pragma comment (lib,"ws2_32")         /* winsock 2 */
#pragma comment (lib,"pcap")           /* pcap */

/* Comment these out to disable OpenSSL support. */
#define HAVE_LIBCRYPTO 1
#define HAVE_OPENSSL_EVP_H 1
#pragma comment (lib,"libeay32")       /* OpenSSL */

/* define if you want to build the possibly-buggy SMB printer */
#define ENABLE_SMB 1

/* Define to 1 if you have the `alarm' function. */
/* #undef HAVE_ALARM */

/* Define to 1 if you have the `bpf_dump' function. */
#define HAVE_BPF_DUMP 1

/* capsicum support available */
/* #undef HAVE_CAPSICUM */

/* Define to 1 if you have the `cap_enter' function. */
/* #undef HAVE_CAP_ENTER */

/* Define to 1 if you have the `cap_ioctls_limit' function. */
/* #undef HAVE_CAP_IOCTLS_LIMIT */

/* Define to 1 if you have the <cap-ng.h> header file. */
/* #undef HAVE_CAP_NG_H */

/* Define to 1 if you have the `cap_rights_limit' function. */
/* #undef HAVE_CAP_RIGHTS_LIMIT */

/* Casper support available */
/* #undef HAVE_CASPER */

/* Define to 1 if you have the declaration of `ether_ntohost', and to 0 if you
   don't. */
/* #undef HAVE_DECL_ETHER_NTOHOST */

/* define if you have the dnet_htoa function */
/* #undef HAVE_DNET_HTOA */

/* Define to 1 if you have the `ether_ntohost' function. */
/* #undef HAVE_ETHER_NTOHOST */

/* Define to 1 if you have the `EVP_CipherInit_ex' function. */
#define HAVE_EVP_CIPHERINIT_EX 1

/* Define to 1 if you have the `EVP_CIPHER_CTX_new' function. */
#define HAVE_EVP_CIPHER_CTX_NEW 1

/* Define to 1 if you have the <fcntl.h> header file. */
#define HAVE_FCNTL_H 1

/* Define to 1 if you have the `fork' function. */
/* #undef HAVE_FORK */

/* Define to 1 if you have the `getopt_long' function. */
/* #undef HAVE_GETOPT_LONG */

/* define if you have getrpcbynumber() */
/* #undef HAVE_GETRPCBYNUMBER */

/* Define to 1 if you have the `getservent' function. */
/* #undef HAVE_GETSERVENT */

/* Define to 1 if you have the <inttypes.h> header file. */
#define HAVE_INTTYPES_H 1

/* Define to 1 if you have the `cap-ng' library (-lcap-ng). */
/* #undef HAVE_LIBCAP_NG */

/* Define to 1 if you have the `rpc' library (-lrpc). */
/* #undef HAVE_LIBRPC */

/* Define to 1 if you have the <memory.h> header file. */
#define HAVE_MEMORY_H 1

/* Define to 1 if you have the <netdnet/dnetdb.h> header file. */
/* #undef HAVE_NETDNET_DNETDB_H */

/* define if you have a dnet_htoa declaration in <netdnet/dnetdb.h> */
/* #undef HAVE_NETDNET_DNETDB_H_DNET_HTOA */

/* Define to 1 if you have the <netinet/ether.h> header file. */
/* #undef HAVE_NETINET_ETHER_H */

/* Define to 1 if you have the <netinet/if_ether.h> header file. */
/* #undef HAVE_NETINET_IF_ETHER_H */

/* Define to 1 if you have the <net/if_pflog.h> header file. */
/* #undef HAVE_NET_IF_PFLOG_H */

/* Define to 1 if you have the <net/pfvar.h> header file. */
/* #undef HAVE_NET_PFVAR_H */

/* Define to 1 if you have the `openat' function. */
/* #undef HAVE_OPENAT */

/* define if the OS provides AF_INET6 and struct in6_addr */
/* #undef HAVE_OS_IPV6_SUPPORT */

/* if there's an os_proto.h for this platform, to use additional prototypes */
#define HAVE_OS_PROTO_H 1

/* Define to 1 if you have the <pcap/bluetooth.h> header file. */
#define HAVE_PCAP_BLUETOOTH_H 1

/* Define to 1 if you have the `pcap_breakloop' function. */
#define HAVE_PCAP_BREAKLOOP 1

/* Define to 1 if you have the `pcap_create' function. */
#define HAVE_PCAP_CREATE 1

/* define if libpcap has pcap_datalink_name_to_val() */
#define HAVE_PCAP_DATALINK_NAME_TO_VAL 1

/* define if libpcap has pcap_datalink_val_to_description() */
#define HAVE_PCAP_DATALINK_VAL_TO_DESCRIPTION 1

/* define if libpcap has pcap_debug */
/* #undef HAVE_PCAP_DEBUG */

/* Define to 1 if you have the `pcap_dump_flush' function. */
#define HAVE_PCAP_DUMP_FLUSH 1

/* define if libpcap has pcap_dump_ftell() */
#define HAVE_PCAP_DUMP_FTELL 1

/* Define to 1 if you have the `pcap_dump_ftell64' function. */
#define HAVE_PCAP_DUMP_FTELL64 1

/* Define to 1 if you have the `pcap_findalldevs' function. */
#define HAVE_PCAP_FINDALLDEVS 1

/* Define to 1 if you have the `pcap_free_datalinks' function. */
#define HAVE_PCAP_FREE_DATALINKS 1

/* Define to 1 if the system has the type `pcap_if_t'. */
#define HAVE_PCAP_IF_T 1

/* Define to 1 if you have the `pcap_lib_version' function. */
#define HAVE_PCAP_LIB_VERSION 1

/* define if libpcap has pcap_list_datalinks() */
#define HAVE_PCAP_LIST_DATALINKS 1

/* Define to 1 if you have the <pcap/nflog.h> header file. */
#define HAVE_PCAP_NFLOG_H 1

/* Define to 1 if you have the <pcap/pcap-inttypes.h> header file. */
#define HAVE_PCAP_PCAP_INTTYPES_H 1

/* Define to 1 if you have the `pcap_setdirection' function. */
#define HAVE_PCAP_SETDIRECTION 1

/* Define to 1 if you have the `pcap_set_datalink' function. */
#define HAVE_PCAP_SET_DATALINK 1

/* Define to 1 if you have the `pcap_set_immediate_mode' function. */
#define HAVE_PCAP_SET_IMMEDIATE_MODE 1

/* Define to 1 if you have the `pcap_set_optimizer_debug' function. */
#define HAVE_PCAP_SET_OPTIMIZER_DEBUG 1

/* Define to 1 if you have the `pcap_set_parser_debug' function. */
#define HAVE_PCAP_SET_PARSER_DEBUG 1

/* Define to 1 if you have the `pcap_set_tstamp_precision' function. */
#define HAVE_PCAP_SET_TSTAMP_PRECISION 1

/* Define to 1 if you have the `pcap_set_tstamp_type' function. */
#define HAVE_PCAP_SET_TSTAMP_TYPE 1

/* Define to 1 if you have the <pcap/usb.h> header file. */
#define HAVE_PCAP_USB_H 1

/* define if libpcap has pcap_version */
/* #undef HAVE_PCAP_VERSION */

/* Define to 1 if you have the `pfopen' function. */
/* #undef HAVE_PFOPEN */

/* Define to 1 if you have the <rpc/rpcent.h> header file. */
/* #undef HAVE_RPC_RPCENT_H */

/* Define to 1 if you have the <rpc/rpc.h> header file. */
/* #undef HAVE_RPC_RPC_H */

/* Define to 1 if you have the `setlinebuf' function. */
/* #undef HAVE_SETLINEBUF */

/* Define to 1 if you have the `sigaction' function. */
/* #undef HAVE_SIGACTION */

/* Define to 1 if you have the `sigset' function. */
/* #undef HAVE_SIGSET */

/* Define to 1 if you have the `snprintf' function. */
#define HAVE_SNPRINTF 1

/* if struct sockaddr has the sa_len member */
/* #undef HAVE_SOCKADDR_SA_LEN */

/* Define to 1 if you have the <stdint.h> header file. */
#define HAVE_STDINT_H 1

/* Define to 1 if you have the <stdlib.h> header file. */
#define HAVE_STDLIB_H 1

/* Define to 1 if you have the `strdup' function. */
#define HAVE_STRDUP 1

/* Define to 1 if you have the `strftime' function. */
#define HAVE_STRFTIME 1

/* Define to 1 if you have the <strings.h> header file. */
#define HAVE_STRINGS_H 1

/* Define to 1 if you have the <string.h> header file. */
#define HAVE_STRING_H 1

/* Define to 1 if you have the `strlcat' function. */
/* #undef HAVE_STRLCAT */

/* Define to 1 if you have the `strlcpy' function. */
/* #undef HAVE_STRLCPY */

/* Define to 1 if you have the `strsep' function. */
/* #undef HAVE_STRSEP */

/* Define to 1 if the system has the type `struct ether_addr'. */
/* #undef HAVE_STRUCT_ETHER_ADDR */

/* Define to 1 if you have the <sys/stat.h> header file. */
#define HAVE_SYS_STAT_H 1

/* Define to 1 if you have the <sys/types.h> header file. */
#define HAVE_SYS_TYPES_H 1

/* Define to 1 if the system has the type `uintptr_t'. */
#define HAVE_UINTPTR_T 1

/* Define to 1 if you have the <unistd.h> header file. */
/* #undef HAVE_UNISTD_H */

/* Define to 1 if you have the `vfork' function. */
/* #undef HAVE_VFORK */

/* Define to 1 if you have the `vfprintf' function. */
#define HAVE_VFPRINTF 1

/* Define to 1 if you have the `vsnprintf' function. */
#define HAVE_VSNPRINTF 1

/* define if libpcap has yydebug */
/* #undef HAVE_YYDEBUG */

/* define if your compiler has __attribute__ */
/* #undef HAVE___ATTRIBUTE__ */

/* if unaligned access fails */
#define LBL_ALIGN 1

/* Define to 1 if netinet/ether.h declares `ether_ntohost' */
/* #undef NETINET_ETHER_H_DECLARES_ETHER_NTOHOST */

/* Define to 1 if netinet/if_ether.h declares `ether_ntohost' */
/* #undef NETINET_IF_ETHER_H_DECLARES_ETHER_NTOHOST */

/* Define to the address where bug reports for this package should be sent. */
#define PACKAGE_BUGREPORT ""

/* Define to the full name of this package. */
#define PACKAGE_NAME ""

/* Define to the full name and version of this package. */
#define PACKAGE_STRING ""

/* Define to the one symbol short name of this package. */
#define PACKAGE_TARNAME ""

/* Define to the home page for this package. */
#define PACKAGE_URL ""

/* Define to the version of this package. */
#define PACKAGE_VERSION ""

/* Define as the return type of signal handlers (`int' or `void'). */
#define RETSIGTYPE void

/* return value of signal handlers */
#define RETSIGVAL /**/

/* Define to 1 if you have the ANSI C header files. */
#define STDC_HEADERS 1

/* Define to 1 if you can safely include both <sys/time.h> and <time.h>. */
#define TIME_WITH_SYS_TIME 1

/* define if you have ether_ntohost() and it works */
/* #undef USE_ETHER_NTOHOST */

/* Define if you enable support for libsmi */
/* #undef USE_LIBSMI */

/* define if should chroot when dropping privileges */
/* #undef WITH_CHROOT */

/* define if should drop privileges by default */
/* #undef WITH_USER */

/* get BSD semantics on Irix */
/* #undef _BSD_SIGNALS */

/* Define to 1 if MinGW rulez */
/* #undef _POSIX */

/* define on AIX to get certain functions */
/* #undef _SUN */

/* define if your compiler allows __attribute__((fallthrough)) without a
   warning */
/* #undef __ATTRIBUTE___FALLTHROUGH_OK 1 */

/* Define to 1 if MinGW rulez */
/* #undef __USE_MINGW_ALARM  */

/* to handle Ultrix compilers that don't support const in prototypes */
/* #undef const */

/* Define as token for inline if inlining supported */
/* #undef inline  */

/* Define to `uint16_t' if u_int16_t not defined. */
#define u_int16_t uint16_t

/* Define to `uint32_t' if u_int32_t not defined. */
#define u_int32_t uint32_t

/* Define to `uint64_t' if u_int64_t not defined. */
#define u_int64_t uint64_t

/* Define to `uint8_t' if u_int8_t not defined. */
#define u_int8_t uint8_t

/* Define to the type of an unsigned integer type wide enough to hold a
   pointer, if such a type exists, and if the system does not define it. */
/* #undef uintptr_t */
