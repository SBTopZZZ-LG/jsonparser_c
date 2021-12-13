#ifndef JSONPARSER_H
#define JSONPARSER_H

// Includes
#include <stdlib.h>
#include <string.h>
//      My Libraries
#include "ntoa.h"
#include "aton.h"

// Collection Constants
const int COLLECTION_SIZE = 2048;
const int COLLECTION_STRING_SIZE = 5192;
const int COLLECTION_NUMBER_SIZE = 28;
const int COLLECTION_STRINGIFY_SIZE = 4096;
// Json Constants
const int JSON_SIZE = 2048;
const int JSON_KEY_MAX_LENGTH = 1024;
const int JSON_STRING_SIZE = 5192;
const int JSON_NUMBER_SIZE = 28;
const int JSON_STRINGIFY_SIZE = 4096;

// Collection
struct Collection
{
    void *collection[COLLECTION_SIZE];
    int length;
    int id_record[COLLECTION_SIZE];
};
// Json
struct Json
{
    char key[JSON_KEY_MAX_LENGTH];
    void *collection[JSON_SIZE];
    int length;
    int id_record[JSON_SIZE];
};

// Collection Data Types
typedef struct
{
    char str[COLLECTION_STRING_SIZE];
} CollectionString;
typedef struct
{
    char num[COLLECTION_NUMBER_SIZE];
} CollectionNumber;
typedef struct
{
    int boolean;
} CollectionBoolean;
typedef struct
{
    struct Collection arr;
} CollectionArray;
typedef struct
{
    struct Json jsonObject;
} CollectionJsonObject;

// Json Data Types
typedef struct
{
    char key[JSON_KEY_MAX_LENGTH];
    char str[JSON_STRING_SIZE];
} JsonString;
typedef struct
{
    char key[JSON_KEY_MAX_LENGTH];
    char num[JSON_NUMBER_SIZE];
} JsonNumber;
typedef struct
{
    char key[JSON_KEY_MAX_LENGTH];
    int boolean;
} JsonBoolean;
typedef struct
{
    char key[JSON_KEY_MAX_LENGTH];
    struct Collection arr;
} JsonArray;

// Collection Function Prototypes
//      Init
void initializeCollection(struct Collection *);
//      Push
//          String
void pushString_collection(struct Collection *, char *);
//          Number
void pushNumber_collection(struct Collection *, char *);
void pushInt8_collection(struct Collection *, int8_t);
void pushInt16_collection(struct Collection *, int16_t);
void pushInt32_collection(struct Collection *, int32_t);
void pushInt64_collection(struct Collection *, int64_t);
void pushUInt8_collection(struct Collection *, uint8_t);
void pushUInt16_collection(struct Collection *, uint16_t);
void pushUInt32_collection(struct Collection *, uint32_t);
void pushUInt64_collection(struct Collection *, uint64_t);
void pushFloat_collection(struct Collection *, float);
void pushDouble_collection(struct Collection *, double);
//          Boolean
void pushBoolean_collection(struct Collection *, int);
//          Array
void pushArray_collection(struct Collection *, struct Collection *);
//          JsonObject
void pushJsonObject_collection(struct Collection *, struct Json *);
//      Delete
int deleteAt_collection(struct Collection *, int);
//      Modify
//          String
int modifyString_collection(struct Collection *, int, char *);
//          Number
int modifyNumber_collection(struct Collection *, int, char *);
int modifyInt8_collection(struct Collection *, int, int8_t);
int modifyInt16_collection(struct Collection *, int, int16_t);
int modifyInt32_collection(struct Collection *, int, int32_t);
int modifyInt64_collection(struct Collection *, int, int64_t);
int modifyUInt8_collection(struct Collection *, int, uint8_t);
int modifyUInt16_collection(struct Collection *, int, uint16_t);
int modifyUInt32_collection(struct Collection *, int, uint32_t);
int modifyUInt64_collection(struct Collection *, int, uint64_t);
int modifyFloat_collection(struct Collection *, int, float);
int modifyDouble_collection(struct Collection *, int, double);
//          Boolean
int modifyBoolean_collection(struct Collection *, int, int);
//          Array
int modifyArray_collection(struct Collection *, int, struct Collection *);
//          JsonObject
int modifyJsonObject_collection(struct Collection *, int, struct Json *);
//      Get
//          String
CollectionString *getString_collection(struct Collection *, int);
//          Number
CollectionNumber *getNumber_collection(struct Collection *, int);
int8_t getInt8_collection(struct Collection *, int);
int16_t getInt16_collection(struct Collection *, int);
int32_t getInt32_collection(struct Collection *, int);
int64_t getInt64_collection(struct Collection *, int);
uint8_t getUInt8_collection(struct Collection *, int);
uint16_t getUInt16_collection(struct Collection *, int);
uint32_t getUInt32_collection(struct Collection *, int);
uint64_t getUInt64_collection(struct Collection *, int);
float getFloat_collection(struct Collection *, int);
double getDouble_collection(struct Collection *, int);
//          Boolean
CollectionBoolean *getBoolean_collection(struct Collection *, int);
//          Array
CollectionArray *getArray_collection(struct Collection *, int);
//          JsonObject
CollectionJsonObject *getJsonObject_collection(struct Collection *, int);
//      Misc
void clearCollection(struct Collection *);
void copyToCollection(struct Collection *, struct Collection *);
void stringifyCollection(struct Collection *, char *);
int extractString(char *, int, char *);
int extractNumber(char *, int, char *);
int extractBoolean(char *, int, int *);
int extractArray(char *, int, char *);
int extractJsonObject(char *, int, char *);
void unstringifyCollection(char *, struct Collection *);

