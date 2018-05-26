# Dynamic Status LED

This library contains a simple but versatile status led. Create a status led that:

* periodically blinks
* shows a small burst and than goes out for a longer period (low-power apps)
* triggers for a certain number of times

Check out the examples to see how to use the library.

## Requirements

You will need to enable C++11 compilation. This can be achieved by changing the three json configurations files in `code/mbed-os/tools/profiles`. Change the `cxx` section of the `GCC_ARM` config to the following:

```json
        "cxx": ["-std=gnu++11", "-fno-rtti", "-Wvla"],
```