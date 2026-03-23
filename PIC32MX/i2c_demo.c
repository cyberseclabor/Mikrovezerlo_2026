#include <xc.h>
#include <sys/attribs.h>

#define SYS_FREQ 80000000L
#define PB_CLK   40000000L

#define I2C_BAUD 100000
#define SLAVE_ADDR 0x50

void I2C1_Init(void);
void I2C1_Start(void);
void I2C1_Stop(void);
void I2C1_SendByte(unsigned char data);
void I2C1_Wait(void);

int main(void)
{
    // I2C inicializálás
    I2C1_Init();

    while(1)
    {
        /*
        I2C1_Start();

        // Slave cím + Write bit (0)
        I2C1_SendByte((SLAVE_ADDR << 1) | 0);

        // Küldendő adat
        I2C1_SendByte(0xA5);

        I2C1_Stop();
         */
        
        // másik megoldás
        // Írunk 0xA5 értéket a 0x10 regiszterbe
        I2C1_WriteRegister(SLAVE_ADDR, 0x10, 0xA5);

        // Kis késleltetés
        for(volatile int i = 0; i < 100000; i++);
    }
}

void I2C1_Init(void)
{
    I2C1CON = 0;  // Modul reset

    // Baud rate beállítás
    I2C1BRG = ((PB_CLK / (2 * I2C_BAUD)) - 2);

    I2C1CONbits.ON = 1; // I2C bekapcsolása
}

void I2C1_Wait(void)
{
    while(I2C1CON & 0x1F); // művelet folyamatban
    while(I2C1STATbits.TRSTAT); // adás folyamatban
}

void I2C1_Start(void)
{
    I2C1_Wait();
    I2C1CONbits.SEN = 1;
    while(I2C1CONbits.SEN);
}

void I2C1_Stop(void)
{
    I2C1_Wait();
    I2C1CONbits.PEN = 1;
    while(I2C1CONbits.PEN);
}

void I2C1_SendByte(unsigned char data)
{
    I2C1_Wait();
    I2C1TRN = data;

    while(I2C1STATbits.TRSTAT); // várakozás

    // ACK ellen?rzés (opcionális)
    if(I2C1STATbits.ACKSTAT)
    {
        // nincs ACK ? hiba
    }
}

void I2C1_WriteRegister(unsigned char slaveAddr,
                        unsigned char regAddr,
                        unsigned char data)
{
    I2C1_Start();

    // Slave cím + write
    I2C1_SendByte((slaveAddr << 1) | 0);

    // Regiszter cím
    I2C1_SendByte(regAddr);

    // Adat
    I2C1_SendByte(data);

    I2C1_Stop();
}

void I2C1_WriteMulti(unsigned char slaveAddr,
                     unsigned char regAddr,
                     unsigned char *data,
                     int length)
{
    I2C1_Start();

    I2C1_SendByte((slaveAddr << 1) | 0);
    I2C1_SendByte(regAddr);

    for(int i = 0; i < length; i++)
    {
        I2C1_SendByte(data[i]);
    }

    I2C1_Stop();
}
