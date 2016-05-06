/******************************************************************************

                  ��Ȩ���� (C), 2001-2011, ��Ϊ�������޹�˾

 ******************************************************************************
  �� �� ��   : MtaRrcInterface.h
  �� �� ��   : ����
  ��    ��   : h44270
  ��������   : 2012��06��01��
  ����޸�   :
  ��������   : MTA��GU�����֮��Ľӿ�ͷ�ļ�
  �����б�   :
  �޸���ʷ   :
  1.��    ��   : 2012��06��01��
    ��    ��   : h44270
    �޸�����   : �����ļ�

 ******************************************************************************/

#ifndef __MTARRCINTERFACE_H__
#define __MTARRCINTERFACE_H__

/*****************************************************************************
  1 ����ͷ�ļ�����
*****************************************************************************/
#include "PsTypeDef.h"
#include "AgpsParaDef.h"
#include "MtaCommInterface.h"

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif
#endif

#pragma pack(4)

/*****************************************************************************
  2 �궨��
*****************************************************************************/
#define  NMR_MAX_FREQ_NUM                       (3)  /* �ϱ�NMR���ݵ�Ƶ��������,W���ֻ֧������Ƶ�㣬TD����ʱ���� */
#define  NMR_MAX_CELL_FREQ_NUM                  (32) /* �ϱ�NMR���ݵ�С�������������� */
#define  RRC_MTA_UTRAN_NMR                      (0)
#define  RRC_MTA_GSM_NMR                        (1)
#define  RRC_MTA_NMR_MAX_GSM_ELEM_NUM           (15) /* �ϱ�NMR���ݵ�GSMԪ�ص������� */

#define  MTA_WRR_AUTOTEST_MAX_PARA_NUM          (10) /* autotest�����·����������� */
#define  WRR_MTA_AUTOTEST_MAX_RSULT_NUM         (20) /* autotest�����ϱ���������� */
#define  WRR_MTA_MEANRPT_MAX_CELL_NUM           (8)  /* һ�β���������С�������� */
#define  WRR_MTA_MAX_MEANRPT_NUM                (10) /* �ϱ������������������� */

#define  WRR_MTA_MAX_NCELL_NUM                  (8)  /* WAS����������� */

/* Added by l00198894 for ����+ECID����, 2013-12-09, begin */
#define  MTA_LRRC_MSG_TYPE_BASE                 (0x1000)            /* MTAģ����LTE�������Ϣ���� */
#define  LRRC_MAX_NCELL_NUM                     (8)
/* Added by l00198894 for ����+ECID����, 2013-12-09, end */


#define  MBMS_AVL_SERVICE_MAX_NUM               (0x10)              /* LRRC�ظ�MTA MBMS�ɷ����б��������� */

#define  MTA_LRRC_INTEREST_FREQ_MAX_NUM         (0x05)              /* MTA֪ͨLRRC Interest�б�Ƶ��������� */

/* Added by y00142674 for �ƶ�Ƶ���ռ�, 2015-07-07, begin */
#define MTA_RRC_MAX_PLMN_NUM                    (32)    /* PLMN�������� */

#define RRC_MTA_MAX_GSM_PLMN_NUM                (15)    /* GSM PLMN�������� */
#define RRC_MTA_MAX_GSM_FREQ_NUM                (60)    /* GSM Ƶ��������� */

#define RRC_MTA_MAX_WCDMA_PLMN_NUM              (32)    /* WCDMA PLMN�������� */
#define RRC_MTA_MAX_WCDMA_FREQ_NUM              (16)    /* WCDMA Ƶ��������� */

#define RRC_MTA_MAX_LTE_PLMN_NUM                (20)    /* LTE PLMN�������� */
#define RRC_MTA_MAX_LTE_FREQ_NUM                (16)    /* LTE Ƶ��������� */
/* Added by y00142674 for �ƶ�Ƶ���ռ�, 2015-07-07, end */


/*****************************************************************************
  3 ö�ٶ���
*****************************************************************************/
/*****************************************************************************
 ö����    : MTA_RRC_MSG_TYPE_ENUM
 �ṹ˵��  : ԭ���usMsgName
 1.��    ��   : 2012��06��01��
   ��    ��   : y00142674,l00128652,h44270
   �޸�����   : Added for AGPS
 2.��    ��   : 2012��11��23��
   ��    ��   : s46746
   �޸�����   : ����NMR����MTA��GU�����֮�����Ϣ
 3.��    ��   : 2012��12��26��
   ��    ��   : m00217266
   �޸�����   : ������WAS���AT�������ϢID
 4.��    ��   : 2013��5��31��
   ��    ��   : s00217060
   �޸�����   : V9R1_SVLTE:������GAS���AT�������ϢID
*****************************************************************************/
enum MTA_RRC_MSG_TYPE_ENUM
{
    /* ��Ϣ���� */                              /* ��ϢID */                    /* ��ע */
    ID_RRC_MTA_MSG_POSITION_REQ                    = 0x0001,                    /* _H2ASN_MsgChoice MTA_RRC_POSITION_REQ_STRU */

    ID_MTA_RRC_QRY_NMR_REQ                         = 0x0003,                    /* _H2ASN_MsgChoice MTA_RRC_QRY_NMR_REQ_STRU */

    ID_MTA_RRC_RESEL_OFFSET_CFG_NTF                = 0x0005,                    /* _H2ASN_MsgChoice MTA_RRC_RESEL_OFFSET_CFG_NTF_STRU */

    ID_MTA_WRR_AUTOTEST_QRY_REQ                    = 0x0007,                    /* _H2ASN_MsgChoice MTA_WRR_AUTOTEST_QRY_REQ_STRU     */

    ID_MTA_WRR_CELLINFO_QRY_REQ                    = 0x0009,                    /* _H2ASN_MsgChoice MTA_WRR_CELLINFO_QRY_REQ_STRU     */

    ID_MTA_WRR_MEASRPT_QRY_REQ                     = 0x000B,                    /* _H2ASN_MsgChoice MTA_WRR_MEANRPT_QRY_REQ_STRU      */

    ID_MTA_WRR_FREQLOCK_SET_REQ                    = 0x000D,                    /* _H2ASN_MsgChoice MTA_WRR_FREQLOCK_SET_REQ_STRU     */

    ID_MTA_WRR_RRC_VERSION_SET_REQ                 = 0x000F,                    /* _H2ASN_MsgChoice MTA_WRR_RRC_VERSION_SET_REQ_STRU  */

    ID_MTA_WRR_CELLSRH_SET_REQ                     = 0x0011,                    /* _H2ASN_MsgChoice MTA_WRR_CELLSRH_SET_REQ_STRU      */

    ID_MTA_WRR_FREQLOCK_QRY_REQ                    = 0x0013,                    /* _H2ASN_MsgChoice MTA_WRR_FREQLOCK_QRY_REQ_STRU     */

    ID_MTA_WRR_RRC_VERSION_QRY_REQ                 = 0x0015,                    /* _H2ASN_MsgChoice MTA_WRR_RRC_VERSION_QRY_REQ_STRU  */

    ID_MTA_WRR_CELLSRH_QRY_REQ                     = 0x0017,                    /* _H2ASN_MsgChoice MTA_WRR_CELLSRH_QRY_REQ_STRU      */

    ID_MTA_GRR_NCELL_MONITOR_SET_REQ               = 0x0019,                    /* _H2ASN_MsgChoice MTA_GRR_NCELL_MONITOR_SET_REQ_STRU      */

    ID_MTA_GRR_NCELL_MONITOR_QRY_REQ               = 0x001B,                    /* _H2ASN_MsgChoice MTA_GRR_NCELL_MONITOR_QRY_REQ_STRU      */

    ID_MTA_RRC_JAM_DETECT_REQ                      = 0x001D,                    /* _H2ASN_MsgChoice MTA_RRC_JAM_DETECT_REQ_STRU */

    ID_MTA_RRC_CHECK_FREQ_VALIDITY_REQ             = 0x001F,                    /* _H2ASN_MsgChoice MTA_RRC_CHECK_FREQ_VALIDITY_REQ_STRU */

    ID_MTA_GRR_FREQLOCK_SET_REQ                    = 0x0021,                    /* _H2ASN_MsgChoice MTA_GRR_FREQLOCK_SET_REQ_STRU     */

    ID_MTA_RRC_NETMON_CELL_QRY_REQ                 = 0x0023,                    /* _H2ASN_MsgChoice MTA_RRC_NETMON_CELL_QRY_REQ_STRU    */
    ID_MTA_GRR_NETMON_CELL_QRY_REQ                 = 0x0025,                    /* _H2ASN_MsgChoice MTA_RRC_NETMON_CELL_QRY_REQ_STRU    */
    ID_MTA_GRR_NETMON_TA_QRY_REQ                   = 0x0027,                    /* _H2ASN_MsgChoice MTA_GRR_NETMON_TA_QRY_REQ_STRU      */
    ID_MTA_WRR_JAM_DETECT_REQ                      = 0x0029,                    /* _H2ASN_MsgChoice MTA_WRR_JAM_DETECT_REQ_STRU */

    /* Added by y00142674 for �ƶ�Ƶ���ռ�, 2015-07-07, begin */
    ID_MTA_RRC_PLMN_FREQ_QRY_REQ                   = 0x002B,                    /* _H2ASN_MsgChoice MTA_RRC_PLMN_FREQ_QRY_REQ_STRU     */
    /* Added by y00142674 for �ƶ�Ƶ���ռ�, 2015-07-07, end */

    ID_MTA_RRC_MSG_POSITION_CNF                    = 0x0002,                    /* _H2ASN_MsgChoice MTA_RRC_POSITION_CNF_STRU */

    ID_RRC_MTA_QRY_NMR_CNF                         = 0x0004,                    /* _H2ASN_MsgChoice RRC_MTA_QRY_NMR_CNF_STRU */

    ID_WRR_MTA_AUTOTEST_QRY_CNF                    = 0x0008,                    /* _H2ASN_MsgChoice WRR_MTA_AUTOTEST_QRY_CNF_STRU     */

    ID_WRR_MTA_CELLINFO_QRY_CNF                    = 0x000A,                    /* _H2ASN_MsgChoice WRR_MTA_CELLINFO_QRY_CNF_STRU     */

    ID_WRR_MTA_MEASRPT_QRY_CNF                     = 0x000C,                    /* _H2ASN_MsgChoice WRR_MTA_MEANRPT_QRY_CNF_STRU      */

    ID_WRR_MTA_FREQLOCK_SET_CNF                    = 0x000E,                    /* _H2ASN_MsgChoice WRR_MTA_FREQLOCK_SET_CNF_STRU     */

    ID_WRR_MTA_RRC_VERSION_SET_CNF                 = 0x0010,                    /* _H2ASN_MsgChoice WRR_MTA_RRC_VERSION_SET_CNF_STRU  */

    ID_WRR_MTA_CELLSRH_SET_CNF                     = 0x0012,                    /* _H2ASN_MsgChoice WRR_MTA_CELLSRH_SET_CNF_STRU      */

    ID_WRR_MTA_FREQLOCK_QRY_CNF                    = 0x0014,                    /* _H2ASN_MsgChoice WRR_MTA_FREQLOCK_QRY_CNF_STRU     */

    ID_WRR_MTA_RRC_VERSION_QRY_CNF                 = 0x0016,                    /* _H2ASN_MsgChoice WRR_MTA_RRC_VERSION_QRY_CNF_STRU  */

    ID_WRR_MTA_CELLSRH_QRY_CNF                     = 0x0018,                    /* _H2ASN_MsgChoice WRR_MTA_CELLSRH_QRY_CNF_STRU      */


    ID_GRR_MTA_NCELL_MONITOR_SET_CNF              = 0x001A,                    /* _H2ASN_MsgChoice GRR_MTA_NCELL_MONITOR_SET_CNF_STRU      */

    ID_GRR_MTA_NCELL_MONITOR_QRY_CNF              = 0x001C,                    /* _H2ASN_MsgChoice GRR_MTA_NCELL_MONITOR_QRY_CNF_STRU      */

    ID_GRR_MTA_NCELL_MONITOR_IND                  = 0x001E,                    /* _H2ASN_MsgChoice GRR_MTA_NCELL_MONITOR_IND_STRU      */

    ID_RRC_MTA_JAM_DETECT_CNF                      = 0x0020,                    /* _H2ASN_MsgChoice RRC_MTA_JAM_DETECT_CNF_STRU */
    ID_RRC_MTA_JAM_DETECT_IND                      = 0x0022,                    /* _H2ASN_MsgChoice RRC_MTA_JAM_DETECT_IND_STRU */

    ID_RRC_MTA_CHECK_FREQ_VALIDITY_CNF             = 0x0024,                    /* _H2ASN_MsgChoice RRC_MTA_CHECK_FREQ_VALIDITY_CNF_STRU */

    ID_GRR_MTA_FREQLOCK_SET_CNF                    = 0x0026,                    /* _H2ASN_MsgChoice GRR_MTA_FREQLOCK_SET_CNF_STRU     */

    ID_GRR_MTA_NETMON_CELL_QRY_CNF                 = 0x0028,                    /* _H2ASN_MsgChoice GRR_MTA_NETMON_CELL_QRY_CNF_STRU   */
    ID_GRR_MTA_NETMON_TA_QRY_CNF                   = 0x002A,                    /* _H2ASN_MsgChoice GRR_MTA_NETMON_TA_QRY_CNF_STRU   */
    ID_RRC_MTA_NETMON_CELL_QRY_CNF                 = 0x002C,                    /* _H2ASN_MsgChoice RRC_MTA_NETMON_CELL_INFO_QRY_CNF_STRU   */

    /* Added by y00142674 for �ƶ�Ƶ���ռ�, 2015-07-07, begin */
    ID_RRC_MTA_PLMN_FREQ_QRY_CNF                   = 0x002E,                    /* _H2ASN_MsgChoice RRC_MTA_PLMN_FREQ_QRY_CNF_STRU     */
    /* Added by y00142674 for �ƶ�Ƶ���ռ�, 2015-07-07, end */

