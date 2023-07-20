#include<stdio.h>
char data_buf[] = {"#12.2*23.2"};

int i = 0;
float temperature;

int main(){
    if (data_buf[i] == '#'){
        i++;
        temperature = 9;
        temperature = temperature / 10;
        printf{"%d", temperature}
    }


return 0;
}