## General info

This project is fork of official CHDK

https://app.assembla.com/spaces/chdk

This fork is based on 1.6.0 version. It is intended for pre-DIGIC 6 processors only.

## Installation

You need to install the official version of CHDK on your SD card first and make it bootable.
Then just overwrite the binary files of this project, DISKBOOT.BIN and the
flt modules as well as the language files. The project only works on bootable SD
cards where the official CHDK project is loaded automatically.

## Features

### AutoISO 2 extensions

  - auto ETTR
  - calculation of overexposure for display values

### Histogram extensions

  - YUV histogram
  - Y waveform
  - Y saturation waveform overlay
  - RGB waveform overlay
  - YUV waveform overlay
  - YUV vectorscope
  - Y staturation parade
  - RGB parade
  - YUV parade

### Zebra extensions

  - zone based YUV luminance false colors
  - RGB saturation false colors
  - RGB zebra as saturation zebra or false colors

### DOF calculator extensions

  - AOV calculation
  - FOV calculation

### Other extensions

  - Kelvin temperature calculation


## Compilation

The code was compiled and tested only for SX10IS and SX100IS. Define these values
in platform\<model>\platform_camera.h as sensor size float values

```
     #undef CAM_SENSOR_WIDTH
     #undef CAM_SENSOR_HEIGHT
     #undef CAM_SENSOR_DIAGONAL
     #define CAM_SENSOR_WIDTH <size in mm>
     #define CAM_SENSOR_HEIGHT <size in mm>
     #define CAM_SENSOR_DIAGONAL <size in mm>
```

example for sx10is, 1/2.3"

```
     #undef CAM_SENSOR_WIDTH
     #undef CAM_SENSOR_HEIGHT
     #undef CAM_SENSOR_DIAGONAL
     #define CAM_SENSOR_WIDTH 6.17f
     #define CAM_SENSOR_HEIGHT 4.55f
     #define CAM_SENSOR_DIAGONAL 7.67f
```

example for sx100is, 1/2.5"

```
     #undef CAM_SENSOR_WIDTH
     #undef CAM_SENSOR_HEIGHT
     #undef CAM_SENSOR_DIAGONAL
     #define CAM_SENSOR_WIDTH 5.744f
     #define CAM_SENSOR_HEIGHT 4.308f
     #define CAM_SENSOR_DIAGONAL 7.18f
```

The default is 1/2.5" sensor size in include/camera.h

## WARNING

The project was tested only on the Powershot SX10IS and SX100IS. I don't know
how it will behave on other camera models so be careful. Many times during
tests and errors in the codes my camera turned off with the lens extended
and in order to restart it I had to remove the batteries. I do not know how
the extended functionalities will affect the stability, especially on other cameras.

## Example screenshot


![This is an image](https://github.com/dariuszrorat/CHDK/blob/master/chdk_sx100.jpg)