    /* Added by l00198894 for ����+ECID����, 2013-12-09, begin */
    /* ��Ϣ����MTA->LRRC/GAS/WRR/TDRRC */
    ID_MTA_LRRC_CELLINFO_QRY_REQ                = MTA_LRRC_MSG_TYPE_BASE + 1,   /* _H2ASN_MsgChoice MTA_LRRC_CELLINFO_QRY_REQ_STRU      */

    ID_MTA_TLRRC_SET_DPDTTEST_FLAG_NTF          = MTA_LRRC_MSG_TYPE_BASE + 3,   /* _H2ASN_MsgChoice MTA_TLRRC_SET_DPDTTEST_FLAG_NTF_STRU      */

    ID_MTA_TLRRC_SET_DPDT_VALUE_NTF             = MTA_LRRC_MSG_TYPE_BASE + 5,   /* _H2ASN_MsgChoice MTA_TLRRC_SET_DPDT_VALUE_NTF_STRU      */

    ID_MTA_TLRRC_QRY_DPDT_VALUE_REQ             = MTA_LRRC_MSG_TYPE_BASE + 7,   /* _H2ASN_MsgChoice MTA_TLRRC_QRY_DPDT_VALUE_REQ_STRU      */

    ID_MTA_LRRC_NETMON_CELL_QRY_REQ             = MTA_LRRC_MSG_TYPE_BASE +11,   /* _H2ASN_MsgChoice MTA_LRRC_NETMON_CELL_QRY_REQ_STRU      */

    ID_MTA_RRC_PROTECT_PS_IND                   = MTA_LRRC_MSG_TYPE_BASE + 9,   /* _H2ASN_MsgChoice MTA_RRC_PROTECT_PS_IND_STRU      */

    /*TģFREQLOCK��ƵREQ��Ϣ*/
    ID_MTA_TDS_FREQLOCK_SET_REQ                 = MTA_LRRC_MSG_TYPE_BASE + 13,  /* _H2ASN_MsgChoice MTA_TDS_FREQLOCK_SET_REQ_STRU      */

    /*LģFREQLOCK��ƵREQ��Ϣ*/
    ID_MTA_LRRC_FREQLOCK_SET_REQ                = MTA_LRRC_MSG_TYPE_BASE + 15,  /* _H2ASN_MsgChoice MTA_TDS_FREQLOCK_SET_REQ_STRU      */

    ID_MTA_LRRC_MBMS_SERVICE_OPTION_REQ         = MTA_LRRC_MSG_TYPE_BASE + 17,  /* _H2ASN_MsgChoice MTA_LRRC_MBMS_SERVICE_OPTION_REQ_STRU      */

    ID_MTA_LRRC_MBMS_SERVICE_STATE_SET_REQ      = MTA_LRRC_MSG_TYPE_BASE + 19,  /* _H2ASN_MsgChoice MTA_LRRC_MBMS_SERVICE_STATE_SET_REQ_STRU      */

    ID_MTA_LRRC_MBMS_AVL_SERVICE_LIST_QRY_REQ   = MTA_LRRC_MSG_TYPE_BASE + 21,  /* _H2ASN_MsgChoice MTA_LRRC_MBMS_AVL_SERVICE_LIST_QRY_REQ_STRU      */

    ID_MTA_LRRC_MBMS_PREFERENCE_SET_REQ         = MTA_LRRC_MSG_TYPE_BASE + 23,  /* _H2ASN_MsgChoice MTA_LRRC_MBMS_PREFERENCE_SET_REQ_STRU      */

    ID_MTA_LRRC_SIB16_NETWORK_TIME_QRY_REQ      = MTA_LRRC_MSG_TYPE_BASE + 25,  /* _H2ASN_MsgChoice MTA_LRRC_SIB16_NETWORK_TIME_QRY_REQ_STRU      */

    ID_MTA_LRRC_BSSI_SIGNAL_LEVEL_QRY_REQ       = MTA_LRRC_MSG_TYPE_BASE + 27,  /* _H2ASN_MsgChoice MTA_LRRC_BSSI_SIGNAL_LEVEL_QRY_REQ_STRU      */

    ID_MTA_LRRC_NETWORK_INFO_QRY_REQ            = MTA_LRRC_MSG_TYPE_BASE + 29,  /* _H2ASN_MsgChoice MTA_LRRC_NETWORK_INFO_QRY_REQ_STRU      */

    ID_MTA_LRRC_EMBMS_STATUS_QRY_REQ            = MTA_LRRC_MSG_TYPE_BASE + 31,  /* _H2ASN_MsgChoice MTA_LRRC_EMBMS_STATUS_QRY_REQ_STRU      */

    ID_MTA_LRRC_MBMS_UNSOLICITED_CFG_SET_REQ    = MTA_LRRC_MSG_TYPE_BASE + 33,  /* _H2ASN_MsgChoice MTA_LRRC_MBMS_UNSOLICITED_CFG_SET_REQ_STRU      */

    ID_MTA_LRRC_LTE_WIFI_COEX_SET_REQ           = MTA_LRRC_MSG_TYPE_BASE + 36,  /* _H2ASN_MsgChoice MTA_LRRC_LTE_WIFI_COEX_SET_REQ_STRU      */

    ID_MTA_LRRC_LOW_POWER_CONSUMPTION_SET_REQ   = MTA_LRRC_MSG_TYPE_BASE + 38,  /* _H2ASN_MsgChoice MTA_LRRC_LOW_POWER_CONSUMPTION_SET_REQ_STRU      */

    ID_MTA_LRRC_INTEREST_LIST_SET_REQ           = MTA_LRRC_MSG_TYPE_BASE + 40,  /* _H2ASN_MsgChoice MTA_LRRC_INTEREST_LIST_SET_REQ_STRU      */

    ID_MTA_LRRC_TRANSMODE_QRY_REQ               = MTA_LRRC_MSG_TYPE_BASE + 49,   /* _H2ASN_MsgChoice MTA_LRRC_TRANSMODE_QRY_REQ_STRU      */

    /************���߷��书��tx power (4G)**********************************/
    ID_MTA_LRRC_QRY_TXPOWER_REQ                = MTA_LRRC_MSG_TYPE_BASE + 51,  /* _H2ASN_MsgChoice MTA_LRRC_TX_PWR_QRY_REQ      */
    /***********************************************************************/
    /************MCS *******************************************************/
    ID_MTA_LRRC_QRY_MCS_REQ                    = MTA_LRRC_MSG_TYPE_BASE + 53,  /* _H2ASN_MsgChoice MTA_LRRC_MCS_QRY_REQ      */
    /***********************************************************************/
    /************EARFCN*****************************************************/
    ID_MTA_LRRC_QRY_EARFCN_REQ                 = MTA_LRRC_MSG_TYPE_BASE + 55,  /* _H2ASN_MsgChoice MTA_LRRC_EARFCN_QRY_REQ      */
    /***********************************************************************/
    /************TDDʱ϶���************************************************/
    ID_MTA_LRRC_QRY_LFRAMERATIO_REQ            = MTA_LRRC_MSG_TYPE_BASE + 57,  /* _H2ASN_MsgChoice MTA_LRRC_LFRAMERATIO_QRY_REQ      */
    /***********************************************************************/
    /************RRC status*************************************************/
    ID_MTA_LRRC_QRY_RRCSTATUS_REQ              = MTA_LRRC_MSG_TYPE_BASE + 59,  /* _H2ASN_MsgChoice MTA_LRRC_RRC_STATUS_QRY_REQ      */
    /***********************************************************************/

    ID_MTA_LRRC_CLEAR_HISTORY_FREQ_REQ          = MTA_LRRC_MSG_TYPE_BASE + 61,   /* _H2ASN_MsgChoice MTA_LRRC_CLEAR_HISTORY_FREQ_REQ_STRU */


    /* ��Ϣ����LRRC/GAS/WRR/TDRRC->MTA */
    ID_LRRC_MTA_CELLINFO_QRY_CNF                = MTA_LRRC_MSG_TYPE_BASE + 2,   /* _H2ASN_MsgChoice LRRC_MTA_CELLINFO_QRY_CNF_STRU      */

    ID_TLRRC_MTA_QRY_DPDT_VALUE_CNF              = MTA_LRRC_MSG_TYPE_BASE + 8,   /* _H2ASN_MsgChoice TLRRC_MTA_QRY_DPDT_VALUE_CNF_STRU      */

    /* Added by l00198894 for ����+ECID����, 2013-12-09, end */

    ID_LRRC_MTA_NETMON_CELL_QRY_CNF             = MTA_LRRC_MSG_TYPE_BASE + 12,  /* _H2ASN_MsgChoice LRRC_MTA_NETMON_CELL_INFO_QRY_CNF_STRU      */

    /*TģFREQLOCK��ƵCNF��Ϣ*/
    ID_TDS_MTA_FREQLOCK_SET_CNF                 = MTA_LRRC_MSG_TYPE_BASE + 14,

    /*LģFREQLOCK��ƵCNF��Ϣ*/
    ID_LRRC_MTA_FREQLOCK_SET_CNF                = MTA_LRRC_MSG_TYPE_BASE + 16,

    ID_LRRC_MTA_MBMS_SERVICE_OPTION_CNF         = MTA_LRRC_MSG_TYPE_BASE + 18,  /* _H2ASN_MsgChoice LRRC_MTA_MBMS_SERVICE_OPTION_CNF_STRU      */

    ID_LRRC_MTA_MBMS_SERVICE_STATE_SET_CNF      = MTA_LRRC_MSG_TYPE_BASE + 20,  /* _H2ASN_MsgChoice LRRC_MTA_MBMS_SERVICE_STATE_SET_CNF_STRU      */

    ID_LRRC_MTA_MBMS_AVL_SERVICE_LIST_QRY_CNF   = MTA_LRRC_MSG_TYPE_BASE + 22,  /* _H2ASN_MsgChoice LRRC_MTA_MBMS_AVL_SERVICE_LIST_QRY_CNF_STRU      */

    ID_LRRC_MTA_MBMS_PREFERENCE_SET_CNF         = MTA_LRRC_MSG_TYPE_BASE + 24,  /* _H2ASN_MsgChoice LRRC_MTA_MBMS_PREFERENCE_SET_CNF_STRU      */

    ID_LRRC_MTA_SIB16_NETWORK_TIME_QRY_CNF      = MTA_LRRC_MSG_TYPE_BASE + 26,  /* _H2ASN_MsgChoice LRRC_MTA_SIB16_NETWORK_TIME_QRY_CNF_STRU      */

    ID_LRRC_MTA_BSSI_SIGNAL_LEVEL_QRY_CNF       = MTA_LRRC_MSG_TYPE_BASE + 28,  /* _H2ASN_MsgChoice LRRC_MTA_BSSI_SIGNAL_LEVEL_QRY_CNF_STRU      */

    ID_LRRC_MTA_NETWORK_INFO_QRY_CNF            = MTA_LRRC_MSG_TYPE_BASE + 30,  /* _H2ASN_MsgChoice LRRC_MTA_NETWORK_INFO_QRY_CNF_STRU      */

    ID_LRRC_MTA_EMBMS_STATUS_QRY_CNF            = MTA_LRRC_MSG_TYPE_BASE + 32,  /* _H2ASN_MsgChoice LRRC_MTA_EMBMS_STATUS_QRY_CNF_STRU      */

    ID_LRRC_MTA_MBMS_UNSOLICITED_CFG_SET_CNF    = MTA_LRRC_MSG_TYPE_BASE + 34,  /* _H2ASN_MsgChoice LRRC_MTA_MBMS_UNSOLICITED_CFG_SET_CNF_STRU      */

    ID_LRRC_MTA_MBMS_SERVICE_EVENT_IND          = MTA_LRRC_MSG_TYPE_BASE + 35,  /* _H2ASN_MsgChoice LRRC_MTA_MBMS_SERVICE_EVENT_IND_STRU      */

    ID_LRRC_MTA_LTE_WIFI_COEX_SET_CNF           = MTA_LRRC_MSG_TYPE_BASE + 37,  /* _H2ASN_MsgChoice LRRC_MTA_LTE_WIFI_COEX_SET_CNF_STRU      */

    ID_LRRC_MTA_LOW_POWER_CONSUMPTION_SET_CNF   = MTA_LRRC_MSG_TYPE_BASE + 39,  /* _H2ASN_MsgChoice LRRC_MTA_LOW_POWER_CONSUMPTION_SET_CNF_STRU      */

    ID_LRRC_MTA_INTEREST_LIST_SET_CNF           = MTA_LRRC_MSG_TYPE_BASE + 41,  /* _H2ASN_MsgChoice LRRC_MTA_INTEREST_LIST_SET_CNF_STRU      */
    ID_MTA_LRRC_SET_FR_REQ                      = MTA_LRRC_MSG_TYPE_BASE + 47,  /* _H2ASN_MsgChoice MTA_LRRC_SET_FR_REQ_STRU      */
    ID_LRRC_MTA_SET_FR_CNF                      = MTA_LRRC_MSG_TYPE_BASE + 48,  /* _H2ASN_MsgChoice LRRC_MTA_SET_FR_CNF_STRU      */

	ID_LRRC_MTA_TRANSMODE_QRY_CNF               = MTA_LRRC_MSG_TYPE_BASE + 50,   /* _H2ASN_MsgChoice LRRC_MTA_TRANSMODE_QRY_CNF_STRU      */

    /************���߷��书��tx power (4G)**********************************/
    ID_LRRC_MTA_QRY_TXPOWER_CNF                = MTA_LRRC_MSG_TYPE_BASE + 52,  /* _H2ASN_MsgChoice LRRC_MTA_TX_PWR_QRY_CNF      */
    /***********************************************************************/
    /************MCS *******************************************************/
    ID_LRRC_MTA_QRY_MCS_CNF                    = MTA_LRRC_MSG_TYPE_BASE + 54,  /* _H2ASN_MsgChoice LRRC_MTA_MCS_QRY_CNF      */
    /***********************************************************************/
    /************EARFCN*****************************************************/
    ID_LRRC_MTA_QRY_EARFCN_CNF                 = MTA_LRRC_MSG_TYPE_BASE + 56,  /* _H2ASN_MsgChoice LRRC_MTA_EARFCN_QRY_CNF      */
    /***********************************************************************/
    /************TDDʱ϶���************************************************/
    ID_LRRC_MTA_QRY_LFRAMERATIO_CNF            = MTA_LRRC_MSG_TYPE_BASE + 58,  /* _H2ASN_MsgChoice LRRC_MTA_LFRAMERATIO_QRY_CNF      */
    /***********************************************************************/
    /************RRC status*************************************************/
    ID_LRRC_MTA_QRY_RRCSTATUS_CNF              = MTA_LRRC_MSG_TYPE_BASE + 60,  /* _H2ASN_MsgChoice LRRC_MTA_RRC_STATUS_QRY_CNF      */
    /***********************************************************************/

