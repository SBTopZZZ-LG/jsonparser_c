#ifndef _JSONPARSER_DEFINITIONS_H
#define _JSONPARSER_DEFINITIONS_H

// Includes
//      My Libraries
#include "jsonparser.h"

// Collection Function Definitions
//      Init
/**
 * @brief Initializes a Collection object to empty
 *
 * @param coll Collection object to initialize
 */
void initializeCollection(struct Collection *coll)
{
    coll->length = 0;
}
//      Push
//          String
/**
 * @brief Push String value to a Collection object
 *
 * @param coll Collection object to push into
 * @param string String value to push
 */
void pushString_collection(struct Collection *coll, char *string)
{
    coll->collection[coll->length] = malloc(sizeof(CollectionString));

    CollectionString *object = (CollectionString *)coll->collection[coll->length];
    strcpy(object->str, string);

    coll->id_record[coll->length] = 0;
    coll->length++;
}
//          Number
/**
 * @brief Push Numerical value to a Collection object
 *
 * @param coll Collection object to push into
 * @param number Numerical value to push
 */
void pushNumber_collection(struct Collection *coll, char *number)
{
    coll->collection[coll->length] = malloc(sizeof(CollectionNumber));

    CollectionNumber *object = (CollectionNumber *)coll->collection[coll->length];
    strcpy(object->num, number);

    coll->id_record[coll->length] = 2;
    coll->length++;
}
/**
 * @brief Push 8-bit signed integer to a Collection object
 *
 * @param coll Collection object to push into
 * @param number Numerical value to push
 */
void pushInt8_collection(struct Collection *coll, int8_t number)
{
    char buffer[i8_size];
    i8toa(number, buffer);
    pushNumber_collection(coll, buffer);
}
/**
 * @brief Push 16-bit signed integer to a Collection object
 *
 * @param coll Collection object to push into
 * @param number Numerical value to push
 */
void pushInt16_collection(struct Collection *coll, int16_t number)
{
    char buffer[i16_size];
    i16toa(number, buffer);
    pushNumber_collection(coll, buffer);
}
/**
 * @brief Push 32-bit signed integer to a Collection object
 *
 * @param coll Collection object to push into
 * @param number Numerical value to push
 */
void pushInt32_collection(struct Collection *coll, int32_t number)
{
    char buffer[i32_size];
    i32toa(number, buffer);
    pushNumber_collection(coll, buffer);
}
/**
 * @brief Push 64-bit signed integer to a Collection object
 *
 * @param coll Collection object to push into
 * @param number Numerical value to push
 */
void pushInt64_collection(struct Collection *coll, int64_t number)
{
    char buffer[i64_size];
    i64toa(number, buffer);
    pushNumber_collection(coll, buffer);
}
/**
 * @brief Push 8-bit unsigned integer to a Collection object
 *
 * @param coll Collection object to push into
 * @param number Numerical value to push
 */
void pushUInt8_collection(struct Collection *coll, uint8_t number)
{
    char buffer[ui8_size];
    ui8toa(number, buffer);
    pushNumber_collection(coll, buffer);
}
/**
 * @brief Push 16-bit unsigned integer to a Collection object
 *
 * @param coll Collection object to push into
 * @param number Numerical value to push
 */
void pushUInt16_collection(struct Collection *coll, uint16_t number)
{
    char buffer[ui16_size];
    ui16toa(number, buffer);
    pushNumber_collection(coll, buffer);
}
/**
 * @brief Push 32-bit unsigned integer to a Collection object
 *
 * @param coll Collection object to push into
 * @param number Numerical value to push
 */
void pushUInt32_collection(struct Collection *coll, uint32_t number)
{
    char buffer[ui32_size];
    ui32toa(number, buffer);
    pushNumber_collection(coll, buffer);
}
/**
 * @brief Push 64-bit unsigned integer to a Collection object
 *
 * @param coll Collection object to push into
 * @param number Numerical value to push
 */
void pushUInt64_collection(struct Collection *coll, uint64_t number)
{
    char buffer[ui64_size];
    ui64toa(number, buffer);
    pushNumber_collection(coll, buffer);
}
/**
 * @brief Push floating-point value to a Collection object
 *
 * @param coll Collection object to push into
 * @param number Numerical value to push
 */
void pushFloat_collection(struct Collection *coll, float number)
{
    char buffer[float_size];
    ftoa(number, buffer);
    pushNumber_collection(coll, buffer);
}
/**
 * @brief Push double to a Collection object
 *
 * @param coll Collection object to push into
 * @param number Numerical value to push
 */
void pushDouble_collection(struct Collection *coll, double number)
{
    char buffer[double_size];
    dtoa(number, buffer);
    pushNumber_collection(coll, buffer);
}
//          Boolean
/**
 * @brief Push boolean value to a Collection object
 *
 * @param coll Collection object to push into
 * @param boolean Boolean value to push
 */
void pushBoolean_collection(struct Collection *coll, int boolean)
{
    coll->collection[coll->length] = malloc(sizeof(CollectionBoolean));

    CollectionBoolean *object = (CollectionBoolean *)coll->collection[coll->length];
    object->boolean = boolean;

    coll->id_record[coll->length] = 3;
    coll->length++;
}
//          Array
/**
 * @brief Push array (Collection object) value to a Collection object
 * [ This function copies the array (Collection object) to the Collection object and DOES NOT store any references ]
 *
 * @param coll Collection object to push into
 * @param array Array (Collection object) to push
 */
void pushArray_collection(struct Collection *coll, struct Collection *array)
{
    coll->collection[coll->length] = malloc(sizeof(CollectionArray));

    CollectionArray *object = (CollectionArray *)coll->collection[coll->length];
    copyToCollection(array, &object->arr);

    coll->id_record[coll->length] = 4;
    coll->length++;
}
//          JsonObject
/**
 * @brief Push json (Json object) value into a Collection object
 * [ This function copies the json (Json) to the Collection object and DOES NOT store any references ]
 *
 * @param coll Collection object to push into
 * @param jsonObject Json object to push
 */
void pushJsonObject_collection(struct Collection *coll, struct Json *jsonObject)
{
    coll->collection[coll->length] = malloc(sizeof(CollectionJsonObject));
    CollectionJsonObject *object = (CollectionJsonObject *)coll->collection[coll->length];
    copyToJson(jsonObject, &object->jsonObject);

    coll->id_record[coll->length] = 5;
    coll->length++;
}
//      Delete
/**
 * @brief Delete a stored value at specified index
 *
 * @param coll Collection object to delete from
 * @param index Index to delete
 * @return int 1 if successful, else 0
 */
int deleteAt_collection(struct Collection *coll, int index)
{
    if (index < 0 || index >= coll->length)
        return 0;

    void *object = coll->collection[index];
    int id = coll->id_record[index];

    // Shift items
    for (int i = index; i < coll->length; i++)
    {
        coll->collection[i] = coll->collection[i + 1];
        coll->id_record[i] = coll->id_record[i + 1];
    }

    // Free
    switch (id)
    {
    case 4:
    {
        // CollectionArray
        CollectionArray *object2 = (CollectionArray *)object;
        clearCollection(&object2->arr);

        break;
    }
    case 5:
    {
        // CollectionJsonObject
        CollectionJsonObject *object2 = (CollectionJsonObject *)object;
        clearJson(&object2->jsonObject);

        break;
    }
    }
    free(object);

    coll->length--;

    return 1;
}
//      Modify
//          String
/**
 * @brief Modifies the value of existing string value with new one inside a Collection object
 *
 * @param coll Collection object to perform modification
 * @param index Index to modify
 * @param string New value
 * @return int 1 if successful, else 0
 */
