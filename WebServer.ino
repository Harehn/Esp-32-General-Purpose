/* 
*  @Author: Nitin Kaundun
*  @Date: Dec 2025
*  @File: WebServer.ino
*  @Description: This file contains the code to create a web server interface for ESP32
*/

#include <WiFi.h>
#include <NetworkClient.h>
#include <WebServer.h>
#include <ESPmDNS.h>

const char *ssid = "........";
const char *password = "........";

WebServer server(80);

/*
* Example function for returning for a route 
*/
void handleRoot() {
  server.send(200, "text/plain", "hello from esp32!");
}

/*
* Example function for returning for a route 
*/
void handleNotFound() {
    server.send(404, "text/plain", "Page Not Found");
}

/*
* Create and set up the server
* @return true if set up properly else false 
*/
bool set_up_server() {
  //------------------ SET UP -----------------------------
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  //------------------ WAIT FOR CONNECTION -----------------
  int iteration = 0;
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
    iteration += 1;
    if (iteration == 30) return false;
  }

  //----------------- PRINT DETAILS ------------------------
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

    if (MDNS.begin("esp32")) {
    Serial.println("MDNS responder started");
  }

  //---------------- SET UP ROUTES --------------------------
  server.on("/", handleRoot);

  server.on("/inline", []() {
    server.send(200, "text/plain", "this works as well");
  });

  server.onNotFound(handleNotFound);

  //---------------- START SERVER ---------------------------
  server.begin();
  Serial.println("HTTP server started");
}

/*
* @prerequisite needs the server to be set up
* wrapper for server handle client 
*/
void server_update(){
  server.handleClient();
  delay(2);  //allow the cpu to switch to other tasks
}