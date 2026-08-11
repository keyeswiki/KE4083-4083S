#include <DFRobot_ENS160.h>
#include <Wire.h>

// 使用I2C通信，地址默认为0x53
DFRobot_ENS160_I2C ENS160(&Wire, 0x53);

void setup(void){
  Serial.begin(9600);

  // 初始化传感器
  while(NO_ERR != ENS160.begin()) {
    Serial.println("与设备的通信失败，请检查连接情况.");
    delay(3000);
  }
  Serial.println("开始好的!");

  // 设置电源模式为标准气体感应模式
  ENS160.setPWRMode(ENS160_STANDARD_MODE);

  // 设置环境温度和湿度用于校准（示例值：25°C，50%RH）
  ENS160.setTempAndHum(25.0, 50.0);
}

void loop(){
  // 获取传感器工作状态
  uint8_t Status = ENS160.getENS160Status();
  Serial.print("传感器运行状态: ");
  Serial.println(Status);

  // 获取空气质量指数(1-5)
  uint8_t AQI = ENS160.getAQI();
  Serial.print("空气质量指数: ");
  Serial.println(AQI);

  // 获取TVOC浓度(0-65000 ppb)
  uint16_t TVOC = ENS160.getTVOC();
  Serial.print("TVOC浓度: ");
  Serial.print(TVOC);
  Serial.println(" ppb");

  // 获取等效CO2浓度(400-65000 ppm)
  uint16_t ECO2 = ENS160.getECO2();
  Serial.print("等效CO2浓度: ");
  Serial.print(ECO2);
  Serial.println(" ppm");

  Serial.println();
  delay(1000);
}
