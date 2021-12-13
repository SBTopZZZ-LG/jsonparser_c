#ifndef NTOA_H
#define NTOA_H

#include <stdint.h>

const int i8_size = 5;
const int i16_size = 7;
const int i32_size = 12;
const int i64_size = 21;

const int ui8_size = 4;
const int ui16_size = 6;
const int ui32_size = 11;
const int ui64_size = 21;

const int float_size = 19;
const int double_size = 28;

/**
 * @brief Converts a 8-bit signed integer (-128 to 127) to character array
 *
 * @param val Integer to convert
 * @param buf Character array to copy to (Recommended buffer length is 5)
 * @return int Returns the length of the conversion string
 */
int i8toa(int8_t val, char *buf)
{
    int neg = (val < 0);
    int counter = 0;

    if (neg)
    {
        val *= -1;
        buf[counter++] = '-';
    }

    int8_t temp = val;
    if (!temp)
        buf[counter++] = '0';
    else
        while (temp)
        {
            int digit = temp % 10;
            temp /= 10;

            buf[counter++] = digit + '0';
        }

    // Flip the buffer
    if (!neg)
        for (int i = 0; i < counter / 2; i++)
        {
            char c = buf[i];
            buf[i] = buf[counter - (i + 1)];
            buf[counter - (i + 1)] = c;
        }
    else
        for (int i = 1; i <= (counter + 1) / 2; i++)
        {
            char c = buf[i];
            buf[i] = buf[(counter + 1) - (i + 1)];
            buf[(counter + 1) - (i + 1)] = c;
        }

    buf[counter] = '\0';

    return counter;
}
/**
 * @brief Converts a 16-bit signed integer (-32,768 to 32,767) to character array
 *
 * @param val Integer to convert
 * @param buf Character array to copy to (Recommended buffer length is 7)
 * @return int Returns the length of the conversion string
 */
int i16toa(int16_t val, char *buf)
{
    int neg = (val < 0);
    int counter = 0;

    if (neg)
    {
        val *= -1;
        buf[counter++] = '-';
    }

    int16_t temp = val;
    if (!temp)
        buf[counter++] = '0';
    else
        while (temp)
        {
            int digit = temp % 10;
            temp /= 10;

            buf[counter++] = digit + '0';
        }

    // Flip the buffer
    if (!neg)
        for (int i = 0; i < counter / 2; i++)
        {
            char c = buf[i];
            buf[i] = buf[counter - (i + 1)];
            buf[counter - (i + 1)] = c;
        }
    else
        for (int i = 1; i <= (counter + 1) / 2; i++)
        {
            char c = buf[i];
            buf[i] = buf[(counter + 1) - (i + 1)];
            buf[(counter + 1) - (i + 1)] = c;
        }

    buf[counter] = '\0';

    return counter;
}
/**
 * @brief Converts a 32-bit signed integer (-2,147,483,648 to 2,147,483,647) to character array
 *
 * @param val Integer to convert
 * @param buf Character array to copy to (Recommended buffer length is 12)
 * @return int Returns the length of the conversion string
 */
int i32toa(int32_t val, char *buf)
{
    int neg = (val < 0);
    int counter = 0;

    if (neg)
    {
        val *= -1;
        buf[counter++] = '-';
    }

    int32_t temp = val;
    if (!temp)
        buf[counter++] = '0';
    else
        while (temp)
        {
            int digit = temp % 10;
            temp /= 10;

            buf[counter++] = digit + '0';
        }

    // Flip the buffer
    if (!neg)
        for (int i = 0; i < counter / 2; i++)
        {
            char c = buf[i];
            buf[i] = buf[counter - (i + 1)];
            buf[counter - (i + 1)] = c;
        }
    else
        for (int i = 1; i <= (counter + 1) / 2; i++)
        {
            char c = buf[i];
            buf[i] = buf[(counter + 1) - (i + 1)];
            buf[(counter + 1) - (i + 1)] = c;
        }

    buf[counter] = '\0';

    return counter;
}
/**
 * @brief Converts a 64-bit signed integer (-9,223,372,036,854,775,808 to 9,223,372,036,854,775,807) to character array
 *
 * @param val Integer to convert
 * @param buf Character array to copy to (Recommended buffer length is 21)
 * @return int Returns the length of the conversion string
 */
int i64toa(int64_t val, char *buf)
{
    int neg = (val < 0);
    int counter = 0;

    if (neg)
    {
        val *= -1;
        buf[counter++] = '-';
    }

    int64_t temp = val;
    if (!temp)
        buf[counter++] = '0';
    else
        while (temp)
        {
            int digit = temp % 10;
            temp /= 10;

            buf[counter++] = digit + '0';
        }

    // Flip the buffer
    if (!neg)
        for (int i = 0; i < counter / 2; i++)
        {
            char c = buf[i];
            buf[i] = buf[counter - (i + 1)];
            buf[counter - (i + 1)] = c;
        }
    else
        for (int i = 1; i <= (counter + 1) / 2; i++)
        {
            char c = buf[i];
            buf[i] = buf[(counter + 1) - (i + 1)];
            buf[(counter + 1) - (i + 1)] = c;
        }

    buf[counter] = '\0';

    return counter;
}

/**
 * @brief Converts a 8-bit unsigned integer (0 to 255) to character array
 *
 * @param val Integer to convert
 * @param buf Character array to copy to (Recommended buffer length is 4)
 * @return int Returns the length of the conversion string
 */
