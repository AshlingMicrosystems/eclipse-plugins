/**
 ******************************************************************************
 * @file      startup_stm32f4xx.c
 * @author    Liviu Ionescu
 * @author    MCD Application Team
 * @author    Code Red Technologies Ltd.
 * @version   V1.2.1
 * @date      19-September-2013
 * @brief     This module performs:
 *                - Set the initial SP
 *                - Set the initial PC == Reset_Handler,
 *                - Set the vector table entries with the exceptions ISR address
 *                - Configure the clock system via the SystemInit()
 *                - Branches to main in the C library (which eventually
 *                  calls main()).
 *            After Reset the Cortex-M4 processor is in Thread mode,
 *            priority is Privileged, and the Stack is set to Main.
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; COPYRIGHT 2013 STMicroelectronics</center></h2>
 *
 * Licensed under MCD-ST Liberty SW License Agreement V2, (the "License");
 * You may not use this file except in compliance with the License.
 * You may obtain a copy of the License at:
 *
 *        http://www.st.com/software_license_agreement_liberty_v2
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 ******************************************************************************
 */

#if defined (__cplusplus)
extern "C"
  {
#endif

//*****************************************************************************
//
// Forward declaration of the default handlers. These are aliased.
// When the application defines a handler (with the same name), this will
// automatically take precedence over these weak definitions
//
//*****************************************************************************
void __attribute__((weak))
Reset_Handler(void);
void __attribute__((weak))
NMI_Handler(void);
void __attribute__((weak))
HardFault_Handler(void);
void __attribute__((weak))
MemManage_Handler(void);
void __attribute__((weak))
BusFault_Handler(void);
void __attribute__((weak))
UsageFault_Handler(void);
void __attribute__((weak))
SVC_Handler(void);
void __attribute__((weak))
DebugMon_Handler(void);
void __attribute__((weak))
PendSV_Handler(void);
void __attribute__((weak))
SysTick_Handler(void);

void __attribute__((weak))
Default_Handler(void);

//*****************************************************************************
//
// Forward declaration of the specific IRQ handlers. These are aliased
// to the Default_Handler, which is a 'forever' loop. When the application
// defines a handler (with the same name), this will automatically take
// precedence over these weak definitions
//
//*****************************************************************************
void __attribute__ ((weak, alias ("Default_Handler")))
WWDG_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
PVD_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TAMP_STAMP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
RTC_WKUP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
FLASH_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
RCC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI0_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Stream0_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Stream1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Stream2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Stream3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Stream4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Stream5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Stream6_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
ADC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN1_TX_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN1_RX0_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN1_RX1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN1_SCE_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI9_5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM1_BRK_TIM9_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM1_UP_TIM10_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM1_TRG_COM_TIM11_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM1_CC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C1_EV_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C1_ER_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C2_EV_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C2_ER_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SPI1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SPI2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USART1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USART2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USART3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
EXTI15_10_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
RTC_Alarm_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
OTG_FS_WKUP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM8_BRK_TIM12_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM8_UP_TIM13_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM8_TRG_COM_TIM14_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM8_CC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA1_Stream7_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
FSMC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SDIO_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SPI3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
UART4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
UART5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM6_DAC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
TIM7_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Stream0_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Stream1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Stream2_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Stream3_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Stream4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
ETH_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
ETH_WKUP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN2_TX_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN2_RX0_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN2_RX1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CAN2_SCE_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
OTG_FS_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Stream5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Stream6_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2_Stream7_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
USART6_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C3_EV_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
I2C3_ER_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
OTG_HS_EP1_OUT_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
OTG_HS_EP1_IN_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
OTG_HS_WKUP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
OTG_HS_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DCMI_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
CRYP_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
HASH_RNG_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
FPU_IRQHandler(void);

#if defined(STM32F427_437xx) || defined(STM32F429_439xx)

void __attribute__ ((weak, alias ("Default_Handler")))
UART7_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
UART8_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SPI4_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SPI5_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SPI6_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
SAI1_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
LTDC_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
LTDC_ER_IRQHandler(void);
void __attribute__ ((weak, alias ("Default_Handler")))
DMA2D_IRQHandler(void);

#endif

//*****************************************************************************
//
// The entry point for the application.
// main() is the entry point for Newlib based applications
//
//*****************************************************************************
extern int
main(void);

extern void
SystemInit(void);

inline void
data_init(unsigned int romstart, unsigned int start, unsigned int len);
inline void
bss_init(unsigned int start, unsigned int len);

/* start address for the initialization values of the .data section.
 defined in linker script */
extern unsigned int _sidata;
/* start address for the .data section. defined in linker script */
extern unsigned int _sdata;
/* end address for the .data section. defined in linker script */
extern unsigned int _edata;
/* start address for the .bss section. defined in linker script */
extern unsigned int _sbss;
/* end address for the .bss section. defined in linker script */
extern unsigned int _ebss;

extern unsigned int _estack;

typedef void
(* const pfn)(void);
extern pfn g_pfnVectors[];

//*****************************************************************************
#if defined (__cplusplus)
} // extern "C"
#endif

