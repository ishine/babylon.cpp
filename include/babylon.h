#ifndef BABYLON_H
#define BABYLON_H

#ifdef __cplusplus
extern "C" {
#endif

#ifdef WIN32
   #define BABYLON_EXPORT __declspec(dllexport)
#else
   #define BABYLON_EXPORT __attribute__((visibility("default"))) __attribute__((used))
#endif

typedef struct {
   const char* language;
   const unsigned char use_dictionaries;
   const unsigned char use_punctuation;
} babylon_g2p_options_t;

BABYLON_EXPORT int babylon_g2p_init(const char* model_path, babylon_g2p_options_t options);

BABYLON_EXPORT char* babylon_g2p(const char* text);

BABYLON_EXPORT int* babylon_g2p_tokens(const char* text);

BABYLON_EXPORT void babylon_g2p_free(void);

BABYLON_EXPORT int babylon_tts_init(const char* model_path);

BABYLON_EXPORT void babylon_tts(const char* text, const char* output_path);

BABYLON_EXPORT void babylon_tts_free(void);

#ifdef __cplusplus
}
#endif

#endif // BABYLON_H