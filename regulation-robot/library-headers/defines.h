
#ifndef DEFINES_H
#define DEFINES_H

typedef union {
    struct {
        unsigned recepEmit:1;
        unsigned enTransfert:1;
        unsigned enAck:1;
        unsigned Counter:8;
        unsigned memPointer:4;
        unsigned courrier:1;
        unsigned chks:16;
    };
} flags_spi;

union float_spi
{
   int b[2];
   float fpval;
};

#define MAX_WORD_COM 10
#define CODE_ACK 0x55
#define CODE_NACK 204

#endif
