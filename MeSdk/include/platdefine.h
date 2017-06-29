#ifndef     _ME_PLAT_TYPE_H_
#define     _ME_PLAT_TYPE_H_

#ifdef  __cplusplus
#define IME_EXTERN_C  extern "C"
#else
#define IME_EXTERN_C
#endif  

//BASE DATA TYPE LENGTH
#define		LEN_INT				(sizeof(int32_t))
#define		LEN_UINT			(sizeof(uint32_t))
#define		LEN_SHORT			(sizeof(int16_t))
#define		LEN_USHORT			(sizeof(uint16_t))


//########################################################
//########################################################
//start define for windows platform
//########################################################
//########################################################
#ifdef	WIN32
#define	PROJECT_FOR_WINDOWS
#endif

#ifdef      PROJECT_FOR_WINDOWS		

/* 系统头文件 */
#include    <winsock2.h>
#include    <windows.h>
#include    <tlhelp32.h>com
#include    <direct.h>  
#include    <io.h> 

/* 数据类型 */
typedef		int					int32_t;
typedef		unsigned int		uint32_t;
typedef		short				int16_t;
typedef     unsigned short      uint16_t;
typedef		unsigned char       uint8_t;
typedef		__int64				int64_t;
typedef     unsigned __int64    uint64_t;

#define		FILE_PATH_SEPARATE	'\\'

//########################################################
//########################################################
//end define for windows platform
//########################################################
//########################################################






//########################################################
//########################################################
//start define in other platform based on unix
//########################################################
//########################################################
#elif       PROJECT_FOR_LINUX

/* 系统头文件 */
#include    <netinet/in.h>
#include    <fcntl.h>
#include    <unistd.h>
#include 	<dirent.h>
#include    <linux/tcp.h>
#include    <sys/types.h>
#include    <sys/stat.h>
#include 	<sys/ioctl.h>
#include    <sys/socket.h>
#include    <pthread.h>
#include 	<errno.h>

/* android platform */
#ifndef		PROJECT_FOR_ANDROID
#include    <uuid/uuid.h>
#endif

#include    <time.h>
#include    <stdarg.h>

#define     _FILE_OFFSET_BITS		64      /* linux large file more than 4G */
#define		FILE_PATH_SEPARATE		'/'

//########################################################
//########################################################
//stop define in other platform based on unix
//########################################################
//########################################################




#endif	//end platform define



#endif  //end _ME_PLAT_TYPE_H_
