# STM32CubeWB0 CMSIS Device MCU Component

![latest tag](https://img.shields.io/github/v/tag/STMicroelectronics/cmsis_device_wb0.svg?color=brightgreen)

## Overview

**STM32Cube** is a STMicroelectronics original initiative aimed at making life easier for developers by reducing effort, time and cost.

**STM32Cube** covers the overall STM32 products portfolio. It includes a comprehensive embedded software platform delivered for each STM32 series.
   * The CMSIS modules (core and device) corresponding to the ARM(tm) core implemented in this STM32 product.
   * The STM32 HAL-LL drivers, an abstraction layer offering a set of APIs ensuring maximized portability across the STM32 portfolio.
   * The BSP drivers of each evaluation, discovery, or nucleo board provided for this STM32 series.
   * A consistent set of middleware libraries such as STM32 BLE, FreeRTOS, and FatFs.
   * A full set of software projects (basic examples, applications, and demonstrations) for each board, each project developed in three flavors using three toolchains (EWARM, MDK-ARM, and STM32CubeIDE).

Two models of publication are proposed for the STM32Cube embedded software:
   * The monolithic **MCU Package**: all STM32Cube software modules of one STM32 series are present (Drivers, Middleware, Projects, Utilities) in the repository (usual name **STM32Cubexx**, xx corresponding to the STM32 series).
   * The **MCU component**: each STM32Cube software module being part of the STM32Cube MCU Package, is delivered as an individual repository, allowing the user to select and get only the required software functions.

## Description

This **cmsis_device_wb0** MCU component repo is one element of the STM32CubeWB0 MCU embedded software package, providing the **cmsis device** part.

## Release note

Details about the content of this release are available in the release note [here](https://htmlpreview.github.io/?https://github.com/STMicroelectronics/cmsis_device_wb0/blob/main/Release_Notes.html).

## Compatibility information

It is **crucial** that you use a consistent set of versions for the CMSIS Core - CMSIS Device, as mentioned in [this](https://htmlpreview.github.io/?https://github.com/STMicroelectronics/STM32CubeWB0/blob/main/Release_Notes.html) release note.

The full **STM32CubeWB0** MCU package is available [here](https://github.com/STMicroelectronics/STM32CubeWB0).

## Troubleshooting

Please refer to the [CONTRIBUTING.md](CONTRIBUTING.md) guide.
