#include <Arduino.h>

#define OUTPUT_PIN 10
// ESP32-C3 GPIO base address
#define DR_REG_GPIO_BASE 0x60004000


void delay_ms(uint32_t ms) {
    uint32_t start = millis(); 
    while (millis() - start < ms) {
    }
}

void switch_off()
{
   // Set GPIO5 as an output
   
  *((volatile uint32_t *)(DR_REG_GPIO_BASE + 0x20)) |= (1 << OUTPUT_PIN);
  // Set GPIO5 to low 
  *((volatile uint32_t *)(DR_REG_GPIO_BASE + 0x04)) &= ~(1 << OUTPUT_PIN);
  
  delay_ms(10000);
  
  // Set GPIO5 to high 
  *((volatile uint32_t *)(DR_REG_GPIO_BASE + 0x04)) |= (1 << OUTPUT_PIN);
   
   delay_ms(1000);

  // Set GPIO5 to low
  *((volatile uint32_t *)(DR_REG_GPIO_BASE + 0x04)) &= ~(1 << OUTPUT_PIN);

}


void setup() {
 switch_off();
}

void loop() {
  esp_deep_sleep_start();
}
