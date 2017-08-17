#ifndef __DEVCMD_H__
#define __DEVCMD_H__

#include <stdint.h>

typedef union {
	struct {
		uint8_t head;
		uint8_t len;
		uint16_t seq;
		uint8_t data[0xFF - 4];
	}p;
	uint8_t packetMem[0xFF];
} Packet_t;

#define PACK_DATA_CNT (0xFF - 4)

typedef enum CMD_HEAD{
	CMD_UNKNOWN,

	// from PC -> MCU
	CMD_GETSTATE,
	CMD_GETADC_FREQ,
	CMD_GETDAC_FREQ,
	CMD_GET_DATA,
	CMD_GET_FILEHASH,
	CMD_START,
	CMD_STOP,
	CMD_CLEAN_FLASH,
	CMD_START_CALIB,

	CMD_SETSTATE,
	CMD_SETADC_FREQ,	
	CMD_SETDAC_FREQ,	
	CMD_LOAD_DATA,
	CMD_SET_FILEHASH,

	// from MCU -> PC
	CMD_GETSTATE_ACK,
	CMD_GETADC_FREQ_ACK,
	CMD_GETDAC_FREQ_ACK,
	CMD_GET_DATA_ACK,
	CMD_GET_FILEHASH_ACK,
	CMD_START_ACK,
	CMD_STOP_ACK,
	CMD_CLEAN_FLASH_ACK,
	CMD_START_CALIB_ACK

};

#define MIN_CMD_LEN				4
#define MIN_CMD_LEN_1U8			(MIN_CMD_LEN + 1)
#define MIN_CMD_LEN_1U32		(MIN_CMD_LEN + 4)

void cmdGetDeviceState(void);
void cmdGetAdcFreq(void);
void cmdGetDacFreq(void);
void cmdGetDacFreq(void);
void cmdGetFileHash(void);
void cmdCleanFlash(void);
void cmdGetAdcData(void);
void cmdStart(uint8_t mode = 0);
void cmdStop(void);
void cmdStartCalib(uint8_t mode = 0);
void cmdLoadData(const uint8_t *Data, size_t dataLen);
void cmdLoadData(const uint8_t *Data, size_t dataLen);

void cmdSetDacFreq(uint32_t DAC_FREQ);
void cmdSetAdcFreq(uint32_t ADC_FREQ);
void cmdSetFileHash(const uint8_t *hashData, int hashLen);
void cmdSetState(uint8_t ledState);


#endif