    ID_LRRC_MTA_CLEAR_HISTORY_FREQ_CNF         = MTA_LRRC_MSG_TYPE_BASE + 62,   /* _H2ASN_MsgChoice LRRC_MTA_CLEAR_HISTORY_FREQ_CNF_STRU */

    ID_MTA_RRC_MSG_TYPE_BUTT
};
typedef VOS_UINT32 MTA_RRC_MSG_TYPE_ENUM_UINT32;

/* Added by l00198894 for ����+ECID����, 2013-12-09, begin */
/*****************************************************************************
 ö����    : MTA_RRC_RESULT_ENUM
 �ṹ˵��  : MTAģ���������Ľ����ö��

  1.��    ��   : 2013��12��09��
    ��    ��   : l00198894
    �޸�����   : ����
*****************************************************************************/
enum MTA_RRC_RESULT_ENUM
{
    MTA_RRC_RESULT_NO_ERROR                     = 0x000000,                     /* ��Ϣ�������� */
    MTA_RRC_RESULT_ERROR,                                                       /* ��Ϣ�������� */

    MTA_RRC_RESULT_BUTT
};
typedef VOS_UINT32 MTA_RRC_RESULT_ENUM_UINT32;
/* Added by l00198894 for ����+ECID����, 2013-12-09, end */

/*******************************************************************************
 ö����    : NMR_UTRAN_MEASURED_TYPE_ENUM
 �ṹ˵��  : NMR������Ϣ����ѡ��:FDD TDD
 1.��    ��   : 2012��11��23��
   ��    ��   : w00134354
   �޸�����   : Added for NMR
*******************************************************************************/
enum NMR_UTRAN_MEASURED_TYPE_ENUM
{
    NMR_UTRAN_MEASURED_TYPE_FDD = 0,
    NMR_UTRAN_MEASURED_TYPE_TDD,
    NMR_UTRAN_MEASURED_TYPE_BUTT
};
typedef VOS_UINT32 NMR_UTRAN_MEASURED_TYPE_ENUM_UINT32;

/*******************************************************************************
 ö����    : GRR_MTA_NCELL_STATE_ENUM
 �ṹ˵��  : ����״̬ö��
 1.��    ��   : 2013��06��04��
   ��    ��   : s00217060
   �޸�����   : for V9R1_SVLTE
*******************************************************************************/
enum GRR_MTA_NCELL_STATE_ENUM
{
    GRR_MTA_NCELL_STATE_NULL    = 0x00,                                         /* ��û��TD��������Ҳû��4G���� */
    GRR_MTA_NCELL_STATE_3G      = 0x01,                                         /* ֻ��TD������ */
    GRR_MTA_NCELL_STATE_4G      = 0x02,                                         /* ֻ��4G������ */
    GRR_MTA_NCELL_STATE_3G4G    = 0x03,                                         /* ����TD��������Ҳ��4G���� */
    GRR_MTA_NCELL_STATE_BUTT

};
typedef VOS_UINT8 GRR_MTA_NCELL_STATE_ENUM_UINT8;

/*****************************************************************************
 ö����    : MTA_RRC_JAM_MODE_ENUM
 �ṹ˵��  : MTAģ����������JAMģʽ��ö��

  1.��    ��   : 2014��04��25��
    ��    ��   : y00142674
    �޸�����   : ����
*****************************************************************************/
enum MTA_RRC_JAM_MODE_ENUM
{
    MTA_RRC_JAM_MODE_STOP               = 0x00,                                 /* ֹͣJAM��� */
    MTA_RRC_JAM_MODE_START,                                                     /* ����JAM��� */

    MTA_RRC_JAM_MODE_BUTT
};
typedef VOS_UINT8 MTA_RRC_JAM_MODE_ENUM_UINT8;


/*****************************************************************************
 ö����    : MTA_RRC_JAM_RESULT_ENUM
 �ṹ˵��  : MTAģ����������JAM�����ö��

  1.��    ��   : 2014��04��25��
    ��    ��   : y00142674
    �޸�����   : ����
*****************************************************************************/
enum MTA_RRC_JAM_RESULT_ENUM
{
    MTA_RRC_JAM_RESULT_JAM_DISAPPEARED  = 0x00,                                 /* ���Ų����� */
    MTA_RRC_JAM_RESULT_JAM_DISCOVERED,                                          /* ���Ŵ��� */

    MTA_RRC_JAM_RESULT_BUTT
};
typedef VOS_UINT8 MTA_RRC_JAM_RESULT_ENUM_UINT8;


/*****************************************************************************
 ö����    : MTA_RRC_FREQLOCK_TYPE_ENUM
 �ṹ˵��  : FREQLOCK��Ƶ����ö��
1.��    ��  : 2014��10��21��
  ��    ��  : z00214637
  �޸�����  : �����ṹ
*****************************************************************************/
enum MTA_RRC_FREQLOCK_TYPE_ENUM
{
    MTA_RRC_FREQLOCK_TYPE_ENUM_FREQ_ONLY     = 1,                               /* ��ƵONLY���� */
    MTA_RRC_FREQLOCK_TYPE_ENUM_FREQ_COMBINED = 2,                               /* ��Ƶ+������/����/����С��ID */
    MTA_RRC_FREQLOCK_TYPE_ENUM_BUTT
};
typedef VOS_UINT8 MTA_RRC_FREQLOCK_TYPE_ENUM_UINT8;

/*****************************************************************************
 ö����    : MTA_LRRC_CLEAR_HISTORY_FREQ_TYPE_ENUM
 �ṹ˵��  : �����ʷƵ������ö��
1.��    ��   : 2015��9��11��
  ��    ��   : z00161729
  �޸�����   : ֧��LTE CSG��������
*****************************************************************************/
enum MTA_LRRC_CLEAR_HISTORY_FREQ_TYPE_ENUM
{
    MTA_LRRC_CLEAR_HISTORY_FREQ_TYPE_NONE_CSG         = 0,    /* �����CSG��ʷƵ����Ϣ */
    MTA_LRRC_CLEAR_HISTORY_FREQ_TYPE_CSG              = 1,    /* ���CSG��ʷƵ����Ϣ */
    MTA_LRRC_CLEAR_HISTORY_FREQ_TYPE_NONE_CSG_AND_CSG = 2,    /* ������У�������CSG��CSG��
                                                                 ��ʷƵ����Ϣ */
    MTA_LRRC_CLEAR_HISTORY_FREQ_TYPE_BUTT
};
typedef VOS_UINT8 MTA_LRRC_CLEAR_HISTORY_FREQ_TYPE_ENUM_UINT8;

/*****************************************************************************
 ö����    : MBMS_SERVICE_OP_ENUM
 �ṹ˵��  : MBMS Service������ʹ��/ȥʹ��ö��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
enum MBMS_SERVICE_OP_ENUM
{
    MBMS_SERVICE_OP_DISABLE             = 0,
    MBMS_SERVICE_OP_ENABLE              = 1,
    MBMS_SERVICE_OP_BUTT
};
typedef VOS_UINT8 MBMS_SERVICE_OP_ENUM_UINT8;

/*****************************************************************************
 ö����    : MBMS_SERVICE_STATE_SET_ENUM
 �ṹ˵��  : MBMS Service״̬����ö��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
enum MBMS_SERVICE_STATE_SET_ENUM
{
    MBMS_SERVICE_STATE_SET_ACTIVE       = 0,
    MBMS_SERVICE_STATE_SET_DEACTIVE     = 1,
    MBMS_SERVICE_STATE_SET_DEACTIVE_ALL = 2,
    MBMS_SERVICE_STATE_SET_BUTT
};
typedef VOS_UINT8 MBMS_SERVICE_STATE_SET_ENUM_UINT8;

/*****************************************************************************
 ö����    : MBMS_CAST_MODE_ENUM
 �ṹ˵��  : MBMS �㲥ģʽö��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
enum MBMS_CAST_MODE_ENUM
{
    MBMS_CAST_MODE_UNICAST              = 0,
    MBMS_CAST_MODE_MULTICAST            = 1,
    MBMS_CAST_MODE_BUTT
};
typedef VOS_UINT8 MBMS_CAST_MODE_ENUM_UINT8;

/*****************************************************************************
 ö����    : MBMS_FUNTIONALITY_STATUS_ENUM
 �ṹ˵��  : MBMS ����״̬ö��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
enum MBMS_FUNTIONALITY_STATUS_ENUM
{
    MBMS_FUNTIONALITY_OFF               = 0,
    MBMS_FUNTIONALITY_ON                = 1,
    MBMS_FUNTIONALITY_STATUS_BUTT
};
typedef VOS_UINT8 MBMS_FUNTIONALITY_STATUS_ENUM_UINT8;

/*****************************************************************************
 ö����    : MBMS_UNSOLICITED_CFG_ENUM
 �ṹ˵��  : MBMS �����ϱ�����ö��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
enum MBMS_UNSOLICITED_CFG_ENUM
{
    MBMS_UNSOLICITED_DISABLE            = 0,
    MBMS_UNSOLICITED_ENABLE             = 1,
    MBMS_UNSOLICITED_CFG_BUTT
};
typedef VOS_UINT8 MBMS_UNSOLICITED_CFG_ENUM_UINT8;

/*****************************************************************************
 ö����    : MBMS_SERVICE_EVENT_ENUM
 �ṹ˵��  : MBMS ����״̬�¼�ö��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
enum MBMS_SERVICE_EVENT_ENUM
{
    MBMS_SERVICE_EVENT_SERVICE_CHANGE       = 0,
    MBMS_SERVICE_EVENT_NO_SERVICE           = 1,
    MBMS_SERVICE_EVENT_ONLY_UNICAST         = 2,
    MBMS_SERVICE_EVENT_SERVICE_AVAILABLE    = 3,
    MBMS_SERVICE_EVENT_BUTT
};
typedef VOS_UINT8 MBMS_SERVICE_EVENT_ENUM_UINT8;

/*****************************************************************************
 ö����    : MTA_LRRC_COEX_BW_TYPE_ENUM
 ö��˵��  : LTE&WIFI��������ö��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
enum MTA_LRRC_COEX_BW_TYPE_ENUM
{
    MTA_LRRC_COEX_BAND_WIDTH_6RB        = 0,                                    /* ����1.4M */
    MTA_LRRC_COEX_BAND_WIDTH_15RB       = 1,                                    /* ����3M */
    MTA_LRRC_COEX_BAND_WIDTH_25RB       = 2,                                    /* ����5M */
    MTA_LRRC_COEX_BAND_WIDTH_50RB       = 3,                                    /* ����10M */
    MTA_LRRC_COEX_BAND_WIDTH_75RB       = 4,                                    /* ����15M */
    MTA_LRRC_COEX_BAND_WIDTH_100RB      = 5,                                    /* ����20M */
    MTA_LRRC_COEX_BAND_WIDTH_BUTT
};
typedef VOS_UINT16 MTA_LRRC_COEX_BW_TYPE_ENUM_UINT16;

/*****************************************************************************
 ö����    : MTA_LRRC_COEX_CFG_ENUM
 ö��˵��  : LTE&WIFI���淽������ö��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
enum MTA_LRRC_COEX_CFG_ENUM
{
    MTA_LRRC_COEX_CFG_DISABLE           = 0,
    MTA_LRRC_COEX_CFG_ENABLE            = 1,
    MTA_LRRC_COEX_CFG_BUTT
};
typedef VOS_UINT16 MTA_LRRC_COEX_CFG_ENUM_UINT16;

/*****************************************************************************
 ö����    : RRC_MTA_BAND_IND_ENUM
 �ṹ˵��  : MTAģ����������Ƶ�ε�ö��

  1.��    ��   : 2015��07��07��
    ��    ��   : y00142674
    �޸�����   : ����, for �ƶ�Ƶ���ռ�
*****************************************************************************/
enum RRC_MTA_BAND_IND_ENUM
{
    RRC_MTA_BAND_IND_NONE               = 0,
    RRC_MTA_BAND_IND_1,
    RRC_MTA_BAND_IND_2,
    RRC_MTA_BAND_IND_3,
    RRC_MTA_BAND_IND_4,
    RRC_MTA_BAND_IND_5,
    RRC_MTA_BAND_IND_6,
    RRC_MTA_BAND_IND_7,
    RRC_MTA_BAND_IND_8,
    RRC_MTA_BAND_IND_9,
    RRC_MTA_BAND_IND_10,
    RRC_MTA_BAND_IND_11,
    RRC_MTA_BAND_IND_12,
    RRC_MTA_BAND_IND_13,
    RRC_MTA_BAND_IND_14,
    RRC_MTA_BAND_IND_15,
    RRC_MTA_BAND_IND_16,
    RRC_MTA_BAND_IND_17,
    RRC_MTA_BAND_IND_18,
    RRC_MTA_BAND_IND_19,
    RRC_MTA_BAND_IND_20,
    RRC_MTA_BAND_IND_21,
    RRC_MTA_BAND_IND_22,
    RRC_MTA_BAND_IND_23,
    RRC_MTA_BAND_IND_24,
    RRC_MTA_BAND_IND_25,
    RRC_MTA_BAND_IND_26,
    RRC_MTA_BAND_IND_27,
    RRC_MTA_BAND_IND_28,
    RRC_MTA_BAND_IND_29,
    RRC_MTA_BAND_IND_30,
    RRC_MTA_BAND_IND_31,
    RRC_MTA_BAND_IND_32,
    RRC_MTA_BAND_IND_33,
    RRC_MTA_BAND_IND_34,
    RRC_MTA_BAND_IND_35,
    RRC_MTA_BAND_IND_36,
    RRC_MTA_BAND_IND_37,
    RRC_MTA_BAND_IND_38,
    RRC_MTA_BAND_IND_39,
    RRC_MTA_BAND_IND_40,
    RRC_MTA_BAND_IND_41,
    RRC_MTA_BAND_IND_42,
    RRC_MTA_BAND_IND_43,
    RRC_MTA_BAND_IND_44,

