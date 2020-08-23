#include "com_ian678_ocrad_Ocrad.h"
#include "../ocradlib.h"

JNIEXPORT jstring JNICALL Java_com_ian678_ocrad_Ocrad_OCRAD_1version(JNIEnv *env, jobject) {
  return env->NewStringUTF(OCRAD_version_string);
}

JNIEXPORT jlong JNICALL Java_com_ian678_ocrad_Ocrad_OCRAD_1open(JNIEnv *env, jobject) {
  return (jlong)OCRAD_open();
}

JNIEXPORT jint JNICALL Java_com_ian678_ocrad_Ocrad_OCRAD_1close(JNIEnv *, jobject, jlong ocrdes) {
  return (jint)OCRAD_close((OCRAD_Descriptor *) ocrdes);
}

JNIEXPORT jint JNICALL Java_com_ian678_ocrad_Ocrad_OCRAD_1get_1errno(JNIEnv *, jobject, jlong ocrdes) {
  return (jint)OCRAD_get_errno((OCRAD_Descriptor *) ocrdes);
}

JNIEXPORT jint JNICALL Java_com_ian678_ocrad_Ocrad_OCRAD_1set_1image(JNIEnv *, jobject, jlong ocrdes, jlong image, jboolean invert) {
  return (jint)OCRAD_set_image((OCRAD_Descriptor *) ocrdes, (OCRAD_Pixmap *) image, invert);
}

JNIEXPORT jint JNICALL Java_com_ian678_ocrad_Ocrad_OCRAD_1set_1image_1from_1file(JNIEnv *env, jobject, jlong ocrdes, jstring filename, jboolean invert) {
  return (jint)OCRAD_set_image_from_file((OCRAD_Descriptor *) ocrdes, env->GetStringUTFChars(filename, false), invert);
}

JNIEXPORT jint JNICALL Java_com_ian678_ocrad_Ocrad_OCRAD_1set_1utf8_1format(JNIEnv *env, jobject, jlong ocrdes, jboolean utf8) {
  return (jint)OCRAD_set_utf8_format((OCRAD_Descriptor *) ocrdes, !!utf8);
}

JNIEXPORT jint JNICALL Java_com_ian678_ocrad_Ocrad_OCRAD_1set_1threshold(JNIEnv *, jobject, jlong ocrdes, jint threshold) {
  return (jint)OCRAD_set_threshold((OCRAD_Descriptor *) ocrdes, threshold);
}

JNIEXPORT jint JNICALL Java_com_ian678_ocrad_Ocrad_OCRAD_1scale(JNIEnv *, jobject, jlong ocrdes, jint value) {
  return (jint)OCRAD_scale((OCRAD_Descriptor *) ocrdes, value);
}

JNIEXPORT jint JNICALL Java_com_ian678_ocrad_Ocrad_OCRAD_1recognize(JNIEnv *, jobject, jlong ocrdes, jboolean layout) {
  return (jint)OCRAD_recognize((OCRAD_Descriptor *) ocrdes, !!layout);
}

JNIEXPORT jint JNICALL Java_com_ian678_ocrad_Ocrad_OCRAD_1result_1blocks(JNIEnv *, jobject, jlong ocrdes) {
  return (jint)OCRAD_result_blocks((OCRAD_Descriptor *) ocrdes);
}

JNIEXPORT jint JNICALL Java_com_ian678_ocrad_Ocrad_OCRAD_1result_1lines(JNIEnv *, jobject, jlong ocrdes, jint blocknum) {
  return (jint)OCRAD_result_lines((OCRAD_Descriptor *) ocrdes, blocknum);
}

JNIEXPORT jint JNICALL Java_com_ian678_ocrad_Ocrad_OCRAD_1result_1chars_1total(JNIEnv *, jobject, jlong ocrdes) {
  return (jint)OCRAD_result_chars_total((OCRAD_Descriptor *) ocrdes);
}

JNIEXPORT jint JNICALL Java_com_ian678_ocrad_Ocrad_OCRAD_1result_1chars_1block(JNIEnv *, jobject, jlong ocrdes, jint blocknum) {
  return (jint)OCRAD_result_chars_block((OCRAD_Descriptor *) ocrdes, blocknum);
}

JNIEXPORT jint JNICALL Java_com_ian678_ocrad_Ocrad_OCRAD_1result_1chars_1line(JNIEnv *, jobject, jlong ocrdes, jint blocknum, jint linenum) {
  return (jint)OCRAD_result_chars_line((OCRAD_Descriptor *) ocrdes, blocknum, linenum);
}

JNIEXPORT jstring JNICALL Java_com_ian678_ocrad_Ocrad_OCRAD_1result_1line(JNIEnv *env, jobject, jlong ocrdes, jint blocknum, jint linenum) {
  return env->NewStringUTF(OCRAD_result_line((OCRAD_Descriptor *) ocrdes, blocknum, linenum));
}

JNIEXPORT jint JNICALL Java_com_ian678_ocrad_Ocrad_OCRAD_1result_1first_1character(JNIEnv *, jobject, jlong ocrdes) {
  return (jint)OCRAD_result_first_character((OCRAD_Descriptor *) ocrdes);
}
