## General info

This project id fork of official CHDK

https://app.assembla.com/spaces/chdk

This fork is not based on newest CHDK version. This is fork of 1.4.1 version.

## New Features

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


## WARNING

The code was compiled and tested only for SX10IS and SX100IS. Define these values
in platform\<model>\platform_camera.h as sensor size float values

```
     #define CAM_SENSOR_WIDTH <size in mm>
     #define CAM_SENSOR_HEIGHT <size in mm>
     #define CAM_SENSOR_DIAGONAL <size in mm>
```

example for sx10is, 1/2.3"

```
     #define CAM_SENSOR_WIDTH 6.17f
     #define CAM_SENSOR_HEIGHT 4.55f
     #define CAM_SENSOR_DIAGONAL 7.67f
```

example for sx100is, 1/2.5"

```
     #define CAM_SENSOR_WIDTH 5.744f
     #define CAM_SENSOR_HEIGHT 4.308f
     #define CAM_SENSOR_DIAGONAL 7.18f
```


![This is an image](https://github.com/dariuszrorat/CHDK/blob/master/chdk_sx100.jpg)