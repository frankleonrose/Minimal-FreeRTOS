# Minimal FreeRTOS

The purpose of this application is to demonstrate building a [FreeRTOS](https://freertos.org) application with as few source files as possible. It uses [PlatformIO](https://platformio.org) and a lightly-forked [CMSIS-FreeRTOS](https://github.com/frankleonrose/CMSIS-FreeRTOS) library to accomplish this goal.

Read more about this library at http://futurose.com/minimal-freertos-with-platformio.html

## Install on Adafruit Feather M0

1. `git clone https://github.com/frankleonrose/Minimal-FreeRTOS`
1. `cd Minimal-FreeRTOS`
1. Plug in Adafruit Feather M0
1. `platformio run -e adafruit_feather_m0 -t upload`

## Contribute

Pull requests welcome. Use issues to discuss any problems you may encounter.

## License and Copyright

[MIT Licensed](LICENSE) open source software.
Copyright (c) 2019 Frank Leon Rose
