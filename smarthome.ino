#include <common.h>
#include <FirebaseESP8266.h>
#include <FirebaseFS.h>
#include <Utils.h>








#include <ESP8266WiFi.h>   


const char *ssid = "SG WIFI 2G"; // The name of the Wi-Fi network that will be created
const char *password = "sg654321";  // The password required to connect to it, leave blank for an open network
const char *firebase_host = "smart-184f7-default-rtdb.asia-southeast1.firebasedatabase.app";
const char *firebase_auth = "dIflX6pUt8KScNTNuqWCtx1H7bk7opkdQqg6GyqW";
FirebaseData fbdo;
void setup() {
  Serial.begin(115200);
  Serial.println();

  WiFi.begin(ssid, password);

  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP()); // Send the IP address of the ESP8266 to the computer
  Serial.println();
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);
  Firebase.begin(firebase_host, firebase_auth);

}




void loop() {
  // put your main code here, to run repeatedly:
//Serial.printf("Set int... %s\n", Firebase.setInt(fbdo, "/test/int", 1) ? "ok" : fbdo.errorReason().c_str());
//if (Firebase.getInt(fdbo, "/users/light")){
//Serial.println(fdbo.intdata());
//}
int c = Firebase.getInt(fbdo, "/users/light") ? fbdo.intData() : 4;
Serial.println(c);
if (c) {
digitalWrite(LED_BUILTIN, HIGH);
//delay(1000);
}
else {
  digitalWrite(LED_BUILTIN, LOW);
}

delay(500);

  }
