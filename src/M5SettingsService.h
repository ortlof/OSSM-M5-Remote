#include <SettingValue.h>
#include <StatefulService.h>
#include <FSPersistence.h>
#include <HttpEndpoint.h>
#include <JsonUtils.h>
#include <NotificationEvents.h>

#ifndef FACTORY_DARKMODE
#define FACTORY_DARKMODE true
#endif

#ifndef FACTORY_VIBRATE
#define FACTORY_VIBRATE true
#endif

#ifndef FACTORY_TOUCH
#define FACTORY_TOUCH true
#endif

#ifndef FACTORY_EJECT
#define FACTORY_EJECT false
#endif

#define M5_SETTINGS_FILE "/config/m5settings.json"
#define M5_SETTINGS_SERVICE_PATH "/rest/m5settings"

class M5Settings
{
public:
    bool darkmode;
    bool vibrate;
    bool touch;
    bool eject;

    static void read(M5Settings &settings, JsonObject &root)
    {
        root["darkmode"] = settings.darkmode;
        root["vibrate"] = settings.vibrate;
        root["touch"] = settings.touch;
        root["eject"] = settings.eject;
    }

    static StateUpdateResult update(JsonObject &root, M5Settings &settings)
    {
        settings.darkmode = root["darkmode"] | FACTORY_DARKMODE;
        settings.vibrate = root["vibrate"] | FACTORY_VIBRATE;
        settings.touch = root["touch"] | FACTORY_TOUCH;
        settings.eject = root["eject"] | FACTORY_EJECT;
        return StateUpdateResult::CHANGED;
    }

};

class M5SettingsService : public StatefulService<M5Settings>
{
public:
    M5SettingsService(AsyncWebServer *server, FS *fs, SecurityManager *securityManager);
    void begin();

private:
    HttpEndpoint<M5Settings> _httpEndpoint;
    FSPersistence<M5Settings> _fsPersistence;

    void onConfigUpdated();
};