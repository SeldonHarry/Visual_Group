/**
 ******************************************************************************
 * @file    minipc_comm.cpp/h
 * @brief   MiniPC communication(UART). MiniPC通信(UART)
 * @author  Spoon Guan
 ******************************************************************************
 * @protocol 通信协议
 * 1. UART config 串口配置
 *    波特率115200，8位数据位，1位停止位，无硬件流控，无校验位
 * 2. frame format 数据帧格式
 *    header(3-byte)+data(n-byte)+tail(2-byte)
 *    header: SOF(1-byte, 0x23)+pack_id(1-byte)+data_len(1-byte,=n)
 *    data: n-byte
 *    tail: CRC16(2-byte)
 ******************************************************************************
 * Copyright (c) 2023 Team JiaoLong-SJTU
 * All rights reserved.
 ******************************************************************************
 */

#ifndef MINIPC_COMM_HPP
#define MINIPC_COMM_HPP

// 编译完成后去掉相对路径引用
#include "utils/connect.h"
#include "utils/fifo_buffer.h"
#include "minipc_protocol.hpp"

#define MINIPC_TX_BUF_SIZE MINIPC_COMM_MAX_SIZE
#define MINIPC_RX_BUF_SIZE MINIPC_COMM_MAX_SIZE

// Mini PC communication class
// 电控视觉通信类
class MiniPCComm {
public:
    MiniPCComm();

    // Handle mode, check connection 处理通信模式，检查连接状态
    void handle(void);
    // Handle data transmit 处理发送数据
    void txMsgHandle(MiniPCCommMsgStream msg_stream, MiniPCCommMsgType msg_type);

    // Data receive callback 接收中断
    void rxCallback(void);

private:
    // Append data length & data to tx buffer
    // 添加数据段长度和数据到发送缓冲区
    template<typename T>
    void appendTxData(const T& data) {
        tx_.frame.data_len = sizeof(data);
        memcpy(tx_.buf + tx_.pack_size, &tx_.frame.data_len, sizeof(tx_.frame.data_len));
        tx_.pack_size += sizeof(tx_.frame.data_len);
        memcpy(tx_.buf + tx_.pack_size, &data, sizeof(data));
        tx_.pack_size += sizeof(data);
    }

public:
    MiniPCMode mode_;

    Connect general_connect_;
    GeneralMsg_PC2Board_t general_pc2board_msg_;
    GeneralMsg_Board2PC_t general_board2pc_msg_;

    Connect aim_shoot_connect_;
    AimShootMsg_PC2Board_t aim_shoot_pc2board_msg_; // 只有这个是会被弹道结算接受的
    AimShootMsg_Board2PC_t aim_shoot_board2pc_msg_;

    Connect navigation_connect_;
    NavigationMsg_PC2Board_t navigation_pc2board_msg_;
    NavigationMsg_Board2PC_t navigation_board2pc_msg_;

    Connect game_status_connect_;
    GameStatusMsg_PC2Board_t game_status_pc2board_msg_;
    GameStatusMsg_Board2PC_t game_status_board2pc_msg_;

    // UnpackError连续触发的次数
    // 最大为1000
    unsigned int continus_error_cnt;

    struct Tx_t {
        uint8_t buf[MINIPC_TX_BUF_SIZE];
        MiniPCCommFrame_t frame;
        uint32_t pack_size;
    } tx_;

    struct Rx_t {
        Rx_t(void): fifo(buf, MINIPC_RX_BUF_SIZE) {}

        uint8_t byte[1];
        uint8_t buf[MINIPC_RX_BUF_SIZE];
        FIFOBuffer fifo; // here is the member FIFO
        MiniPCCommFrame_t frame;
        uint32_t expect_size;
    } rx_;

    enum MessageUnpackStep_e {
        WAIT,
        PACK_ID,
        DATA_LEN,
        DATA,
        CRC16,
        READ_DATA,
    } unpack_step_;

    enum UnpackError_e {
        NO_ERROR,
        ID_UNDEFINED,
        DATA_LEN_OUTRANGE,
        CRC_FAIL,
    } unpack_error_;

private:
    // handle communication error
    void errorHandler(const UnpackError_e& error_type) {
        if (error_type == NO_ERROR) {
            if (continus_error_cnt < 1000)
                continus_error_cnt++;
        }
        continus_error_cnt = 0;
    }
};

#endif // MINIPC_COMM_H