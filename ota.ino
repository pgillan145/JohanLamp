void setupOTA(void (*pulser)()) {
  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
#ifdef SER
    Serial.println("WiFi shield not present");
#endif
    // don't continue:
    while (true);
  }
  
  WiFi.setHostname("johanlamp");    
  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) {
    pulser();
#ifdef SER
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
#endif
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);
  }
#ifdef SER
  printWifiStatus();   
#endif
  // start the WiFi OTA library with internal (flash) based storage
  ArduinoOTA.begin(WiFi.localIP(), "arduino", "arduino", InternalStorage);
}

void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);


  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
