
#ifndef _AUDIO_AUTO_TEST_ASP_CFG_H
#define _AUDIO_AUTO_TEST_ASP_CFG_H

/*****************************************************************************
  1 其他头文件包含
*****************************************************************************/
#include "util.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

/*****************************************************************************
  2 宏定义
*****************************************************************************/



/*****************************************************************************
  3 枚举定义
*****************************************************************************/


/*****************************************************************************
  4 STRUCT定义
*****************************************************************************/

/*****************************************************************************
  5 函数指针
*****************************************************************************/


/*****************************************************************************
  6 OTHERS定义
*****************************************************************************/


/*****************************************************************************
  7 全局变量声明
*****************************************************************************/


/*****************************************************************************
  8 函数声明
*****************************************************************************/
extern int      asp_cfg_reg_read    (unsigned int reg);
extern void     asp_cfg_powerup     (void);
extern int      asp_cfg_reg_rw_test (struct at_util_reg_test_type regs[], int size);
extern void     asp_cfg_ip_init     (void);
extern void     asp_cfg_reg_write   (unsigned int reg, unsigned int value);


#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of _AUDIO_AUTO_TEST_ASP_CFG_H */


