// ABOUTME: Main application entry point.
// ABOUTME: Initializes the watch and runs the main loop.

#include "cal_darian.h"
#include <LV_Helper.h>
#include <LilyGoLib.h>
#include <WiFiManager.h>
#include <time.h>

// Versioning
const char *APP_VERSION = "1.0.0";

// LVGL objects
lv_obj_t *time_label;
lv_obj_t *darian_date_label;
lv_obj_t *battery_label;
lv_obj_t *version_label;

// extern "C" {
// LV_IMG_DECLARE(background_image);
// }

WiFiManager wm;

// Screen management
const long INACTIVITY_TIME_MS = 10000; // 10 seconds
unsigned long last_activity_time = 0;
bool screen_on = true;

void turn_off_screen() {
  watch.disableSleep();
  screen_on = false;
}

void turn_on_screen() {
  watch.enableSleep();
  screen_on = true;
  last_activity_time = millis();
}

void configModeCallback(WiFiManager *myWiFiManager) {
  Serial.println("Entered config mode");
  Serial.println(WiFi.softAPIP());
  Serial.println(myWiFiManager->getConfigPortalSSID());
}

void setup_wifi_and_ntp() {
  wm.setAPCallback(configModeCallback);

  if (!wm.autoConnect("MarsWatchAP")) {
    Serial.println("Failed to connect and hit timeout");
    delay(3000);
    ESP.restart();
  }

  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Set default timezone to Europe/Amsterdam
  setenv("TZ", "CET-1CEST,M3.5.0,M10.5.0/3", 1);
  tzset();

  // Add a parameter for timezone to WiFiManager
  WiFiManagerParameter custom_timezone(
      "timezone", "Timezone (e.g., CET-1CEST,M3.5.0,M10.5.0/3)",
      "CET-1CEST,M3.5.0,M10.5.0/3", 40);
  wm.addParameter(&custom_timezone);

  if (!wm.autoConnect("MarsWatchAP")) {
    Serial.println("Failed to connect and hit timeout");
    delay(3000);
    ESP.restart();
  }

  // Get timezone from WiFiManager and set it
  setenv("TZ", custom_timezone.getValue(), 1);
  tzset();

  configTime(0, 0, "pool.ntp.org", "time.nist.gov");
}

void update_display() {
  // Update time
  time_t now;
  struct tm timeinfo;
  time(&now);
  localtime_r(&now, &timeinfo);
  char time_buf[9];
  strftime(time_buf, sizeof(time_buf), "%H:%M:%S", &timeinfo);
  lv_label_set_text(time_label, time_buf);

  // Update Darian date
  Darian_Date darian_date;
  gregorian_to_darian(&timeinfo, &darian_date);
  char darian_buf[50];
  sprintf(darian_buf, "%d %s %d", darian_date.day, darian_date.month_name,
          darian_date.year);
  lv_label_set_text(darian_date_label, darian_buf);

  // Update battery status
  int battery_percent = watch.getBatteryPercent();
  if (battery_percent != -1) {
    lv_label_set_text_fmt(battery_label, "Battery: %d%%", battery_percent);
  } else {
    lv_label_set_text(battery_label, "Battery: N/A");
  }
}

void setup() {
  Serial.begin(115200);
  watch.begin();

  // // Splash screen
  // lv_obj_t *splash_label = lv_label_create(lv_scr_act());
  // lv_label_set_text_fmt(splash_label, "Mars Watch\nv%s", APP_VERSION);
  // lv_obj_align(splash_label, LV_ALIGN_CENTER, 0, 0);
  // delay(2000); // Display splash for 2 seconds
  // lv_obj_del(splash_label);

  lv_init();
  beginLvglHelper();

  setup_wifi_and_ntp();

  lv_obj_t *scr = lv_scr_act();
  // lv_obj_t *background_img = lv_img_create(scr);
  // lv_img_set_src(background_img, &background_image);
  // lv_obj_align(background_img, LV_ALIGN_CENTER, 0, 0);

  // Create styles
  static lv_style_t style_text;
  lv_style_init(&style_text);
  lv_style_set_text_color(&style_text, lv_color_hex(0xFFA500)); // Orange
  lv_style_set_text_font(&style_text, &lv_font_montserrat_28);

  static lv_style_t style_small_text;
  lv_style_init(&style_small_text);
  lv_style_set_text_color(&style_small_text, lv_color_hex(0x00CED1)); // Teal
  lv_style_set_text_font(&style_small_text, &lv_font_montserrat_14);

  // Time label
  time_label = lv_label_create(scr);
  lv_obj_add_style(time_label, &style_text, 0);
  lv_obj_align(time_label, LV_ALIGN_CENTER, 0, -30);

  // Darian date label
  darian_date_label = lv_label_create(scr);
  lv_obj_add_style(darian_date_label, &style_text, 0);
  lv_obj_align(darian_date_label, LV_ALIGN_CENTER, 0, 10);

  // Battery label
  battery_label = lv_label_create(scr);
  lv_obj_add_style(battery_label, &style_small_text, 0);
  lv_obj_align(battery_label, LV_ALIGN_BOTTOM_LEFT, 10, -10);

  // Version label
  version_label = lv_label_create(scr);
  lv_obj_add_style(version_label, &style_small_text, 0);
  lv_label_set_text_fmt(version_label, "v%s", APP_VERSION);
  lv_obj_align(version_label, LV_ALIGN_BOTTOM_RIGHT, -10, -10);

  update_display();
  last_activity_time = millis();
}

void loop() {
  lv_task_handler();
  delay(5);

  // Screen sleep management
  if (screen_on && (millis() - last_activity_time > INACTIVITY_TIME_MS)) {
    turn_off_screen();
  }

  // Update display every second
  static uint32_t last_update_time = 0;
  if (millis() - last_update_time > 1000) {
    update_display();
    last_update_time = millis();
  }
}