    RRC_MTA_BAND_IND_BUTT
};
typedef VOS_UINT16 RRC_MTA_BAND_IND_ENUM_UINT16;


/*****************************************************************************
 ö����    : MTA_RRC_FREQ_QRY_TYPE_ENUM
 ö��˵��  : Ƶ��Ƶ�β�ѯ������

  1.��    ��   : 2015��7��22��
    ��    ��   : f00179208
    �޸�����   : ����
*****************************************************************************/
enum MTA_RRC_FREQ_QRY_TYPE_ENUM
{
    MTA_RRC_FREQ_QRY_TYPE_SPEC_PLMN           = 0,
    MTA_RRC_FREQ_QRY_TYPE_ALL_PLMN            = 1,
    MTA_RRC_FREQ_QRY_TYPE_BUTT
};
typedef VOS_UINT8 MTA_RRC_FREQ_QRY_TYPE_UINT8;


/*****************************************************************************
  4 ȫ�ֱ�������
*****************************************************************************/

/*****************************************************************************
  5 ��Ϣͷ����
*****************************************************************************/

/*****************************************************************************
  6 ��Ϣ����
*****************************************************************************/

/*****************************************************************************
  7 STRUCT����
*****************************************************************************/
/*****************************************************************************
 �ṹ��    : MTA_RRC_PLMN_ID_STRU
 �ṹ˵��  : PLMN ID�ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulMcc;                                  /* MCC, 3 bytes, ��Чֵ: 0xFFFFFFFF */
    VOS_UINT32                          ulMnc;                                  /* MNC, 2 or 3 bytes, ��Чֵ: 0xFFFFFFFF */
} MTA_RRC_PLMN_ID_STRU;

/*******************************************************************************
 �ṹ��    : MTA_RRC_POSITION_REQ_STRU
 �ṹ˵��  : ����㷢�͸�GPSоƬ�Ķ�λ����Ĳ���
 1.��    ��   : 2012��06��01��
   ��    ��   : y00142674,l00128652,h44270
   �޸�����   : Added for AGPS
*******************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                             stMsgHeader;                    /*_H2ASN_Skip*/

    VOS_UINT32                                  bitOpAssistData   : 1;
    VOS_UINT32                                  bitOpPosMeas      : 1;
    VOS_UINT32                                  bitOpSpare        : 30;

    PS_BOOL_ENUM_UINT8                          enDeleteAssistDataFlag;         /* �Ƿ���Ҫ����������ݵı�� */
    VOS_UINT8                                   aucRsv[3];                      /* ����λ */
    AGPS_ASSIST_DATA_STRU                       stAssistData;                   /* assist_data,�������� */
    AGPS_MEASURE_REQ_STRU                       stPosMeas;                      /* pos_meas,λ�ò������� */
}MTA_RRC_POSITION_REQ_STRU;

/*******************************************************************************
 �ṹ��    : MTA_RRC_POSITION_CNF_STRU
 �ṹ˵��  : GPS�Ķ�λ�ظ�
 1.��    ��   : 2012��06��01��
   ��    ��   : y00142674,l00128652,h44270
   �޸�����   : Added for AGPS
*******************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                                     stMsgHeader;            /*_H2ASN_Skip*/

    VOS_UINT8                                           aucRsv[3];              /* ����λ */
    AGPS_POSITION_RESULT_TYPE_ENUM_UINT8                enResultTypeChoice;     /* �����Ϣ���� */
    union
    {
        AGPS_LOCATION_INFO_STRU                         stLocationInfo;         /* location,λ����Ϣ */
        AGPS_GPS_MEASURE_INFO_STRU                      stGpsMeasInfo;          /* GPS_meas,GPS������Ϣ */
        AGPS_POSITION_GPS_ADDITION_ASSIST_REQ_STRU      stAssistDataReq;        /* GPS_assist_req,������������ */
        AGPS_POSITION_ERR_STRU                          stPosErr;               /* pos_err,λ�ô�����Ϣ */
    }u;
}MTA_RRC_POSITION_CNF_STRU;

/*******************************************************************************
 �ṹ��    : MTA_RRC_RESEL_OFFSET_CFG_NTF
 �ṹ˵��  : W��L��ѡ���Ͳ�������
 1.��    ��   : 2012��12��07��
   ��    ��   : l00128652 h44270
   �޸�����   : �����ṹ

*******************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                             stMsgHeader;                    /*_H2ASN_Skip*/
    PS_BOOL_ENUM_UINT8                          enOffsetEnable;                 /* 0:������1:����*/
    VOS_UINT8                                   aucRsv[3];                      /* ����λ*/
}MTA_RRC_RESEL_OFFSET_CFG_NTF_STRU;


/*******************************************************************************
 �ṹ��    : NMR_UTRAN_FREQUENCY_INFO_FDD_STRU
 �ṹ˵��  : NMR Ƶ����Ϣ

 1.��    ��   : 2012��11��23��
   ��    ��   : w00134354
   �޸�����   : Added for NMR

   FrequencyInfoFDD ::= SEQUENCE {uarfcn-UL UARFCN OPTIONAL,
                                  uarfcn-DL UARFCN,...}
*******************************************************************************/
typedef struct
{
    VOS_UINT32                                  bitOpUarfcn_UL        : 1;
    VOS_UINT32                                  bitOpSpare            : 31;
    VOS_UINT16                                  usUlUarfcn;           /* ����Ƶ�� */
    VOS_UINT16                                  usDlUarfcn;           /* ����Ƶ�� */
}NMR_UTRAN_FREQUENCY_INFO_FDD_STRU;

/*******************************************************************************
 �ṹ��    : NMR_UTRAN_FREQUENCY_INFO_STRU
 �ṹ˵��  : NMR FrequencyInfo�ṹ
 1.��    ��   : 2012��11��23��
   ��    ��   : w00134354
   �޸�����   : Added for NMR
*******************************************************************************/
typedef struct
{
    NMR_UTRAN_MEASURED_TYPE_ENUM_UINT32           enFreqInfoChoice;     /* NMRƵ����Ϣ����:0:FDD,1:TDD */
    union
    {
        NMR_UTRAN_FREQUENCY_INFO_FDD_STRU         stFreqInfoFDD;         /* fdd */
        VOS_UINT32                                ulFreqInfoTDD;          /*  TDD */
    }u;

}NMR_UTRAN_FREQUENCY_INFO_STRU;
/*******************************************************************************
 �ṹ��    : NMR_UTRAN_CELL_MEAS_RESULTS_FDD_STRU
 �ṹ˵��  : NMR Cell Measured Results FDD
 1.��    ��   : 2012��11��23��
   ��    ��   : w00134354
   �޸�����   : Added for NMR
*******************************************************************************/

typedef struct
{
    VOS_UINT32                                  bitOpEcn0      : 1;
    VOS_UINT32                                  bitOpRscp      : 1;
    VOS_UINT32                                  bitOpPathloss  : 1;
    VOS_UINT32                                  bitOpSpare     : 29;

    VOS_UINT16                                  usCellPSC;
    VOS_UINT8                                   ucEcn0;              /* INTEGER(0..63) */
    VOS_UINT8                                   ucRscp;              /*  INTEGER(0..127)*/
    VOS_UINT8                                   ucPathloss;           /* INTEGER(46..173)  */
    VOS_UINT8                                   aucRsv[3];


}NMR_UTRAN_CELL_MEAS_RESULTS_FDD_STRU;

/*******************************************************************************
 �ṹ��    : NMR_UTRAN_MEAS_RESULTS_STRU
 �ṹ˵��  : NMR Cell Measured Results TDD
 1.��    ��   : 2012��11��23��
   ��    ��   : w00134354
   �޸�����   : Added for NMR
*******************************************************************************/
typedef struct
{
    VOS_UINT32                                  bitOpProposedTGSN  : 1;
    VOS_UINT32                                  bitOpRscp          : 1;
    VOS_UINT32                                  bitOpPathloss      : 1;
    VOS_UINT32                                  bitOpTimeslotISCP  : 1;
    VOS_UINT32                                  bitOpSpare         : 28;

    VOS_UINT8                                   ucCellParaID;         /* INTEGER(0..127) */
    VOS_UINT8                                   ucProposedTGSN;       /* INTEGER(0..14)  */
    VOS_UINT8                                   ucRscp;               /* INTEGER(0..127) */
    VOS_UINT8                                   ucPathloss;           /* INTEGER(46..173) */
    VOS_UINT8                                   ucTimeslotISCP;       /* INTEGER(46..173) */
    VOS_UINT8                                   aucRsv[3];

}NMR_UTRAN_CELL_MEAS_RESULTS_TDD_STRU;

/*******************************************************************************
 �ṹ��    : NMR_UTRAN_CELL_MEAS_RESULTS_STRU
 �ṹ˵��  : NMR Cell Measured Results
 1.��    ��   : 2012��11��23��
   ��    ��   : w00134354
   �޸�����   : Added for NMR
*******************************************************************************/
typedef struct
{
    VOS_UINT32                                  bitOpCellID               : 1;
    VOS_UINT32                                  bitOpSpare                : 31;

    VOS_UINT32                                  ulCellID;                 /*  */
    NMR_UTRAN_MEASURED_TYPE_ENUM_UINT32         enCellMeasTypeChoice;     /* NMRƵ����Ϣ����:FDD,TDD */
    union
    {
        NMR_UTRAN_CELL_MEAS_RESULTS_FDD_STRU    stCellMeasResultsFDD;         /* FDD */
        NMR_UTRAN_CELL_MEAS_RESULTS_TDD_STRU    stCellMeasResultsTDD;         /*  TDD */
    }u;

}NMR_UTRAN_CELL_MEAS_RESULTS_STRU;

/*******************************************************************************
 �ṹ��    : NMR_MEASURED_RESULTS_LIST_STRU
 �ṹ˵��  : NMR Cell Measured Results List
 1.��    ��   : 2012��11��23��
   ��    ��   : w00134354
   �޸�����   : Added for NMR
*******************************************************************************/
typedef struct
{
    VOS_UINT32                                  ulMeasCellNum;            /* (0,32) */
    NMR_UTRAN_CELL_MEAS_RESULTS_STRU            astCellMeasResults[NMR_MAX_CELL_FREQ_NUM];
}NMR_UTRAN_CELL_MEAS_RESULTS_LIST_STRU;

/*******************************************************************************
 �ṹ��    : NMR_UTRAN_MEASURED_RESULTS_STRU
 �ṹ˵��  : 3Gģʽ�²������
 1.��    ��   : 2012��11��23��
   ��    ��   : w00134354
   �޸�����   : Added for NMR
*******************************************************************************/
typedef struct
{
    VOS_UINT32                                  bitOpFrequencyInfo        : 1;
    VOS_UINT32                                  bitOpUTRA_CarrierRSSI     : 1;
    VOS_UINT32                                  bitOpCellMeasResultsList  : 1;
    VOS_UINT32                                  bitOpSpare                : 29;

    NMR_UTRAN_FREQUENCY_INFO_STRU               stFrequencyInfo;
    VOS_UINT32                                  ulUTRA_CarrierRSSI; /* Ƶ���RSSI */
    NMR_UTRAN_CELL_MEAS_RESULTS_LIST_STRU       stCellMeasResultsList;
}NMR_UTRAN_MEASURED_RESULTS_STRU;

/*******************************************************************************
 �ṹ��    : RRC_MTA_UTRAN_NMR_STRU
 �ṹ˵��  : 3Gģʽ��NMR������Ϣ
 1.��    ��   : 2012��11��23��
   ��    ��   : w00134354
   �޸�����   : Added for NMR
*******************************************************************************/
typedef struct
{
    VOS_UINT32                                ulFreqNum;            /* (0,8) */
    NMR_UTRAN_MEASURED_RESULTS_STRU           astMeasResults[NMR_MAX_FREQ_NUM];
}RRC_MTA_UTRAN_NMR_STRU;

/*******************************************************************************
 �ṹ��    : RRC_MTA_GSM_NMR_ELEMENT_STRU
 �ṹ˵��  : 2Gģʽ��NMR ELEMENT������Ϣ
 1.��    ��   : 2012��11��26��
   ��    ��   : j00178524
   �޸�����   : Added for NMR
*******************************************************************************/
typedef struct
{
    VOS_UINT16                                usArfcn;            /* С������Ƶ���, ȡֵ��Χ[0,1023] */
    VOS_UINT8                                 ucBsic;             /* С��BSIC, [0,63] */
    VOS_UINT8                                 ucRxlev;            /* С��������ƽ, �Ѿ�ӳ��Ϊ[0,63]��ȡֵ��Χ��ȡֵ */
}RRC_MTA_GSM_NMR_ELEMENT_STRU;


/*******************************************************************************
 �ṹ��    : RRC_MTA_GSM_NMR_STRU
 �ṹ˵��  : 2Gģʽ��NMR������Ϣ
 1.��    ��   : 2012��11��26��
   ��    ��   : j00178524
   �޸�����   : Added for NMR
*******************************************************************************/
typedef struct
{
    VOS_UINT32                                ulElemNum;                        /* GSM NMRԪ�ظ��� [0,15] */

    /* GSM NMRԪ������, ��һ��Ԫ�ط���С��, ֮���Ԫ����GSM����, GSM���������ź�ǿ���ɸߵ������� */
    RRC_MTA_GSM_NMR_ELEMENT_STRU              astNmrElem[RRC_MTA_NMR_MAX_GSM_ELEM_NUM];
}RRC_MTA_GSM_NMR_STRU;

/*****************************************************************************
 �ṹ��    : MTA_RRC_QRY_NMR_REQ_STRU
 �ṹ˵��  : ID_MTA_RRC_QRY_NMR_REQ��Ϣ�ṹ
 1.��    ��   : 2012��11��23��
   ��    ��   : s46746
   �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     MsgHeader;          /* ��Ϣͷ    */     /*_H2ASN_Skip*/
    /* MTA_RRC_MSG_TYPE_ENUM_UINT32        enMsgId; */

    VOS_UINT8                           aucReserve[4];                          /* Ԥ������ʹ�� */
} MTA_RRC_QRY_NMR_REQ_STRU;

