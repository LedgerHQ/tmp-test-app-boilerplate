/* @BANNER@ */

#ifndef USBD_LEDGER_CDC_H
#define USBD_LEDGER_CDC_H

/* Includes ------------------------------------------------------------------*/
#include <stdint.h>
#include "usbd_def.h"
#include "usbd_ledger_types.h"
#include "ledger_protocol.h"

/* Exported enumerations -----------------------------------------------------*/

/* Exported defines   --------------------------------------------------------*/

/* Exported types, structures, unions ----------------------------------------*/

/* Exported macros------------------------------------------------------------*/

/* Exported variables --------------------------------------------------------*/
extern const usbd_class_info_t     USBD_LEDGER_CDC_Control_class_info;
extern const usbd_class_info_t     USBD_LEDGER_CDC_Data_class_info;

/* Exported functions prototypes--------------------------------------------- */
uint8_t USBD_LEDGER_CDC_init        (USBD_HandleTypeDef *pdev, void* cookie);
uint8_t USBD_LEDGER_CDC_cmd_init    (USBD_HandleTypeDef *pdev, void* cookie);
uint8_t USBD_LEDGER_CDC_de_init     (USBD_HandleTypeDef *pdev, void* cookie);
uint8_t USBD_LEDGER_CDC_setup       (USBD_HandleTypeDef *pdev, void* cookie,
                                     USBD_SetupReqTypedef *req);
uint8_t USBD_LEDGER_CDC_ep0_rx_ready(USBD_HandleTypeDef *pdev, void* cookie);
uint8_t USBD_LEDGER_CDC_data_in     (USBD_HandleTypeDef *pdev, void* cookie, uint8_t ep_num);
uint8_t USBD_LEDGER_CDC_data_out    (USBD_HandleTypeDef *pdev, void* cookie, uint8_t ep_num,
                                     uint8_t* packet, uint16_t packet_length);

uint8_t USBD_LEDGER_CDC_send_packet (USBD_HandleTypeDef *pdev, void* cookie,
                                     uint8_t* packet, uint16_t packet_length,
                                     uint32_t timeout_ms);

uint8_t *USBD_LEDGER_CDC_get_bos_desc(USBD_SpeedTypeDef speed, uint16_t *length);

#endif // USBD_LEDGER_CDC_H

