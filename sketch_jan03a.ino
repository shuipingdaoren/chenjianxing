#include <Adafruit_NeoPixel.h> 
#define PIN 6                      

#define PIN_NUM 2 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIN_NUM, PIN, NEO_GRB + NEO_KHZ800);
#define Light_PIN A0  //光照传感器接AO引脚
#define Light A2 //人体红外传感器A2引脚 
#define Light_value1 400

//光强预设值
int sensorValue;
int a;
void setup()                                //创建无返回值函数
 {
  Serial.begin(115200);               //初始化串口通信，并将波特率设置为115200
  strip.begin();                             //准备对灯珠进行数据发送
  strip.show();                              //初始化所有的灯珠为关的状态
}
void loop()                                  //无返回值loop函数
 {
  sensorValue = analogRead(Light_PIN);  //光检测
  a=analogRead(Light);
  Serial.println(a);  
  if(a!=0){
  if (sensorValue < Light_value1)                          //若光强小于400
   {strip.setPixelColor(0, strip.Color(255, 255, 255));//红光
    strip.setPixelColor(1, strip.Color(255, 255, 255));
    strip.show();   //LED显示
  }
  else if (sensorValue >= Light_value1 )
       {strip.setPixelColor(0, strip.Color(0, 0, 0));
       strip.setPixelColor(1, strip.Color(0, 0, 0));
    strip.show();   //LED显示
  }
  }
  else
  {strip.setPixelColor(0, strip.Color(0, 0, 0));
       strip.setPixelColor(1, strip.Color(0, 0, 0));
    strip.show();   //LED显示
} 
 }