/*****************************************************************************
 �ṹ��    : RRC_MTA_QRY_NMR_CNF_STRU
 �ṹ˵��  : ID_RRC_MTA_QRY_NMR_CNF��Ϣ�ṹ
 1.��    ��   : 2012��11��23��
   ��    ��   : s46746
   �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     MsgHeader;          /* ��Ϣͷ    */     /*_H2ASN_Skip*/

    /* ulChoice �ĺ궨�� */
    VOS_UINT32                          ulChoice;
    union
    {
        RRC_MTA_UTRAN_NMR_STRU          stUtranNMRData;
        RRC_MTA_GSM_NMR_STRU            stGsmNMRData;
    }u;
} RRC_MTA_QRY_NMR_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_WRR_AUTOTEST_PARA_STRU
 �ṹ˵��  : AS�����������

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucCmd;                                  /* �Զ����������� */
    VOS_UINT8                           ucParaNum;                              /* ����������� */
    VOS_UINT16                          usReserve;                              /* ���ֽڶ��� */
    VOS_UINT32                          aulPara[MTA_WRR_AUTOTEST_MAX_PARA_NUM]; /* ������� */
}MTA_WRR_AUTOTEST_PARA_STRU;

/*****************************************************************************
 �ṹ��    : MTA_WRR_AUTOTEST_QRY_REQ_STRU
 �ṹ˵��  : AS��������ṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    MTA_WRR_AUTOTEST_PARA_STRU          stWrrAutotestPara;
}MTA_WRR_AUTOTEST_QRY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : WRR_MTA_AUTOTEST_QRY_RSLT_STRU
 �ṹ˵��  : WAS��������ؽ��

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulRsltNum;                              /* ��ѯ������� */
    VOS_UINT32                          aulRslt[WRR_MTA_AUTOTEST_MAX_RSULT_NUM];/* ��ѯ��� */
}WRR_MTA_AUTOTEST_QRY_RSLT_STRU;

/*****************************************************************************
 �ṹ��    : WRR_MTA_AUTOTEST_QRY_CNF_STRU
 �ṹ˵��  : WAS��������ؽ����Ϣ�ṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulResult;
    WRR_MTA_AUTOTEST_QRY_RSLT_STRU      stWrrAutoTestRslt;
} WRR_MTA_AUTOTEST_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_WRR_CELLINFO_SET_REQ_STRU
 �ṹ˵��  : MTA����WAS cellinfo��Ϣ�ṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulSetCellInfo;                          /* 0:��ѯ��С����Ϣ 1:��ѯW������Ϣ */
} MTA_WRR_CELLINFO_QRY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : WRR_MTA_WCDMA_CELLINFO_STRU
 �ṹ˵��  : С����Ϣ�ṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT16                      usCellFreq;                                 /* Ƶ�� */
    VOS_UINT16                      usPrimaryScramCode;                         /* ���� */
    VOS_INT16                       sCpichRscp;                                 /* RSCPֵ */
    VOS_INT16                       sCpichEcN0;                                 /* ECN0ֵ */

}WRR_MTA_WCDMA_CELLINFO_STRU;

/*****************************************************************************
 �ṹ��    : WRR_MTA_WCDMA_CELLINFO_RSLT_STRU
 �ṹ˵��  : WRR�ظ�MTAС����Ϣ��ѯ�ṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
     VOS_UINT32                     ulCellNum;
     WRR_MTA_WCDMA_CELLINFO_STRU    astWCellInfo[WRR_MTA_MAX_NCELL_NUM];         /*���֧��W 8�������Ĳ�ѯ*/

} WRR_MTA_WCDMA_CELLINFO_RSLT_STRU;
/*****************************************************************************
 �ṹ��    : WRR_MTA_CELLINFO_QRY_CNF_STRU
 �ṹ˵��  : WRR�ظ�MTAС����Ϣ��ѯ�ṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                              ulMsgName;                          /*_H2ASN_Skip*/
    VOS_UINT32                              ulResult;
    WRR_MTA_WCDMA_CELLINFO_RSLT_STRU        stWrrCellInfo;
} WRR_MTA_CELLINFO_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_WRR_MEANRPT_QRY_REQ_STRU
 �ṹ˵��  : MTA�·�MEANRPT QRY��Ϣ�ṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;
} MTA_WRR_MEANRPT_QRY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : WRR_MTA_MEANRPT_STRU
 �ṹ˵��  : ���������е��¼�+С��

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT16                      usEventId;                                  /* ��Ӧ���¼����� */
    VOS_UINT16                      usCellNum;                                  /* һ�β��������ϱ�С������*/
    VOS_UINT16                      ausPrimaryScramCode[WRR_MTA_MEANRPT_MAX_CELL_NUM];/* ���� */
}WRR_MTA_MEANRPT_STRU;

/*****************************************************************************
 �ṹ��    : WRR_MTA_MEANRPT_RSLT_STRU
 �ṹ˵��  : �Զ�������AT^MEANRPT,
             ��ѯ������10�β��������е��¼�+С��

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                      ulRptNum;                                   /* ����Ĳ���������� */
    WRR_MTA_MEANRPT_STRU            astMeanRptInfo[WRR_MTA_MAX_MEANRPT_NUM];    /* ���������ϱ���С�� */
}WRR_MTA_MEANRPT_RSLT_STRU;


/*****************************************************************************
 �ṹ��    : WRR_MTA_MEANRPT_QRY_CNF_STRU
 �ṹ˵��  : WRR��MTA�ظ�^MEANRPT�������Ϣ�ṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulResult;
    WRR_MTA_MEANRPT_RSLT_STRU           stMeanRptRslt;
} WRR_MTA_MEANRPT_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_WRR_FREQLOCK_CTRL_STRU
 �ṹ˵��  : WAS��Ƶ���ƽṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucFreqLockEnable;                       /* �Ƿ���Ƶ 0:δ��Ƶ 1:��Ƶ */
    VOS_UINT8                           aucReserved[1];
    VOS_UINT16                          usLockedFreq;                           /* ������Ƶ�� */
} MTA_WRR_FREQLOCK_CTRL_STRU;

/*****************************************************************************
 �ṹ��    : MTA_WRR_FREQLOCK_SET_REQ_STRU
 �ṹ˵��  : MTA�·�MEANRPT QRY��Ϣ�ṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    MTA_WRR_FREQLOCK_CTRL_STRU          stFrelock;
} MTA_WRR_FREQLOCK_SET_REQ_STRU;

/*****************************************************************************
 �ṹ��    : WRR_MTA_FREQLOCK_SET_CNF_STRU
 �ṹ˵��  : MTA��AT�ص���Ƶ���ý��

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulResult;
} WRR_MTA_FREQLOCK_SET_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_WRR_FREQLOCK_QRY_REQ_STRU
 �ṹ˵��  : MTA�·�MEANRPT QRY��Ϣ�ṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;
} MTA_WRR_FREQLOCK_QRY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : WRR_MTA_FREQLOCK_QRY_CNF_STRU
 �ṹ˵��  : MTA��AT�ص���Ƶ���ƽṹ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulResult;
    MTA_WRR_FREQLOCK_CTRL_STRU          stFreqLockInfo;
} WRR_MTA_FREQLOCK_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_WRR_RRC_VERSION_SET_REQ_STRU
 �ṹ˵��  : MTA����WRR version

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT8                           ucRRCVersion;                           /* RRC�汾 */
    VOS_UINT8                           aucReserv[3];
} MTA_WRR_RRC_VERSION_SET_REQ_STRU;

/*****************************************************************************
 �ṹ��    : MTA_WRR_RRC_VERSION_QRY_REQ_STRU
 �ṹ˵��  : MTA��ѯWRR version

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;
} MTA_WRR_RRC_VERSION_QRY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : WRR_MTA_RRC_VERSION_SET_CNF_STRU
 �ṹ˵��  : WRR��MTA�ϱ�version���ý��

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulResult;
} WRR_MTA_RRC_VERSION_SET_CNF_STRU;

/*****************************************************************************
 �ṹ��    : WRR_MTA_RRC_VERSION_QRY_CNF_STRU
 �ṹ˵��  : WRR��MTA�ϱ�version��ѯ���

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulResult;
    VOS_UINT8                           ucRrcVersion;                           /* RRC�汾 */
    VOS_UINT8                           aucReserved[3];
} WRR_MTA_RRC_VERSION_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_WRR_CELLSRH_SET_REQ_STRU
 �ṹ˵��  : MTA�·�WRR cellsrh��������

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT8                           ucCellSrh;                              /* ����ģʽ 0:����ģʽ 1:��ʹ��������Ϣģʽ */
    VOS_UINT8                           aucReserve[3];
} MTA_WRR_CELLSRH_SET_REQ_STRU;

/*****************************************************************************
 �ṹ��    : WRR_MTA_CELLSRH_SET_CNF_STRU
 �ṹ˵��  : WRR��MTA�ϱ�cellsrh���ý��

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulResult;
} WRR_MTA_CELLSRH_SET_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_WRR_CELLSRH_QRY_REQ_STRU
 �ṹ˵��  : MTA�·���ѯWRR cellsrh ��Ϣ

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;
} MTA_WRR_CELLSRH_QRY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : WRR_MTA_CELLSRH_QRY_CNF_STRU
 �ṹ˵��  : WRR��MTA�ϱ�cellsrh��ѯ���

  1.��    ��   : 2012��12��29��
    ��    ��   : m00217266
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulResult;
    VOS_UINT8                           ucCellSearchType;                       /* ����ģʽ 0:����ģʽ 1:��ʹ��������Ϣģʽ */
    VOS_UINT8                           aucReserve[3];
} WRR_MTA_CELLSRH_QRY_CNF_STRU;


/*****************************************************************************
 �ṹ��    : MTA_GRR_NCELL_MONITOR_SET_REQ_STRU
 �ṹ˵��  : MTA����GRRC����ϵͳС���仯��Ϣ����������Ϣ

  1.��    ��   : 2013��5��31��
    ��    ��   : s00217060
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT8                           ucSwitch;
    VOS_UINT8                           aucReserved[3];
} MTA_GRR_NCELL_MONITOR_SET_REQ_STRU;

/*****************************************************************************
 �ṹ��    : MTA_GRR_NCELL_MONITOR_QRY_REQ_STRU
 �ṹ˵��  : MTA����GRRC�Ĳ�ѯ��ϵͳС���仯��Ϣ����������Ϣ

  1.��    ��   : 2013��5��31��
    ��    ��   : s00217060
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;
} MTA_GRR_NCELL_MONITOR_QRY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : GRR_MTA_NCELL_MONITOR_SET_CNF_STRU
 �ṹ˵��  : GRRC����MTA����ϵͳС���仯��Ϣ����������Ϣ�Ļظ�

  1.��    ��   : 2013��5��31��
    ��    ��   : s00217060
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulResult;
} GRR_MTA_NCELL_MONITOR_SET_CNF_STRU;

/*****************************************************************************
 �ṹ��    : GRR_MTA_NCELL_MONITOR_QRY_CNF_STRU
 �ṹ˵��  : GRRC����MTA�Ĳ�ѯ��ϵͳС���仯��Ϣ����������Ϣ�Ļظ�

  1.��    ��   : 2013��5��31��
    ��    ��   : s00217060
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulResult;
    VOS_UINT8                           ucSwitch;
    GRR_MTA_NCELL_STATE_ENUM_UINT8      enNcellState;
    VOS_UINT8                           aucReserved[2];
} GRR_MTA_NCELL_MONITOR_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : GRR_MTA_NCELL_MONITOR_IND_STRU
 �ṹ˵��  : GRRC����MTA����ϵͳС���仯��Ϣ�����ϱ�

  1.��    ��   : 2013��5��31��
    ��    ��   : s00217060
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    GRR_MTA_NCELL_STATE_ENUM_UINT8      enNcellState;
    VOS_UINT8                           aucReserved[3];
} GRR_MTA_NCELL_MONITOR_IND_STRU;

/* Added by l00198894 for ����+ECID����, 2013-12-09, begin */
/*****************************************************************************
 �ṹ��    : MTA_LRRC_CELLINFO_QRY_REQ_STRU
 �ṹ˵��  : MTA���͸�LRRC��ѯLTE��ǿ��С����Ϣ

  1.��    ��   : 2013��12��09��
    ��    ��   : l00198894
    �޸�����   : ����+ECID����
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                /*_H2ASN_Skip*/
    VOS_UINT8                           aucReserved[4];             /* ����λ */
}MTA_LRRC_CELLINFO_QRY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_CELLINFO_STRU
 �ṹ˵��  : LTE��ǿ��С����Ϣ�ṹ

  1.��    ��   : 2013��12��09��
    ��    ��   : l00198894
    �޸�����   : ����+ECID����

  2.��    ��   : 2015��12��2��
    ��    ��   : l00198894
    �޸�����   : DTS2015120206389: LRRC�ӿڱ����TA��ƫ�������������
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpEarfcn   :1;
    VOS_UINT32                          bitOpRsrp     :1;
    VOS_UINT32                          bitOpRsrq     :1;
    VOS_UINT32                          bitOpTa       :1;
    VOS_UINT32                          bitSpare      :28;
    VOS_UINT32                          ulPhyCellCode;
    VOS_UINT32                          ulEarfcn;
    VOS_UINT32                          ulRsrp;
    VOS_UINT32                          ulRsrq;
    VOS_UINT32                          ulTa;                                   /* ʱ����ǰ����ȡֵ��Χ0~1282 */
}LRRC_CELLINFO_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_CELLINFO_RSLT_STRU
 �ṹ˵��  : LTE��ǿ��С����Ϣ����ṹ

  1.��    ��   : 2013��12��09��
    ��    ��   : l00198894
    �޸�����   : ����+ECID����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulTac;
    VOS_UINT32                          ulCellNum;
    LRRC_CELLINFO_STRU                  astCellInfo[LRRC_MAX_NCELL_NUM];
}LRRC_CELLINFO_RSLT_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_MTA_CELLINFO_QRY_CNF_STRU
 �ṹ˵��  : LRRC�ظ�MTAģ����ǿ��С����Ϣ��ѯ����ṹ

  1.��    ��   : 2013��12��09��
    ��    ��   : l00198894
    �޸�����   : ����+ECID����
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;
    LRRC_CELLINFO_RSLT_STRU             stCellInfoRslt;
}LRRC_MTA_CELLINFO_QRY_CNF_STRU;
/* Added by l00198894 for ����+ECID����, 2013-12-09, end */

