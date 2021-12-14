# JsonParser for C (Documentation)

For usage example, check [**Example**](https://github.com/SBTopZZZ-LG/jsonparser_c/blob/main/example/main.c) code.

### Include the library  

    #include "jsonparser.h"

## Table of Contents  
- [**Collection**](#collection)
  * [Declaring a collection](#declaring-a-collection)
  * [Pushing items into the collection](#pushing-items-into-the-collection)
    + [Push methods](#push-methods)
    + [Examples](#examples)
    + [**Note that**](#note-that)
  * [Modifying an item inside the collection](#modifying-an-item-inside-the-collection)
    + [Modify methods](#modify-methods)
    + [Examples](#examples-1)
    + [**Note that**](#note-that-1)
  * [Delete an item inside the collection](#delete-an-item-inside-the-collection)
    + [Examples](#examples-2)
  * [Get an item from inside the collection](#get-an-item-from-inside-the-collection)
    + [Get methods](#get-methods)
    + [Examples](#examples-3)
    + [**Note that**](#note-that-2)
  * [Other functions](#other-functions)
  * [Stringify](#stringify)
    + [Example](#example)
  * [Clearing the memory](#clearing-the-memory)
    + [Example](#example-1)
  * [Unstringify](#unstringify)
    + [Example](#example-2)
- [**Json**](#json)
  * [Declaring a json](#declaring-a-json)
  * [Putting items in the json](#putting-items-in-the-json)
    + [Put methods](#put-methods)
    + [Examples](#examples-4)
    + [**Note that**](#note-that-3)
  * [Modifying an item inside the json](#modifying-an-item-inside-the-json)
    + [Modify methods](#modify-methods-1)
    + [Examples](#examples-5)
    + [**Note that**](#note-that-4)
  * [Delete an item inside the json](#delete-an-item-inside-the-json)
    + [Examples](#examples-6)
  * [Get an item from inside the json](#get-an-item-from-inside-the-json)
    + [Get methods](#get-methods-1)
    + [Examples](#examples-7)
    + [**Note that**](#note-that-5)
  * [Other functions](#other-functions-1)
  * [Stringify](#stringify-1)
    + [Example](#example-3)
  * [Clearing the memory](#clearing-the-memory-1)
    + [Example](#example-4)
  * [Unstringify](#unstringify-1)
    + [Example](#example-5)

## Collection
**A collection mimics an array inside a json.**  
Items can be pushed, deleted, modified, and retrieved from the collection like an array. It has it's own functions to stringify and unstringify collection items.

### Declaring a collection  

    struct Collection coll; // Declare
    initializeCollection(&coll); // Initialize the collection  

`initializeCollection(struct Collection *)` initializes the collection by setting the property **length** equal to **zero**.
  
    /**
    * @brief Initializes a Collection object to empty
    *
    * @param coll Collection object to initialize
    */
    void initializeCollection(struct Collection *coll)
    {
	    coll->length = 0;
    }

### Pushing items into the collection
After initialization, you can begin pushing items into the collection using the provided functions.

| Collection DataTypes | What it stores    |
|----------------------|-------------------|
| *CollectionString*     | String values     |
| *CollectionNumber*     | Numerical values  |
| *CollectionBoolean*    | Boolean values    |
| *CollectionArray*      | Collection		 |
| *CollectionJsonObject* | Json object       |  

#### Push methods
| Collection Push Methods     | What it pushes   |
|-----------------------------|------------------|
| *pushString_collection*     | String values    |
| *pushNumber_collection*     | Numerical values |
| *pushBoolean_collection*    | Boolean values   |
| *pushArray_collection*      | Collection       |
| *pushJsonObject_collection* | Json object      |  

`pushNumber_collection(struct Collection *, char *)` accepts numerical value in the form of string.  

    /**
    * @brief Push Numerical value to a Collection object
    *
    * @param coll Collection object to push into
    * @param number Numerical value to push
    */
    void pushNumber_collection(struct Collection *coll, char *number);
Below are functions that enable users to "implicitly" convert the numerical values to string.  

| CollectionNumber Push Methods | What it pushes           |
|-------------------------------|--------------------------|
| *pushInt8_collection*           | 8-bit signed integers    |
| *pushInt16_collection*          | 16-bit signed integers   |
| *pushInt32_collection*          | 32-bit signed integers   |
| *pushInt64_collection*          | 64-bit signed integers   |
| *pushUInt8_collection*          | 8-bit unsigned integers  |
| *pushUInt16_collection*         | 16-bit unsigned integers |
| *pushUInt32_collection*         | 32-bit unsigned integers |
| *pushUInt64_collection*         | 64-bit unsigned integers |
| *pushFloat_collection*          | Floating-point numbers   |
| *pushDouble_collection*         | Double                   |  

#### Examples  

    pushString_collection(&coll, "Hello World!");  
    pushBoolean_collection(&coll, 1); // 0 = false, 1 = true  
    pushInt32_collection(&coll, 123123);
    pushUInt8_collection(&coll, (uint8_t) 190);

#### Note that
All push methods **DO NOT** store any references from the user side and the values are directly copied into new instances.  

    struct Collection coll2;
    initializeCollection(&coll2);
	
	// Pushing items into new collection
	pushString_collection(&coll2, "What's up!");
	...
	
	// Push coll2 into coll
	pushArray_collection(&coll, &coll2);
	
	// Altering coll2 does not cause any alterations to collection inside the coll
	pushInt8_collection(&coll2, (int8_t) 100);  
	
### Modifying an item inside the collection  

After pushing, you can modifying items inside the collection with new values.  

#### Modify methods  

| Collection Modify Methods | What it modifies         |
|---------------------------|--------------------------|
| *modifyString_collection*     | String values    |
| *modifyNumber_collection*     | Numerical values    |
| *modifyBoolean_collection*     | Boolean values    |
| *modifyInt8_collection*     | 8-bit signed integers    |
| *modifyInt16_collection*    | 16-bit signed integers   |
| *modifyInt32_collection*    | 32-bit signed integers   |
| *modifyInt64_collection*    | 64-bit signed integers   |
| *modifyUInt8_collection*    | 8-bit unsigned integers  |
| *modifyUInt16_collection*   | 16-bit unsigned integers |
| *modifyUInt32_collection*   | 32-bit unsigned integers |
| *modifyUInt64_collection*   | 64-bit unsigned integers |
| *modifyFloat_collection*    | Floating-point numbers   |
| *modifyDouble_collection*   | Double                   |
| *modifyArray_collection*     | Collection    |
| *modifyJsonObject_collection*     | JsonObject    |

#### Examples  

    modifyString_collection(&coll, 0, "Hello World Again!");
    modifyBoolean_collection(&coll, 1, 0);
    
#### Note that
All modify methods **DO NOT** store any references from the user side (just like push methods) and the values are directly copied and overwritten on old values. 
 
### Delete an item inside the collection

Pushed items can be deleted from the collection using the `deleteAt_collection(struct Collection *coll, int index)` function.  
`index` is the index at which the item is located at. This clears the memory allocated by that item inside the collection.  

#### Examples  

    deleteAt_collection(&coll, 1);
    deleteAt_collection(&coll, 0);
    
### Get an item from inside the collection
Pushed items can be accessed from the collection using the get functions provided.  

#### Get methods  
| Collection Get Methods   | What it retrieves        |
|--------------------------|--------------------------|
| *getString_collection*     | String values            |
| *getNumber_collection*     | Numerical values         |
| *getBoolean_collection*    | Boolean values           |
| *getArray_collection*      | Collection               |
| *getJsonObject_collection* | JsonObject               |  

`getNumber_collection(struct Collection *, int)` returns the numerical value in the form of string.  

    /**
    * @brief Get the Number collection object at specified index
    *
    * @param coll Collection object to get from
    * @param index Index to get
    * @return CollectionNumber* Reference to the stored value
    */
    CollectionNumber *getNumber_collection(struct Collection *coll, int index);

Below are functions that enable users to "implicitly" convert the numerical values to string.  

  | CollectionNumber Get Methods | What it retrieves        |
|------------------------------|--------------------------|
| *getInt8_collection*           | 8-bit signed integers    |
| *getInt16_collection*          | 16-bit signed integers   |
| *getInt32_collection*          | 32-bit signed integers   |
| *getInt64_collection*          | 64-bit signed integers   |
| *getUInt8_collection*          | 8-bit unsigned integers  |
| *getUInt16_collection*         | 16-bit unsigned integers |
| *getUInt32_collection*         | 32-bit unsigned integers |
| *getUInt64_collection*         | 64-bit unsigned integers |
| *getFloat_collection*          | Floating-point numbers   |
| *getDouble_collection*         | Double                   |  

#### Examples  

    char *hellowrldtext = getString_collection(&coll, 0)->str;
    int boolvalue = getBoolean_collection(&coll, 1)->boolean;  

The functions return the value in the form of Collection structures.  

| Collection Get Methods   | Structure it returns        |
|--------------------------|--------------------------|
| *getString_collection*     | CollectionString            |
| *getNumber_collection*     | CollectionNumber         |
| *getBoolean_collection*    | CollectionBoolean         |
| *getArray_collection*      | CollectionArray        |
| *getJsonObject_collection* | CollectionJsonObject          |  

    /**
    * @brief Represents a string value within a Collection
    *
    */
    typedef struct
    {
	    char str[COLLECTION_STRING_SIZE];
    } CollectionString;
    
    /**
    * @brief Represents a numerical value within a Collection
    *
    */
    typedef struct
    {
	    char num[COLLECTION_NUMBER_SIZE];
    } CollectionNumber;
    
    /**
    * @brief Represents a boolean value within a Collection
    *
    */
    typedef struct
    {
	    int boolean;
    } CollectionBoolean;
    
    /**
    * @brief Represents an array (nested Collection) within a Collection
    *
    */
    typedef struct
    {
	    struct Collection arr;
    } CollectionArray;
    
    /**
    * @brief Represents a json value within a Collection
    *
    */
    typedef struct
    {
	    struct Json jsonObject;
    } CollectionJsonObject;  
    
#### Note that  
All get functions (except for the CollectionNumber functions) return a reference to the stored item inside the collection. Making changes to the returned data is also reflected inside the collection. 

### Other functions  

 - `copyToCollection(struct Collection *coll, struct Collection *destn)`  
 This function copies the items of one collection `coll` into another collection `destn`. The `destn` collection need not be initialized since it is initialized inside the function.  This function **COPIES** and **DOES NOT** create references of the items stored in source collection into destination collection.  

### Stringify  
Finally, to convert the collection into a parseable string, use the `stringifyCollection(struct Collection *, char *)` function.  

    /**
    * @brief Stringifies the Collection object into a parseable string
    *
    * @param coll Collection object to stringify
    * @param buffer Character array to copy parseable string into
    */
    void stringifyCollection(struct Collection *coll, char *buffer);

`buffer` is the character array where the parseable result is to be copied. This array should have enough size to store the final result.  

#### Example  
Please refer to the [**Example**](https://github.com/SBTopZZZ-LG/jsonparser_c/blob/main/example/main.c) code for implementation example.  

### Clearing the memory  

If you don't intend to use the collection after the stringify, you can safely clear the collection to clear the memory.  

`clearCollection(struct Collection *)` function is used to clear a collection, thus clearing the memory held by it.  

Collection items are created using **dynamic memory allocation** and hence require to be freed manually after use.  

#### Example  
Please refer to the [**Example**](https://github.com/SBTopZZZ-LG/jsonparser_c/blob/main/example/main.c) code for implementation example.  

### Unstringify  

`unstringifyCollection(char *, struct Collection *)` function converts or unstringifies a parseable string into a collection. 

    /**
    * @brief Unstringifies the specified parseable string into a Collection object
    *
    * @param data Parseable string to unstringify
    * @param parsed Collection object to populate
    */
    void unstringifyCollection(char *data, struct Collection *parsed);

The function parses the `data` and finalizes the contents inside the `parsed` collection. **NOTE** that `parsed` is a non-null pointer to a collection and the function **DOES NOT** allocate it.  

#### Example  
Please refer to the [**Example**](https://github.com/SBTopZZZ-LG/jsonparser_c/blob/main/example/main.c) code for implementation example.  

## Json
**A json mimics a hashmap to store key-value pairs.**  
Items can be put, deleted, modified, and retrieved from the json like a hashmap. It has it's own functions to stringify and unstringify json items.

### Declaring a json  

    struct Json json; // Declare
    initializeJson(&json); // Initialize the json  

`initializeJson(struct Json *)` initializes the json by setting the property **length** equal to **zero**.

    /**
    * @brief Initializes a Json object to empty
    *
    * @param coll Json object to initialize
    */
    void initializeJson(struct Json *json)
    {
	    json->length = 0;
    }

### Putting items in the json
After initialization, you can begin putting items into the json using the provided functions.

| Json DataTypes | What it stores    |
|----------------------|-------------------|
| *JsonString*     | String values     |
| *JsonNumber*     | Numerical values  |
| *JsonBoolean*    | Boolean values    |
| *JsonArray*      | Collection		 |
| *struct Json* | Json object       |  

#### Put methods
| Json Put Methods     | What it puts   |
|-----------------------------|------------------|
| *putString_json*     | String values    |
| *putNumber_json*     | Numerical values |
| *putBoolean_json*    | Boolean values   |
| *putArray_json*      | Collection       |
| *putJsonObject_json* | Json object      |  

`putNumber_json(struct Json *, char *, char *)` accepts numerical value in the form of string (just like the collection).  

    /**
    * @brief Put Numerical value to a Json object
    *
    * @param json Json object to put into
    * @param key Key to assign
    * @param value Value to assign
    */
    void putNumber_json(struct Json *json, char *key, char *value);

Below are functions that enable users to "implicitly" convert the numerical values to string.  

| JsonNumber Put Methods | What it puts           |
|-------------------------------|--------------------------|
| *putInt8_json*           | 8-bit signed integers    |
| *putInt16_json*          | 16-bit signed integers   |
| *putInt32_json*          | 32-bit signed integers   |
| *putInt64_json*          | 64-bit signed integers   |
| *putUInt8_json*          | 8-bit unsigned integers  |
| *putUInt16_json*         | 16-bit unsigned integers |
| *putUInt32_json*         | 32-bit unsigned integers |
| *putUInt64_json*         | 64-bit unsigned integers |
| *putFloat_json*          | Floating-point numbers   |
| *putDouble_json*         | Double                   |  

#### Examples  

    putString_json(&json, "greeting", "Hello World! 0_0");  
    putBoolean_json(&json, "lovesFood", 0); // 0 = false, 1 = true  
    putInt32_json(&json, "favouriteNumber", 123123);
    putUInt8_json(&json, "favouriteNumber2", (uint8_t) 190);

#### Note that
All put methods (just like the push methods in collection) **DO NOT** store any references from the user side and the values are directly copied into new instances.  

### Modifying an item inside the json  

After putting, you can modifying items inside the json with new values.  

#### Modify methods  

| Json Modify Methods | What it modifies         |
|---------------------------|--------------------------|
| *modifyString_json*     | String values    |
| *modifyNumber_json*     | Numerical values    |
| *modifyBoolean_json*     | Boolean values    |
| *modifyInt8_json*     | 8-bit signed integers    |
| *modifyInt16_json*    | 16-bit signed integers   |
| *modifyInt32_json*    | 32-bit signed integers   |
| *modifyInt64_json*    | 64-bit signed integers   |
| *modifyUInt8_json*    | 8-bit unsigned integers  |
| *modifyUInt16_json*   | 16-bit unsigned integers |
| *modifyUInt32_json*   | 32-bit unsigned integers |
| *modifyUInt64_json*   | 64-bit unsigned integers |
| *modifyFloat_json*    | Floating-point numbers   |
| *modifyDouble_json*   | Double                   |
| *modifyArray_json*     | Collection    |
| *modifyJsonObject_json*     | JsonObject    |

#### Examples  

    modifyString_json(&json, "greeting", "Hello World :)");
    modifyBoolean_json(&json, "lovesFood", 1);
    
#### Note that
All modify methods **DO NOT** store any references from the user side (just like put methods) and the values are directly copied and overwritten on old values. 
 
### Delete an item inside the json

Put items can be deleted from the json using the `deleteKey_json(struct Collection *coll, char *key)` function.  
`key` is the key of the item. This clears the memory allocated by that item inside the json.  

#### Examples  

    deleteKey_json(&json, "favouriteNumber");
    deleteKey_json(&json, "favouriteNumber2");
    
### Get an item from inside the json
Put items can be accessed from the json using the get functions provided.  

#### Get methods  
| Json Get Methods   | What it retrieves        |
|--------------------------|--------------------------|
| *getString_json*     | String values            |
| *getNumber_json*     | Numerical values         |
| *getBoolean_json*    | Boolean values           |
| *getArray_json*      | Collection               |
| *getJsonObject_json* | JsonObject               |  

`getNumber_json(struct Json *, char *)` returns the numerical value in the form of string.  

    /**
    * @brief Get the Number json object with specified key
    *
    * @param json Json object to get from
    * @param key Key to get
    * @return JsonNumber* Reference to stored value
    */
    JsonNumber *getNumber_json(struct Json *json, char *key);

Below are functions that enable users to "implicitly" convert the numerical values to string.  

  | JsonNumber Get Methods | What it retrieves        |
|------------------------------|--------------------------|
| *getInt8_json*           | 8-bit signed integers    |
| *getInt16_json*          | 16-bit signed integers   |
| *getInt32_json*          | 32-bit signed integers   |
| *getInt64_json*          | 64-bit signed integers   |
| *getUInt8_json*          | 8-bit unsigned integers  |
| *getUInt16_json*         | 16-bit unsigned integers |
| *getUInt32_json*         | 32-bit unsigned integers |
| *getUInt64_json*         | 64-bit unsigned integers |
| *getFloat_json*          | Floating-point numbers   |
| *getDouble_json*         | Double                   |  

#### Examples  

    char *hellowrldtext = getString_json(&json, "greeting")->str;
    int boolvalue = getBoolean_json(&json, "lovesFood")->boolean;  

The functions return the value in the form of Json structures.  

| Json Get Methods   | Structure it returns        |
|--------------------------|--------------------------|
| *getString_json*     | JsonString            |
| *getNumber_json*     | JsonNumber         |
| *getBoolean_json*    | JsonBoolean         |
| *getArray_json*      | JsonArray        |
| *getJsonObject_json* | struct Json          |  

    /**
    * @brief Represents a string value within Json
    *
    */
    typedef struct
    {
	    char key[JSON_KEY_MAX_LENGTH];
	    char str[JSON_STRING_SIZE];
    } JsonString;
    
    /**
    * @brief Represents a numerical value within Json
    *
    */
    typedef struct
    {
	    char key[JSON_KEY_MAX_LENGTH];
	    char num[JSON_NUMBER_SIZE];
    } JsonNumber;
    
    /**
    * @brief Represents a boolean value within Json
    *
    */
    typedef struct
    {
	    char key[JSON_KEY_MAX_LENGTH];
	    int boolean;
    } JsonBoolean;
    
    /**
    * @brief Represents an array (Collection) value within Json
    *
    */
    typedef struct
    {
	    char key[JSON_KEY_MAX_LENGTH];
	    struct Collection arr;
    } JsonArray;
    
#### Note that  
All get functions (except for the JsonNumber functions) return a reference to the stored item inside the json. Making changes to the returned data is also reflected inside the json. 

### Other functions  

 - `copyToJson(struct Json *json, struct Json *destn)`  
 This function copies the items of one json `json` into another json `destn`. The `destn` json need not be initialized since it is initialized inside the function.  This function **COPIES** and **DOES NOT** create references of the items stored in source json into destination json.  

### Stringify  
Finally, to convert the json into a parseable string, use the `stringifyJson(struct Json *, char *)` function.  

    /**
    * @brief Stringifies specified Json object into a parseable string
    *
    * @param json Json object to stringify
    * @param buffer Character array to copy parseable string into
    */
    void stringifyJson(struct Json *json, char *buffer);

`buffer` is the character array where the parseable result is to be copied. This array should have enough size to store the final result.  

#### Example  
Please refer to the [**Example**](https://github.com/SBTopZZZ-LG/jsonparser_c/blob/main/example/main.c) code for implementation example.  

### Clearing the memory  

If you don't intend to use the json after the stringify, you can safely clear the json to clear the memory.  

`clearJson(struct Json *)` function is used to clear a json, thus clearing the memory held by it.  

Json items are created using **dynamic memory allocation** and hence require to be freed manually after use.  

#### Example  
Please refer to the [**Example**](https://github.com/SBTopZZZ-LG/jsonparser_c/blob/main/example/main.c) code for implementation example.  

### Unstringify  

`unstringifyJson(char *, struct Json *)` function converts or unstringifies a parseable string into a json. 

    /**
    * @brief Unstringifies the specified parseable string into a Json object
    *
    * @param data Parseable string to unstringify
    * @param parsed Json object to populate
    */
    void unstringifyJson(char *data, struct Json *parsed);

The function parses the `data` and finalizes the contents inside the `parsed` json. **NOTE** that `parsed` is a non-null pointer to a json and the function **DOES NOT** allocate it.  

#### Example  
Please refer to the [**Example**](https://github.com/SBTopZZZ-LG/jsonparser_c/blob/main/example/main.c) code for implementation example.  
