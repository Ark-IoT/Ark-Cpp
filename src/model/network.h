

#ifndef network_h
#define network_h

#include <cstring>

namespace ARK {

/*  ================================================  */
/*  ARK::NetworkType  */
  enum NetworkType { INVALID = -1, DEV = 0, MAIN = 1, CUSTOM = 2 };
/*  ================================================  */

/********************************************************************************
*
* Network: 
*  	578e820911f24e039733b45e4882b73e301f813a0d2c31330dafda84534ffa23
*		DARK
*		DѦ
*		https://dexplorer.ark.io/
*		30
*
********************************************************************************/

/*  ================================================  */
  /*  ============  */
  /*  ARK::Network  */
struct Network {
public:
    char nethash[65];		//TODO: review sizes
    char token[8];
    char symbol[4];
    char explorer[65];
    int version;

    Network() : nethash(), token(), symbol(), explorer(), version(-1) { }
    Network(
        const char* const n, 
        const char* const t, 
        const char* const s, 
        const char* const e, 
        int v
    ) : nethash(), token(), symbol(), explorer(), version(v) { 
        strncpy(nethash, n, sizeof(nethash) / sizeof(nethash[0]));
        strncpy(token, t, sizeof(token) / sizeof(token[0]));
        strncpy(symbol, s, sizeof(symbol) / sizeof(symbol[0]));
        strncpy(explorer, e, sizeof(explorer) / sizeof(explorer[0]));
    }

    void description(char* const buf, size_t size) const;

    bool operator==(const Network& rhs) const;
    bool operator!=(const Network& rhs) const;
};
  /*  ============  */
  /*  ================================================  */
  /*  ================  */
  /*  ARK::Network_ADV  */
  namespace Network_ADV {
    struct bip32_t {
      long pub;         // base58 will have a prefix 'apub'
      long priv;        // base58Priv will have a prefix 'apriv'
    };

    struct network_t {
      const char* messagePrefix;
      bip32_t bip32;
      long pubKeyHash;  // Addresses will begin with 'A'
      long wif;         // Network prefix for wif generation
    };
  };
/*  ================  */

};


#endif
