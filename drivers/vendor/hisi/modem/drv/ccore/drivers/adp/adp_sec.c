



#ifdef __cplusplus
extern "C"
{
#endif
#include "drv_comm.h"
#include "sec_balong.h"



/*****************************************************************************
* 函 数 名  : mdrv_crypto_secboot_supported
*
* 功能描述  : 当前版本是否支持安全启动
*
* 输入参数  : unsigned char *pu8Data 是否支持安全启动标志[1:支持   0:不支持]
* 输出参数  :
*
* 返 回 值  : 0，成功；其他，失败；
*
* 其它说明  :
*
*****************************************************************************/
int mdrv_crypto_secboot_supported (unsigned char *pu8Data)
{
    return secureSupport( pu8Data );

}

/*****************************************************************************
* 函 数 名  : mdrv_crypto_sec_started
*
* 功能描述  : 查询当前版本是否已经启用安全启动
*
* 输入参数  : unsigned char *pu8Data 是否已经启用安全启动标志[1:启用   0:未启用]
* 输出参数  :
*
* 返 回 值  : 0，成功；其他，失败；
*
* 其它说明  :
*
*****************************************************************************/
int mdrv_crypto_sec_started (unsigned char *pu8Data)
{
    return secureAlreadyUse( pu8Data );

}

/*****************************************************************************
* 函 数 名  : mdrv_crypto_start_secure
*
* 功能描述  : 启用安全启动
*
* 输入参数  : void
* 输出参数  :
*
* 返 回 值  : 0，成功；其他，失败；
*
* 其它说明  :
*
*****************************************************************************/
int mdrv_crypto_start_secure (void)
{
    return startSecure();

}

/*****************************************************************************
* 函 数 名  : mdrv_crypto_check_sec
*
* 功能描述  : 安全镜像判断
*
* 输入参数  : void
* 输出参数  :
*
* 返 回 值  : 1，安全镜像；0，非安全镜像
*
* 其它说明  :
*
*****************************************************************************/
unsigned int mdrv_crypto_check_sec (void)
{
    return drvSecCheck();

}


#ifdef __cplusplus
}
#endif

