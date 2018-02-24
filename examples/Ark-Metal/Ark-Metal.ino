

#include <ark.h>
#include <yourWiFiLibrary.h>

/*  ==========================================================================  */
const char* ssid = "yourSSID";
const char* password = "yourWiFiPassword";
/*  ==========================================================================  */


/*  ==========================================================================  */
extern "C" {
#include "user_interface.h"
}
/*  ==========================================================================  */


/*  ==========================================================================  */
Address darkAddress = { "DHQ4Fjsyiop3qBR4otAjAu6cBHkgRELqGA" };
String darkBlockID = "4367122150875693402";
Publickey darkPubkey = { "0275776018638e5c40f1b922901e96cac2caa734585ef302b4a2801ee9a338a456" };
Hash transactionID = { "4e68a917d06382ce335656eef5560a537fc806ecadf3972c5221b86babecc63e" };
/*  ==========================================================================  */


/*  ==========================================================================  */
void reportFreeHeap() {
  Serial.println("system_get_free_heap_size: ");
  Serial.println(system_get_free_heap_size());
  Serial.println("\n=====\n");
  delay(50);
};
/*  ==========================================================================  */


/*  ==========================================================================  */
void testAccount(ARK::API::Manager _arkManager) {
  Serial.println("\n\n========== Account ==========\n\n=====\n");

/*  ==================================  */
 String balanceDescription = _arkManager.accountBalance(darkAddress).description();
    Serial.println("balanceDescription: ");
    Serial.println(balanceDescription);
    Serial.println("\n=====\n");
    delay(50); 
/*  ==================================  */

/*  ==================================  */
  String publicKeyDescription = _arkManager.accountPublickey(darkAddress).description();
    Serial.println("publicKeyDescription: ");
    Serial.println(publicKeyDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String delegatesFeeArk = _arkManager.accountDelegatesFee(darkAddress).ark;
    Serial.println("delegatesFeeArk: ");
    Serial.println(delegatesFeeArk);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String delegatesDescription = _arkManager.accountDelegates(darkAddress).description();
    Serial.println("delegatesDescription: ");
    Serial.println(delegatesDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String accountDescription = _arkManager.account(darkAddress).description();
    Serial.println("accountDescription: ");
    Serial.println(accountDescription);
    Serial.println();
/*  ==================================  */
  Serial.println("========== /Account ==========\n");
};
/*  ==========================================================================  */


/*  ==========================================================================  */
void testBlock(ARK::API::Manager _arkManager) {
  Serial.println("\n\n========== Block ==========\n\n=====\n");
/*  ==================================  */
  String blockDescription = _arkManager.block(darkBlockID).description();
    Serial.println("blockDescription: ");
    Serial.println(blockDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
/*  ==================================  */
/* needs stream->string size fix for large callbacks */
//  String blocks = _arkManager.blocks();
//    Serial.println(blocks);
//    Serial.println();
//    delay(50);
/*  ==================================  */
/*  ==================================  */

/*  ==================================  */
  String blockEpoch = _arkManager.blockEpoch();
    Serial.println("blockEpoch: ");
    Serial.println(blockEpoch);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String blockHeightDescription = _arkManager.blockHeight().description();
    Serial.println("blockHeightDescription: ");
    Serial.println(blockHeightDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String blockNethashDescription = _arkManager.blockNethash().description();
    Serial.println("blockNethashDescription: ");
    Serial.println(blockNethashDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String blockFeeArk = _arkManager.blockFee().ark;
    Serial.println("blockFeeArk: ");
    Serial.println(blockFeeArk);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String blockFeesDescription = _arkManager.blockFees().description();
    Serial.println("blockFeesDescription: ");
    Serial.println(blockFeesDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String blockMilestone = _arkManager.blockMilestone();
    Serial.println("blockMilestone: ");
    Serial.println(blockMilestone);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */
  String blockRewardArk = _arkManager.blockReward().ark;
    Serial.println("blockRewardArk: ");
    Serial.println(blockRewardArk);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String blockSupplyArk = _arkManager.blockSupply().ark;
    Serial.println("blockSupplyArk: ");
    Serial.println(blockSupplyArk);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String blockStatusDescription = _arkManager.blockStatus().description();
    Serial.println("blockStatusDescription: ");
    Serial.println(blockStatusDescription);
    delay(50);
/*  ==================================  */
  Serial.println("========== /Block ==========\n");
};
/*  ==========================================================================  */


/*  ==========================================================================  */
void testDelegate(ARK::API::Manager _arkManager) {
  Serial.println("\n\n========== Delegate ==========\n\n=====\n");
/*  ==================================  */
  int delegatesCount = _arkManager.delegatesCount();
    Serial.println("delegatesCount: ");
    Serial.println(delegatesCount);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String delegateSearchDescription = _arkManager.delegateSearch("sleepdeficit").description();
    Serial.println("delegateSearchDescription: ");
    Serial.println(delegateSearchDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String delegateVotersDescription = _arkManager.delegateVoters(darkPubkey).description();
    Serial.println("delegateVotersDescription: ");
    Serial.println(delegateVotersDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String delegateByUsernameDescription = _arkManager.delegate("sleepdeficit").description();
    Serial.println("delegateByUsernameDescription: ");
    Serial.println(delegateByUsernameDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String delegateByPublickeyDescription = _arkManager.delegate(darkPubkey.description()).description();
    Serial.println("delegateByPublickeyDescription: ");
    Serial.println(delegateByPublickeyDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
/*  ==================================  */
/*    BROKEN: fix for large callbacks    */
/*  Delegates callback is ~13,564 bytes  */
//  String delegates = _arkManager.getDelegates();
//    Serial.println("delegates: ");
//    Serial.println(delegates);
//    Serial.println("\n=====\n");
//    delay(50);
/*  ==================================  */
/*  ==================================  */

/*  ==================================  */
  String delegateFeeArk = _arkManager.delegateFee().ark;
    Serial.println("delegateFeeArk: ");
    Serial.println(delegateFeeArk);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String delegateForgedByAccount = _arkManager.delegateForgedByAccount(darkPubkey);
    Serial.println("delegateForgedByAccount: ");
    Serial.println(delegateForgedByAccount);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String delegateNextForgersDescription = _arkManager.delegateNextForgers().description();
    Serial.println("delegateNextForgersDescription: ");
    Serial.println(delegateNextForgersDescription);
    Serial.println("\n=====\n");
    delay(50);        
/*  ==================================  */
  Serial.println("========== /Delegate ==========\n");
};
/*  ==========================================================================  */


/*  ==========================================================================  */
void testLoader(ARK::API::Manager _arkManager) {
  Serial.println("\n\n========== Loader ==========\n\n=====\n");
/*  ==================================  */
  String loaderStatusDescription = _arkManager.loaderStatus().description();
    Serial.println("loaderStatusDescription: ");
    Serial.println(loaderStatusDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String loaderSyncDescription = _arkManager.loaderSync().description();
    Serial.println("loaderSyncDescription: ");
    Serial.println(loaderSyncDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String loaderAutoconfigureDescription = _arkManager.loaderAutoconfigure().description();
    Serial.println("loaderAutoconfigureDescription: ");
    Serial.println(loaderAutoconfigureDescription);
    Serial.println("\n=====\n");
    delay(50); 
/*  ==================================  */
  Serial.println("========== /Loader ==========\n");
};
/*  ==========================================================================  */


/*  ==========================================================================  */
void testPeer(ARK::API::Manager _arkManager) {
  Serial.println("\n\n========== Peer ==========\n\n=====\n");
/*  ==================================  */
  String peerDescription = _arkManager.peer("167.114.29.55", 4002).description();
    Serial.println("peerDescription: ");
    Serial.println(peerDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */
/*  ==================================  */

/*  ==================================  */
/*    BROKEN: fix for large callbacks  */
/*    Peers callback is ~10,000 bytes  */
//  String peersDescription = _arkManager.peers().description();
//    Serial.println("peersDescription: ");
//    Serial.println(peersDescription);
//    Serial.println("\n=====\n");
//    delay(50);
/*  ==================================  */
/*  ==================================  */

/*  ==================================  */
  String peerVersionDescription = _arkManager.peerVersion().description();
    Serial.println("peerVersionDescription: ");
    Serial.println(peerVersionDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */
  Serial.println("========== /Peer ==========\n");
};
/*  ==========================================================================  */


/*  ==========================================================================  */
void testSignatures(ARK::API::Manager _arkManager) {
  Serial.println("\n\n========== Signatures ==========\n\n=====\n");
/*  ==================================  */
  String signaturesFeeArk = _arkManager.signaturesFee().ark;
    Serial.println("signaturesFeeArk: ");
    Serial.println(signaturesFeeArk);
    Serial.println();
    delay(50);
/*  ==================================  */
  Serial.println("========== /Signatures ==========\n");
};
/*  ==========================================================================  */


/*  ==========================================================================  */
void testMultiSignatures(ARK::API::Manager _arkManager) {
  Serial.println("\n\n========== MultiSignatures ==========\n\n=====\n");
/*  ==================================  */
  String multisignaturesPending = _arkManager.multisignaturesPending(darkHash);
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
  Serial.println("========== /MultiSignatures ==========\n");
};
/*  ==========================================================================  */


/*  ==========================================================================  */
void testTransaction(ARK::API::Manager _arkManager) {
  Serial.println("\n\n========== Transaction ==========\n\n=====\n");
/*  ==================================  */
  String transactionFromIDDescription = _arkManager.transaction(transactionID).description(); //has vendorField value
    Serial.println("transactionFromIDDescription: ");
    Serial.println(transactionFromIDDescription);
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
  String transactionUnconfirmedFromIdDescription = _arkManager.transactionUnconfirmed(transactionID).description();
    Serial.println("transactionUnconfirmedFromIdDescription: ");
    Serial.println(transactionUnconfirmedFromIdDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */

/*  ==================================  */
  String transactionsUnconfirmedDescription = _arkManager.transactionsUnconfirmed().description();
    Serial.println("transactionsUnconfirmedDescription: ");
    Serial.println(transactionsUnconfirmedDescription);
    Serial.println("\n=====\n");
    delay(50);
/*  ==================================  */
  Serial.println("========== /Transaction ==========\n");
};
/*  ==========================================================================  */


/*  ==========================================================================  */
void setupWiFi() {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  { delay(500); Serial.println("waiting for connection..."); }
  Serial.print("local IP: "); Serial.println(WiFi.localIP());
};
/*  ==========================================================================  */


/*  ==========================================================================  */
void test() {
/*  ==================================  */
  reportFreeHeap();
/*  ==================================  */
  ARK::Network devnet = ARK::Constants::Networks::Devnet::model;
  ARK::API::Manager arkManager(devnet); // || arkManager.connect(mainnet);
    reportFreeHeap();
/*  ==================================  */
  testAccount(arkManager);
    reportFreeHeap();
/*  ==================================  */
/*  ==================================  */
  testBlock(arkManager);
    reportFreeHeap();
/*  ==================================  */
/*  ==================================  */
  testDelegate(arkManager);
    reportFreeHeap();
/*  ==================================  */
/*  ==================================  */
  testLoader(arkManager);
    reportFreeHeap();
/*  ==================================  */
/*  ==================================  */
  testPeer(arkManager);
    reportFreeHeap();
/*  ==================================  */
/*  ==================================  */
  testSignatures(arkManager);
    reportFreeHeap();
/*  ==================================  */
/*  ==================================  */
  testMultiSignatures(arkManager);
    reportFreeHeap();
/*  ==================================  */
/*  ==================================  */
  testTransaction(arkManager);
    reportFreeHeap();
/*  ==================================  */
};
/*  ==========================================================================  */


void setup() {
  Serial.begin(115200);
  setupWiFi();
}

void loop() {
  test();
  ESP.deepSleep(4294967000);
}