int modifyString_collection(struct Collection *coll, int index, char *string)
{
    if (index < 0 || index >= coll->length)
        return 0;

    CollectionString *object = (CollectionString *)coll->collection[index];

    if (!object)
        return 0;

    strcpy(object->str, string);

    return 1;
}
//          Number
/**
 * @brief Modifies the value of existing numerical value with new one inside a Collection object
 *
 * @param coll Collection object to perform modification
 * @param index Index to modify
 * @param number New value
 * @return int 1 if successful, else 0
 */
int modifyNumber_collection(struct Collection *coll, int index, char *number)
{
    if (index < 0 || index >= coll->length)
        return 0;

    CollectionNumber *object = (CollectionNumber *)coll->collection[index];

    if (!object)
        return 0;

    strcpy(object->num, number);

    return 1;
}
/**
 * @brief Modifies the value of existing numerical value (8-bit signed) with new one inside a Collection object
 *
 * @param coll Collection object to perform modification
 * @param index Index to modify
 * @param number New value
 * @return int 1 if successful, else 0
 */
int modifyInt8_collection(struct Collection *coll, int index, int8_t number)
{
    char buffer[i8_size];
    i8toa(number, buffer);
    return modifyNumber_collection(coll, index, buffer);
}
/**
 * @brief Modifies the value of existing numerical value (16-bit signed) with new one inside a Collection object
 *
 * @param coll Collection object to perform modification
 * @param index Index to modify
 * @param number New value
 * @return int 1 if successful, else 0
 */
int modifyInt16_collection(struct Collection *coll, int index, int16_t number)
{
    char buffer[i16_size];
    i16toa(number, buffer);
    return modifyNumber_collection(coll, index, buffer);
}
/**
 * @brief Modifies the value of existing numerical value (32-bit signed) with new one inside a Collection object
 *
 * @param coll Collection object to perform modification
 * @param index Index to modify
 * @param number New value
 * @return int 1 if successful, else 0
 */
int modifyInt32_collection(struct Collection *coll, int index, int32_t number)
{
    char buffer[i32_size];
    i32toa(number, buffer);
    return modifyNumber_collection(coll, index, buffer);
}
/**
 * @brief Modifies the value of existing numerical value (64-bit signed) with new one inside a Collection object
 *
 * @param coll Collection object to perform modification
 * @param index Index to modify
 * @param number New value
 * @return int 1 if successful, else 0
 */
int modifyInt64_collection(struct Collection *coll, int index, int64_t number)
{
    char buffer[i64_size];
    i64toa(number, buffer);
    return modifyNumber_collection(coll, index, buffer);
}
/**
 * @brief Modifies the value of existing numerical value (8-bit unsigned) with new one inside a Collection object
 *
 * @param coll Collection object to perform modification
 * @param index Index to modify
 * @param number New value
 * @return int 1 if successful, else 0
 */
int modifyUInt8_collection(struct Collection *coll, int index, uint8_t number)
{
    char buffer[ui8_size];
    ui8toa(number, buffer);
    return modifyNumber_collection(coll, index, buffer);
}
/**
 * @brief Modifies the value of existing numerical value (16-bit unsigned) with new one inside a Collection object
 *
 * @param coll Collection object to perform modification
 * @param index Index to modify
 * @param number New value
 * @return int 1 if successful, else 0
 */
int modifyUInt16_collection(struct Collection *coll, int index, uint16_t number)
{
    char buffer[ui16_size];
    ui16toa(number, buffer);
    return modifyNumber_collection(coll, index, buffer);
}
/**
 * @brief Modifies the value of existing numerical value (32-bit unsigned) with new one inside a Collection object
 *
 * @param coll Collection object to perform modification
 * @param index Index to modify
 * @param number New value
 * @return int 1 if successful, else 0
 */
int modifyUInt32_collection(struct Collection *coll, int index, uint32_t number)
{
    char buffer[ui32_size];
    ui32toa(number, buffer);
    return modifyNumber_collection(coll, index, buffer);
}
/**
 * @brief Modifies the value of existing numerical value (64-bit unsigned) with new one inside a Collection object
 *
 * @param coll Collection object to perform modification
 * @param index Index to modify
 * @param number New value
 * @return int 1 if successful, else 0
 */
int modifyUInt64_collection(struct Collection *coll, int index, uint64_t number)
{
    char buffer[ui64_size];
    ui64toa(number, buffer);
    return modifyNumber_collection(coll, index, buffer);
}
/**
 * @brief Modifies the value of existing floating-point value with new one inside a Collection object
 *
 * @param coll Collection object to perform modification
 * @param index Index to modify
 * @param number New value
 * @return int 1 if successful, else 0
 */
int modifyFloat_collection(struct Collection *coll, int index, float number)
{
    char buffer[float_size];
    ftoa(number, buffer);
    return modifyNumber_collection(coll, index, buffer);
}
/**
 * @brief Modifies the value of existing double with new one inside a Collection object
 *
 * @param coll Collection object to perform modification
 * @param index Index to modify
 * @param number New value
 * @return int 1 if successful, else 0
 */
int modifyDouble_collection(struct Collection *coll, int index, double number)
{
    char buffer[double_size];
    dtoa(number, buffer);
    return modifyNumber_collection(coll, index, buffer);
}
//          Boolean
/**
 * @brief Modifies the value of existing boolean value with new one inside a Collection object
 *
 * @param coll Collection object to perform modification
 * @param index Index to modify
 * @param boolean New value
 * @return int 1 if successful, else 0
 */
int modifyBoolean_collection(struct Collection *coll, int index, int boolean)
{
    if (index < 0 || index >= coll->length)
        return 0;

    CollectionBoolean *object = (CollectionBoolean *)coll->collection[index];

    if (!object)
        return 0;

    object->boolean = boolean;

    return 1;
}
//          Array
/**
 * @brief Modifies the value of existing array (Collection object) value with new one inside a Collection object
 * [ This function copies the array (Collection object) to the Collection object and DOES NOT store any references ]
 *
 * @param coll Collection object to perform modification
 * @param index Index to modify
 * @param array New value
 * @return int 1 if successful, else 0
 */
int modifyArray_collection(struct Collection *coll, int index, struct Collection *array)
{
    if (index < 0 || index >= coll->length)
        return 0;

    CollectionArray *object = (CollectionArray *)coll->collection[index];

    if (!object)
        return 0;

    // Clear and copy
    clearCollection(&object->arr);
    copyToCollection(array, &object->arr);

    return 1;
}
//          JsonObject
/**
 * @brief Modifies the value of existing json (Json) value with new one inside a Collection object
 * [ This function copies the json (Json) to the Collection object and DOES NOT store any references ]
 *
 * @param coll Collection object to perform modification
 * @param index Index to modify
 * @param array New value
 * @return int 1 if successful, else 0
 */
