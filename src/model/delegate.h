

#ifndef delegate_h
#define delegate_h

/********************************************************************************
*
* delegate: 
*		{  
*			"username": String,
*			"address":	Address,
*			"publicKey":	Publickey,
*			"vote":	Balance,
*			"producedblocks": uint,
*			"missedblocks":	uint,
*			"rate":	int,
*			"approval": double,
*			"productivity":	double
*		}
*
********************************************************************************/

namespace ARK
{
	
/*  ================================================  */
/*  =============  */
/*  ARK::Delegate  */
struct Delegate
{
public:
	char username[1024];
	Address address;
	Publickey publicKey;
	Balance vote;
	int producedblocks;
	int missedblocks;
	int rate;
	double approval;
	double productivity;

	void description(char* const buf, size_t size);

};
/*  =============  */
/*  ================================================  */

}

/*  ================================================  */
/*  =====  */
/*  Description  */
void ARK::Delegate::Delegate::description(char* const buf, size_t size)
{
    //TODO:  check len for sufficient size  
    strcpy(buf, "username: ");
    strcat(buf, this->username);
    strcat(buf, "\naddress.description: ");
    strcat(buf, this->address.description());
    strcat(buf, "\npublicKey.description: ");
    strcat(buf, this->publicKey.description());
    strcat(buf, "\nvote.ark: ");
    strcat(buf, this->vote.ark());
    strcat(buf, "\nproducedblocks: ");
    sprintf(buf + strlen(buf), "%d", this->producedblocks);
    strcat(buf, "\nmissedblocks: ");
    sprintf(buf + strlen(buf), "%d", this->missedblocks);
    strcat(buf, "\nrate: ");
    sprintf(buf + strlen(buf), "%d", this->rate);
    strcat(buf, "\napproval: ");
    sprintf(buf + strlen(buf), "%f", this->approval);
    strcat(buf, "%\nproductivity: ");
    sprintf(buf + strlen(buf), "%f", this->productivity);
    strcat(buf, "%");
}
/*  =====  */
/*  ================================================  */

#endif
