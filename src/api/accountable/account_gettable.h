

#ifndef ACCOUNT_GETTABLE_H
#define ACCOUNT_GETTABLE_H

namespace ARK
{
namespace API
{
namespace Account
{

/*************************************************
*  PROTECTED: ARK::API::Account::Gettable
**************************************************/

class Gettable
{
  protected:
		/*************************************************
		*	ARK::API::Account::Gettable::balance
		*		/api/accounts/getBalance?address=arkAddress
		**************************************************/
    ARK::API::Account::Respondable::Balances balance(
        ARK::Utilities::Network::Connector &netManager,
        const Address &arkAddress);

    ARK::API::Account::Respondable::Balances balancefromJSON(const char *const jsonStr);
    /*************************************************/


/**************************************************************************************************/


		/*************************************************
		*	ARK::API::Account::Gettable::publickey
		*		/api/accounts/getPublickey?address=arkAddress
		**************************************************/
    Publickey publickey(
        ARK::Utilities::Network::Connector &netManager,
        const Address &arkAddress);

    Publickey publickeyfromJSON(const char *const jsonStr);
    /*************************************************/


/**************************************************************************************************/


		/*************************************************
		*	ARK::API::Account::Gettable::delegatesFee
		*		/api/accounts/delegates/fee?address=arkAddress
		**************************************************/
    Balance delegatesFee(
        ARK::Utilities::Network::Connector &netManager,
        const Address &arkAddress);

    Balance delegatesFeefromJSON(const char *const jsonStr);
    /*************************************************/


/**************************************************************************************************/


		/*************************************************
		*	ARK::API::Account::Gettable::delegates
		*		/api/accounts/delegates?address=arkAddress
		**************************************************/
    ARK::Delegate delegates(
        ARK::Utilities::Network::Connector &netManager,
        const Address &arkAddress);

    ARK::Delegate delegatesfromJSON(const char *const jsonStr);
    /*************************************************/


/**************************************************************************************************/


		/*************************************************
		*	ARK::API::Account::Gettable::account
		*		/api/accounts?address=arkAddress 
		**************************************************/
    ARK::Account account(
        ARK::Utilities::Network::Connector &netManager,
        const Address &arkAddress);

    ARK::Account accountfromJSON(const char *const jsonStr);
    /*************************************************/
};
/*************************************************/
};
};
};


/*************************************************
*	ARK::API::Account::Gettable::balance
*		/api/accounts/getBalance?address=arkAddress
**************************************************/
ARK::API::Account::Respondable::Balances ARK::API::Account::Gettable::balance(
    ARK::Utilities::Network::Connector &netManager,
    const Address &arkAddress)
{
	char uri[256] = {'\0'}; // TODO: check size
	strcpy(uri, ARK::API::Paths::Account::getBalance_s);
	strcat(uri, "?address=");
	strcat(uri, arkAddress.value);

	auto callback = netManager.cb(uri);

	return ARK::API::Account::Gettable::balancefromJSON(callback);
};
/*************************************************
*
*	{
*		"success":true,
*		"balance":  "Balance",
*		"unconfirmedBalance": "Balance"
*	}
*
**************************************************/
ARK::API::Account::Respondable::Balances ARK::API::Account::Gettable::balancefromJSON(const char *const jsonStr)
{
	ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
	return {
		Balance(parser.valueFor("balance")),
		Balance(parser.valueFor("unconfirmedBalance"))
	};
};
/*************************************************/


/**************************************************************************************************/


/*************************************************
*	ARK::API::Account::Gettable::publickey
*		/api/accounts/getPublickey?address=arkAddress
**************************************************/
Publickey ARK::API::Account::Gettable::publickey(
    ARK::Utilities::Network::Connector &netManager,
    const Address &arkAddress)
{
	char uri[256] = {'\0'}; // TODO:  check size

	strcpy(uri, ARK::API::Paths::Account::getPublickey_s);
	strcat(uri, "?address=");
	strcat(uri, arkAddress.value);

	auto callback = netManager.cb(uri);
	return ARK::API::Account::Gettable::publickeyfromJSON(callback);
};
/*************************************************
*
*	{
*		"success":true,
*		"publicKey":  "Publickey"
*	}
*
**************************************************/
Publickey ARK::API::Account::Gettable::publickeyfromJSON(const char *const jsonStr)
{
	ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
	return Publickey(parser.valueFor("publicKey"));
};
/*************************************************/


/**************************************************************************************************/