/*****************************************************************************
 �ṹ��    : MTA_RRC_PROTECT_PS_IND_STRU
 �ṹ˵��  : MTA���͸�rrc��lrrcģ��PS������Ϣ�Ľṹ

  1.��    ��   : 2014��3��25��
    ��    ��   : y00176023
    �޸�����   : ����^PSPROTECTMODE����
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;               /*_H2ASN_Skip*/
    PS_BOOL_ENUM_UINT8                  enProtectFlg;              /* ps ������־ */
    VOS_UINT8                           aucRsv[3];                 /* ����λ */
} MTA_RRC_PROTECT_PS_IND_STRU;

/*****************************************************************************
�ṹ��    : MTA_TLRRC_SET_DPDTTEST_FLAG_NTF_STRU
�ṹ˵��  : ���������㷨�򿪡��ر���Ϣ�ṹ

  1.��    ��  : 2014��04��01��
    ��    ��  : g00261581
    ��������  : �½�
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT8                           ucFlag;
    VOS_UINT8                           aucReserved[3];
} MTA_TLRRC_SET_DPDTTEST_FLAG_NTF_STRU;

/*****************************************************************************
�ṹ��    : MTA_TLRRC_SET_DPDT_VALUE_NTF_STRU
�ṹ˵��  : �������ߵ�ǰDPDT Valueֵ

  1.��    ��  : 2014��04��01��
    ��    ��  : g00261581
    ��������  : �½�
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulDpdtValue;
} MTA_TLRRC_SET_DPDT_VALUE_NTF_STRU;

/*****************************************************************************
�ṹ��    : MTA_TLRRC_QRY_DPDT_VALUE_REQ_STRU
�ṹ˵��  : ��ѯ��ǰ����״̬��Ϣ�ṹ

  1.��    ��  : 2014��04��01��
    ��    ��  : g00261581
    ��������  : �½�
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT8                           aucReserved[4];
} MTA_TLRRC_QRY_DPDT_VALUE_REQ_STRU;

/*****************************************************************************
�ṹ��    : TLRRC_MTA_QRY_DPDT_VALUE_CNF_STRU
�ṹ˵��  : ��ѯ��Ӧ�������ʾ��ǰ����DPDT Valueֵ

  1.��    ��  : 2014��04��01��
    ��    ��  : g00261581
    ��������  : �½�
*****************************************************************************/
typedef struct
{
    VOS_MSG_HEADER                                                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulMsgName;                              /*_H2ASN_Skip*/
    VOS_UINT32                          ulDpdtValue;
    MTA_RRC_RESULT_ENUM_UINT32          enResult;
} TLRRC_MTA_QRY_DPDT_VALUE_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_RRC_JAM_DETECT_REQ_STRU
 �ṹ˵��  : MTA����RRC��JAM��������

  1.��    ��   : 2014��4��25��
    ��    ��   : y00142674
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    MTA_RRC_JAM_MODE_ENUM_UINT8         enMode;                                 /* JAM���õ�ģʽ */
    VOS_UINT8                           ucMethod;                               /* JAMʹ�õķ�����ȡֵ��Χ[0,1]*/
    VOS_UINT8                           ucThreshold;                            /* �����Ҫ�ﵽ��Ƶ�����ֵ��ȡֵ��Χ:[0,30] */
    VOS_UINT8                           ucFreqNum;                              /* �����Ҫ�ﵽ��Ƶ�������ȡֵ��Χ:[0,255] */
} MTA_RRC_JAM_DETECT_REQ_STRU;
/*****************************************************************************
 �ṹ��    : MTA_WRR_JAM_DETECT_REQ_STRU
 �ṹ˵��  : MTA����WAS��JAM��������

  1.��    ��   : 2015��2��17��
    ��    ��   : y00142674
    �޸�����   : ����

*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    MTA_RRC_JAM_MODE_ENUM_UINT8         enMode;                                 /* JAM���õ�ģʽ */
    VOS_UINT8                           ucMethod;                               /* JAMʹ�õķ�����ȡֵ��Χ[0,1]*/
    VOS_UINT8                           ucRssiSrhThreshold;                     /* ����RSSIʱ�����Ҫ�ﵽ��Ƶ�����ֵ��ȡֵ��Χ:[0,70]��ʵ���õ�ʱ���70ʹ�� */
    VOS_UINT8                           ucRssiSrhFreqPercent;                   /* ����RSSIʱ�����Ҫ�ﵽ��Ƶ�����ռƵ������(BAND�͸����ź�ȡ����)�İٷֱȣ�ȡֵ��Χ:[0,100]
                                                                                   ���Ŵ�������NV����Ĭ��30M��RSSI�ٷֱ�Ĭ��70%������BAND��������30M����Ƶ�������Ҫ�ﵽ(30M/3M)*70% = 7�� */
    VOS_UINT16                          usPschSrhThreshold;                     /* ����PSCHʱ�����ҪС�ڵ��ڵ�Ƶ�����ֵ��ȡֵ��Χ:[0,65535] */
    VOS_UINT8                           ucPschSrhFreqPercent;                   /* ����PSCHʱ�����Ҫ�ﵽ��Ƶ�����ռƵ������(BAND�͸����ź�ȡ����)�İٷֱȣ�ȡֵ��Χ:[0,100]
                                                                                   �����źŰ���NV����Ĭ��30M��RSSI�ٷֱ�Ĭ��70%��PSCH�ٷֱ�Ĭ��80%��
                                                                                   ����BAND��������30M����Ƶ�������Ҫ�ﵽ((30M*70%)/200K)*80% = 84�� */
    VOS_UINT8                           aucRsv[1];
} MTA_WRR_JAM_DETECT_REQ_STRU;
/*****************************************************************************
 �ṹ��    : RRC_MTA_JAM_DETECT_CNF_STRU
 �ṹ˵��  : RRC����MTA��JAM��⹦�����õĻظ�

  1.��    ��   : 2014��4��25��
    ��    ��   : y00142674
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                               /* JAM���õĽ�� */
} RRC_MTA_JAM_DETECT_CNF_STRU;

/*****************************************************************************
 �ṹ��    : RRC_MTA_JAM_DETECT_IND_STRU
 �ṹ˵��  : RRC����MTA��JAM������Ļظ�

  1.��    ��   : 2014��4��25��
    ��    ��   : y00142674
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    MTA_RRC_JAM_RESULT_ENUM_UINT8       enResult;                               /* JAM���Ľ�� */
    VOS_UINT8                           aucReserved[3];
} RRC_MTA_JAM_DETECT_IND_STRU;

/*****************************************************************************
 �ṹ��    : MTA_RRC_CHECK_FREQ_VALIDITY_REQ_STRU
 �ṹ˵��  : MTA����������㣬���Ƶ����Ч�Ե�����

  1.��    ��   : 2014��6��3��
    ��    ��   : g00261581
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    VOS_UINT16                          usFreq;                                 /* Ƶ��ֵ */
    MTA_RRC_GSM_BAND_ENUM_UINT16        enBand;                                 /* GSMģʽ����Ҫ��Ƶ�� */
} MTA_RRC_CHECK_FREQ_VALIDITY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : RRC_MTA_CHECK_FREQ_VALIDITY_CNF_STRU
 �ṹ˵��  : ������㷢��MTA��Ƶ�������Ļظ�

  1.��    ��   : 2014��6��3��
    ��    ��   : g00261581
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                               /* MTA_RRC_RESULT_NO_ERROR:Ƶ����Ч�� MTA_RRC_RESULT_ERROR:Ƶ����Ч*/
} RRC_MTA_CHECK_FREQ_VALIDITY_CNF_STRU;
/*****************************************************************************
 �ṹ��    : MTA_GRR_FREQLOCK_SET_REQ_STRU
 �ṹ˵��  : MTA��GAS�·���Ƶ��Ϣ�ṹ

  1.��    ��   : 2014��07��28��
    ��    ��   : y00142674
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    PS_BOOL_ENUM_UINT8                  enLockFlg;                              /* PS_TRUE:������PS_FALSE:ȥ���� */
    VOS_UINT8                           aucReserved[3];                         /* ����λ */
    VOS_UINT16                          usFreq;                                 /* Ƶ��ֵ */
    MTA_RRC_GSM_BAND_ENUM_UINT16        enBand;                                 /* GSMƵ�� */
} MTA_GRR_FREQLOCK_SET_REQ_STRU;

/*****************************************************************************
 �ṹ��    : GRR_MTA_FREQLOCK_SET_CNF_STRU
 �ṹ˵��  : GAS��MTA�ص���Ƶ���ý��

  1.��    ��   : 2014��07��28��
    ��    ��   : y00142674
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                               /* MTA_RRC_RESULT_NO_ERROR:��Ƶ�ɹ��� MTA_RRC_RESULT_ERROR:��Ƶʧ��*/
} GRR_MTA_FREQLOCK_SET_CNF_STRU;


/*****************************************************************************
 �ṹ��    : MTA_RRC_PLMN_FREQ_QRY_REQ_STRU
 �ṹ˵��  : MTA����RRC��Ƶ���ѯ����

  1.��    ��   : 2015��07��07��
    ��    ��   : y00142674
    �޸�����   : ����, for �ƶ�Ƶ���ռ�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    MTA_RRC_FREQ_QRY_TYPE_UINT8         enQueryType;                            /* ��ѯ���� */
    VOS_UINT8                           aucRsv[2];                              /* ����λ */
    VOS_UINT8                           ucPlmnIdNum;                            /* ��ѯָ��PLMN�ĸ���������enPlmnCheckFlagΪTRUEʱʹ�� */
    MTA_RRC_PLMN_ID_STRU                astPlmnIdList[MTA_RRC_MAX_PLMN_NUM];    /* PLMN���б�������enPlmnCheckFlagΪTRUEʱʹ�� */
} MTA_RRC_PLMN_FREQ_QRY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : RRC_MTA_FREQ_INFO_STRU
 �ṹ˵��  : RRC����MTA��Ƶ����Ϣ

  1.��    ��   : 2015��07��07��
    ��    ��   : y00142674
    �޸�����   : ����, for �ƶ�Ƶ���ռ�
*****************************************************************************/
typedef struct
{
    RRC_MTA_BAND_IND_ENUM_UINT16        enBandInd;                              /* Ƶ��ָʾ */
    VOS_UINT16                          usFreq;                                 /* Ƶ����Ϣ */
}RRC_MTA_FREQ_INFO_STRU;

/*****************************************************************************
 �ṹ��    : RRC_MTA_LTE_FREQ_INFO_STRU
 �ṹ˵��  : LRRC����MTA��Ƶ����Ϣ

  1.��    ��   : 2015��07��07��
    ��    ��   : y00142674
    �޸�����   : ����, for �ƶ�Ƶ���ռ�
*****************************************************************************/
typedef struct
{
    RRC_MTA_BAND_IND_ENUM_UINT16        enBandInd;                              /* Ƶ��ָʾ */
    VOS_UINT8                           aucRsv[2];                              /* ����λ */
    VOS_UINT32                          ulFreq;                                 /* Ƶ����Ϣ */
}RRC_MTA_LTE_FREQ_INFO_STRU;

/*****************************************************************************
 �ṹ��    : RRC_MTA_GSM_FREQ_LIST_STRU
 �ṹ˵��  : RRC����MTA��GSMƵ���б�

  1.��    ��   : 2015��07��07��
    ��    ��   : y00142674
    �޸�����   : ����, for �ƶ�Ƶ���ռ�
*****************************************************************************/
typedef struct
{
    MTA_RRC_PLMN_ID_STRU                stPlmnId;                               /* ��ѯ����PLMN */
    VOS_UINT16                          usFreqNum;                              /* Ƶ����Ŀ */
    VOS_UINT8                           aucRsv[2];                              /* ����λ */
    RRC_MTA_FREQ_INFO_STRU              astFreqList[RRC_MTA_MAX_GSM_FREQ_NUM];  /* Ƶ���б� */
}RRC_MTA_GSM_FREQ_LIST_STRU;

/*****************************************************************************
 �ṹ��    : RRC_MTA_WCDMA_FREQ_LIST_STRU
 �ṹ˵��  : RRC����MTA��WCDMAƵ���б�

  1.��    ��   : 2015��07��07��
    ��    ��   : y00142674
    �޸�����   : ����, for �ƶ�Ƶ���ռ�
*****************************************************************************/
typedef struct
{
    MTA_RRC_PLMN_ID_STRU                stPlmnId;                               /* ��ѯ����PLMN */
    VOS_UINT16                          usFreqNum;                              /* Ƶ����Ŀ */
    VOS_UINT8                           aucRsv[2];                              /* ����λ */
    RRC_MTA_FREQ_INFO_STRU              astFreqList[RRC_MTA_MAX_WCDMA_FREQ_NUM];  /* Ƶ���б� */
}RRC_MTA_WCDMA_FREQ_LIST_STRU;

/*****************************************************************************
 �ṹ��    : RRC_MTA_LTE_FREQ_LIST_STRU
 �ṹ˵��  : RRC����MTA��LTEƵ���б�

  1.��    ��   : 2015��07��07��
    ��    ��   : y00142674
    �޸�����   : ����, for �ƶ�Ƶ���ռ�
*****************************************************************************/
typedef struct
{
    MTA_RRC_PLMN_ID_STRU                stPlmnId;                               /* ��ѯ����PLMN */
    VOS_UINT16                          usFreqNum;                              /* Ƶ����Ŀ */
    VOS_UINT8                           aucRsv[2];                              /* ����λ */
    RRC_MTA_LTE_FREQ_INFO_STRU          astFreqList[RRC_MTA_MAX_LTE_FREQ_NUM];  /* Ƶ���б� */
}RRC_MTA_LTE_FREQ_LIST_STRU;

