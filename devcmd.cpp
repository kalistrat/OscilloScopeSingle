#include <string.h>
#include "devcmd.h"
#include "hdlc.h"
static uint8_t seqIdx=0;

//-----------------------------------------------------------------------------
void cmdGetDeviceState(void)
{
	Packet_t t;
	t.p.head = CMD_GETSTATE;
	t.p.seq = seqIdx++;
	t.p.len = MIN_CMD_LEN;
	hdlc_tx_frame(t.packetMem, t.p.len);
}

//-----------------------------------------------------------------------------
void cmdGetAdcFreq(void)
{
	Packet_t t;
	t.p.head = CMD_GETADC_FREQ;
	t.p.seq = seqIdx++;
	t.p.len = MIN_CMD_LEN;
	hdlc_tx_frame(t.packetMem, t.p.len);
}

//-----------------------------------------------------------------------------
void cmdGetDacFreq(void)
{
	Packet_t t;
	t.p.head = CMD_GETDAC_FREQ;
	t.p.seq = seqIdx++;
	t.p.len = MIN_CMD_LEN;
	hdlc_tx_frame(t.packetMem, t.p.len);
}

//-----------------------------------------------------------------------------
void cmdGetFileHash(void)
{
	Packet_t t;
	t.p.head = CMD_GET_FILEHASH;
	t.p.seq = seqIdx++;
	t.p.len = MIN_CMD_LEN;
	hdlc_tx_frame(t.packetMem, t.p.len);
}

//-----------------------------------------------------------------------------
void cmdCleanFlash(void)
{
	Packet_t t;
	t.p.head = CMD_CLEAN_FLASH;
	t.p.seq = seqIdx++;
	t.p.len = MIN_CMD_LEN;
	hdlc_tx_frame(t.packetMem, t.p.len);
}

//-----------------------------------------------------------------------------
void cmdStart(uint8_t mode)
{
	Packet_t t;
	t.p.head = CMD_START;
	t.p.seq = seqIdx++;
	t.p.len = MIN_CMD_LEN_1U8;
	*((uint8_t*)&t.p.data[0]) = mode;
	hdlc_tx_frame(t.packetMem, t.p.len);
}

//-----------------------------------------------------------------------------
void cmdStop(void)
{
	Packet_t t;
	t.p.head = CMD_STOP;
	t.p.seq = seqIdx++;
	t.p.len = MIN_CMD_LEN;
	hdlc_tx_frame(t.packetMem, t.p.len);
}

//-----------------------------------------------------------------------------
void cmdStartCalib(uint8_t mode)
{
	Packet_t t;
	t.p.head = CMD_START_CALIB;
	t.p.seq = seqIdx++;
	t.p.len = MIN_CMD_LEN_1U8;
	*((uint8_t*)&t.p.data[0]) = mode;
	hdlc_tx_frame(t.packetMem, t.p.len);
}

//-----------------------------------------------------------------------------
void cmdGetAdcData(void)
{
	Packet_t t;
	t.p.head = CMD_GET_DATA;
	t.p.seq = seqIdx++;
	t.p.len = MIN_CMD_LEN;
	hdlc_tx_frame(t.packetMem, t.p.len);
}

//-----------------------------------------------------------------------------
//#define MAX_DATAPACK_LEN	128
void cmdLoadData(const uint8_t *Data, size_t dataLen)
{
	// TODO: debug
	const uint8_t *dataPtr = Data;
	const uint8_t *dataPtrEnd = Data + dataLen;
	Packet_t t;
	size_t packCnt;
	uint8_t *dPtr, *dPtrEnd;

	uint32_t dataOffset;
	if (dataLen < PACK_DATA_CNT){
		packCnt = 1;
	}
	else if (dataLen % PACK_DATA_CNT == 0){
		packCnt = dataLen / PACK_DATA_CNT;
	}
	else {
		packCnt = dataLen / PACK_DATA_CNT + 1;
	}

	dataOffset = 0;
	for (size_t pI = 0; pI < packCnt; pI++){
		memset(&t, 0, sizeof(Packet_t));
		dPtr = t.p.data;
		dPtrEnd = t.p.data + PACK_DATA_CNT;
		t.p.head = CMD_LOAD_DATA;
		t.p.seq = seqIdx++;
		t.p.len = MIN_CMD_LEN;
		*((uint32_t*)&t.p.data[0]) = dataOffset;	t.p.len += 4;	dPtr += 4;

		while ((dataPtr != dataPtrEnd) && (dPtr != dPtrEnd)) {
			*dPtr++ = *dataPtr++;
			t.p.len++;
		}
		hdlc_tx_frame(t.packetMem, t.p.len);
		dataOffset += (t.p.len - MIN_CMD_LEN - 4);
	}
}

//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
void cmdSetDacFreq(uint32_t DAC_FREQ)
{
	Packet_t t;
	t.p.head = CMD_SETDAC_FREQ;
	t.p.seq = seqIdx++;
	t.p.len = MIN_CMD_LEN_1U32;
	*((uint32_t*)&t.p.data[0]) = DAC_FREQ;
	hdlc_tx_frame(t.packetMem, t.p.len);
}

//-----------------------------------------------------------------------------
void cmdSetAdcFreq(uint32_t ADC_FREQ)
{
	Packet_t t;
	t.p.head = CMD_SETADC_FREQ;
	t.p.seq = seqIdx++;
	t.p.len = MIN_CMD_LEN_1U32;
	*((uint32_t*)&t.p.data[0]) = ADC_FREQ;
	hdlc_tx_frame(t.packetMem, t.p.len);
}

//-----------------------------------------------------------------------------
void cmdSetFileHash(const uint8_t *hashData, int hashLen)
{
	// TODO: think about hash data (fileDate^fileLen^...  etc)
	const uint8_t *hashPtr = hashData;
	Packet_t t;
	uint8_t *dptr = t.p.data;
	int i;
	t.p.head = CMD_SET_FILEHASH;
	t.p.seq = seqIdx++;
	for (i = 0, t.p.len = MIN_CMD_LEN; i < hashLen; i++, t.p.len++)
		*dptr++ = *hashPtr++;
	hdlc_tx_frame(t.packetMem, t.p.len);
}

//-----------------------------------------------------------------------------
void cmdSetState(uint8_t ledState)
{
	// TODO: think about state format
	Packet_t t;
	t.p.head = CMD_SETADC_FREQ;
	t.p.seq = seqIdx++;
	t.p.len = MIN_CMD_LEN_1U8;
	*((uint8_t*)&t.p.data[0]) = ledState;
	hdlc_tx_frame(t.packetMem, t.p.len);
}

//-----------------------------------------------------------------------------