int modifyJsonObject_collection(struct Collection *coll, int index, struct Json *jsonObject)
{
    if (index < 0 || index >= coll->length)
        return 0;

    CollectionJsonObject *object = (CollectionJsonObject *)coll->collection[index];

    if (!object)
        return 0;

    // Clear and copy
    clearJson(&object->jsonObject);
    copyToJson(jsonObject, &object->jsonObject);

    return 1;
}
//      Get
//          String
/**
 * @brief Get the String collection object at specified index
 *
 * @param coll Collection object to get from
 * @param index Index to get
 * @return CollectionString* Reference to the stored value
 */
CollectionString *getString_collection(struct Collection *coll, int index)
{
    if (index < 0 || index >= coll->length)
        return NULL;

    return (CollectionString *)coll->collection[index];
}
//          Number
/**
 * @brief Get the Number collection object at specified index
 *
 * @param coll Collection object to get from
 * @param index Index to get
 * @return CollectionNumber* Reference to the stored value
 */
CollectionNumber *getNumber_collection(struct Collection *coll, int index)
{
    if (index < 0 || index >= coll->length)
        return NULL;

    return (CollectionNumber *)coll->collection[index];
}
/**
 * @brief Get and parse the Number collection object at specified index to 8-bit signed integer
 *
 * @param coll Collection object to get from
 * @param index Index to get
 * @return int8_t Parsed value
 */
int8_t getInt8_collection(struct Collection *coll, int index)
{
    CollectionNumber *object = (CollectionNumber *)coll->collection[index];
    return atoi8(object->num);
}
/**
 * @brief Get and parse the Number collection object at specified index to 16-bit signed integer
 *
 * @param coll Collection object to get from
 * @param index Index to get
 * @return int16_t Parsed value
 */
int16_t getInt16_collection(struct Collection *coll, int index)
{
    CollectionNumber *object = (CollectionNumber *)coll->collection[index];
    return atoi16(object->num);
}
/**
 * @brief Get and parse the Number collection object at specified index to 32-bit signed integer
 *
 * @param coll Collection object to get from
 * @param index Index to get
 * @return int32_t Parsed value
 */
int32_t getInt32_collection(struct Collection *coll, int index)
{
    CollectionNumber *object = (CollectionNumber *)coll->collection[index];
    return atoi32(object->num);
}
/**
 * @brief Get and parse the Number collection object at specified index to 64-bit signed integer
 *
 * @param coll Collection object to get from
 * @param index Index to get
 * @return int64_t Parsed value
 */
int64_t getInt64_collection(struct Collection *coll, int index)
{
    CollectionNumber *object = (CollectionNumber *)coll->collection[index];
    return atoi64(object->num);
}
/**
 * @brief Get and parse the Number collection object at specified index to 8-bit unsigned integer
 *
 * @param coll Collection object to get from
 * @param index Index to get
 * @return uint8_t Parsed value
 */
uint8_t getUInt8_collection(struct Collection *coll, int index)
{
    CollectionNumber *object = (CollectionNumber *)coll->collection[index];
    return atoui8(object->num);
}
/**
 * @brief Get and parse the Number collection object at specified index to 16-bit unsigned integer
 *
 * @param coll Collection object to get from
 * @param index Index to get
 * @return uint16_t Parsed value
 */
uint16_t getUInt16_collection(struct Collection *coll, int index)
{
    CollectionNumber *object = (CollectionNumber *)coll->collection[index];
    return atoui16(object->num);
}
/**
 * @brief Get and parse the Number collection object at specified index to 32-bit unsigned integer
 *
 * @param coll Collection object to get from
 * @param index Index to get
 * @return uint32_t Parsed value
 */
uint32_t getUInt32_collection(struct Collection *coll, int index)
{
    CollectionNumber *object = (CollectionNumber *)coll->collection[index];
    return atoui32(object->num);
}
/**
 * @brief Get and parse the Number collection object at specified index to 64-bit unsigned integer
 *
 * @param coll Collection object to get from
 * @param index Index to get
 * @return uint64_t Parsed value
 */
uint64_t getUInt64_collection(struct Collection *coll, int index)
{
    CollectionNumber *object = (CollectionNumber *)coll->collection[index];
    return atoui64(object->num);
}
/**
 * @brief Get and parse the Number collection object at specified index to floating-point number
 *
 * @param coll Collection object to get from
 * @param index Index to get
 * @return float Parsed value
 */
float getFloat_collection(struct Collection *coll, int index)
{
    CollectionNumber *object = (CollectionNumber *)coll->collection[index];
    return atofloat(object->num);
}
/**
 * @brief Get and parse the Number collection object at specified index to double
 *
 * @param coll Collection object to get from
 * @param index Index to get
 * @return double Parsed value
 */
double getDouble_collection(struct Collection *coll, int index)
{
    CollectionNumber *object = (CollectionNumber *)coll->collection[index];
    return atodouble(object->num);
}
//          Boolean
/**
 * @brief Get the Boolean collection object at specified index
 *
 * @param coll Collection object to get from
 * @param index Index to get
 * @return CollectionBoolean* Reference to stored value
 */
CollectionBoolean *getBoolean_collection(struct Collection *coll, int index)
{
    if (index < 0 || index >= coll->length)
        return NULL;

    return (CollectionBoolean *)coll->collection[index];
}
//          Array
/**
 * @brief Get the Array collection object at specified index
 *
 * @param coll Collection object to get from
 * @param index Index to get
 * @return CollectionArray* Reference to stored value
 */
CollectionArray *getArray_collection(struct Collection *coll, int index)
{
    if (index < 0 || index >= coll->length)
        return NULL;

    return (CollectionArray *)coll->collection[index];
}
//          JsonObject
/**
 * @brief Get the JsonObject collection object at specified index
 *
 * @param coll Collection object to get from
 * @param index Index to get
 * @return CollectionJsonObject* Reference to stored value
 */
CollectionJsonObject *getJsonObject_collection(struct Collection *coll, int index)
{
    if (index < 0 || index >= coll->length)
        return NULL;

    return (CollectionJsonObject *)coll->collection[index];
}
//      Misc
/**
 * @brief Deep clears a collection and destroys all objects under the collection
 *
 * @param coll Collection object to clear
 */
void clearCollection(struct Collection *coll)
{
    while (coll->length > 0)
    {
        int id = coll->id_record[coll->length - 1];

        switch (id)
        {
        case 4:
        {
            // CollectionArray
            CollectionArray *object2 = (CollectionArray *)coll->collection[coll->length - 1];
            clearCollection(&object2->arr);

            break;
        }
        case 5:
        {
            // CollectionJsonObject
            CollectionJsonObject *object2 = (CollectionJsonObject *)coll->collection[coll->length - 1];
            clearJson(&object2->jsonObject);

            break;
        }
        }

        free(coll->collection[coll->length - 1]);

        coll->length--;
    }
}
/**
 * @brief Deep copies contents of one Collection object to another Collection object
 * [ This function copies the collection (Collection) object contents to the destination (Collection object) and DOES NOT store any references ]
 *
 * @param coll Collection object to copy from
 * @param destn Collection object to copy into
 */
