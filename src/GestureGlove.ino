/**
 * Project  : GestureGlove - Universal Appliance Controller & Sign Translator
 * Author   : Muhammad Raffa Danendra & Team
 * Platform : Arduino Nano
 */

const int sensorPin[5] = {7, 8, 9, 10, 11}; // Jempol -> Kelingking
const int ledPin[5]    = {2, 3, 4, 5, 6};   // LED Jempol -> Kelingking

String lastGesture = "";

String detectGesture(bool f[5]);

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 5; i++) {
    pinMode(sensorPin[i], INPUT_PULLUP);
    pinMode(ledPin[i], OUTPUT);
  }

  Serial.println("=================================");
  Serial.println("     GESTURE DETECTION READY     ");
  Serial.println("=================================");
  Serial.println("Jempol -> Kelingking : D7 - D11");
  Serial.println("LED                  : D2 - D6");
  Serial.println("=================================");
}

void loop() {
  bool f[5];

  for (int i = 0; i < 5; i++) {
    f[i] = (digitalRead(sensorPin[i]) == LOW);
    digitalWrite(ledPin[i], f[i]);
  }

  String gesture = detectGesture(f);

  if (gesture != lastGesture) {
    Serial.println("👉 GESTURE : " + gesture);
    lastGesture = gesture;
  }

  delay(60);
}

// ==========================================
//              GESTURE LOGIC
// ==========================================
String detectGesture(bool f[5]) {

  // SEMUA JARI
  if (f[0] && f[1] && f[2] && f[3] && f[4]) {
    return "TERIMA KASIH / TANGAN TERKEPAL";
  }
  if (!f[0] && !f[1] && !f[2] && !f[3] && !f[4]) {
    return "TANGAN TERBUKA";
  }

  // SATU JARI
  if (f[0] && !f[1] && !f[2] && !f[3] && !f[4]) {
    return "JEMPOL / OK";
  }
  if (!f[0] && f[1] && !f[2] && !f[3] && !f[4]) {
    return "DIAM / TUNJUK";
  }
  if (!f[0] && !f[1] && f[2] && !f[3] && !f[4]) {
    return "TENGAH";
  }

  // DUA JARI
  if (!f[0] && f[1] && f[2] && !f[3] && !f[4]) {
    return "PEACE ✌";
  }
  if (f[0] && f[1] && !f[2] && !f[3] && !f[4]) {
    return "MINUM";
  }

  // TIGA JARI
  if (f[0] && f[1] && f[2] && !f[3] && !f[4]) {
    return "MAKAN";
  }
  if (!f[0] && f[1] && f[2] && f[3] && !f[4]) {
    return "HALO 👋";
  }

  // EMPAT JARI
  if (!f[0] && f[1] && f[2] && f[3] && f[4]) {
    return "DIAM ✋";
  }

  return "CUSTOM";
}
