#ifndef EventEndpoint_h
#define EventEndpoint_h

/**
 *   ESP32 SvelteKit
 *
 *   A simple, secure and extensible framework for IoT projects for ESP32 platforms
 *   with responsive Sveltekit front-end built with TailwindCSS and DaisyUI.
 *   https://github.com/theelims/ESP32-sveltekit
 *
 *   Copyright (C) 2018 - 2023 rjwats
 *   Copyright (C) 2023 theelims
 *
 *   All Rights Reserved. This software may be modified and distributed under
 *   the terms of the LGPL v3 license. See the LICENSE file for details.
 **/

#include <EventSocket.h>
#include <PsychicHttp.h>
#include <SecurityManager.h>
#include <StatefulService.h>

template <class T>
class EventEndpoint
{
public:
    EventEndpoint(JsonStateReader<T> stateReader, JsonStateUpdater<T> stateUpdater, StatefulService<T> *statefulService, EventSocket *socket, const char *event, size_t bufferSize = DEFAULT_BUFFER_SIZE) : _stateReader(stateReader),
                                                                                                                                                                                                            _stateUpdater(stateUpdater),
                                                                                                                                                                                                            _statefulService(statefulService),
                                                                                                                                                                                                            _socket(socket),
                                                                                                                                                                                                            _bufferSize(bufferSize),
                                                                                                                                                                                                            _event(event)
    {
        _socket->on(event, std::bind(&EventEndpoint::updateState, this, std::placeholders::_1, std::placeholders::_2));
        _statefulService->addUpdateHandler([&](const String &originId)
                                           { syncState(originId); },
                                           false);
    }

private:
    JsonStateReader<T> _stateReader;
    JsonStateUpdater<T> _stateUpdater;
    StatefulService<T> *_statefulService;
    EventSocket *_socket;
    const char *_event;
    size_t _bufferSize;

    // TODO Why?
    void updateState(JsonObject &root, int originId)
    {
        if (_statefulService->updateWithoutPropagation(root, _stateUpdater) == StateUpdateResult::CHANGED)
        {
            _statefulService->callUpdateHandlers(String(originId));
        }
    }

    // TODO Does not synchronize state with the client on first connect
    void syncState(const String &originId)
    {
        DynamicJsonDocument jsonDocument{_bufferSize};
        JsonObject root = jsonDocument.to<JsonObject>();
        String output;
        _statefulService->read(root, _stateReader);
        serializeJson(root, output);
        _socket->emit(_event, output.c_str(), originId.c_str());
    }
};

#endif