//*****************************************************************************
//
// The vector table.
// This relies on the linker script to place at correct location in memory.
//
//*****************************************************************************

__attribute__ ((section(".isr_vector")))
pfn g_pfnVectors[] =
  {
  // Core Level - CM4
      (pfn) &_estack,                           // The initial stack pointer
      Reset_Handler,                            // The reset handler

      NMI_Handler,                              // The NMI handler
      HardFault_Handler,                        // The hard fault handler
      MemManage_Handler,                        // The MPU fault handler
      BusFault_Handler,                         // The bus fault handler
      UsageFault_Handler,                       // The usage fault handler
      0,                                        // Reserved
      0,                                        // Reserved
      0,                                        // Reserved
      0,                                        // Reserved
      SVC_Handler,                              // SVCall handler
      DebugMon_Handler,                         // Debug monitor handler
      0,                                        // Reserved
      PendSV_Handler,                           // The PendSV handler
      SysTick_Handler,                          // The SysTick handler

      // Chip Level - STM32F4xx
      WWDG_IRQHandler,                          // Window WatchDog
      PVD_IRQHandler,                         // PVD through EXTI Line detection
      TAMP_STAMP_IRQHandler,      // Tamper and TimeStamps through the EXTI line
      RTC_WKUP_IRQHandler,                   // RTC Wakeup through the EXTI line
      FLASH_IRQHandler,                         // FLASH
      RCC_IRQHandler,                           // RCC
      EXTI0_IRQHandler,                         // EXTI Line0
      EXTI1_IRQHandler,                         // EXTI Line1
      EXTI2_IRQHandler,                         // EXTI Line2
      EXTI3_IRQHandler,                         // EXTI Line3
      EXTI4_IRQHandler,                         // EXTI Line4
      DMA1_Stream0_IRQHandler,                  // DMA1 Stream 0
      DMA1_Stream1_IRQHandler,                  // DMA1 Stream 1
      DMA1_Stream2_IRQHandler,                  // DMA1 Stream 2
      DMA1_Stream3_IRQHandler,                  // DMA1 Stream 3
      DMA1_Stream4_IRQHandler,                  // DMA1 Stream 4
      DMA1_Stream5_IRQHandler,                  // DMA1 Stream 5
      DMA1_Stream6_IRQHandler,                  // DMA1 Stream 6
      ADC_IRQHandler,                           // ADC1, ADC2 and ADC3s
#if defined(STM32F401xx)
      0,
      0,
      0,
      0,
#else
      CAN1_TX_IRQHandler,                       // CAN1 TX
      CAN1_RX0_IRQHandler,                      // CAN1 RX0
      CAN1_RX1_IRQHandler,                      // CAN1 RX1
      CAN1_SCE_IRQHandler,                      // CAN1 SCE
#endif
      EXTI9_5_IRQHandler,                       // External Line[9:5]s
      TIM1_BRK_TIM9_IRQHandler,                 // TIM1 Break and TIM9
      TIM1_UP_TIM10_IRQHandler,                 // TIM1 Update and TIM10
      TIM1_TRG_COM_TIM11_IRQHandler,   // TIM1 Trigger and Commutation and TIM11
      TIM1_CC_IRQHandler,                       // TIM1 Capture Compare
      TIM2_IRQHandler,                          // TIM2
      TIM3_IRQHandler,                          // TIM3
      TIM4_IRQHandler,                          // TIM4
      I2C1_EV_IRQHandler,                       // I2C1 Event
      I2C1_ER_IRQHandler,                       // I2C1 Error
      I2C2_EV_IRQHandler,                       // I2C2 Event
      I2C2_ER_IRQHandler,                       // I2C2 Error
      SPI1_IRQHandler,                          // SPI1
      SPI2_IRQHandler,                          // SPI2
      USART1_IRQHandler,                        // USART1
      USART2_IRQHandler,                        // USART2
#if defined(STM32F401xx)
      0,
#else
      USART3_IRQHandler,                        // USART3
#endif
      EXTI15_10_IRQHandler,                     // External Line[15:10]s
      RTC_Alarm_IRQHandler,             // RTC Alarm (A and B) through EXTI Line
      OTG_FS_WKUP_IRQHandler,             // USB OTG FS Wakeup through EXTI line
#if defined(STM32F401xx)
      0,
      0,
      0,
      0,
#else
      TIM8_BRK_TIM12_IRQHandler,                // TIM8 Break and TIM12
      TIM8_UP_TIM13_IRQHandler,                 // TIM8 Update and TIM13
      TIM8_TRG_COM_TIM14_IRQHandler,   // TIM8 Trigger and Commutation and TIM14
      TIM8_CC_IRQHandler,                       // TIM8 Capture Compare
#endif
      DMA1_Stream7_IRQHandler,                  // DMA1 Stream7
#if defined(STM32F401xx)
      0,
#else
      FSMC_IRQHandler,                          // FSMC
#endif
      SDIO_IRQHandler,                          // SDIO
      TIM5_IRQHandler,                          // TIM5
      SPI3_IRQHandler,                          // SPI3
#if defined(STM32F401xx)
      0,
      0,
      0,
      0,
#else

      UART4_IRQHandler,                         // UART4
      UART5_IRQHandler,                         // UART5
      TIM6_DAC_IRQHandler,                    // TIM6 and DAC1&2 underrun errors
      TIM7_IRQHandler,                          // TIM7
#endif
      DMA2_Stream0_IRQHandler,                  // DMA2 Stream 0
      DMA2_Stream1_IRQHandler,                  // DMA2 Stream 1
      DMA2_Stream2_IRQHandler,                  // DMA2 Stream 2
      DMA2_Stream3_IRQHandler,                  // DMA2 Stream 3
      DMA2_Stream4_IRQHandler,                  // DMA2 Stream 4
#if defined(STM32F401xx)
      0,
      0,
      0,
      0,
      0,
      0,
#else
      ETH_IRQHandler,                           // Ethernet
      ETH_WKUP_IRQHandler,                  // Ethernet Wakeup through EXTI line
      CAN2_TX_IRQHandler,                       // CAN2 TX
      CAN2_RX0_IRQHandler,                      // CAN2 RX0
      CAN2_RX1_IRQHandler,                      // CAN2 RX1
      CAN2_SCE_IRQHandler,                      // CAN2 SCE
#endif
      OTG_FS_IRQHandler,                        // USB OTG FS
      DMA2_Stream5_IRQHandler,                  // DMA2 Stream 5
      DMA2_Stream6_IRQHandler,                  // DMA2 Stream 6
      DMA2_Stream7_IRQHandler,                  // DMA2 Stream 7
      USART6_IRQHandler,                        // USART6
      I2C3_EV_IRQHandler,                       // I2C3 event
      I2C3_ER_IRQHandler,                       // I2C3 error
#if defined(STM32F401xx)
      0,
      0,
      0,
      0,
      0,
      0,
      0,
#else
      OTG_HS_EP1_OUT_IRQHandler,                // USB OTG HS End Point 1 Out
      OTG_HS_EP1_IN_IRQHandler,                 // USB OTG HS End Point 1 In
      OTG_HS_WKUP_IRQHandler,                  // USB OTG HS Wakeup through EXTI
      OTG_HS_IRQHandler,                        // USB OTG HS
      DCMI_IRQHandler,                          // DCMI
      CRYP_IRQHandler,                          // CRYP crypto
      HASH_RNG_IRQHandler,                      // Hash and Rng
#endif
      FPU_IRQHandler                      // FPU
#if defined(STM32F427_437xx) || defined(STM32F429_439xx)
    UART7_IRQHandler                  // UART7
    UART8_IRQHandler// UART8
    SPI4_IRQHandler// SPI4
    SPI5_IRQHandler// SPI5
    SPI6_IRQHandler// SPI6
    SAI1_IRQHandler// SAI1
    LTDC_IRQHandler// LTDC
    LTDC_ER_IRQHandler// LTDC error
    DMA2D_IRQHandler// DMA2D
#endif
};