void copyToCollection(struct Collection *coll, struct Collection *destn)
{
    initializeCollection(destn);

    for (int i = 0; i < coll->length; i++)
    {
        int id = coll->id_record[i];

        switch (id)
        {
        case 0:
        {
            // CollectionString
            CollectionString *object = (CollectionString *)coll->collection[i];
            pushString_collection(destn, object->str);

            break;
        }
        case 2:
        {
            // CollectionNumber
            CollectionNumber *object = (CollectionNumber *)coll->collection[i];
            pushNumber_collection(destn, object->num);

            break;
        }
        case 3:
        {
            // CollectionBoolean
            CollectionBoolean *object = (CollectionBoolean *)coll->collection[i];
            pushBoolean_collection(destn, object->boolean);

            break;
        }
        case 4:
        {
            // CollectionArray
            CollectionArray *object = (CollectionArray *)coll->collection[i];
            pushArray_collection(destn, &object->arr);

            break;
        }
        case 5:
        {
            // CollectionJsonObject
            CollectionJsonObject *object = (CollectionJsonObject *)coll->collection[i];
            pushJsonObject_collection(destn, &object->jsonObject);

            break;
        }
        }
    }
}
/**
 * @brief Stringifies the Collection object into a parseable string
 *
 * @param coll Collection object to stringify
 * @param buffer Character array to copy parseable string into
 */
void stringifyCollection(struct Collection *coll, char *buffer)
{
    char result[COLLECTION_STRINGIFY_SIZE];
    int index = 0;

    index += overwriteToCharArray(result, "[", index);

    for (int i = 0; i < coll->length; i++)
    {
        if (i > 0)
            index += overwriteToCharArray(result, ",", index);

        int id = coll->id_record[i];

        switch (id)
        {
        case 0:
        {
            // CollectionString
            CollectionString *object = (CollectionString *)coll->collection[i];

            index += overwriteToCharArray(result, "\"", index);
            index += overwriteToCharArray(result, object->str, index);
            index += overwriteToCharArray(result, "\"", index);

            break;
        }
        case 2:
        {
            // CollectionNumber
            CollectionNumber *object = (CollectionNumber *)coll->collection[i];

            // index += overwriteToCharArray(result, "\"", index); // No quotation marks for numbers
            index += overwriteToCharArray(result, object->num, index);
            // index += overwriteToCharArray(result, "\"", index); // No quotation marks for numbers

            break;
        }
        case 3:
        {
            // CollectionBoolean
            CollectionBoolean *object = (CollectionBoolean *)coll->collection[i];

            // index += overwriteToCharArray(result, "\"", index); // No quotation marks for booleans
            index += overwriteToCharArray(result, object->boolean == 1 ? "true" : "false", index);
            // index += overwriteToCharArray(result, "\"", index); // No quotation marks for booleans

            break;
        }
        case 4:
        {
            // CollectionArray
            CollectionArray *object = (CollectionArray *)coll->collection[i];

            char temp_result[COLLECTION_STRINGIFY_SIZE];
            stringifyCollection(&object->arr, temp_result);

            index += overwriteToCharArray(result, temp_result, index);

            break;
        }
        case 5:
        {
            // CollectionJsonObject
            CollectionJsonObject *object = (CollectionJsonObject *)coll->collection[i];

            char temp_result[JSON_STRINGIFY_SIZE];
            stringifyJson(&object->jsonObject, temp_result);

            index += overwriteToCharArray(result, temp_result, index);

            break;
        }
        }
    }

    index += overwriteToCharArray(result, "]", index);

    // Copy to buffer
    strcpy(buffer, result);
}
int extractString(char *data, int index, char *buffer)
{
    int i;
    for (i = index + 1; data[i] != '\0'; i++)
        if (data[i] == '"')
        {
            buffer[i - (index + 1)] = '\0';
            break;
        }
        else
            buffer[i - (index + 1)] = data[i];

    return i - (index + 1) + 1;
}
int extractNumber(char *data, int index, char *buffer)
{
    int i;
    for (i = index; data[i] != '\0'; i++)
        if (data[i] != '.' && !(data[i] >= '0' && data[i] <= '9'))
        {
            buffer[i - index] = '\0';
            break;
        }
        else
            buffer[i - index] = data[i];

    return i - index;
}
int extractBoolean(char *data, int index, int *result)
{
    int i;
    char buffer[6];
    for (i = index; i < index + 5; i++)
        if (data[i] != 't' && data[i] != 'r' && data[i] != 'u' &&
            data[i] != 'e' && data[i] != 'f' && data[i] != 'a' &&
            data[i] != 'l' && data[i] != 's')
        {
            buffer[i - index] = '\0';
            break;
        }
        else
            buffer[i - index] = data[i];

    if (strcmp(buffer, "true") == 0)
        *result = 1;
    else
        *result = 0;

    return i - index;
}
int extractArray(char *data, int index, char *buffer)
{
    int i, sum = 0;
    for (i = index; data[i] != '\0'; i++)
    {
        if (data[i] == '[')
            sum += 1;
        else if (data[i] == ']')
            sum -= 1;

        buffer[i - index] = data[i];

        if (sum == 0)
        {
            buffer[i + 1 - index] = '\0';
            break;
        }
    }

    return i - index;
}
int extractJsonObject(char *data, int index, char *buffer)
{
    int i, sum = 0;
    for (i = index; data[i] != '\0'; i++)
    {
        if (data[i] == '{')
            sum += 1;
        else if (data[i] == '}')
            sum -= 1;

        buffer[i - index] = data[i];

        if (sum == 0)
        {
            buffer[i + 1 - index] = '\0';
            break;
        }
    }

    return i - index;
}
/**
 * @brief Unstringifies the specified parseable string into a Collection object
 *
 * @param data Parseable string to unstringify
 * @param parsed Collection object to populate
 */
void unstringifyCollection(char *data, struct Collection *parsed)
{
    if (data[0] != '[')
        return;

    // Initialize collection
    initializeCollection(parsed);

    for (int i = 1; data[i] != '\0'; i++)
    {
        switch (data[i])
        {
        case '"':
        {
            // CollectionString
            char temp[COLLECTION_STRING_SIZE];
            i += extractString(data, i, temp);

            pushString_collection(parsed, temp);

            break;
        }
        case 't': // CollectionBoolean
        case 'f':
        {
            // CollectionBoolean
            int boolean;
            i += extractBoolean(data, i, &boolean);

            pushBoolean_collection(parsed, boolean);

            break;
        }
        case '[':
        {
            // CollectionArray
            char temp[COLLECTION_STRINGIFY_SIZE];
            i += extractArray(data, i, temp);

            struct Collection temp_coll;
            unstringifyCollection(temp, &temp_coll);
            pushArray_collection(parsed, &temp_coll);

            break;
        }
        case '{':
        {
            // CollectionJsonObject
            char temp[JSON_STRING_SIZE];
            i += extractJsonObject(data, i, temp);

            struct Json temp_json;
            unstringifyJson(temp, &temp_json);
            pushJsonObject_collection(parsed, &temp_json);

            break;
        }
        case ',':
            break;
        default:
        {
            // CollectionNumber?
            if (data[i] == '-' || data[i] == '.' || (data[i] >= '0' && data[i] <= '9'))
            {
                // CollectionNumber
                char temp[COLLECTION_NUMBER_SIZE];
                i += extractNumber(data, i, temp);

                pushNumber_collection(parsed, temp);
            }

            break;
        }
        }
    }
}

// Json Function Definitions
//      Init
/**
 * @brief Initializes a Json object to empty
 *
 * @param coll Json object to initialize
 */
void initializeJson(struct Json *json)
{
    json->length = 0;
}
//      Put
//          String
/**
 * @brief Put String value to a Json object
 *
 * @param json Json object to put into
 * @param key Key to assign
 * @param str Value to assign
 */
