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

Hash transactionID("4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e");

/*  ==================================  */
	char buf[1024] = {};
	_arkManager.transaction(transactionID).description(buf, sizeof(buf)); //has vendorField value
    Serial.println("transactionFromIDDescription: ");
    Serial.println(buf);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
/*  ==================================  */
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~28,908 bytes  */
//  String transactions = _arkManager.transactions();
//    Serial.println("transactions: ");
//    Serial.println(transactions);
//    Serial.println("\n=====\n");
//    delay(50);
/*  ==================================  */
/*  ==================================  */

/*  ==================================  */
	const auto transactionUnconfirmedFromId = _arkManager.transactionUnconfirmed(transactionID);
    Serial.println("transactionUnconfirmedFromId: ");
    Serial.println(transactionUnconfirmedFromId);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
	const auto transactionsUnconfirmed = _arkManager.transactionsUnconfirmed();
    Serial.println("transactionsUnconfirmed: ");
    Serial.println(transactionsUnconfirmed);
    Serial.println("\n=====\n");
    delay(50);
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