#include <driverlib.h>


const eUSCI_UART_Config uartConfig =
{
 EUSCI_A_UART_CLOCKSOURCE_SMCLK,
 13, //
 0,
 37,
 EUSCI_A_UART_NO_PARITY,
 EUSCI_A_UART_LSB_FIRST,
 EUSCI_A_UART_ONE_STOP_BIT,
 EUSCI_A_UART_MODE,
 EUSCI_A_UART_OVERSAMPLING_BAUDRATE_GENERATION
};






void transmit(char *str);



void main(void)
{
    WDT_A_holdTimer();
    MAP_CS_initClockSignal(CS_ACLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    GPIO_setAsPeripheralModuleFunctionInputPin(GPIO_PORT_P1, GPIO_PIN2|GPIO_PIN3, GPIO_PRIMARY_MODULE_FUNCTION);

    CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_12);

    UART_initModule(EUSCI_A0_BASE, &uartConfig);
    UART_enableModule(EUSCI_A0_BASE);


    transmit("Hello World\r\n");

    PCM_setPowerState(PCM_LPM0_LDO_VCORE0);
}

void transmit(char *str)
{
    while(*str != 0){
        UART_transmitData(EUSCI_A0_BASE, *str++);}
}