void putString_json(struct Json *json, char *key, char *str)
{
    json->collection[json->length] = malloc(sizeof(JsonString));

    JsonString *object = (JsonString *)json->collection[json->length];
    strcpy(object->key, key);
    strcpy(object->str, str);

    json->id_record[json->length] = 0;
    json->length++;
}
//          Number
/**
 * @brief Put Numerical value to a Json object
 *
 * @param json Json object to put into
 * @param key Key to assign
 * @param value Value to assign
 */
void putNumber_json(struct Json *json, char *key, char *value)
{
    json->collection[json->length] = malloc(sizeof(JsonNumber));

    JsonNumber *object = (JsonNumber *)json->collection[json->length];
    strcpy(object->key, key);
    strcpy(object->num, value);

    json->id_record[json->length] = 2;
    json->length++;
}
/**
 * @brief Put 8-bit signed integer to a Json object
 *
 * @param json Json object to put into
 * @param key Key to assign
 * @param value Value to assign
 */
void putInt8_json(struct Json *json, char *key, int8_t value)
{
    char buffer[i8_size];
    i8toa(value, buffer);

    putNumber_json(json, key, buffer);
}
/**
 * @brief Put 16-bit signed integer to a Json object
 *
 * @param json Json object to put into
 * @param key Key to assign
 * @param value Value to assign
 */
void putInt16_json(struct Json *json, char *key, int16_t value)
{
    char buffer[i16_size];
    i16toa(value, buffer);

    putNumber_json(json, key, buffer);
}
/**
 * @brief Put 32-bit signed integer to a Json object
 *
 * @param json Json object to put into
 * @param key Key to assign
 * @param value Value to assign
 */
void putInt32_json(struct Json *json, char *key, int32_t value)
{
    char buffer[i32_size];
    i32toa(value, buffer);

    putNumber_json(json, key, buffer);
}
/**
 * @brief Put 64-bit signed integer to a Json object
 *
 * @param json Json object to put into
 * @param key Key to assign
 * @param value Value to assign
 */
void putInt64_json(struct Json *json, char *key, int64_t value)
{
    char buffer[i64_size];
    i64toa(value, buffer);

    putNumber_json(json, key, buffer);
}
/**
 * @brief Put 8-bit unsigned integer to a Json object
 *
 * @param json Json object to put into
 * @param key Key to assign
 * @param value Value to assign
 */
void putUInt8_json(struct Json *json, char *key, uint8_t value)
{
    char buffer[ui8_size];
    ui8toa(value, buffer);

    putNumber_json(json, key, buffer);
}
/**
 * @brief Put 16-bit unsigned integer to a Json object
 *
 * @param json Json object to put into
 * @param key Key to assign
 * @param value Value to assign
 */
void putUInt16_json(struct Json *json, char *key, uint16_t value)
{
    char buffer[ui16_size];
    ui16toa(value, buffer);

    putNumber_json(json, key, buffer);
}
/**
 * @brief Put 32-bit unsigned integer to a Json object
 *
 * @param json Json object to put into
 * @param key Key to assign
 * @param value Value to assign
 */
void putUInt32_json(struct Json *json, char *key, uint32_t value)
{
    char buffer[ui32_size];
    ui32toa(value, buffer);

    putNumber_json(json, key, buffer);
}
/**
 * @brief Put 64-bit unsigned integer to a Json object
 *
 * @param json Json object to put into
 * @param key Key to assign
 * @param value Value to assign
 */
void putUInt64_json(struct Json *json, char *key, uint64_t value)
{
    char buffer[ui64_size];
    ui64toa(value, buffer);

    putNumber_json(json, key, buffer);
}
/**
 * @brief Put floating-point number to a Json object
 *
 * @param json Json object to put into
 * @param key Key to assign
 * @param value Value to assign
 */
void putFloat_json(struct Json *json, char *key, float value)
{
    char buffer[float_size];
    ftoa(value, buffer);

    putNumber_json(json, key, buffer);
}
/**
 * @brief Put double to a Json object
 *
 * @param json Json object to put into
 * @param key Key to assign
 * @param value Value to assign
 */
void putDouble_json(struct Json *json, char *key, double value)
{
    char buffer[double_size];
    dtoa(value, buffer);

    putNumber_json(json, key, buffer);
}
//          Boolean
/**
 * @brief Put boolean value to a Json object
 *
 * @param json Json object to put into
 * @param key Key to assign
 * @param boolean Value to assign (0 = false, 1 = true)
 */
void putBoolean_json(struct Json *json, char *key, int boolean)
{
    json->collection[json->length] = malloc(sizeof(JsonBoolean));

    JsonBoolean *object = (JsonBoolean *)json->collection[json->length];
    strcpy(object->key, key);
    object->boolean = boolean;

    json->id_record[json->length] = 3;
    json->length++;
}
//          Array
/**
 * @brief Put array (Collection) value to a Json object
 * [ This function copies the array (Collection) to the Json object and DOES NOT store any references ]
 *
 * @param json Json object to put into
 * @param key Key to assign
 * @param arr Value to assign
 */
void putArray_json(struct Json *json, char *key, struct Collection *arr)
{
    json->collection[json->length] = malloc(sizeof(JsonArray));

    JsonArray *object = (JsonArray *)json->collection[json->length];
    strcpy(object->key, key);
    initializeCollection(&object->arr);
    copyToCollection(arr, &object->arr);

    json->id_record[json->length] = 5;
    json->length++;
}
//          JsonObject
/**
 * @brief Put json (Json object) value into a Json object
 * [ This function copies the json (Json object) to the (Json object) and DOES NOT store any references ]
 *
 * @param json Collection object to put into
 * @param key Key to assign
 * @param jsonObject Value to assign
 */
void putJsonObject_json(struct Json *json, char *key, struct Json *jsonObject)
{
    json->collection[json->length] = malloc(sizeof(struct Json));

    struct Json *object = (struct Json *)json->collection[json->length];
    copyToJson(jsonObject, object);
    strcpy(object->key, key);

    json->id_record[json->length] = 4;
    json->length++;
}
//      Modify
//          String
/**
 * @brief Modifies the value of existing string value with new one inside a Json object
 *
 * @param json Json object to perform modification
 * @param key Key to assign
 * @param str New Value to assign
 * @return int 1 if successful, else 0
 */
int modifyString_json(struct Json *json, char *key, char *str)
{
    JsonString *object = (JsonString *)getWithKey_json(json, key);

    if (!object)
        return 0;

    strcpy(object->str, str);
    return 1;
}
//          Number
/**
 * @brief Modifies the value of existing numerical value with new one inside a Json object
 *
 * @param json Json object to perform modification
 * @param key Key to assign
 * @param value New Value to assign
 * @return int 1 if successful, else 0
 */
int modifyNumber_json(struct Json *json, char *key, char *value)
{
    JsonNumber *object = (JsonNumber *)getWithKey_json(json, key);

    if (!object)
        return 0;

    strcpy(object->num, value);
    return 1;
}
/**
 * @brief Modifies the value of existing numerical value (8-bit signed) with new one inside a Json object
 *
 * @param json Json object to perform modification
 * @param key Key to assign
 * @param value New Value to assign
 * @return int 1 if successful, else 0
 */
