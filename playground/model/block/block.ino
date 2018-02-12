#include <ark.h>

/********************************************************************************
*
* block: 
*   {
*     "id": String,                         //  "5907849310697169543",
*     "version":  int,                      //  0,
*     "timestamp":  String,                 //  27400752,
*     "height": String,                     //  2467562,
*     "previousBlock":  String,             //  "7012858385202614513",
*     "numberOfTransactions": String,       //  0,
*     "totalAmount":  Balance,              //  0,
*     "totalFee": Balance,                  //  0,
*     "reward": Balance,                    //  200000000,
*     "payloadLength":  String,             //  0,
*     "payloadHash":  Hash,                 //  "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
*     "generatorPublicKey": Publickey,      //  "03127001718bee76f14133272f0f4a928ffa8c2b38cafd94d7100253dac732c644",
*     "generatorId":  Address,              //  "D9rv3h61heDYHQ3b3Xk3V5epHSTTC6Vn1d",
*      "blockSignature":  Signature,        //  "3045022100e0fc6b066209fd9a70e61372cda2e38431ace5cf79ee0557eb2b1b14315d70f302201978696b71c9a177fa1ce9480ceb1ad04a15471d4c6e8d5b2dcd6d931f350efe",
*     "confirmations":  String,             //  3,
*     "totalForged":  Balance               //  "200000000"
*   }
*
********************************************************************************/

void constructBlock() {

  ARK::Block block(
    "5907849310697169543",
    0,
    "27400752",
    "2467562",
    "7012858385202614513",
    "0",
    "0",
    "0",
    "200000000",
    "0",
    "e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",
    "03127001718bee76f14133272f0f4a928ffa8c2b38cafd94d7100253dac732c644",
    "D9rv3h61heDYHQ3b3Xk3V5epHSTTC6Vn1d",
    "3045022100e0fc6b066209fd9a70e61372cda2e38431ace5cf79ee0557eb2b1b14315d70f302201978696b71c9a177fa1ce9480ceb1ad04a15471d4c6e8d5b2dcd6d931f350efe",
    "3",
    "200000000"
  );

  Serial.println("Offline Instantiated Block Description\n"); 
  char buf[512] = {};
  block.description(buf, sizeof(buf));
  Serial.println(buf); 

};


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
  constructBlock();
    reportFreeHeap();
  ESP.deepSleep(4294967000);
}

void setup() {
  Serial.begin(115200);
    reportFreeHeap();
  check();
}

void loop() {}