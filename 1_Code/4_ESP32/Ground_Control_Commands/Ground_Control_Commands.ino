#include <Bluepad32.h>
#include <Wire.h>

int last_buttons = 0x0000;
float ax_max = 1;
float p_max = 0.5;
float roll_max = 0.3;
float pitch_max = 0.3;
float Ground_Commands[5];
float inactivity_counter = 0;
uint8_t active = 0;
uint8_t token_Init = 0;
uint8_t ESC_Status = 0;

ControllerPtr myControllers[BP32_MAX_GAMEPADS];

// This callback gets called any time a new gamepad is connected.
// Up to 4 gamepads can be connected at the same time.
void onConnectedController(ControllerPtr ctl) {
    bool foundEmptySlot = false;
    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
        if (myControllers[i] == nullptr) {
            Serial.printf("CALLBACK: Controller is connected, index=%d\n", i);
            // Additionally, you can get certain gamepad properties like:
            // Model, VID, PID, BTAddr, flags, etc.
            ControllerProperties properties = ctl->getProperties();
            Serial.printf("Controller model: %s, VID=0x%04x, PID=0x%04x\n", ctl->getModelName().c_str(), properties.vendor_id,
                           properties.product_id);
            myControllers[i] = ctl;
            foundEmptySlot = true;
            break;
        }
    }
    if (!foundEmptySlot) {
        Serial.println("CALLBACK: Controller connected, but could not found empty slot");
    }
}

void onDisconnectedController(ControllerPtr ctl) {
    bool foundController = false;

    for (int i = 0; i < BP32_MAX_GAMEPADS; i++) {
        if (myControllers[i] == ctl) {
            Serial.printf("CALLBACK: Controller disconnected from index=%d\n", i);
            myControllers[i] = nullptr;
            foundController = true;
            break;
        }
    }

    if (!foundController) {
        Serial.println("CALLBACK: Controller disconnected, but not found in myControllers");
    }
}

void dumpGamepad(ControllerPtr ctl) {
    Serial.printf(
        "idx=%d, dpad: 0x%02x, buttons: 0x%04x, axis L: %4d, %4d, axis R: %4d, %4d, brake: %4d, throttle: %4d, "
        "misc: 0x%02x, gyro x:%6d y:%6d z:%6d, accel x:%6d y:%6d z:%6d\n",
        ctl->index(),        // Controller Index
        ctl->dpad(),         // D-pad
        ctl->buttons(),      // bitmask of pressed buttons
        ctl->axisX(),        // (-511 - 512) left X Axis
        ctl->axisY(),        // (-511 - 512) left Y axis
        ctl->axisRX(),       // (-511 - 512) right X axis
        ctl->axisRY(),       // (-511 - 512) right Y axis
        ctl->brake(),        // (0 - 1023): brake button
        ctl->throttle(),     // (0 - 1023): throttle (AKA gas) button
        ctl->miscButtons(),  // bitmask of pressed "misc" buttons
        ctl->gyroX(),        // Gyro X
        ctl->gyroY(),        // Gyro Y
        ctl->gyroZ(),        // Gyro Z
        ctl->accelX(),       // Accelerometer X
        ctl->accelY(),       // Accelerometer Y
        ctl->accelZ()        // Accelerometer Z
    );
}


void processGamepad(ControllerPtr ctl) 
{
  Ground_Commands[0] = (ctl->throttle() - ctl->brake()) / 1020.0 * ax_max;

  if (ctl->axisY() < -25 || ctl->axisY() > 25) 
  {
    Ground_Commands[2] = ctl->axisY() / 508.0 * pitch_max;
  }
  else 
  {
    Ground_Commands[2] = 0.0;
  }


  if (ctl->axisX() < -25 || ctl->axisX() > 25) 
  {
    Ground_Commands[3] = ctl->axisX() / 508.0 * roll_max;
  }
  else 
  {
    Ground_Commands[3] = 0.0;
  }


  if (ctl->axisRX() < -25 || ctl->axisRX() > 25) {

    Ground_Commands[1] = -ctl->axisRX() / 508.0 * p_max;
  }
  else 
  {
    Ground_Commands[1] = 0.0;
  }


  if (last_buttons == 0x0000 && ctl->buttons() == 0x0008) 
  {
    if (active == 1)
    {
      active = 2;
    }
    else if (active == 2)
    {
      active = 1;
    }
  }

  if (last_buttons == 0x0000 && ctl->buttons() == 0x0002) 
  {
    if (active == 0) 
    {
      active = 1;
    }
    else 
    {
      active = 0;
    }
  }


  last_buttons = ctl->buttons();


  // Serial.printf("xdot = %4f, ydot = %4f, zdot = %4f, p = %4f, Activated = %1f\n", Ground_Commands[0],Ground_Commands[1],Ground_Commands[2],Ground_Commands[3],Ground_Commands[4]);

  // dumpGamepad(ctl);

}