int modifyInt8_json(struct Json *json, char *key, int8_t value)
{
    char buffer[i8_size];
    i8toa(value, buffer);
    return modifyNumber_json(json, key, buffer);
}
/**
 * @brief Modifies the value of existing numerical value (16-bit signed) with new one inside a Json object
 *
 * @param json Json object to perform modification
 * @param key Key to assign
 * @param value New Value to assign
 * @return int 1 if successful, else 0
 */
int modifyInt16_json(struct Json *json, char *key, int16_t value)
{
    char buffer[i16_size];
    i16toa(value, buffer);
    return modifyNumber_json(json, key, buffer);
}
/**
 * @brief Modifies the value of existing numerical value (32-bit signed) with new one inside a Json object
 *
 * @param json Json object to perform modification
 * @param key Key to assign
 * @param value New Value to assign
 * @return int 1 if successful, else 0
 */
int modifyInt32_json(struct Json *json, char *key, int32_t value)
{
    char buffer[i32_size];
    i32toa(value, buffer);
    return modifyNumber_json(json, key, buffer);
}
/**
 * @brief Modifies the value of existing numerical value (64-bit signed) with new one inside a Json object
 *
 * @param json Json object to perform modification
 * @param key Key to assign
 * @param value New Value to assign
 * @return int 1 if successful, else 0
 */
int modifyInt64_json(struct Json *json, char *key, int64_t value)
{
    char buffer[i64_size];
    i64toa(value, buffer);
    return modifyNumber_json(json, key, buffer);
}
/**
 * @brief Modifies the value of existing numerical value (8-bit unsigned) with new one inside a Json object
 *
 * @param json Json object to perform modification
 * @param key Key to assign
 * @param value New Value to assign
 * @return int 1 if successful, else 0
 */
int modifyUInt8_json(struct Json *json, char *key, uint8_t value)
{
    char buffer[ui8_size];
    ui8toa(value, buffer);
    return modifyNumber_json(json, key, buffer);
}
/**
 * @brief Modifies the value of existing numerical value (16-bit unsigned) with new one inside a Json object
 *
 * @param json Json object to perform modification
 * @param key Key to assign
 * @param value New Value to assign
 * @return int 1 if successful, else 0
 */
int modifyUInt16_json(struct Json *json, char *key, uint16_t value)
{
    char buffer[ui16_size];
    ui16toa(value, buffer);
    return modifyNumber_json(json, key, buffer);
}
/**
 * @brief Modifies the value of existing numerical value (32-bit unsigned) with new one inside a Json object
 *
 * @param json Json object to perform modification
 * @param key Key to assign
 * @param value New Value to assign
 * @return int 1 if successful, else 0
 */
int modifyUInt32_json(struct Json *json, char *key, uint32_t value)
{
    char buffer[ui32_size];
    ui32toa(value, buffer);
    return modifyNumber_json(json, key, buffer);
}
/**
 * @brief Modifies the value of existing numerical value (64-bit unsigned) with new one inside a Json object
 *
 * @param json Json object to perform modification
 * @param key Key to assign
 * @param value New Value to assign
 * @return int 1 if successful, else 0
 */
int modifyUInt64_json(struct Json *json, char *key, uint64_t value)
{
    char buffer[ui64_size];
    ui64toa(value, buffer);
    return modifyNumber_json(json, key, buffer);
}
/**
 * @brief Modifies the value of existing numerical value (floating-point number) with new one inside a Json object
 *
 * @param json Json object to perform modification
 * @param key Key to assign
 * @param value New Value to assign
 * @return int 1 if successful, else 0
 */
int modifyFloat_json(struct Json *json, char *key, float value)
{
    char buffer[float_size];
    ftoa(value, buffer);
    return modifyNumber_json(json, key, buffer);
}
/**
 * @brief Modifies the value of existing double with new one inside a Json object
 *
 * @param json Json object to perform modification
 * @param key Key to assign
 * @param value New Value to assign
 * @return int 1 if successful, else 0
 */
int modifyDouble_json(struct Json *json, char *key, double value)
{
    char buffer[double_size];
    dtoa(value, buffer);
    return modifyNumber_json(json, key, buffer);
}
//          Boolean
/**
 * @brief Modifies the value of existing boolean value with new one inside a Json object
 *
 * @param json Json object to perform modification
 * @param key Key to assign
 * @param boolean New Value to assign (0 = false, 1 = true)
 * @return int 1 if successful, else 0
 */
int modifyBoolean_json(struct Json *json, char *key, int boolean)
{
    JsonBoolean *object = (JsonBoolean *)getWithKey_json(json, key);

    if (!object)
        return 0;

    object->boolean = boolean;
    return 1;
}
//          Array
/**
 * @brief Modifies the value of existing array (Collection) value with new one inside a Json object
 * [ This function copies the array (Collection) to the (Json object) and DOES NOT store any references ]
 *
 * @param json Json object to perform modification
 * @param key Key to assign
 * @param arr New Value to assign
 * @return int 1 if successful, else 0
 */
int modifyArray_json(struct Json *json, char *key, struct Collection *arr)
{
    JsonArray *object = (JsonArray *)getWithKey_json(json, key);

    if (!object)
        return 0;

    // Clear and copy
    clearCollection(&object->arr);
    copyToCollection(arr, &object->arr);
    return 1;
}
//          JsonObject
/**
 * @brief Modifies the value of existing json (Json object) value with new one inside a Json object
 * [ This function copies the json (Json object) to the (Json object) and DOES NOT store any references ]
 *
 * @param json Json object to perform modification
 * @param key Key to assign
 * @param arr New Value to assign
 * @return int 1 if successful, else 0
 */
int modifyJsonObject_json(struct Json *json, char *key, struct Json *jsonObject)
{
    struct Json *object = (struct Json *)getWithKey_json(json, key);

    if (!object)
        return 0;

    // Clear and copy
    clearJson(object);
    copyToJson(jsonObject, object);
    return 1;
}
//      Get
int getIndexWithKey_json(struct Json *json, char *key)
{
    for (int i = 0; i < json->length; i++)
    {
        int id = json->id_record[i];

        switch (id)
        {
        case 0:
        {
            // CollectionString
            JsonString *object = (JsonString *)json->collection[i];

            if (strcmp(object->key, key) == 0)
                return i;

            break;
        }
        case 2:
        {
            // CollectionNumber
            JsonNumber *object = (JsonNumber *)json->collection[i];

            if (strcmp(object->key, key) == 0)
                return i;

            break;
        }
        case 3:
        {
            // CollectionBoolean
            JsonBoolean *object = (JsonBoolean *)json->collection[i];

            if (strcmp(object->key, key) == 0)
                return i;

            break;
        }
        case 4:
        {
            // Json Object
            struct Json *object = (struct Json *)json->collection[i];

            if (strcmp(object->key, key) == 0)
                return i;

            break;
        }
        case 5:
        {
            // CollectionArray
            JsonArray *object = (JsonArray *)json->collection[i];

            if (strcmp(object->key, key) == 0)
                return i;

            break;
        }
        }
    }

    return -1;
}
void *getWithKey_json(struct Json *json, char *key)
{
    for (int i = 0; i < json->length; i++)
    {
        int id = json->id_record[i];

        switch (id)
        {
        case 0:
        {
            // CollectionString
            JsonString *object = (JsonString *)json->collection[i];

            if (strcmp(object->key, key) == 0)
                return object;

            break;
        }
        case 2:
        {
            // CollectionNumber
            JsonNumber *object = (JsonNumber *)json->collection[i];

            if (strcmp(object->key, key) == 0)
                return object;

            break;
        }
        case 3:
        {
            // CollectionBoolean
            JsonBoolean *object = (JsonBoolean *)json->collection[i];

            if (strcmp(object->key, key) == 0)
                return object;

            break;
        }
        case 4:
        {
            // Json Object
            struct Json *object = (struct Json *)json->collection[i];

            if (strcmp(object->key, key) == 0)
                return object;

            break;
        }
        case 5:
        {
            // CollectionArray
            JsonArray *object = (JsonArray *)json->collection[i];

            if (strcmp(object->key, key) == 0)
                return object;

            break;
        }
        }
    }

    return NULL;
}
//          String
/**
 * @brief Get the String json object with specified key
 *
 * @param json Json object to get from
 * @param key Key to get
 * @return JsonString* Reference to stored value
 */
