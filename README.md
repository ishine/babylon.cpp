<div align="center">
  <img alt="logo" height="200px" src="babylon.svg">
</div>

# babylon.cpp

[![Build Windows](https://github.com/Mobile-Artificial-Intelligence/babylon.cpp/actions/workflows/build-windows.yml/badge.svg)](https://github.com/Mobile-Artificial-Intelligence/babylon.cpp/actions/workflows/build-windows.yml)
[![Build MacOS](https://github.com/Mobile-Artificial-Intelligence/babylon.cpp/actions/workflows/build-macos.yml/badge.svg)](https://github.com/Mobile-Artificial-Intelligence/babylon.cpp/actions/workflows/build-macos.yml)
[![Build Linux](https://github.com/Mobile-Artificial-Intelligence/babylon.cpp/actions/workflows/build-linux.yml/badge.svg)](https://github.com/Mobile-Artificial-Intelligence/babylon.cpp/actions/workflows/build-linux.yml)
[![Build Android](https://github.com/Mobile-Artificial-Intelligence/babylon.cpp/actions/workflows/build-android.yml/badge.svg)](https://github.com/Mobile-Artificial-Intelligence/babylon.cpp/actions/workflows/build-android.yml)

Babylon.cpp is a C and C++ library for grapheme to phoneme conversion and text to speech synthesis. 
For phonemization a ONNX runtime port of the [DeepPhonemizer](https://github.com/as-ideas/DeepPhonemizer) model is used. 
For speech synthesis [VITS](https://github.com/jaywalnut310/vits) models are used. 
[Piper](https://github.com/rhasspy/piper) models are compatible after a conversion script is run.

## Build and Run

To build and run the library run the following commands:

```bash
make
./bin/babylon_example
```

To reduce compile time by default the libary uses onnxruntime shared libraries provided by microsoft.
This can be overridden by setting `BABYLON_BUILD_SOURCE` to `ON`.

## Usage

### C Example:

```c
#include "babylon.h"

int main() {
    babylon_g2p_options_t options = {
      .language = "en_us",
      .use_dictionaries = 1,
      .use_punctuation = 1,
    };

    babylon_g2p_init("path/to/deep_phonemizer.onnx", options);

    const char* text = "Hello World";

    babylon_tts_init("path/to/vits.onnx");

    babylon_tts(text, "path/to/output.wav");

    babylon_tts_free();
    
    babylon_g2p_free();

    return 0;
}
```

### C++ example:

```cpp
#include "babylon.hpp"

int main() {
    DeepPhonemizer::Session dp("path/to/deep_phonemizer.onnx");

    Vits::Session vits("path/to/vits.onnx");

    std::string text = "Hello World";

    std::vector<std::string> phonemes = dp.g2p(text);

    vits.tts(phonemes, "path/to/output.wav");

    return 0;
}
```