inline void
__attribute__((always_inline))
data_init(unsigned int romstart, unsigned int start, unsigned int len)
{
  unsigned int *pulDest = (unsigned int*) start;
  unsigned int *pulSrc = (unsigned int*) romstart;
  unsigned int loop;
  for (loop = 0; loop < len; loop = loop + 4)
    *pulDest++ = *pulSrc++;
}

inline void
__attribute__((always_inline))
bss_init(unsigned int start, unsigned int len)
{
  unsigned int *pulDest = (unsigned int*) start;
  unsigned int loop;
  for (loop = 0; loop < len; loop = loop + 4)
    *pulDest++ = 0;
}

void __attribute__ ((section(".flashtext")))
Reset_Handler(void)
{

  // Use Old Style Data and BSS section initialization.
  // This will only initialize a single RAM bank.
  unsigned int * LoadAddr, *ExeAddr, *EndAddr, SectionLen;

  // Copy the data segment from flash to SRAM.
  LoadAddr = &_sidata;
  ExeAddr = &_sdata;
  EndAddr = &_edata;
  SectionLen = (void*) EndAddr - (void*) ExeAddr;
  data_init((unsigned int) LoadAddr, (unsigned int) ExeAddr, SectionLen);

  // Zero fill the bss segment
  ExeAddr = &_sbss;
  EndAddr = &_ebss;
  SectionLen = (void*) EndAddr - (void*) ExeAddr;
  bss_init((unsigned int) ExeAddr, SectionLen);

#if defined (__VFP_FP__) && !defined (__SOFTFP__)
  /*
   * Code to enable the Cortex-M4 FPU only included
   * if appropriate build options have been selected.
   * Code taken from Section 7.1, Cortex-M4 TRM (DDI0439C)
   */
  asm volatile
  (
      " LDR.W           R0, =0xE000ED88 \n" // CPACR is located at address 0xE000ED88
      " LDR             R1, [R0] \n"// Read CPACR
      " ORR             R1, R1, #(0xF << 20) \n"// Set bits 20-23 to enable CP10 and CP11 coprocessor
      " STR             R1, [R0]"// Write back the modified value to the CPACR
      : /* out */
      : /* in */
      : /* clobber */
  );
#endif // (__VFP_FP__) && !(__SOFTFP__)
//#ifdef __USE_CMSIS
  SystemInit();
//#endif

#if defined (__cplusplus)
  //
  // Call C++ library initialisation
  //
  __libc_init_array();
#endif

  main();

  //
  // main() shouldn't return, but if it does, we'll just enter an infinite loop
  //
  while (1)
    {
      ;
    }

}