/*************************************************
*	ARK::API::Account::Gettable::delegatesFee
*		/api/accounts/delegates/fee?address=arkAddress
**************************************************/
Balance ARK::API::Account::Gettable::delegatesFee(
    ARK::Utilities::Network::Connector &netManager,
    const Address &arkAddress)
{

	char uri[256] = {'\0'}; // TODO:  check size

	strcpy(uri, ARK::API::Paths::Account::delegatesFee_s);
	strcat(uri, "?address=");
	strcat(uri, arkAddress.value);

	auto callback = netManager.cb(uri);

	return ARK::API::Account::Gettable::delegatesFeefromJSON(callback);
};
/*************************************************
*
*	{
*		"success":true,
*		"fee":2500000000
*	}
*
**************************************************/
Balance ARK::API::Account::Gettable::delegatesFeefromJSON(const char *const jsonStr)
{
	ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
	return Balance(parser.valueFor("fee"));
};
/*************************************************/


/**************************************************************************************************/


/*************************************************
*	ARK::API::Account::Gettable::delegates
*		/api/accounts/delegates?address=arkAddress
**************************************************/
ARK::Delegate ARK::API::Account::Gettable::delegates(
    ARK::Utilities::Network::Connector &netManager,
    const Address &arkAddress)
{
	char uri[256] = {'\0'}; // TODO:  check size

	strcpy(uri, ARK::API::Paths::Account::delegates_s);
	strcat(uri, "?address=");
	strcat(uri, arkAddress.value);

	auto callback = netManager.cb(uri);
	return ARK::API::Account::Gettable::delegatesfromJSON(callback);
};
/*************************************************
*
*	{
*		"success":true,
*		"delegates":
*		[
*			{
*				"username": "sleepdeficit",
*				"address":  "Address",
*				"publicKey":  "Publickey",
*				"vote": "Balance",
*				"producedblocks": const char*,
*				"missedblocks": String,
*				"rate": int,
*				"approval": double,
*				"productivity": double
*			}
*		]
*	}
*
**************************************************/
ARK::Delegate ARK::API::Account::Gettable::delegatesfromJSON(const char *const jsonStr)
{
    ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));

    return {
        parser.subarrayValueIn("delegates", 0, "username"),
        Address(parser.subarrayValueIn("delegates", 0, "address")),
        Publickey(parser.subarrayValueIn("delegates", 0, "publicKey")),
        Balance(parser.subarrayValueIn("delegates", 0, "vote")),
        atoi(parser.subarrayValueIn("delegates", 0, "producedblocks")),
        atoi(parser.subarrayValueIn("delegates", 0, "missedblocks")),
        atoi(parser.subarrayValueIn("delegates", 0, "rate")),
        atof(parser.subarrayValueIn("delegates", 0, "approval")),
        atof(parser.subarrayValueIn("delegates", 0, "productivity"))
    };
};
/*************************************************/


/**************************************************************************************************/


/*************************************************
*	ARK::API::Account::Gettable::account
*		/api/accounts?address=arkAddress 
**************************************************/
ARK::Account ARK::API::Account::Gettable::account(
    ARK::Utilities::Network::Connector &netManager,
    const Address &arkAddress)
{
	char uri[81 + 1] = {'\0'}; // TODO:  check size

	strcpy(uri, ARK::API::Paths::Account::accounts_s);
	strcat(uri, "?address=");
	strcat(uri, arkAddress.value);

	auto callback = netManager.cb(uri);
	return ARK::API::Account::Gettable::accountfromJSON(callback);
};

/*

}
*/
/*************************************************
*
*	{
*		"success":true,
*		"account":
*		{
*			"address":  "Address",
*			"unconfirmedBalance": "Balance",
*			"balance":  "Balance",
*			"publicKey":  "Publickey",
*			"unconfirmedSignature": int,
*			"secondSignature":  int,
*			"secondPublicKey":  "Publickey",
*			"multisignatures":[],
*			"u_multisignatures":[]
*		}
*	}
*
**************************************************/
ARK::Account ARK::API::Account::Gettable::accountfromJSON(const char *const jsonStr)
{
	ARK::Utilities::JSONParser parser(jsonStr, strlen(jsonStr));
	return {
		Address(parser.subvalueIn("account", "address")),
		Balance(parser.subvalueIn("account", "unconfirmedBalance")),
		Balance(parser.subvalueIn("account", "balance")),
		Publickey(parser.subvalueIn("account", "publicKey")),
		atoi(parser.subvalueIn("account", "unconfirmedSignature")),
		atoi(parser.subvalueIn("account", "secondSignature")),
		Publickey(parser.subvalueIn("account", "secondPublicKey")),
		Signature(parser.subvalueIn("account", "multisignatures")),
		Signature(parser.subvalueIn("account", "u_multisignatures"))
	};
};
/*************************************************/


#endif
