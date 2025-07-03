# Mars Watch TODO

## Core Requirements
- [x] Show current time in digital 24-hours format "HH:MM:SS".
- [x] Display the current date using the Darian (Mars) Calendar.
- [x] Display the current battery power status.
- [x] The app should be versioned, eg. version 1.0.9.

## Technical Requirements
- [x] Use the 't-watch-s3' branch of the 'Xinyuan-LilyGO/TTGO_TWatch_Library'.
- [x] Use the LVGL-library for display functionality.
- [ ] Have a 'splash screen' to display during booting phase.
- [x] Use tzapu/WiFiManager to allow the user to configure WiFi credentials and Timezone.
- [x] Default timezone should be Europe/Amsterdam, but there has to be an option for the user to change this.
- [x] Sync the correct current date/time with public NTP server(s) for the Timezone configured.
- [x] Conserve battery life:
    - [V] Make the screen go to dark/sleep after a number of seconds (default: 10).
    - [V] Disable WiFi when not needed.

## Testing
- [ ] All tests should run successfully (in 'native' environment).

## Style Requirements
- [ ] Make the watch face visually appealing.
- [ ] The watchface should be styled in 'Retrofuturism' style.
- [x] Use the colors grey, orange, teal etc.
- [ ] Use a suitable background image for the watchface in retrofuturism style.

## Project Management
- [x] Create todo.md file
- [ ] Create session summary file at the end of the session.
