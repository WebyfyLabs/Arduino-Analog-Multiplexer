/**
 * @file AnalogMux.cpp
 * @author dhanesh (dhanesh@webyfy.com)
 * @brief Library for 8-channel and 16-channel analog multiplexer
 * @version 0.1
 * @date 2021-05-19
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "Arduino.h"
#include "AnalogMux.h"

/**
 * @brief Default Constructor
 */
AnalogMux::AnalogMux() : _selectCount{0}
{
}

/**
 * @brief Destroy the Analog Mux:: Analog Mux object
 * 
 */
AnalogMux::~AnalogMux()
{
    if (_selectPins != nullptr)
    {
        delete[] _selectPins;
    }
}

/**
 * @brief Setup analog input pins and select pins
 * 
 * @param ain Analog Pin for reading output signal from the multiplexer
 * @param selectCount count of select pins
 * @param selectPins array of select pins
 */
void AnalogMux::begin(uint8_t ain, uint8_t selectCount, uint8_t selectPins[])
{
    _ain = ain;
    _selectCount = selectCount;
    _selectPins = new uint8_t[selectCount];
    for (int i = 0; i < selectCount; i++)
    {
        _selectPins[i] = selectPins[i];
        pinMode(selectPins[i], OUTPUT);
    }
}

/**
 * @brief Get analog reading from a channel
 * 
 * @param channel which channel to read
 * @return analog reading of the channel
 */
int AnalogMux::readChannel(uint8_t channel)
{
    // select channel
    for (int8_t i = 0; i < _selectCount; i++)
    {
        digitalWrite(_selectPins[i], channel % 2);
        channel /= 2;
    }

    return analogRead(_ain);
}

// Methods for unit testing
#ifdef UNIT_TEST
/**
 * @brief Gets the analog Input Pin
 * 
 * @return analog input pin
 */
uint8_t AnalogMux::signalPin(void)
{
    return _ain;
}

/**
 * @brief get the number of select pins
 * 
 * @return the number of select pins
 */
uint8_t AnalogMux::selectCount(void)
{
    return _selectCount;
}

/**
   * @brief Get channel count
   * 
   * Gets the maximum number of channels possible with the 
   * given select pins
   * 
   * @return maximum channel count
   */
uint8_t AnalogMux::channelCount(void)
{
    return 1 << _selectCount;
}

/**
   * @brief Get currently selected channel
   * 
   * @return currently selected channel number
   */
uint8_t AnalogMux::currentChannel(void)
{
    uint8_t channel = 0;
    for (uint8_t i = 0; i < _selectCount; i++)
    {
        channel += (1 << i) * digitalRead(_selectPins[i]);
    }

    return channel;
}
#endif