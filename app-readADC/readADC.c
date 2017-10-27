/*
 ============================================================================
 Name        : readADC.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Read ADC input for given pin number every 1 second and print 
               the value in C, Ansi-style

 Note: This Program runs in infinite loop once given valid pin number.
 ============================================================================
*/

#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_BUF 64
 
/* Function declarations */
int readADC(unsigned int pin);

int main(int argc, char *argv[])
{
    int adc0 = 0;
 
    if (argc < 2)
    {
       printf("Usage: ./<binary> <pin-number> \n \
               Pins 0:P9_39, 1:P9_40, 2:P9_37, 3:P9_38, 4:P9_33, 5:P9_36, 6:P9_35 \n \
               Example : ./readADC 0\n");
       exit(0);
    }

    //Enable ADC pins within code
    system("echo BB-ADC > /sys/devices/platform/bone_capemgr/slots");

    while (1)
    {
        adc0 = readADC(atoi(argv[1]));

        //Print ADC readings
        printf("ADC %d: %d\n", atoi(argv[1]), adc0);

        sleep(1);
    }

    return 0;  
}

int readADC(unsigned int pin)  
{  
    int fd;
    char buf[MAX_BUF];
    char val[4];     //holds up to 4 digits for ADC value

    //Stores the ADC pin file path string into "buf"  
    snprintf(buf, sizeof(buf), "/sys/bus/iio/devices/iio:device0/in_voltage%d_raw", pin);

    fd = open(buf, O_RDONLY);     //open ADC as read only

    //Check ADC is enabled or not
    if (fd < 0)
    {
        printf("Error: ADC open failed, %s\n", buf);
        exit(0);
    }

    read(fd, &val, 4); //read ADC ing value
    close(fd);  //close file and stop reading

    return atoi(val); //returns an integer value
}
