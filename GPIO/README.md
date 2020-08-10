# LED test

1. Connect 5VO and (+)
2. And connect GND and (-).<br>This process gives voltage on the breadboard.
3. Connect GPIO21 ,register and LED.<br>I set up like this.
![image](/uploads/2b8bbef7ff5088d916089b6eb825dced/image.png)
<br>
4. Now open terminal on raspberry and make a dir. I set it GPIO.
5. Create a file for LED testing. I make ledTest.c for this.

```
#include<stdio.h>
#include<wiringPi.h>
// gcc test.c -lwiringPi
int main()
{
	int i;
	if(wiringPiSetup()==-1) return -1;
	pinMode(29, OUTPUT);// set Pin mode no.29 cause BCM 21 is 29 on wiringPi)
	for(i=0; i<5; i++)
	{
		digitalWrite(29,1);//turn on led(1)
		delay(500); //delay 0.5 second
		digitalWrite(29,0);//turn on led(1)
		delay(500); //delay 0.5 second
	}
	return 0;
}
```
6. Execute this with `gcc ledTest.c -lwiringPi`.<br>The command `-l` means add basic header file search directory on preprocessing.
7. The result should be like...
![image](/uploads/4e3f52e0009c3cf537c0a10c6a427c68/image.png)
![KakaoTalk_20200811_010052414](/uploads/68c4b55fb70e952624c3d35c8f72720a/KakaoTalk_20200811_010052414.mp4)





