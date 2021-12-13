#ifndef ATON_H
#define ATON_H

#include <stdlib.h>

/**
 * @brief Converts given string to a 8-bit signed integer (-128 to 127)
 *
 * @param string String to convert
 * @return int8_t Conversion result
 */
int8_t atoi8(char *string)
{
    int8_t val = 0;
    int isNegative = string[0] == '-' ? 1 : 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '-' || string[i] == '+')
            continue;

        int digit = string[i] - '0';
        val = val * 10 + digit;
    }

    if (isNegative)
        val *= -1;

    return val;
}
/**
 * @brief Converts given string to a 16-bit signed integer (-32,768 to 32,767)
 *
 * @param string String to convert
 * @return int16_t Conversion result
 */
int16_t atoi16(char *string)
{
    int16_t val = 0;
    int isNegative = string[0] == '-' ? 1 : 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '-' || string[i] == '+')
            continue;

        int digit = string[i] - '0';
        val = val * 10 + digit;
    }

    if (isNegative)
        val *= -1;

    return val;
}
/**
 * @brief Converts given string to a 32-bit signed integer (-2,147,483,648 to 2,147,483,647)
 *
 * @param string String to convert
 * @return int32_t Conversion result
 */
int32_t atoi32(char *string)
{
    int32_t val = 0;
    int isNegative = string[0] == '-' ? 1 : 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '-' || string[i] == '+')
            continue;

        int digit = string[i] - '0';
        val = val * 10 + digit;
    }

    if (isNegative)
        val *= -1;

    return val;
}
/**
 * @brief Converts given string to a 64-bit signed integer (-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807)
 *
 * @param string String to convert
 * @return int64_t Conversion result
 */
int64_t atoi64(char *string)
{
    int64_t val = 0;
    int isNegative = string[0] == '-' ? 1 : 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '-' || string[i] == '+')
            continue;

        int digit = string[i] - '0';
        val = val * 10 + digit;
    }

    if (isNegative)
        val *= -1;

    return val;
}

/**
 * @brief Converts given string to a 8-bit unsigned integer (0 to 255)
 *
 * @param string String to convert
 * @return uint8_t Conversion result
 */
uint8_t atoui8(char *string)
{
    int8_t val = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '+')
            continue;

        int digit = string[i] - '0';
        val = val * 10 + digit;
    }

    return val;
}
/**
 * @brief Converts given string to a 16-bit unsigned integer (0 to 65,535)
 *
 * @param string String to convert
 * @return uint16_t Conversion result
 */
uint16_t atoui16(char *string)
{
    uint16_t val = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '+')
            continue;

        int digit = string[i] - '0';
        val = val * 10 + digit;
    }

    return val;
}
/**
 * @brief Converts given string to a 32-bit unsigned integer (0 to 4,294,967,295)
 *
 * @param string String to convert
 * @return uint32_t Conversion result
 */
uint32_t atoui32(char *string)
{
    uint32_t val = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '+')
            continue;

        int digit = string[i] - '0';
        val = val * 10 + digit;
    }

    return val;
}
/**
 * @brief Converts given string to a 64-bit unsigned integer (0 to 18,446,744,073,709,551,615)
 *
 * @param string String to convert
 * @return uint64_t Conversion result
 */
uint64_t atoui64(char *string)
{
    uint64_t val = 0;

    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '+')
            continue;

        int digit = string[i] - '0';
        val = val * 10 + digit;
    }

    return val;
}

/**
 * @brief Converts given string to a floating-point number
 *
 * @param string String to convert
 * @return float Conversion result
 */
float atofloat(char *string)
{
    float val = 0.0;
    int isNegative = string[0] == '-' ? 1 : 0;

    int decimal = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '-' || string[i] == '+')
            continue;
        else if (string[i] == '.')
        {
            decimal = 1;
            i++;
        }
        else if (decimal)
            decimal++;

        float digit = string[i] - '0';
        for (int j = 0; j < decimal; j++)
            digit /= 10;

        if (!decimal)
            val = val * 10 + digit;
        else
            val += digit;
    }

    if (isNegative)
        val *= -1;

    return val;
}
/**
 * @brief Converts given string to a double
 *
 * @param string String to convert
 * @return double Conversion result
 */
double atodouble(char *string)
{
    double val = 0.0;
    int isNegative = string[0] == '-' ? 1 : 0;

    int decimal = 0;
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == '-' || string[i] == '+')
            continue;
        else if (string[i] == '.')
        {
            decimal = 1;
            i++;
        }
        else if (decimal)
            decimal++;

        double digit = string[i] - '0';
        for (int j = 0; j < decimal; j++)
            digit /= 10;

        if (!decimal)
            val = val * 10 + digit;
        else
            val += digit;
    }

    if (isNegative)
        val *= -1;

    return val;
}

#endif