JsonString *getString_json(struct Json *json, char *key)
{
    return (JsonString *)getWithKey_json(json, key);
}
//          Number
/**
 * @brief Get the Number json object with specified key
 *
 * @param json Json object to get from
 * @param key Key to get
 * @return JsonNumber* Reference to stored value
 */
JsonNumber *getNumber_json(struct Json *json, char *key)
{
    return (JsonNumber *)getWithKey_json(json, key);
}
/**
 * @brief Get and parse the Number json object with specified key to 8-bit signed integer
 *
 * @param json Json object to get from
 * @param key Key to get
 * @return int8_t Parsed value
 */
int8_t getInt8_json(struct Json *json, char *key)
{
    JsonNumber *object = (JsonNumber *)getWithKey_json(json, key);
    return atoi8(object->num);
}
/**
 * @brief Get and parse the Number json object with specified key to 16-bit signed integer
 *
 * @param json Json object to get from
 * @param key Key to get
 * @return int16_t Parsed value
 */
int16_t getInt16_json(struct Json *json, char *key)
{
    JsonNumber *object = (JsonNumber *)getWithKey_json(json, key);
    return atoi16(object->num);
}
/**
 * @brief Get and parse the Number json object with specified key to 32-bit signed integer
 *
 * @param json Json object to get from
 * @param key Key to get
 * @return int32_t Parsed value
 */
int32_t getInt32_json(struct Json *json, char *key)
{
    JsonNumber *object = (JsonNumber *)getWithKey_json(json, key);
    return atoi32(object->num);
}
/**
 * @brief Get and parse the Number json object with specified key to 64-bit signed integer
 *
 * @param json Json object to get from
 * @param key Key to get
 * @return int64_t Parsed value
 */
int64_t getInt64_json(struct Json *json, char *key)
{
    JsonNumber *object = (JsonNumber *)getWithKey_json(json, key);
    return atoi64(object->num);
}
/**
 * @brief Get and parse the Number json object with specified key to 8-bit unsigned integer
 *
 * @param json Json object to get from
 * @param key Key to get
 * @return uint8_t Parsed value
 */
uint8_t getUInt8_json(struct Json *json, char *key)
{
    JsonNumber *object = (JsonNumber *)getWithKey_json(json, key);
    return atoui8(object->num);
}
/**
 * @brief Get and parse the Number json object with specified key to 16-bit unsigned integer
 *
 * @param json Json object to get from
 * @param key Key to get
 * @return uint16_t Parsed value
 */
uint16_t getUInt16_json(struct Json *json, char *key)
{
    JsonNumber *object = (JsonNumber *)getWithKey_json(json, key);
    return atoui16(object->num);
}
/**
 * @brief Get and parse the Number json object with specified key to 32-bit unsigned integer
 *
 * @param json Json object to get from
 * @param key Key to get
 * @return uint32_t Parsed value
 */
uint32_t getUInt32_json(struct Json *json, char *key)
{
    JsonNumber *object = (JsonNumber *)getWithKey_json(json, key);
    return atoui32(object->num);
}
/**
 * @brief Get and parse the Number json object with specified key to 64-bit unsigned integer
 *
 * @param json Json object to get from
 * @param key Key to get
 * @return uint64_t Parsed value
 */
uint64_t getUInt64_json(struct Json *json, char *key)
{
    JsonNumber *object = (JsonNumber *)getWithKey_json(json, key);
    return atoui64(object->num);
}
/**
 * @brief Get and parse the Number json object with specified key to floating-point number
 *
 * @param json Json object to get from
 * @param key Key to get
 * @return float Parsed value
 */
float getFloat_json(struct Json *json, char *key)
{
    JsonNumber *object = (JsonNumber *)getWithKey_json(json, key);
    return atofloat(object->num);
}
/**
 * @brief Get and parse the Number json object with specified key to double
 *
 * @param json Json object to get from
 * @param key Key to get
 * @return double Parsed value
 */
double getDouble_json(struct Json *json, char *key)
{
    JsonNumber *object = (JsonNumber *)getWithKey_json(json, key);
    return atodouble(object->num);
}
//          Boolean
/**
 * @brief Get the Boolean json object with specified key
 *
 * @param json Json object to get from
 * @param key Key to get
 * @return JsonBoolean* Reference to stored value
 */
JsonBoolean *getBoolean_json(struct Json *json, char *key)
{
    return (JsonBoolean *)getWithKey_json(json, key);
}
//          Array
/**
 * @brief Get the Array json object with specified key
 *
 * @param json Json object to get from
 * @param key Key to get
 * @return JsonArray* Reference to stored value
 */
JsonArray *getArray_json(struct Json *json, char *key)
{
    return (JsonArray *)getWithKey_json(json, key);
}
//          JsonObject
/**
 * @brief Get the JsonObject json object with specified key
 *
 * @param json Json object to get from
 * @param key Key to get
 * @return struct Json* Reference to stored value
 */
struct Json *getJsonObject_json(struct Json *json, char *key)
{
    return (struct Json *)getWithKey_json(json, key);
}
//      Delete
/**
 * @brief Delete a stored value with specified key
 *
 * @param json Json object to delete from
 * @param key Key to delete
 * @return int 1 if successful, else 0
 */
int deleteKey_json(struct Json *json, char *key)
{
    if (!json->length)
        return 0;

    int index = getIndexWithKey_json(json, key);

    if (index == -1)
        return 0;

    void *object = json->collection[index];
    int id = json->id_record[index];

    // Shift items
    for (int i = index; i < json->length; i++)
    {
        json->collection[i] = json->collection[i + 1];
        json->id_record[i] = json->id_record[i + 1];
    }

    // Free
    switch (id)
    {
    case 4:
    {
        // CollectionJsonObject
        struct Json *object2 = (struct Json *)object;
        clearJson(object2);

        break;
    }
    case 5:
    {
        // CollectionArray
        JsonArray *object2 = (JsonArray *)object;
        clearCollection(&object2->arr);

        break;
    }
    }
    free(object);

    json->length--;

    return 1;
}
//      Misc
int overwriteToCharArray(char *array, char *data, int index)
{
    int i;
    for (i = index; data[i - index] != '\0'; i++)
        array[i] = data[i - index];

    // Set null character
    array[i] = '\0';

    return i - index;
}
/**
 * @brief Deep clears a Json object and destroys all objects under the Json object
 *
 * @param json Json object to clear
 */