/*****************************************************************************
 �ṹ��    : RRC_MTA_GSM_PLMN_FREQ_LIST_STRU
 �ṹ˵��  : GSM����MTA��Ƶ���ѯ���

  1.��    ��   : 2015��07��07��
    ��    ��   : y00142674
    �޸�����   : ����, for �ƶ�Ƶ���ռ�
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucPlmnNum;                              /* ��ѯ����PLMN�ĸ��� */
    VOS_UINT8                           aucRsv[3];                              /* ����λ */
    RRC_MTA_GSM_FREQ_LIST_STRU          astPlmnFreqList[RRC_MTA_MAX_GSM_PLMN_NUM];  /* ��ѯ����Ƶ���б� */
} RRC_MTA_GSM_PLMN_FREQ_LIST_STRU;

/*****************************************************************************
 �ṹ��    : RRC_MTA_WCDMA_PLMN_FREQ_LIST_STRU
 �ṹ˵��  : WCDMA����MTA��Ƶ���ѯ���

  1.��    ��   : 2015��07��07��
    ��    ��   : y00142674
    �޸�����   : ����, for �ƶ�Ƶ���ռ�
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucPlmnNum;                              /* ��ѯ����PLMN�ĸ��� */
    VOS_UINT8                           aucRsv[3];                              /* ����λ */
    RRC_MTA_WCDMA_FREQ_LIST_STRU        astPlmnFreqList[RRC_MTA_MAX_WCDMA_PLMN_NUM];  /* ��ѯ����Ƶ���б� */
} RRC_MTA_WCDMA_PLMN_FREQ_LIST_STRU;

/*****************************************************************************
 �ṹ��    : RRC_MTA_LTE_PLMN_FREQ_LIST_STRU
 �ṹ˵��  : LTE����MTA��Ƶ���ѯ���

  1.��    ��   : 2015��07��07��
    ��    ��   : y00142674
    �޸�����   : ����, for �ƶ�Ƶ���ռ�
*****************************************************************************/
typedef struct
{
    VOS_UINT8                           ucPlmnNum;                              /* ��ѯ����PLMN�ĸ��� */
    VOS_UINT8                           aucRsv[3];                              /* ����λ */
    RRC_MTA_LTE_FREQ_LIST_STRU          astPlmnFreqList[RRC_MTA_MAX_LTE_PLMN_NUM];  /* ��ѯ����Ƶ���б� */
} RRC_MTA_LTE_PLMN_FREQ_LIST_STRU;


/*****************************************************************************
 �ṹ��    : RRC_MTA_PLMN_FREQ_QRY_CNF_STRU
 �ṹ˵��  : RRC����MTA��Ƶ���ѯ��������ֲ�ͬģʽ

  1.��    ��   : 2015��07��07��
    ��    ��   : y00142674
    �޸�����   : ����, for �ƶ�Ƶ���ռ�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    VOS_RATMODE_ENUM_UINT32             enRatType;                              /* ģʽ���� *//* _H2ASN_Replace VOS_UINT32 enRatType; */
    union
    {
        RRC_MTA_GSM_PLMN_FREQ_LIST_STRU     stGsmFreqList;                      /* GSM��Ƶ���б� */
        RRC_MTA_WCDMA_PLMN_FREQ_LIST_STRU   stWcdmaFreqList;                    /* WCDMA��Ƶ���б� */
        RRC_MTA_LTE_PLMN_FREQ_LIST_STRU     stLteFreqList;                      /* LTE��Ƶ���б� */
    }u;
} RRC_MTA_PLMN_FREQ_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_TDS_FREQLOCK_SET_REQ_STRU
 �ṹ˵��  : MTA��TDS�·�����Ƶ��Ϣ�ṹ

  1.��    ��   : 2014��10��21��
    ��    ��   : z00214637
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    PS_BOOL_ENUM_UINT8                  enLockFlg;                              /* PS_TRUE:������PS_FALSE:ȥ���� */
    MTA_RRC_FREQLOCK_TYPE_ENUM_UINT8    ucFreqType;                             /* 1: ��Ƶ,2:Ƶ��+���� */
    VOS_UINT16                          usFreq;                                 /* Ƶ��ֵ */
    VOS_UINT32                          ulSc;                                   /* ���� */
} MTA_TDS_FREQLOCK_SET_REQ_STRU;

/*****************************************************************************
 �ṹ��    : TDS_MTA_FREQLOCK_SET_CNF_STRU
 �ṹ˵��  : TDS��MTA�ص���Ƶ���ý��

  1.��    ��   : 2014��10��21��
    ��    ��   : z00214637
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                                    /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                                       /* MTA_RRC_RESULT_NO_ERROR:��Ƶ�ɹ���MTA_RRC_RESULT_RRC:��Ƶʧ�� */
} TDS_MTA_FREQLOCK_SET_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_LRRC_CLEAR_HISTORY_FREQ_REQ_STRU
 �ṹ˵��  : MTA��LTE AS�·������ʷƵ����Ϣ�ṹ

  1.��    ��   : 2015��9��11��
    ��    ��   : z00161729
    �޸�����   : ֧��LTE CSG��������
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                                         stMsgHeader;               /*_H2ASN_Skip*/
    MTA_LRRC_CLEAR_HISTORY_FREQ_TYPE_ENUM_UINT8             enClearHistoryFreqType;
    VOS_UINT8                                               aucReserved[3];
} MTA_LRRC_CLEAR_HISTORY_FREQ_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_MTA_CLEAR_HISTORY_FREQ_CNF_STRU
 �ṹ˵��  : LRRC��MTA�ظ������ʷƵ����Ϣ�ṹ

  1.��    ��   : 2015��9��11��
     ��    ��   : z00161729
     �޸�����   : ֧��LTE CSG��������
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                  /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;
} LRRC_MTA_CLEAR_HISTORY_FREQ_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_TDRR_FREQLOCK_SET_REQ_STRU
 �ṹ˵��  : MTA��LTE AS�·�����Ƶ��Ϣ�ṹ

  1.��    ��   : 2014��10��21��
    ��    ��   : z00214637
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                            /*_H2ASN_Skip*/
    PS_BOOL_ENUM_UINT8                  enLockFlg;                              /* PS_TRUE:������PS_FALSE:ȥ���� */
    MTA_RRC_FREQLOCK_TYPE_ENUM_UINT8    ucFreqType;                             /* 1: ��Ƶ,2:Ƶ��+����С��ID */
    VOS_UINT16                          usFreq;                                 /* Ƶ��ֵ */
    VOS_UINT32                          ulPhyCellId;                            /* ����С��ID */
} MTA_LRRC_FREQLOCK_SET_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_MTA_FREQLOCK_SET_CNF_STRU
 �ṹ˵��  : LRRC��MTA�ص���Ƶ���ý��

  1.��    ��   : 2014��10��21��
    ��    ��   : z00214637
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;                  /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                     /* MTA_RRC_RESULT_NO_ERROR:��Ƶ�ɹ���MTA_RRC_RESULT_RRC:��Ƶʧ�� */
} LRRC_MTA_FREQLOCK_SET_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_LRRC_MBMS_SERVICE_OPTION_REQ_STRU
 �ṹ˵��  : MTA֪ͨLRRC MBMS�������Բ�������ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    MBMS_SERVICE_OP_ENUM_UINT8          enOption;                               /* 0:ȥʹ�ܣ�1:ʹ�� */
    VOS_UINT8                           aucReserved[3];                         /* ����λ */
} MTA_LRRC_MBMS_SERVICE_OPTION_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_MTA_MBMS_SERVICE_OPTION_CNF_STRU
 �ṹ˵��  : LRRC�ظ�MTA MBMS�������Բ�������ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                               /* ������� */
} LRRC_MTA_MBMS_SERVICE_OPTION_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MBMS_TMGI_STRU
 �ṹ˵��  : TMGI�ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          ulMbmsSerId;                            /* Service ID */
    MTA_RRC_PLMN_ID_STRU                stPlmnId;                               /* PLMN ID */
} MBMS_TMGI_STRU;

/*****************************************************************************
 �ṹ��    : MTA_LRRC_MBMS_SERVICE_STATE_SET_REQ_STRU
 �ṹ˵��  : MTA֪ͨLRRC MBMS����״̬��������ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    MBMS_SERVICE_STATE_SET_ENUM_UINT8   enStateSet;                             /* ״̬���� */
    VOS_UINT8                           aucReserved[3];                         /* ����λ */
    VOS_UINT32                          ulAreaId;                               /* Area ID */
    MBMS_TMGI_STRU                      stTMGI;                                 /* TMGI */
} MTA_LRRC_MBMS_SERVICE_STATE_SET_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_MTA_MBMS_SERVICE_STATE_SET_CNF_STRU
 �ṹ˵��  : LRRC�ظ�MTA MBMS����״̬���ý���ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                               /* ״̬���ý�� */
} LRRC_MTA_MBMS_SERVICE_STATE_SET_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_LRRC_MBMS_AVL_SERVICE_LIST_QRY_REQ_STRU
 �ṹ˵��  : MTA֪ͨLRRC MBMS���÷����б���ѯ����ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    VOS_UINT8                           aucReserved[4];                         /* ����λ */
} MTA_LRRC_MBMS_AVL_SERVICE_LIST_QRY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : MTA_LRRC_MBMS_AVL_SERVICE_STRU
 �ṹ˵��  : MBMS���÷���ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    VOS_UINT32                          bitOpSessionId  : 1;
    VOS_UINT32                          bitSpare        : 31;
    VOS_UINT32                          ulAreaId;                               /* Area ID */
    MBMS_TMGI_STRU                      stTMGI;                                 /* TMGI */
    VOS_UINT32                          ulSessionId;                            /* Session ID */
} MTA_LRRC_MBMS_AVL_SERVICE_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_MTA_MBMS_AVL_SERVICE_LIST_QRY_CNF_STRU
 �ṹ˵��  : LRRC�ظ�MTA MBMS���÷����б���ѯ����ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                                /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                                   /* ״̬���ý�� */
    VOS_UINT32                          ulAvlServiceNum;                            /* ���÷�����,0:��ʾû�п��÷��� */
    MTA_LRRC_MBMS_AVL_SERVICE_STRU      astAvlServices[MBMS_AVL_SERVICE_MAX_NUM];   /* ���÷����б� */
} LRRC_MTA_MBMS_AVL_SERVICE_LIST_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_LRRC_MBMS_PREFERENCE_SET_REQ_STRU
 �ṹ˵��  : MTA֪ͨLRRC MBMS�㲥ģʽ����ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    MBMS_CAST_MODE_ENUM_UINT8           enCastMode;                             /* 0:����,1:�鲥 */
    VOS_UINT8                           aucReserved[3];                         /* ����λ */
} MTA_LRRC_MBMS_PREFERENCE_SET_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_MTA_MBMS_PREFERENCE_SET_CNF_STRU
 �ṹ˵��  : LRRC�ظ�MTA MBMS�㲥ģʽ���ý���ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                                /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                                   /* �㲥ģʽ���ý�� */
} LRRC_MTA_MBMS_PREFERENCE_SET_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_LRRC_SIB16_NETWORK_TIME_QRY_REQ_STRU
 �ṹ˵��  : MTA֪ͨLRRC SIB16����ʱ��Ĳ�ѯ����ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    VOS_UINT8                           aucReserved[4];                         /* ����λ */
} MTA_LRRC_SIB16_NETWORK_TIME_QRY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_MTA_SIB16_NETWORK_TIME_QRY_CNF_STRU
 �ṹ˵��  : LRRC�ظ�MTA SIB16����ʱ��Ĳ�ѯ����ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                                /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                                   /* ��ѯ������� */
    VOS_UINT32                          ulReserved;                                 /* ����λ */
    VOS_UINT64                          ullUTC;                                     /* (0..549755813887) */
} LRRC_MTA_SIB16_NETWORK_TIME_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_LRRC_BSSI_SIGNAL_LEVEL_QRY_REQ_STRU
 �ṹ˵��  : MTA֪ͨLRRC BSSI�ź�ǿ�Ȳ�ѯ����ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    VOS_UINT8                           aucReserved[4];                         /* ����λ */
} MTA_LRRC_BSSI_SIGNAL_LEVEL_QRY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_MTA_BSSI_SIGNAL_LEVEL_QRY_CNF_STRU
 �ṹ˵��  : LRRC�ظ�MTA BSSI�ź�ǿ�Ȳ�ѯ����ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                               /* ��ѯ������� */
    VOS_UINT8                           ucBSSILevel;                            /* BSSI�ź�ǿ��,0xFF:��ʾBSSI�ź�ǿ����Ч */
    VOS_UINT8                           aucReserved[3];                         /* ����λ */
} LRRC_MTA_BSSI_SIGNAL_LEVEL_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_LRRC_NETWORK_INFO_QRY_REQ_STRU
 �ṹ˵��  : MTA֪ͨLRRC ��ѯ������Ϣ����ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    VOS_UINT8                           aucReserved[4];                         /* ����λ */
} MTA_LRRC_NETWORK_INFO_QRY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_MTA_NETWORK_INFO_QRY_CNF_STRU
 �ṹ˵��  : LRRC�ظ�MTA������Ϣ��ѯ����ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                               /* ��ѯ������������û��������Ϣ�����Ҳ����Ϊʧ�� */
    VOS_UINT32                          ulCellId;                               /* С��ID */
} LRRC_MTA_NETWORK_INFO_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_LRRC_EMBMS_STATUS_QRY_REQ_STRU
 �ṹ˵��  : MTA֪ͨLRRC ��ѯeMBMS����״̬����ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    VOS_UINT8                           aucReserved[4];                         /* ����λ */
} MTA_LRRC_EMBMS_STATUS_QRY_REQ_STRU;