int ui8toa(uint8_t val, char *buf)
{
    int counter = 0;

    uint8_t temp = val;
    if (!temp)
        buf[counter++] = '0';
    else
        while (temp)
        {
            int digit = temp % 10;
            temp /= 10;

            buf[counter++] = digit + '0';
        }

    // Flip the buffer
    for (int i = 0; i < counter / 2; i++)
    {
        char c = buf[i];
        buf[i] = buf[counter - (i + 1)];
        buf[counter - (i + 1)] = c;
    }

    buf[counter] = '\0';

    return counter;
}
/**
 * @brief Converts a 16-bit unsigned integer (0 to 65,535) to character array
 *
 * @param val Integer to convert
 * @param buf Character array to copy to (Recommended buffer length is 6)
 * @return int Returns the length of the conversion string
 */
int ui16toa(uint16_t val, char *buf)
{
    int counter = 0;

    uint16_t temp = val;
    if (!temp)
        buf[counter++] = '0';
    else
        while (temp)
        {
            int digit = temp % 10;
            temp /= 10;

            buf[counter++] = digit + '0';
        }

    // Flip the buffer
    for (int i = 0; i < counter / 2; i++)
    {
        char c = buf[i];
        buf[i] = buf[counter - (i + 1)];
        buf[counter - (i + 1)] = c;
    }

    buf[counter] = '\0';

    return counter;
}
/**
 * @brief Converts a 32-bit unsigned integer (0 to 4,294,967,295) to character array
 *
 * @param val Integer to convert
 * @param buf Character array to copy to (Recommended buffer length is 11)
 * @return int Returns the length of the conversion string
 */
int ui32toa(uint32_t val, char *buf)
{
    int counter = 0;

    uint32_t temp = val;
    if (!temp)
        buf[counter++] = '0';
    else
        while (temp)
        {
            int digit = temp % 10;
            temp /= 10;

            buf[counter++] = digit + '0';
        }

    // Flip the buffer
    for (int i = 0; i < counter / 2; i++)
    {
        char c = buf[i];
        buf[i] = buf[counter - (i + 1)];
        buf[counter - (i + 1)] = c;
    }

    buf[counter] = '\0';

    return counter;
}
/**
 * @brief Converts a 64-bit unsigned integer (0 to 18,446,744,073,709,551,615) to character array
 *
 * @param val Integer to convert
 * @param buf Character array to copy to (Recommended buffer length is 21)
 * @return int Returns the length of the conversion string
 */
int ui64toa(uint64_t val, char *buf)
{
    int counter = 0;

    uint64_t temp = val;
    if (!temp)
        buf[counter++] = '0';
    else
        while (temp)
        {
            int digit = temp % 10;
            temp /= 10;

            buf[counter++] = digit + '0';
        }

    // Flip the buffer
    for (int i = 0; i < counter / 2; i++)
    {
        char c = buf[i];
        buf[i] = buf[counter - (i + 1)];
        buf[counter - (i + 1)] = c;
    }

    buf[counter] = '\0';

    return counter;
}

/**
 * @brief Converts a floating-point number to character array
 *
 * @param val Float to convert
 * @param buf Character array to copy to (Recommended buffer length is 19)
 * @return int Returns the length of the conversion string
 */
int ftoa(float val, char *buf)
{
    int counter = 0, neg = (val < 0 ? 1 : 0);

    if (neg)
    {
        buf[counter++] = '-';
        val *= -1;
    }

    const int DECIMAL_COUNT = 6;
    float temp = (int)val;

    if (!temp)
        buf[counter++] = '0';
    else
        while ((int)temp)
        {
            int digit = (int)temp % 10;
            temp /= 10;

            buf[counter++] = digit + '0';
        }

    // Flip items in the buffer
    if (!neg)
        for (int i = 0; i < counter / 2; i++)
        {
            char c = buf[i];
            buf[i] = buf[counter - (i + 1)];
            buf[counter - (i + 1)] = c;
        }
    else
    {
        for (int i = 1; i < (counter + 1) / 2; i++)
        {
            char c = buf[i];
            buf[i] = buf[(counter + 1) - (i + 1)];
            buf[(counter + 1) - (i + 1)] = c;
        }
    }

    // Decimal point
    buf[counter++] = '.';

    int decimalIndex = counter;
    temp = val;
    for (int i = 0; i < DECIMAL_COUNT; i++)
    {
        temp -= (int)temp;
        temp *= 10;
        int digit = (int)temp % 10;

        buf[counter++] = digit + '0';
    }

    buf[counter] = '\0';

    return counter;
}
/**
 * @brief Converts a double to character array
 *
 * @param val Double to convert
 * @param buf Character array to copy to (Recommended buffer length is 28)
 * @return int Returns the length of the conversion string
 */
int dtoa(double val, char *buf)
{
    int counter = 0, neg = (val < 0 ? 1 : 0);

    if (neg)
    {
        buf[counter++] = '-';
        val *= -1;
    }

    const int DECIMAL_COUNT = 15;
    double temp = (int)val;

    if (!temp)
        buf[counter++] = '0';
    else
        while ((int)temp)
        {
            int digit = (int)temp % 10;
            temp /= 10;

            buf[counter++] = digit + '0';
        }

    // Flip items in the buffer
    if (!neg)
        for (int i = 0; i < counter / 2; i++)
        {
            char c = buf[i];
            buf[i] = buf[counter - (i + 1)];
            buf[counter - (i + 1)] = c;
        }
    else
    {
        for (int i = 1; i < (counter + 1) / 2; i++)
        {
            char c = buf[i];
            buf[i] = buf[(counter + 1) - (i + 1)];
            buf[(counter + 1) - (i + 1)] = c;
        }
    }

    // Decimal point
    buf[counter++] = '.';

    int decimalIndex = counter;
    temp = val;
    for (int i = 0; i < DECIMAL_COUNT; i++)
    {
        temp -= (int)temp;
        temp *= 10;
        int digit = (int)temp % 10;

        buf[counter++] = digit + '0';
    }

    buf[counter] = '\0';

    return counter;
}

#endif