void clearJson(struct Json *json)
{
    while (json->length > 0)
    {
        int id = json->id_record[json->length - 1];

        switch (id)
        {
        case 4:
        {
            // CollectionJsonObject
            struct Json *object2 = (struct Json *)json->collection[json->length - 1];
            clearJson(object2);

            break;
        }
        case 5:
        {
            // CollectionArray
            JsonArray *object2 = (JsonArray *)json->collection[json->length - 1];
            clearCollection(&object2->arr);

            break;
        }
        }

        free(json->collection[json->length - 1]);

        json->length--;
    }
}
/**
 * @brief Deep copies contents of one Json object to another Json object
 * [ This function copies the json (Json object) contents to the destination (Json object) and DOES NOT store any references ]
 *
 * @param json Json object to copy from
 * @param destn Json object to copy into
 */
void copyToJson(struct Json *json, struct Json *destn)
{
    initializeJson(destn);

    for (int i = 0; i < json->length; i++)
    {
        int id = json->id_record[i];

        switch (id)
        {
        case 0:
        {
            // CollectionString
            JsonString *object = (JsonString *)json->collection[i];
            putString_json(destn, object->key, object->str);

            break;
        }
        case 2:
        {
            // CollectionNumber
            JsonNumber *object = (JsonNumber *)json->collection[i];
            putNumber_json(destn, object->key, object->num);

            break;
        }
        case 3:
        {
            // CollectionBoolean
            JsonBoolean *object = (JsonBoolean *)json->collection[i];
            putBoolean_json(destn, object->key, object->boolean);

            break;
        }
        case 4:
        {
            // Json Object
            struct Json *object = (struct Json *)json->collection[i];
            putJsonObject_json(destn, object->key, object);

            break;
        }
        case 5:
        {
            // CollectionArray
            JsonArray *object = (JsonArray *)json->collection[i];
            putArray_json(destn, object->key, &object->arr);

            break;
        }
        }
    }
}
/**
 * @brief Stringifies specified Json object into a parseable string
 *
 * @param json Json object to stringify
 * @param buffer Character array to copy parseable string into
 */
void stringifyJson(struct Json *json, char *buffer)
{
    char result[JSON_STRINGIFY_SIZE];
    int index = 0;

    index += overwriteToCharArray(result, "{", index);

    for (int i = 0; i < json->length; i++)
    {
        if (i > 0)
            index += overwriteToCharArray(result, ",", index);

        int id = json->id_record[i];

        switch (id)
        {
        case 0:
        {
            // CollectionString
            JsonString *object = (JsonString *)json->collection[i];

            index += overwriteToCharArray(result, "\"", index);
            index += overwriteToCharArray(result, object->key, index);
            index += overwriteToCharArray(result, "\":", index);
            index += overwriteToCharArray(result, "\"", index);
            index += overwriteToCharArray(result, object->str, index);
            index += overwriteToCharArray(result, "\"", index);

            break;
        }
        case 2:
        {
            // CollectionNumber
            JsonNumber *object = (JsonNumber *)json->collection[i];

            index += overwriteToCharArray(result, "\"", index);
            index += overwriteToCharArray(result, object->key, index);
            index += overwriteToCharArray(result, "\":", index);
            // index += overwriteToCharArray(result, "\"", index); // No quotation marks for numbers
            index += overwriteToCharArray(result, object->num, index);
            // index += overwriteToCharArray(result, "\"", index); // No quotation marks for numbers

            break;
        }
        case 3:
        {
            // CollectionBoolean
            JsonBoolean *object = (JsonBoolean *)json->collection[i];

            index += overwriteToCharArray(result, "\"", index);
            index += overwriteToCharArray(result, object->key, index);
            index += overwriteToCharArray(result, "\":", index);
            // index += overwriteToCharArray(result, "\"", index); // No quotation marks for booleans
            index += overwriteToCharArray(result, object->boolean == 1 ? "true" : "false", index);
            // index += overwriteToCharArray(result, "\"", index); // No quotation marks for booleans

            break;
        }
        case 4:
        {
            // Json Object
            struct Json *object = (struct Json *)json->collection[i];

            index += overwriteToCharArray(result, "\"", index);
            index += overwriteToCharArray(result, object->key, index);
            index += overwriteToCharArray(result, "\":", index);

            char buffer[JSON_STRINGIFY_SIZE];
            stringifyJson(object, buffer);
            index += overwriteToCharArray(result, buffer, index);

            break;
        }
        case 5:
        {
            // CollectionArray
            JsonArray *object = (JsonArray *)json->collection[i];

            index += overwriteToCharArray(result, "\"", index);
            index += overwriteToCharArray(result, object->key, index);
            index += overwriteToCharArray(result, "\":", index);

            char buffer[COLLECTION_STRINGIFY_SIZE];
            stringifyCollection(&object->arr, buffer);
            index += overwriteToCharArray(result, buffer, index);

            break;
        }
        }
    }

    index += overwriteToCharArray(result, "}", index);

    // Copy to buffer
    strcpy(buffer, result);
}
/**
 * @brief Unstringifies the specified parseable string into a Json object
 *
 * @param data Parseable string to unstringify
 * @param parsed Json object to populate
 */
void unstringifyJson(char *data, struct Json *parsed)

{
    if (data[0] != '{')
        return;

    // Initialize json
    initializeJson(parsed);

    int data_type = 0;
    char lastKey[JSON_KEY_MAX_LENGTH], lastValue[JSON_STRINGIFY_SIZE];

    for (int i = 1; data[i] != '\0'; i++)
    {
        switch (data[i])
        {
        case '"':
        {
            // CollectionString
            if (data_type == 0)
            {
                i += extractString(data, i, lastKey);
                data_type = 1;
            }
            else if (data_type == 1)
            {
                i += extractString(data, i, lastValue);
                data_type = 0;
                putString_json(parsed, lastKey, lastValue);
            }

            break;
        }
        case 't': // CollectionBoolean
        case 'f':
        {
            // CollectionBoolean
            int boolean;
            i += extractBoolean(data, i, &boolean);

            putBoolean_json(parsed, lastKey, boolean);

            data_type = 0;

            break;
        }
        case '[':
        {
            // CollectionArray
            char temp[COLLECTION_STRINGIFY_SIZE];
            i += extractArray(data, i, temp);

            struct Collection temp_coll;
            unstringifyCollection(temp, &temp_coll);
            putArray_json(parsed, lastKey, &temp_coll);

            data_type = 0;

            break;
        }
        case '{':
        {
            // CollectionJsonObject
            char temp[JSON_STRINGIFY_SIZE];
            i += extractJsonObject(data, i, temp);

            struct Json temp_json;
            unstringifyJson(temp, &temp_json);
            putJsonObject_json(parsed, lastKey, &temp_json);

            data_type = 0;

            break;
        }
        case ':':
        {
            data_type = 1;
            break;
        }
        case ',':
        {
            data_type = 0;
            break;
        }
        default:
        {
            // CollectionNumber?
            if (data[i] == '-' || data[i] == '.' || (data[i] >= '0' && data[i] <= '9'))
            {
                // CollectionNumber
                i += extractNumber(data, i, lastValue);

                putNumber_json(parsed, lastKey, lastValue);

                data_type = 0;
            }

            break;
        }
        }
    }
}

#endif