/*****************************************************************************
 �ṹ��    : LRRC_MTA_EMBMS_STATUS_QRY_CNF_STRU
 �ṹ˵��  : LRRC�ظ�MTA eMBMS����״̬����ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                               /* ��ѯ������� */
    MBMS_FUNTIONALITY_STATUS_ENUM_UINT8 enStatus;                               /* ����״̬ */
    VOS_UINT8                           aucReserved[3];                         /* ����λ */
} LRRC_MTA_EMBMS_STATUS_QRY_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_LRRC_MBMS_UNSOLICITED_CFG_SET_REQ_STRU
 �ṹ˵��  : MTA֪ͨLRRC ����MBMS�����ϱ���������ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    MBMS_UNSOLICITED_CFG_ENUM_UINT8     enCfg;                                  /* 0:�ر�,1:�� */
    VOS_UINT8                           aucReserved[3];                         /* ����λ */
} MTA_LRRC_MBMS_UNSOLICITED_CFG_SET_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_MTA_MBMS_UNSOLICITED_CFG_SET_CNF_STRU
 �ṹ˵��  : LRRC�ظ�MTA MBMS�����ϱ��������ý���ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                               /* ���ò������ */
} LRRC_MTA_MBMS_UNSOLICITED_CFG_SET_CNF_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_MTA_MBMS_SERVICE_EVENT_IND_STRU
 �ṹ˵��  : LRRC��MTA����MBMS�����¼������ϱ��ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    MBMS_SERVICE_EVENT_ENUM_UINT8       enEvent;                                /* �����¼� */
    VOS_UINT8                           aucReserved[3];                         /* ����λ */
} LRRC_MTA_MBMS_SERVICE_EVENT_IND_STRU;

/*****************************************************************************
 �ṹ��    : MTA_LRRC_COEX_PARA_STRU
 �ṹ˵��  : LTE&WIFI��������ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    MTA_LRRC_COEX_BW_TYPE_ENUM_UINT16           enCoexBWType;
    MTA_LRRC_COEX_CFG_ENUM_UINT16               enCfg;
    VOS_UINT16                                  usTxBegin;
    VOS_UINT16                                  usTxEnd;
    VOS_INT16                                   sTxPower;
    VOS_UINT16                                  usRxBegin;
    VOS_UINT16                                  usRxEnd;
    VOS_UINT16                                  usReserved;                 /* ����λ */
} MTA_LRRC_COEX_PARA_STRU;

/*****************************************************************************
 �ṹ��    : MTA_LRRC_LTE_WIFI_COEX_SET_REQ_STRU
 �ṹ˵��  : MTA֪ͨLRRC ����LTE&WIFI������������ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    VOS_UINT16                          usCoexParaNum;
    VOS_UINT16                          usCoexParaSize;
    VOS_UINT8                           aucCoexPara[4];
} MTA_LRRC_LTE_WIFI_COEX_SET_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_MTA_LTE_WIFI_COEX_SET_CNF_STRU
 �ṹ˵��  : LRRC�ظ�MTA LTE&WIFI�����������ý���ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                               /* ���ý�� */
} LRRC_MTA_LTE_WIFI_COEX_SET_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_LRRC_LOW_POWER_CONSUMPTION_SET_REQ_STRU
 �ṹ˵��  : MTA֪ͨLRRC���õ͹�������ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    VOS_BOOL                            bLowPowerFlg;                           /* VOS_FALSE: Normal;VOS_TRUE: Low Power Consumption */
} MTA_LRRC_LOW_POWER_CONSUMPTION_SET_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_MTA_LOW_POWER_CONSUMPTION_SET_CNF_STRU
 �ṹ˵��  : LRRC�ظ�MTA�͹������ý���ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                               /* ���ò������ */
} LRRC_MTA_LOW_POWER_CONSUMPTION_SET_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_LRRC_INTEREST_LIST_SET_REQ_STRU
 �ṹ˵��  : MTA֪ͨLRRC����Interest����ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                                    /*_H2ASN_Skip*/
    VOS_UINT32                          aulFreqList[MTA_LRRC_INTEREST_FREQ_MAX_NUM];    /* Ƶ���б� */
    VOS_BOOL                            bMbmsPriority;                                  /* VOS_FALSE: Normal;VOS_TRUE: Low Power Consumption */
} MTA_LRRC_INTEREST_LIST_SET_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_MTA_INTEREST_LIST_SET_CNF_STRU
 �ṹ˵��  : LRRC�ظ�MTA Interest���ý���ṹ��

  1.��    ��   : 2015��5��22��
    ��    ��   : w00316404
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                                    /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                                       /* ���ò������ */
} LRRC_MTA_INTEREST_LIST_SET_CNF_STRU;
/*******************************************************************************
 �ṹ��    : MTA_LRRC_SET_FR_REQ_STRU
 �ṹ˵��  : ����LRRC����FR����
 1.��    ��   : 2015��05��25��
   ��    ��   : z00301431
   �޸�����   : FR��̬��������
*******************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                             stMsgHeader;                    /*_H2ASN_Skip*/

    PS_BOOL_ENUM_UINT8                          enActFrFlag;                    /* ����FR��־��0:������  1:���� */
    VOS_UINT8                                   aucRsv[3];                      /* ����λ */
}MTA_LRRC_SET_FR_REQ_STRU;

/*******************************************************************************
 �ṹ��    : LRRC_MTA_SET_FR_CNF_STRU
 �ṹ˵��  : LRRC�ظ���FR������Ӧ
 1.��    ��   : 2015��05��25��
   ��    ��   : z00301431
   �޸�����   : FR��̬��������
*******************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                             stMsgHeader;                    /*_H2ASN_Skip*/

    MTA_RRC_RESULT_ENUM_UINT32                  enRslt;                         /* FR���ü���� */
}LRRC_MTA_SET_FR_CNF_STRU;

/*****************************************************************************
 �ṹ��    : MTA_LRRC_TRANSMODE_QRY_REQ_STRU
 �ṹ˵��  : MTA��LRRC��ѯ����ģʽ����ID_MTA_LRRC_TRANSMODE_QRY_REQ�ṹ��

  1.��    ��   : 2015��7��30��
    ��    ��   : lwx277467
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    VOS_UINT8                           aucReserved[4];                         /* ����λ */
} MTA_LRRC_TRANSMODE_QRY_REQ_STRU;

/*****************************************************************************
 �ṹ��    : LRRC_MTA_TRANSMODE_QRY_CNF_STRU
 �ṹ˵��  : LRR�ظ�MTA����ģʽ��ѯ���ID_LRRC_MTA_TRANSMODE_QRY_CNF�ṹ��

  1.��    ��   : 2015��7��30��
    ��    ��   : lwx277467
    �޸�����   : ����
*****************************************************************************/
typedef struct
{
    PS_MSG_HEADER_STRU                  stMsgHeader;                            /*_H2ASN_Skip*/
    MTA_RRC_RESULT_ENUM_UINT32          enResult;                               /*��ѯ�������*/
    VOS_UINT8                           ucTransMode;                            /*����ģʽ*/
    VOS_UINT8                           aucReserved[3];                         /* ����λ */
} LRRC_MTA_TRANSMODE_QRY_CNF_STRU;

/************���߷��书��tx power (4G) begin*********************************/
/*****************************************************************************
 �ṹ��    : TX_PWR_INFO_STRU
 �ṹ˵��  : TXPower ���ݽṹ��

  1.��    ��   : 2015��5��21��
    ��    ��   : l00277962
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    VOS_INT16     sPuschPwr;
    VOS_INT16     sPucchPwr;
    VOS_INT16     sSrsPwr;
    VOS_INT16     sPrachPwr;
}TX_PWR_INFO_STRU;
/*****************************************************************************
 �ṹ��    : MTA_LRRC_TX_PWR_QRY_REQ
 �ṹ˵��  : MTA��LRRC��ѯTXPower

  1.��    ��   : 2015��5��21��
    ��    ��   : l00277962
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;
    VOS_UINT8                           aucReserved[4];
}MTA_LRRC_TX_PWR_QRY_REQ;
/*****************************************************************************
 �ṹ��    : TX_PWR_INFO_STRU
 �ṹ˵��  : LRRC��MTA�ظ�TXPower

  1.��    ��   : 2015��5��21��
    ��    ��   : l00277962
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;
    MTA_RRC_RESULT_ENUM_UINT32          enResult;
    TX_PWR_INFO_STRU                    stTxPwrInfo;
}LRRC_MTA_TX_PWR_QRY_CNF;
/************���߷��书��tx power (4G) end***********************************/

/************MCS �����е��ƽ����ʽ *****************************************/
/*****************************************************************************
 �ṹ��    : TX_PWR_INFO_STRU
 �ṹ˵��  : MCS ���ݽṹ��

  1.��    ��   : 2015��5��21��
    ��    ��   : l00277962
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    VOS_UINT16     usUlMcs;
    VOS_UINT16     usDlMcs[2];
    VOS_UINT8      aucReserved[2];
}MCS_INFO_STRU;
/*****************************************************************************
 �ṹ��    : TX_PWR_INFO_STRU
 �ṹ˵��  : MTA��LRRC��ѯMCS

  1.��    ��   : 2015��5��21��
    ��    ��   : l00277962
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;
    VOS_UINT8                           aucReserved[4];
}MTA_LRRC_MCS_QRY_REQ;
/*****************************************************************************
 �ṹ��    : TX_PWR_INFO_STRU
 �ṹ˵��  : LRRC��MTA�ظ�MCS

  1.��    ��   : 2015��5��21��
    ��    ��   : l00277962
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;
    MTA_RRC_RESULT_ENUM_UINT32          enResult;
    MCS_INFO_STRU                       stMCSInfo;
}LRRC_MTA_MCS_QRY_CNF;
/****************************************************************************/

/************EARFCN**********************************************************/
/*****************************************************************************
 �ṹ��    : TX_PWR_INFO_STRU
 �ṹ˵��  : EARFCN ���ݽṹ��

  1.��    ��   : 2015��5��21��
    ��    ��   : l00277962
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    VOS_UINT16    usUlEarfcn;
    VOS_UINT16    usDlEarfcn;
}EARFCN_INFO_STRU;
/*****************************************************************************
 �ṹ��    : TX_PWR_INFO_STRU
 �ṹ˵��  : MTA��LRRC��ѯEARFCN

  1.��    ��   : 2015��5��21��
    ��    ��   : l00277962
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;
    VOS_UINT8                           aucReserved[4];
}MTA_LRRC_EARFCN_QRY_REQ;
/*****************************************************************************
 �ṹ��    : TX_PWR_INFO_STRU
 �ṹ˵��  : LRRC��MTA�ظ�EARFCN

  1.��    ��   : 2015��5��21��
    ��    ��   : l00277962
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;
    MTA_RRC_RESULT_ENUM_UINT32          enResult;
    EARFCN_INFO_STRU                    stEarfcnInfo;
}LRRC_MTA_EARFCN_QRY_CNF;
/****************************************************************************/

/************TDDʱ϶���*****************************************************/
/*****************************************************************************
 �ṹ��    : TX_PWR_INFO_STRU
 �ṹ˵��  : TDDʱ϶������ݽṹ��

  1.��    ��   : 2015��5��21��
    ��    ��   : l00277962
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    VOS_UINT8   ucSubframeAssign;
    VOS_UINT8   ucSubframePatterns;
}LFRAMERATIO_INFO_STRU;
/*****************************************************************************
 �ṹ��    : TX_PWR_INFO_STRU
 �ṹ˵��  : MTA��LRRC��ѯTDDʱ϶���

  1.��    ��   : 2015��5��21��
    ��    ��   : l00277962
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;
    VOS_UINT8                           aucReserved[4];
}MTA_LRRC_LFRAMERATIO_QRY_REQ;
/*****************************************************************************
 �ṹ��    : TX_PWR_INFO_STRU
 �ṹ˵��  : LRRC��MTA�ظ�TDDʱ϶���

  1.��    ��   : 2015��5��21��
    ��    ��   : l00277962
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;
    MTA_RRC_RESULT_ENUM_UINT32          enResult;
    LFRAMERATIO_INFO_STRU               stTddConfig;
}LRRC_MTA_LFRAMERATIO_QRY_CNF;
/****************************************************************************/

/************RRC status******************************************************/
/*****************************************************************************
 �ṹ��    : TX_PWR_INFO_STRU
 �ṹ˵��  : MTA��LRRC��ѯRRC status

  1.��    ��   : 2015��5��21��
    ��    ��   : l00277962
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;
    VOS_UINT8                           aucReserved[4];
}MTA_LRRC_RRC_STATUS_QRY_REQ;
/*****************************************************************************
 �ṹ��    : TX_PWR_INFO_STRU
 �ṹ˵��  : LRRC��MTA�ظ�RRC status

  1.��    ��   : 2015��5��21��
    ��    ��   : l00277962
    �޸�����   : �½�
*****************************************************************************/
typedef struct
{
    MSG_HEADER_STRU                     stMsgHeader;
    MTA_RRC_RESULT_ENUM_UINT32          enResult;
    VOS_UINT8                           ulRRCStatus;
}LRRC_MTA_RRC_STATUS_QRY_CNF;
/****************************************************************************/

/*****************************************************************************
  8 UNION����
*****************************************************************************/

/*****************************************************************************
  9 OTHERS����
*****************************************************************************/

/*****************************************************************************
  H2ASN������Ϣ�ṹ����
*****************************************************************************/
typedef struct
{
    MTA_RRC_MSG_TYPE_ENUM_UINT32        enMsgID;                                /*_H2ASN_MsgChoice_Export MTA_RRC_MSG_TYPE_ENUM_UINT32*/
    VOS_UINT8                           aucMsgBlock[4];
    /***************************************************************************
        _H2ASN_MsgChoice_When_Comment          MTA_RRC_MSG_TYPE_ENUM_UINT32
    ****************************************************************************/
}MTA_RRC_MSG_DATA;
/*_H2ASN_Length UINT32*/

typedef struct
{
    VOS_MSG_HEADER
    MTA_RRC_MSG_DATA                    stMsgData;
}MtaRrcInterface_MSG;

/*****************************************************************************
  10 ��������
*****************************************************************************/
#if (FEATURE_ON == FEATURE_UE_MODE_CDMA)
extern VOS_UINT32 CAS_GetpEsnByMeid(VOS_UINT8 *pucMeid, VOS_UINT32 *pulEsn);
#endif

#if ((VOS_OS_VER == VOS_WIN32) || (VOS_OS_VER == VOS_NUCLEUS))
#pragma pack()
#else
#pragma pack(0)
#endif




#ifdef __cplusplus
    #if __cplusplus
        }
    #endif
#endif

#endif /* end of MtaRrcInterface.h */