void processControllers() {
  for (auto myController : myControllers) {
    if (myController && myController->isConnected() && myController->hasData()) {
      if (myController->isGamepad()) {
         processGamepad(myController);
      }
      else {
        Serial.println("Unsupported controller");
      }
    }
  }
}


// Arduino setup function. Runs in CPU 1
void setup() {
    Serial.begin(115200);
    Serial.printf("Firmware: %s\n", BP32.firmwareVersion());



    const uint8_t* addr = BP32.localBdAddress();
    Serial.printf("BD Addr: %2X:%2X:%2X:%2X:%2X:%2X\n", addr[0], addr[1], addr[2], addr[3], addr[4], addr[5]);

    // Setup the Bluepad32 callbacks
    BP32.setup(&onConnectedController, &onDisconnectedController);

    // "forgetBluetoothKeys()" should be called when the user performs
    // a "device factory reset", or similar.
    // Calling "forgetBluetoothKeys" in setup() just as an example.
    // Forgetting Bluetooth keys prevents "paired" gamepads to reconnect.
    // But it might also fix some connection / re-connection issues.
    BP32.forgetBluetoothKeys();

    // Enables mouse / touchpad support for gamepads that support them.
    // When enabled, controllers like DualSense and DualShock4 generate two connected devices:
    // - First one: the gamepad
    // - Second one, which is a "virtual device", is a mouse.
    // By default, it is disabled.
    BP32.enableVirtualDevice(false);

    delay(400);


    // Serial.begin(115200);
    // while(!Serial);
    // printf("test");

    // Start UART1 (TX→17, RX→16)
    Serial1.begin(115200, SERIAL_8N1, 16, 17);
    
}

// Arduino loop function. Runs in CPU 1.
void loop() {
    // This call fetches all the controllers' data.
    // Call this function in your main loop.

  bool dataUpdated = BP32.update();
  
  if (dataUpdated) // If we received new data from the DS4
  {
    processControllers();
    Ground_Commands[4] = active;
    inactivity_counter = 0;

    ControllerPtr ctl = myControllers[0];

    if (ctl && ctl->isConnected()) 
    {
      if      (active == 2) ctl->setColorLED(0, 255, 0);
      else if (active == 1) ctl->setColorLED(255, 222, 33);
      else                  ctl->setColorLED(255,   0,  0);
    }

  }
  else // If we did not receive new data from the DS4
  {
    inactivity_counter += 1;

    if (inactivity_counter > 200)
    {
      if (active == 0) 
      {
        Ground_Commands[4] = 0;
      }
      else
      {
        Ground_Commands[4] = 1; // No cambiem el active ja que aixi si recupera la senyal tindra el active antic
      }
       
    }
  }

  if (active == 0)
  {
    token_Init = 0;
  }
  else if (active == 2)
  {
    token_Init = 1;
  }


  if (active == 1 && token_Init == 1 && ESC_Status == 0)
  {
    active = 0;
  }


  // Send Ground Commands

  uint8_t out[22];
  out[0] = 0x55;
  out[1] = 0xAA;
  memcpy(out + 2, Ground_Commands, sizeof(Ground_Commands));
  Serial1.write(out, sizeof(out));  // sends 22 bytes every loop
  
  // Receive ESC Status to check if motors have been turned off

  uint8_t STM32Read = Serial1.read();

  if (STM32Read != -1)
  {
    ESC_Status = STM32Read;
  }


  delay(20);
}
