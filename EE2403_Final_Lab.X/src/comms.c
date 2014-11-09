

#include <stdio.h>
#include "../inc/comms.h"


//<editor-fold defaultstate="collapsed" desc="UART Setup">

/*
 * Uncomment InvertBits to invert the bits to Active High
 */
//#define InvertU1RxTxBits
//#define InvertU2RxTxBits


//Set up UART and pins
//UART Pins are on RPn (remappable)

void UART1_Config(void){

    OpenUART1((
            UART_EN &                   //Enable UART Module
            UART_IDLE_CON &             //Work while idle
            UART_IrDA_DISABLE &         //Disable Infared decoder
            UART_MODE_SIMPLEX &         //UART Simplex mode (RTS pin)
            UART_UEN_00 &               //TX/RX pins configured all other latched
            UART_DIS_WAKE &             //Disable wake on Start bit
            UART_DIS_LOOPBACK &         //Disable loopback
            UART_DIS_ABAUD &            //Disable Auto Baud
            UART_UXRX_IDLE_ONE &        //Receive idle is 1
            UART_BRGH_SIXTEEN &         //16 clocks per bit period
            UART_NO_PAR_8BIT &          //No parity bit
            UART_1STOPBIT               //One stop bit
            ),
            (
            UART_INT_TX_LAST_CH &       //Interrupt when last character shifted out
            UART_IrDA_POL_INV_ZERO &    //IrDA encoded, UxTX Idel state is '0'
            UART_SYNC_BREAK_DISABLED &  //Sync break transmission disabled or completed
            UART_TX_ENABLE &            //Transmit enable
            UART_TX_BUF_NOT_FUL &       //Transmit buffer is not full
            UART_INT_RX_CHAR &          //Interrupt on every char received
            UART_ADR_DETECT_DIS &       //address detect disable
            UART_RX_OVERRUN_CLEAR       //Rx buffer Over run status bit clear
            ),
            (
            __BAUDUART1_ //Baud rate
            ));
    ConfigIntUART1(
                UART_RX_INT_DIS &        //Receive interrupt disabled
                UART_RX_INT_PR1 &       //Priority RX interrupt 1
                UART_TX_INT_DIS &       //transmit interrupt disabled
                UART_TX_INT_PR2         //Priority TX interrupt 1
            );



#ifdef InvertU1RxTxBits
    U1STAbits.UTXINV = 0;
    U1MODEbits.URXINV = 0;
#endif

    //Set the tristate and map pins for Uart
    TRIS_U1TX;
    TRIS_U1RX;
    MAP_U1TX;
    MAP_U1RX;
}

void UART2_Config(void){

    OpenUART2((
            UART_EN &                   //Enable UART Module
            UART_IDLE_CON &             //Work while idle
            UART_IrDA_DISABLE &         //Disable Infared decoder
            UART_MODE_SIMPLEX &         //UART Simplex mode (RTS pin)
            UART_UEN_00 &               //TX/RX pins configured all other latched
            UART_DIS_WAKE &             //Disable wake on Start bit
            UART_DIS_LOOPBACK &         //Disable loopback
            UART_DIS_ABAUD &            //Disable Auto Baud
            UART_UXRX_IDLE_ONE &        //Receive idle is 1
            UART_BRGH_SIXTEEN &         //16 clocks per bit period
            UART_NO_PAR_8BIT &          //No parity bit
            UART_1STOPBIT               //One stop bit
            ),
            (
            UART_INT_TX_LAST_CH &       //Interrupt when last character shifted out
            UART_IrDA_POL_INV_ZERO &    //IrDA encoded, UxTX Idel state is '0'
            UART_SYNC_BREAK_DISABLED &  //Sync break transmission disabled or completed
            UART_TX_ENABLE &            //Transmit enable
            UART_TX_BUF_NOT_FUL &       //Transmit buffer is not full
            UART_INT_RX_CHAR &          //Interrupt on every char received
            UART_ADR_DETECT_DIS &       //address detect disable
            UART_RX_OVERRUN_CLEAR       //Rx buffer Over run status bit clear
            ),
            (
            __BAUDUART2_ //Baud rate
            ));
    ConfigIntUART2(
                UART_RX_INT_EN &        //Receive interrupt enabled
                UART_RX_INT_PR2 &       //Priority RX interrupt 1
                UART_TX_INT_DIS &       //transmit interrupt disabled
                UART_TX_INT_PR1         //Priority TX interrupt 1
            );



#ifdef InvertU2RxTxBits
    U2STAbits.UTXINV = 0;
    U2MODEbits.URXINV = 0;
#endif

    //Set the tristate and map pins for Uart
    TRIS_U2TX;
    TRIS_U2RX;
    MAP_U2TX;
    MAP_U2RX;
}
//</editor-fold>

//<editor-fold defaultstate="collapsed" desc="SPI Setup">
void Setup_SPI1()
{
     OpenSPI1(
            (
            ENABLE_SCK_PIN  &//
       //     FIFO_BUFFER_DISABLE      &
            ENABLE_SDO_PIN          &//
            SPI_MODE16_OFF          &//
            SPI_SMP_ON            &//
            SPI_CKE_ON             &//
            SLAVE_ENABLE_OFF        &//
            CLK_POL_ACTIVE_HIGH     &//
            MASTER_ENABLE_ON        &//
            SEC_PRESCAL_4_1         &//
            PRI_PRESCAL_4_1//
            )
            ,
            (
            FRAME_ENABLE_OFF        &   //NOT USED
            FRAME_SYNC_OUTPUT       &   //NOT USED
            FRAME_POL_ACTIVE_HIGH   &   //NOT USED
            FRAME_SYNC_EDGE_PRECEDE   //NOT USED

            )
            ,
            (
            SPI_ENABLE          &//
            SPI_IDLE_CON        &//
            SPI_RX_OVFLOW_CLR   //
            )
            );

    ConfigIntSPI1(SPI_INT_EN & SPI_INT_PRI_5);

    TRIS_SCLK;
    TRIS_MOSI;
    TRIS_MISO;

    MAP_SCLK;
    MAP_MOSI;
    MAP_MISO;


    printf("SPI1 Setup\r\n");
    return;
}

//</editor-fold>

