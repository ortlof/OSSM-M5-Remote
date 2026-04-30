#pragma once

#include <Arduino.h>

bool OssmBleTryConnect();
bool OssmBleConnected();

void OssmBleSetMode(bool enabled);
bool OssmBleIsMode();

bool OssmBleSendText(const String& command, String* response = nullptr);
bool OssmBleSendCommand(int command, float value, float speedValue, float maxDepthMm, float maxSpeedValue, String* response = nullptr);
bool OssmBlePrepareStrokeEngine();
bool OssmBleReadState(String* stateText);
bool OssmBlePollLimits(float* outMaxDepthMm, float* outMaxSpeedValue);
