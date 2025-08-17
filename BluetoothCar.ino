// Bluetooth Controlled Car Project
// Using Arduino + HC-05 + L298N Motor Driver
// Commands: F - Forward, B - Backward, L - Left, R - Right, S - Stop

int m1 = 13;  // Motor 1 pin
int m2 = 12;  // Motor 2 pin
int n1 = 7;   // Motor 3 pin
int n2 = 6;   // Motor 4 pin
char data;    // To store incoming command from Bluetooth

void setup() {
  // Set motor pins as output
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);
  pinMode(n1, OUTPUT);
  pinMode(n2, OUTPUT);

  // Start serial communication with Bluetooth
  Serial.begin(9600);
}

void loop() {
  if (Serial.available()) {    // Check if data is coming from Bluetooth
    data = Serial.read();      // Read the command

    if (data == 'F') {         // Move Forward
      Serial.println("FORWARD");
      digitalWrite(m1, 0);
      digitalWrite(m2, 1);
      digitalWrite(n1, 0);
      digitalWrite(n2, 1);
      delay(5000);
    }

    if (data == 'B') {         // Move Backward
      Serial.println("BACKWARD");
      digitalWrite(m1, 1);
      digitalWrite(m2, 0);
      digitalWrite(n1, 1);
      digitalWrite(n2, 0);
      delay(5000);
    }

    if (data == 'R') {         // Turn Right
      Serial.println("RIGHT");
      digitalWrite(m1, 0);
      digitalWrite(m2, 1);
      digitalWrite(n1, 1);
      digitalWrite(n2, 0);
      delay(5000);
    }

    if (data == 'L') {         // Turn Left
      Serial.println("LEFT");
      digitalWrite(m1, 1);
      digitalWrite(m2, 0);
      digitalWrite(n1, 0);
      digitalWrite(n2, 1);
      delay(5000);
    }

    if (data == 'S') {         // Stop
      Serial.println("STOP");
      digitalWrite(m1, 0);
      digitalWrite(m2, 0);
      digitalWrite(n1, 0);
      digitalWrite(n2, 0);
      delay(5000);
    }
  }
}
