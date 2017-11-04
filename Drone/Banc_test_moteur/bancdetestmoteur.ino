/************************************************* *************************************************
* OPEN-SMART demo code for FSR sensor module (50N / 5KG)
* You can learnto know the pressure on the sensitive area. 
*
*Store: https://open-smart.aliexpress.com/store/1199788
           dx.com
************************************************** ************************************************** *****/

//FSR Val
#define FSR_PIN A0
#define DIVIDER_RES 10 //the resistance of the resistor connect with the FSR resistor in series.
// Voltage val
#include <Wire.h>
int val11;
int val2;

// the setup routine runs once when you press reset:
void setup()
{
	// initialize serial communication at 9600 bits per second:
	Serial.begin(9600);
	/*
	//~ Voltage Sensor Setup Start
	pinMode(LED1,OUTPUT);
	Serial.println("Emartee.Com");
	Serial.println("Voltage: ");
	Serial.print("V");
	//~ # Voltage Sensor Setup stop
*/
}

// the loop routine runs over and over again forever:
void loop()
{
	/*
	//~ Voltage Sensor Loop Start	
	float temp;
	val11=analogRead(1);
	temp=val11/4.092;
	val11=(int)temp;//
	val2=((val11%100)/10);
	Serial.println(val2);
	delay(1000);
	//~ Voltage Sensor Loop Stop

	//~ Current Sensor Loop Start	
	float average = 0;
	for(int i = 0; i < 1000; i++) {
		average = average + (.0264 * analogRead(A0) -13.51) / 1000;

		//5A mode, if 20A or 30A mode, need to modify this formula to 
		//(.19 * analogRead(A0) -25) for 20A mode and 
		//(.044 * analogRead(A0) -3.78) for 30A mode

		delay(1);
	}
	Serial.println(average);  
	//~ Current Sensor Loop Start	
	*/
	//~ FSR Loop Start
	int sensorValue = analogRead(FSR_PIN);
	float val = sensorValue;
	float res = DIVIDER_RES*1023.00/val-DIVIDER_RES;
	//print out the value you read:
	Serial.println(sensorValue);
	Serial.print(res);
	Serial.println("KOhm");
	judgeForce(res);
	delay(600);        // delay in between reads for stability
	//~ FSR Loop Stop
}

void judgeForce(float res)
{
	if(res > 1200) Serial.println("Nothing on the FSR");
	else if(res > 300) Serial.println("Did you have breakfast? Your strength is too small.");
	else if(res > 50) Serial.println("Your strength can be bigger...");
	else if(res > 15) Serial.println("Man, your strength is big!");
	else Serial.println("You are most strong in the world!");
}
