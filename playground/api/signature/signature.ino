#include <ark.h>
//#include <yourWiFiLibrary.h>
/*  example: #include <ESP8266WiFi.h> */

const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";


/********************************************************************************
* block: 
********************************************************************************/


void checkAPI() {
/*  ==================================  */
  ARK::Network devnet = ARK::Constants::Networks::Devnet::model;
  ARK::API::Manager _arkManager(devnet);
/*  ==================================  */

Publickey darkPubkey("0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456" );

/*  ==================================  */
  const auto signaturesFee = _arkManager.signaturesFee();
    Serial.println("signaturesFeeArk: ");
    Serial.println(signaturesFee.ark());
    Serial.println();
    delay(50);
/*  ==================================  */


/*  ==================================  */
  const auto multisignaturesPending = _arkManager.multisignaturesPending(darkPubkey);
    Serial.println("multisignaturesPending: ");
    Serial.println(multisignaturesPending);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
/*  ==================================  */
/*  Only on Mainnet?  */
//  String multisignaturesAccounts = _arkManager.multisignaturesAccounts(darkHash);
//    Serial.println("multisignaturesAccounts: ");
//    Serial.println(multisignaturesAccounts);
//    Serial.println("\n=====\n");
//    delay(50);
/*  ==================================  */
/*  ==================================  */

}


/*  ==========================================================================  */
extern "C" {
#include "user_interface.h"
}
void reportFreeHeap() {
  Serial.print("\n\nsystem_get_free_heap_size: ");
  Serial.print(system_get_free_heap_size());
  Serial.println("\n\n");
};
/*  ==========================================================================  */


void check() {
  checkAPI();
    reportFreeHeap();
  ESP.deepSleep(4294967000);
}

void setup() {
  Serial.begin(115200);
    reportFreeHeap();
	WiFi.begin(ssid, password);
	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
		Serial.print(".");
	}
	Serial.println();

	Serial.print("Connected, IP address: ");
	Serial.println(WiFi.localIP());
  check();
}

void loop() {}