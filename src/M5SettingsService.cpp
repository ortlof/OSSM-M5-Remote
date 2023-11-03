#include <M5SettingsService.h>
#include <main.h>

M5SettingsService::M5SettingsService(AsyncWebServer *server, FS *fs, SecurityManager *securityManager) : _httpEndpoint(M5Settings::read,
                                                                                                                        M5Settings::update, 
                                                                                                                        this, 
                                                                                                                        server, 
                                                                                                                        M5_SETTINGS_SERVICE_PATH, 
                                                                                                                        securityManager,
                                                                                                                        AuthenticationPredicates::IS_AUTHENTICATED),
                                                                                                        _fsPersistence(M5Settings::read, M5Settings::update, this, fs, M5_SETTINGS_FILE)
{
   // configure settings service update handler to update LED state
    addUpdateHandler([&](const String &originId){ 
    onConfigUpdated();},
                     false);
}

void M5SettingsService::begin()
{
    _fsPersistence.readFromFS();
}

void M5SettingsService::onConfigUpdated()
{
    _fsPersistence.writeToFS();
}