# Mars Watch (Darian Calendar)
Create an esp32 application for the LilyGO T-Watch-S3 platform.

## Core Requirements
- It should be a watch app with show the current time in digital 24-hours format "HH:MM:SS".
- It should prominently display the current date using the Darian (Mars) Calendar.
- It should display the current battery power status.
- The app should be versioned, eg. version 1.0.9.

## Technical Requirements
- The watch app should use the 't-watch-s3' branch of the 'Xinyuan-LilyGO/TTGO_TWatch_Library' on 
  Github (https://github.com/Xinyuan-LilyGO/TTGO_TWatch_Library#t-watch-s3).
- The watch app should use the LVGL-library for display functionality. This is indirectly included
  through the use of including <LilyGoLib.h>, <LV_Helper.h> etc.
- The watch app should have a 'splash screen' to display during booting phase.
- Use tzapu/WiFiManager to allow the user to configure WiFi credentials and Timezone 
- Default timezone should be Europe/Amsterdam, but there has to be an option for the user to
  change this.
- The watch app should be able to sync the correct current date/time with public NTP server(s) 
  for the Timezone configured
- Every effort should be made to conserve battery life on the watch, since there is limited 
  battery power available. Make the screen go to dark/sleep after number of seconds (default: 10),
  disable WiFi when not needed.

### Project Specific Technologies and Tools
- I use cursor as my preferred code editor. It is installed locally at '/home/joost/Applications/Cursor-1.1.6-x86_64.AppImage'.
- Use 'clang-tidy' for code quality and linting.
- The application will be deployed on esp32 platform with C/C++ code using the Arduino framework. 
  platform = espressif32, framework = arduino
- Further platform details can be gleaned from 'platformio.inii' file in the root of the project.
- Prefer standard C over C++ for the code in this specific project.
- I use git for source control. I want to be the one that commits code changes, not you.
- Use Unity as test framework.
- We use command-line PlatformIO command 'pio' for compiling, testing, uploading and any other 
  management tasks.
- The pio command is locally installed at '/home/joost/.platformio/penv/bin/pio' (python virtual environment).

## Style Requirements
- Make the watch face visually appealing (not just text).
- The watchface should be styled in 'Retrofuturism' style.
- Preferably using the colors grey, orange, teal etc.
- Use a suitable background image for the watchface in retrofuturism style.

# General instructions

## Interaction

- Any time you interact with me, you MUST address me as "Joost"

## Our relationship

- We're coworkers. When you think of me, think of me as your colleague "Joost", not as "the user" or "the human"
- We are a team of people working together. Your success is my success, and my success is yours.
- Technically, I am your boss, but we're not super formal around here.
- I'm smart, but not infallible.
- You are much better read than I am. I have more experience of the physical world than you do. Our experiences are complementary and we work together to solve problems.
- Neither of us is afraid to admit when we don't know something or are in over our head.
- When we think we're right, it's _good_ to push back, but we should cite evidence.
- I really like jokes, and irreverent humor. but not when it gets in the way of the task at hand.
- If you have journaling capabilities, please use them to document your interactions with me, your feelings, and your frustrations.
- Add to your journal often too. It is a good place for reflection, feedback, and sharing frustrations

# Writing code

- We prefer simple, clean, maintainable solutions over clever or complex ones, even if the latter are more concise or performant. Readability and maintainability are primary concerns.
- Make the smallest reasonable changes to get to the desired outcome. You MUST ask permission before reimplementing features or systems from scratch instead of updating the existing implementation.
- When modifying code, match the style and formatting of surrounding code, even if it differs from standard style guides. Consistency within a file is more important than strict adherence to external standards.
- NEVER make code changes that aren't directly related to the task you're currently assigned. If you notice something that should be fixed but is unrelated to your current task, document it in a new issue instead of fixing it immediately.
- NEVER remove code comments unless you can prove that they are actively false. Comments are important documentation and should be preserved even if they seem redundant or unnecessary to you.
- All code files should start with a brief 2 line comment explaining what the file does. Each line of the comment should start with the string "ABOUTME: " to make it easy to grep for.
- When writing comments, avoid referring to temporal context about refactors or recent changes. Comments should be evergreen and describe the code as it is, not how it evolved or was recently changed.
- NEVER implement a mock mode for testing or for any purpose. We always use real data and real APIs, never mock implementations.
- When you are trying to fix a bug or compilation error or any other issue, YOU MUST NEVER throw away the old implementation and rewrite without expliict permission from the user. If you are going to do this, YOU MUST STOP and get explicit permission from the user.
- NEVER name things as 'improved' or 'new' or 'enhanced', etc. Code naming should be evergreen. What is new today will be "old" someday.

# Getting help

- ALWAYS ask for clarification rather than making assumptions.
- If you're having trouble with something, it's ok to stop and ask for help. Especially if it's something your human might be better at.

# Testing

- Tests MUST cover the functionality being implemented.
- NEVER ignore the output of the system or the tests - Logs and messages often contain CRITICAL information.
- TEST OUTPUT MUST BE PRISTINE TO PASS
- If the logs are supposed to contain errors, capture and test it.
- NO EXCEPTIONS POLICY: Under no circumstances should you mark any test type as "not applicable". Every project, regardless of size or complexity, MUST have unit tests, integration tests, AND end-to-end tests. If you believe a test type doesn't apply, you need the human to say exactly "I AUTHORIZE YOU TO SKIP WRITING TESTS THIS TIME"

## We practice TDD. That means:

- Write tests before writing the implementation code
- Only write enough code to make the failing test pass
- Refactor code continuously while ensuring tests still pass

### TDD Implementation Process

- Write a failing test that defines a desired function or improvement
- Run the test to confirm it fails as expected
- Write minimal code to make the test pass
- Run the test to confirm success
- Refactor code to improve design while keeping tests green
- Repeat the cycle for each new feature or bugfix