// Json Function Prototypes
//      Init
void initializeJson(struct Json *);
//      Put
//          String
void putString_json(struct Json *, char *, char *);
//          Number
void putNumber_json(struct Json *, char *, char *);
void putInt8_json(struct Json *, char *, int8_t);
void putInt16_json(struct Json *, char *, int16_t);
void putInt32_json(struct Json *, char *, int32_t);
void putInt64_json(struct Json *, char *, int64_t);
void putUInt8_json(struct Json *, char *, uint8_t);
void putUInt16_json(struct Json *, char *, uint16_t);
void putUInt32_json(struct Json *, char *, uint32_t);
void putUInt64_json(struct Json *, char *, uint64_t);
void putFloat_json(struct Json *, char *, float);
void putDouble_json(struct Json *, char *, double);
//          Boolean
void putBoolean_json(struct Json *, char *, int);
//          Array
void putArray_json(struct Json *, char *, struct Collection *);
//          JsonObject
void putJsonObject_json(struct Json *, char *, struct Json *);
//      Modify
//          String
int modifyString_json(struct Json *, char *, char *);
//          Number
int modifyNumber_json(struct Json *, char *, char *);
int modifyInt8_json(struct Json *, char *, int8_t);
int modifyInt16_json(struct Json *, char *, int16_t);
int modifyInt32_json(struct Json *, char *, int32_t);
int modifyInt64_json(struct Json *, char *, int64_t);
int modifyUInt8_json(struct Json *, char *, uint8_t);
int modifyUInt16_json(struct Json *, char *, uint16_t);
int modifyUInt32_json(struct Json *, char *, uint32_t);
int modifyUInt64_json(struct Json *, char *, uint64_t);
int modifyFloat_json(struct Json *, char *, float);
int modifyDouble_json(struct Json *, char *, double);
//          Boolean
int modifyBoolean_json(struct Json *, char *, int);
//          Array
int modifyArray_json(struct Json *, char *, struct Collection *);
//          JsonObject
int modifyJsonObject_json(struct Json *, char *, struct Json *);
//      Delete
int deleteKey_json(struct Json *, char *);
//      Get
int getIndexWithKey_json(struct Json *, char *);
void *getWithKey_json(struct Json *, char *);
//          String
JsonString *getString_json(struct Json *, char *);
//          Number
JsonNumber *getNumber_json(struct Json *, char *);
int8_t getInt8_json(struct Json *, char *);
int16_t getInt16_json(struct Json *, char *);
int32_t getInt32_json(struct Json *, char *);
int64_t getInt64_json(struct Json *, char *);
uint8_t getUInt8_json(struct Json *, char *);
uint16_t getUInt16_json(struct Json *, char *);
uint32_t getUInt32_json(struct Json *, char *);
uint64_t getUInt64_json(struct Json *, char *);
float getFloat_json(struct Json *, char *);
double getDouble_json(struct Json *, char *);
//          Boolean
JsonBoolean *getBoolean_json(struct Json *, char *);
//          Array
JsonArray *getArray_json(struct Json *, char *);
//          JsonObject
struct Json *getJsonObject_json(struct Json *, char *);
//      Misc
int overwriteToCharArray(char *, char *, int);
void clearJson(struct Json *);
void copyToJson(struct Json *, struct Json *);
void stringifyJson(struct Json *, char *);
void unstringifyJson(char *, struct Json *);

// Include Definitions
#include "_jsonparser.definitions.h"

#endif