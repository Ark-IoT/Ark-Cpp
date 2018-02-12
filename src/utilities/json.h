

#ifndef JSON_H
#define JSON_H

namespace ARK
{
namespace Utilities
{

/*  ==========================================================================  */
/**************************************************
* ARK::Utilities::JSONString 
*
* The purpose of this class is to serve as an
*   entry point for integrating and simplifying
*   integration of a JSON library
**************************************************/
  struct JSONString
  {

    private:
      String jsonStr;

    public:
      JSONString(const String& _jsonStr);
      String valueFor(const String& _key);
      String valueIn(const String& _key, const String& _subkey);
      String subvalueFor(const String& _key, int _pos);
      String subvalueIn(const String& _key, const String& _subkey);
      String subarrayValueIn(const String& _key, int _pos, const String& _subkey);
  };
/*  ==========================================================================  */


};
};





/*  ==========================================================================  */
/**************************************************
* Initialize from a JSON String
**************************************************/
ARK::Utilities::JSONString::JSONString(const String& _jsonStr)
{
  this->jsonStr = _jsonStr;
};

/**************************************************
* valueFor(key)
*
* { "key1": value1, "key2": value2 } 
**************************************************/
String ARK::Utilities::JSONString::valueFor(const String& _key)
{
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
  return root[_key];
}

/**************************************************
* valueIn(key, subkey)
*
* 
**************************************************/
String ARK::Utilities::JSONString::valueIn(const String& _key, const String& _subkey)
{
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
  return root[_key][_subkey];
}

/**************************************************
* subvalueFor(key, position)
*
* { "key": { subValue1, subvalue2 } } 
**************************************************/
String ARK::Utilities::JSONString::subvalueFor(const String& _key, int _pos)
{
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
  return root[_key][_pos];
}


/**************************************************
* subvalueIn(key, subkey)
*
*  
**************************************************/
String ARK::Utilities::JSONString::subvalueIn(const String& _key, const String& _subkey)
{
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
  JsonObject &newRoot = root[_key];
  return newRoot[_subkey];
}

/**************************************************
* subarrayValueIn(key, position, subkey)
*
*  
**************************************************/
String ARK::Utilities::JSONString::subarrayValueIn(const String& _key, int _pos, const String& _subkey)
{
  const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
  DynamicJsonBuffer jsonBuffer(capacity);
  JsonObject &root = jsonBuffer.parseObject(this->jsonStr);
  // JsonArray& root = jsonBuffer.parseArray(this->jsonStr);
  return root[_key][_pos][_subkey];
}
/*  ==========================================================================  */





/*  ==========================================================================  */
/*  ==========================================================================  */
// /**************************************************
// * ARK::Utilities::JSONChar 
// *
// * The purpose of this class is to serve as an
// *   entry point for integrating and simplifying
// *   integration of a JSON library
// **************************************************/
// struct JSONChar
// {
//   private:
//     char *jsonChars;
//   public:
//     JSONChar(const char *_jsonChars);
//     const char *subvalueIn(const char *_key, const char *_subkey);
//     const char *subarrayValueIn(const char *_key, int _pos, const char *_subkey);
// };
// ARK::Utilities::JSONChar::JSONChar(const char *_jsonChars)
// {
//   strcpy(this->jsonChars, _jsonChars);
// };
// const char *ARK::Utilities::JSONChar::subvalueIn(const char *key, const char *subkey)
// {
//   const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
//   DynamicJsonBuffer jsonBuffer(capacity);
//   JsonObject &root = jsonBuffer.parseObject(this->jsonChars);
//   jsonBuffer.clear();
//   JsonObject &newRoot = root[key];
//   return newRoot[subkey];
// }
// const char *ARK::Utilities::JSONChar::subarrayValueIn(const char *_key, int _pos, const char *_subkey)
// {
//   const size_t capacity = JSON_OBJECT_SIZE(3) + JSON_ARRAY_SIZE(2) + 60;
//   DynamicJsonBuffer jsonBuffer(capacity);
//   jsonBuffer.clear();
//   JsonObject &root = jsonBuffer.parseObject(this->jsonChars);
//   // JsonArray& root = jsonBuffer.parseArray(this->jsonChars);
//   return root[_key][_pos][_subkey];
// }
/*  ==========================================================================  */
/*  ==========================================================================  */

#endif
