#ifndef modbus_h
#define modbus_h

/* Modbus Function codes */
#define MODBUS_FC_READ_COIL_STATUS          0x01    // 1
#define MODBUS_FC_READ_INPUT_STATUS         0x02    // 1
#define MODBUS_FC_READ_HOLDING_REGISTERS    0x03    // 16
#define MODBUS_FC_READ_INPUT_REGISTERS      0x04    // 16
#define MODBUS_FC_WRITE_SINGLE_COIL         0x05    // 1
#define MODBUS_FC_WRITE_SINGLE_REGISTER     0x06    // 16
#define MODBUS_FC_READ_EXCEPTION_STATUS     0x07    // Diag
#define MODBUS_FC_WRITE_MULTIPLE_COILS      0x0F    // 1
#define MODBUS_FC_WRITE_HOLDING_REGISTERS   0x10    // 16
#define MODBUS_FC_REPORT_SLAVE_ID           0x11    // Diag
#define MODBUS_FC_RD_WR_MULTIPLE_REGISTERS  0x17    // 16

/* Modbus Protocol exceptions */
#define MODBUS_NO_ERROR         0x00
#define MODBUS_ILLEGAL_FUNCTION        -0x01
#define MODBUS_ILLEGAL_DATA_ADDRESS    -0x02
#define MODBUS_ILLEGAL_DATA_VALUE      -0x03
#define MODBUS_SLAVE_DEVICE_FAILURE    -0x04
#define MODBUS_SERVER_FAILURE          -0x04
#define MODBUS_ACKNOWLEDGE             -0x05
#define MODBUS_SLAVE_DEVICE_BUSY       -0x06
#define MODBUS_SERVER_BUSY             -0x06
#define MODBUS_NEGATIVE_ACKNOWLEDGE    -0x07
#define MODBUS_MEMORY_PARITY_ERROR     -0x08
#define MODBUS_GATEWAY_PROBLEM_PATH    -0x0A
#define MODBUS_GATEWAY_PROBLEM_TARGET  -0x0B


struct s_modbusPDU {
  byte function;
  byte start_addr_hi;
  byte start_addr_lo;
  byte num_regs_hi;
  byte num_regs_lo;
};

class Modbus
{
  private:

  public:
    void Init(void);

};

#endif