//*****************************************************************************
//
// Processor ends up here if an unexpected interrupt occurs or a specific
// handler is not present in the application code.
//
//*****************************************************************************

void __attribute__ ((section(".flashtext")))
Default_Handler(void)
{
  while (1)
    {
    }
}

//*****************************************************************************
// Default exception handlers. Override the ones here by defining your own
// handler routines in your application code.
//*****************************************************************************
void __attribute__ ((section(".flashtext")))
NMI_Handler(void)
{
  while (1)
    {
    }
}

void __attribute__ ((section(".flashtext")))
HardFault_Handler(void)
{
  while (1)
    {
    }
}

void __attribute__ ((section(".flashtext")))
MemManage_Handler(void)
{
  while (1)
    {
    }
}

void __attribute__ ((section(".flashtext")))
BusFault_Handler(void)
{
  while (1)
    {
    }
}

void __attribute__ ((section(".flashtext")))
UsageFault_Handler(void)
{
  while (1)
    {
    }
}

void __attribute__ ((section(".flashtext")))
SVC_Handler(void)
{
  while (1)
    {
    }
}

void __attribute__ ((section(".flashtext")))
DebugMon_Handler(void)
{
  while (1)
    {
    }
}

void __attribute__ ((section(".flashtext")))
PendSV_Handler(void)
{
  while (1)
    {
    }
}

void __attribute__ ((section(".flashtext")))
SysTick_Handler(void)
{
  while (1)
    {
    }
}
