int main()
{
    RCC_EnablePeriphera(BUS_AHB1, PERIPHERAL_GPIOA_AHB1);
    RCC_enuEnablePreipheral(BUS_AHB1, PERIPHERAL_GPIOB_AHB1);
    RCC_enuEnablePreipheral(BUS_APB2, PERIPHERAL_USART1_APB2);

    LCD_Init_Asynch();
    Switch_Init();

    Scheduler_Init();
    Scheduler_StartOS();
}