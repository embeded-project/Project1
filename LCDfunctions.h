void mdelay(int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<3180;j++)
        {}
}
void udelay(int n)
{
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<3;j++)
        {}
}


void LCD_command(unsigned char com)
{

    GPIO_PORTA_DATA_R=0;
    mdelay(1);
    GPIO_PORTA_DATA_R |=0x40;
    mdelay(1);
    GPIO_PORTB_DATA_R=com;
    udelay(1);
    GPIO_PORTA_DATA_R=0;
    udelay(1);

}



void LCD_char(unsigned char data)
{
    GPIO_PORTA_DATA_R=0x80;
    mdelay(1);
    GPIO_PORTA_DATA_R |=0x40;
   mdelay(1);
    GPIO_PORTB_DATA_R=data;
    udelay(1);
    GPIO_PORTA_DATA_R=0;
    udelay(50);
}


void LCD_string(char *str) // to print string (pointer to elements of array of char)
{
    int i;
    for(i=0;str[i]!=0;i++)  /* Send each char of string  */
    {
        LCD_char(str[i]);  /* Call LCD data write */
        mdelay(20);
    }
}

void LCD_integers(int data)
{
    int p;
    int k=0;
    while(data>0)
    {
        num[k]=data%10;
        data=data/10;
        k++;
    }
    k--;
    for (p=k;p>=0;p--)
    {
        c=num[p]+48;

        GPIO_PORTA_DATA_R=0x80;       //Rs=1 send data, Rw=0 write,E=0 initially enable=0
        mdelay(1);
        GPIO_PORTA_DATA_R |=0x40;      // E=1 (low to high) without affecting other pins
        mdelay(1);
        GPIO_PORTB_DATA_R=c;           // send data to the screen
        udelay(1);
        GPIO_PORTA_DATA_R=0;           //Rs=0 Rw=0 E=0(back to the beginning)
        udelay(50);
    }
}


void LCD_displayDouble(double deci)
{
    int integer_part=deci;
    int decimal_part=(deci - integer_part)*100000;

    LCD_integers(integer_part);
    LCD_char('.');
    LCD_integers(decimal_part);
}
