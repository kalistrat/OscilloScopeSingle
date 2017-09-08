#include <iostream>
#include <QApplication>
#include "mainwindow.h"
#include "hdlc.h"
#include "devcmd.h"
#include <stdio.h>
#include <vector>
#include "crc16_ccitt.h"

void hdlc_put_char(uint8_t data);
void hdlc_on_rx_frame(const uint8_t *buffer, uint16_t bytes_received);
std::vector<uint8_t>TxData;
static uint16_t errHead = 0, errLen = 0;

int main(int argc, char *argv[]) {
    std::cout << QT_VERSION_STR << std::endl;
    QApplication app(argc, argv);
    MainWindow md;
    md.show();

    crc16_ccitt_init();
    hdlc_init(hdlc_put_char, hdlc_on_rx_frame);

    return app.exec();
}

void hdlc_put_char(uint8_t data)
{
    TxData.push_back(data);
}

//-----------------------------------------------------------------------------
void hdlc_on_rx_frame(const uint8_t *buffer, uint16_t bytes_received)
{
    Packet_t t;
    uint32_t ADC_FREQ, DAC_FREQ;
    uint8_t fileHash[10];
    uint8_t btnState, ledState, dacProgress, crcErrCnt, headErrCnt, lenErrCnt;
    uint8_t *dPtr;
    memcpy(&t.packetMem, buffer, bytes_received);
    if (t.p.len != bytes_received){
        errLen++;
        return;
    }

    switch (buffer[0]){
        case CMD_GETSTATE_ACK:
            printf("CMD_GETSTATE_ACK\n");
            dPtr = t.p.data;
            btnState = *dPtr++;
            ledState = *dPtr++;
            dacProgress = *dPtr++;
            crcErrCnt = *dPtr++;
            headErrCnt = *dPtr++;
            lenErrCnt = *dPtr++;
            break;
        case CMD_GETADC_FREQ_ACK:
            ADC_FREQ = *(uint32_t*)t.p.data;
            printf("CMD_GETADC_FREQ_ACK %i\n", ADC_FREQ);
            break;
        case CMD_GETDAC_FREQ_ACK:
            DAC_FREQ = *(uint32_t*)t.p.data;
            printf("CMD_GETDAC_FREQ_ACK %i\n", DAC_FREQ);
            break;
        case CMD_GET_DATA_ACK:
            printf("CMD_GET_DATA_ACK\n");
            break;
        case CMD_GET_FILEHASH_ACK:
            printf("CMD_GET_FILEHASH_ACK\n");
            memcpy(fileHash, t.p.data, t.p.len - 4);
            break;
        case CMD_START_ACK:
            printf("START OK\n");
            break;
        case CMD_STOP_ACK:
            printf("STOP OK\n");
            break;
        case CMD_CLEAN_FLASH_ACK:
            printf("CMD_CLEAN_FLASH OK\n");
            break;
        case CMD_START_CALIB_ACK:
            // TODO: think
            printf("CMD_START_CALIB_ACK\n");
            break;
        default:
            errHead++;
            break;
    }
}