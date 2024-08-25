#include "babylon.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        return 1;
    }

    babylon_g2p_options_t options = {
      .language = "en_us",
      .use_dictionaries = 1,
      .use_punctuation = 1
    };

    babylon_g2p_init("./models/deep_phonemizer.onnx", options);

    babylon_tts_init("./models/curie.onnx");

    babylon_tts(argv[1], "path/to/output.wav");

    babylon_tts_free();
    
    babylon_g2p_free();

    return 0;
}