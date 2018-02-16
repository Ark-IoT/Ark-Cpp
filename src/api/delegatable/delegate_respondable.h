

#ifndef DELEGATE_RESPONDABLE_H
#define DELEGATE_RESPONDABLE_H

namespace ARK
{
namespace API
{
namespace Delegate
{
namespace Respondable
{


/*************************************************
*	ARK::API::Delegate::Respondable::Search
*
*		@variables:
*			const char* username;
*			Address address;
*			Publickey publicKey;
*			const Balance vote;
*			int producedblocks;
*			int missedblocks;
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*			Model for Delegate Search API Response
*
**************************************************/
struct Search
{
  public:
    const char* username;
    Address address;
    Publickey publicKey;
    const Balance vote;
    int producedblocks;
    int missedblocks;

    void printTo(HardwareSerial &serial);
};
/*************************************************/


/**************************************************************************************************/


/*************************************************
*	ARK::API::Delegate::Respondable::Voters
*
*		@variables:
*			size_t count;
*			ARK::Voter* const _voters;
*
*   @methods:	printTo(HardwareSerial &serial)
*		@deconstuctor:	~Voters() { delete [] _voters; };
*		@operators: 
*			Voter& operator[](size_t index)
*			Voter& operator[](size_t index)
*
*   @description:
*			Model for Delegate Voters API Response
*
**************************************************/
struct Voters
{
	public:
    size_t count;
    ARK::Voter* const _voters;

    Voters(size_t c) : count(c), _voters(new ARK::Voter[c]) { }

    ~Voters() {
			delete [] _voters;
    }

    const Voter& operator[](size_t index) const { return _voters[index]; }
    Voter& operator[](size_t index) { return _voters[index]; }

    void printTo(HardwareSerial &serial);
};
/*************************************************/


/**************************************************************************************************/


/*************************************************
*	ARK::API::Delegate::Respondable::ForgedByAccount
*
*		@variables:
*			const Balance fees;
*			const Balance rewards;
*			const Balance forged;
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*			Model for Delegate Forging Totals API Response
*
**************************************************/
struct ForgedByAccount
{
	public:
    const Balance fees;
    const Balance rewards;
    const Balance forged;

    void printTo(HardwareSerial &serial);
};
/*************************************************/


/**************************************************************************************************/


/*************************************************
*	ARK::API::Delegate::Respondable::NextForgers
*
*		@variables:
*			char currentBlock[64];
*			char currentSlot[64];
*			Publickey* const delegateKeys = new Publickey[10];
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*			Model for Next 10 Forging Delegate Publickeys API Response
*
**************************************************/
struct NextForgers
{
	public:
		char currentBlock[64];
		char currentSlot[64];
		Publickey* const delegateKeys = new Publickey[10];

		NextForgers(
				const char* const _currentBlock,
				const char* const _currentSlot,
				const Publickey* const _delegates);

		void printTo(HardwareSerial &serial);
};
/*************************************************/

};
};
};
};


/*************************************************
*	ARK::API::Delegate::Respondable::Search 
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*     Prints API Delegate Search Response to Serial
*
**************************************************/
void ARK::API::Delegate::Respondable::Search::printTo(HardwareSerial &serial)
{
    serial.print("\nusername: ");
    serial.print(this->username);
    serial.print("\naddress: ");
    serial.print(this->address.value);
    serial.print("\npublicKey: ");
    serial.print(this->publicKey.value);
    serial.print("\nvote: ");
    serial.print(this->vote.ark());
    serial.print("\nproducedblocks: ");
    serial.print(this->producedblocks);
    serial.print("\nmissedblocks: ");
    serial.print(this->missedblocks);
    serial.print("\n");
    serial.flush();
}
/*************************************************/


/**************************************************************************************************/


/*************************************************
*	ARK::API::Delegate::Respondable::Voters 
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*     Prints API Delegate Voters Response to Serial
*
**************************************************/
void ARK::API::Delegate::Respondable::Voters::printTo(HardwareSerial &serial)
{
  if (this->count > 0) {
      serial.print("\n\0");
    for (int i = 0; i < static_cast<int>(this->count); i++) {
        serial.print("\nvoter ");
        serial.print(i + 1);
        serial.print(":\n");
        (*this)[i].printTo(serial);
        serial.print("\n");
    };
  };
  serial.flush();
}
/*************************************************/


/**************************************************************************************************/


/*************************************************
*	ARK::API::Delegate::Respondable::ForgedByAccount 
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*     Prints API Delegate Forging Totals to Serial
*
**************************************************/
void ARK::API::Delegate::Respondable::ForgedByAccount::printTo(HardwareSerial &serial)
{
    serial.print("\nfees: ");
    serial.print(this->fees.ark());
    serial.print("\nrewards: ");
    serial.print(this->rewards.ark());
    serial.print("\nforged: ");
    serial.print(this->forged.ark());
    serial.print("\n");
    serial.flush();
}
/*************************************************/


/**************************************************************************************************/


/*************************************************
*	ARK::API::Delegate::Respondable::NextForgers 
*
*   @constructor:
*			NextForgers(
*				const char* const _currentBlock,
*				const char* const _currentSlot,
*				const Publickey* const _delegates
*			)
*
*   @description:
*     Constructs API Delegate NextForgers Response
*
**************************************************/
ARK::API::Delegate::Respondable::NextForgers::NextForgers(
		const char* const _currentBlock,
		const char* const _currentSlot,
		const Publickey* const _delegates) :
				currentBlock(), currentSlot()
{
	strncpy(this->currentBlock, _currentBlock, sizeof(this->currentBlock));
	strncpy(this->currentSlot, _currentSlot, sizeof(this->currentSlot));
	for (auto i = 0; i < 10; ++i)
	{
		this->delegateKeys[i] = _delegates[i];
	};
}


/*************************************************
*	ARK::API::Delegate::Respondable::NextForgers 
*
*   @methods:	printTo(HardwareSerial &serial)
*
*   @description:
*     Prints Next 10 Forging Delegate Publickeys to Serial
*
**************************************************/
void ARK::API::Delegate::Respondable::NextForgers::printTo(HardwareSerial &serial)
{
	serial.print("\ncurrentBlock: ");
	serial.print(this->currentBlock);
	serial.print("\ncurrentSlot: ");
	serial.print(this->currentSlot);
	serial.print("\n");

	for (int i = 0; i < 9; i++)
	{
		serial.print("delegate ");
		serial.print(i + 1);
		serial.print(": \n publicKey: ");
		serial.print(delegateKeys[i].value);
		serial.print("\n");
	};
	serial.flush();
}
/*************************************************/


#endif
