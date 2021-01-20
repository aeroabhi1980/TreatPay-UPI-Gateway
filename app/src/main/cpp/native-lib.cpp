#include <jni.h>
#include <string>

extern "C" JNIEXPORT jstring JNICALL
Java_in_abhiworld_upigateway_Wrap_t1(
        JNIEnv* env,
        jclass clazz) {
    std::string api_key = "https://app.badabazar.in/login.php?";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upigateway_Wrap_t2(JNIEnv * env, jclass clazz) {
    std::string api_key = "https://random.badabazar.in/kyc.php";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upigateway_Wrap_t3(JNIEnv * env, jclass clazz) {
    std::string api_key = "https://treatpay.com/API/v2/agent/aeps.php?for=key_live";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upigateway_Wrap_t4(JNIEnv * env, jclass clazz) {
    std::string api_key = "https://agent.treatpay.com/response.php?";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upigateway_Wrap_t5(JNIEnv * env, jclass clazz) {
    std::string api_key = "https://agent.treatpay.com/pay.php";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upigateway_Wrap_t6(JNIEnv * env, jclass clazz) {
    std::string api_key = "xayjuqy79po6nrhp";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upigateway_Wrap_t7(JNIEnv * env, jclass clazz) {
    std::string api_key = "https://api.treatpay.com/GTW/payments_update_enc.php?";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upigateway_Wrap_t8(JNIEnv * env, jclass clazz) {
    std::string api_key = "anoroc";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upigateway_Wrap_t9(JNIEnv * env, jclass clazz) {
    std::string api_key = "https://api.treatpay.com/GTW/payments_enc.php?";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upigateway_Wrap_t10(JNIEnv * env, jclass clazz) {
    std::string api_key = "9fb663ccd2bc5c1e9656427563634503";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upigateway_Wrap_t11(JNIEnv * env, jclass clazz) {
    std::string api_key = "9005065666";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upigateway_Wrap_t12(JNIEnv * env, jclass clazz) {
    std::string api_key = "https://treatpay.com/img/logo_aeps.png";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upigateway_Wrap_t13(JNIEnv * env, jclass clazz) {
    std::string api_key = "https://treatpay.com/aeps_android_b2c.php";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_in_abhiworld_upigateway_Wrap_enc(
        JNIEnv* pEnv,
        jclass pThis,
        jint a) {
    return (a + 1)*(a + 1);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upigateway_Wrap_r1(JNIEnv * env, jclass clazz, jint n) {
    std::string api_key = "";
    char chars[]= "abcdefghijklmnopqrstuvwxyz0123456789";
    jint len=strlen(chars);
    for(int  i=0;i<n;i++) {
        api_key+=chars[rand() % len];
    }
    return env->NewStringUTF(api_key.c_str());
}

extern "C" JNIEXPORT jstring JNICALL
Java_in_abhiworld_upilibrary_Wrap_t1(
        JNIEnv* env,
        jclass clazz) {
    std::string api_key = "https://app.badabazar.in/login.php?";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upilibrary_Wrap_t2(JNIEnv * env, jclass clazz) {
    std::string api_key = "https://random.badabazar.in/kyc.php";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upilibrary_Wrap_t3(JNIEnv * env, jclass clazz) {
    std::string api_key = "https://treatpay.com/API/v2/agent/aeps.php?for=key_live";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upilibrary_Wrap_t4(JNIEnv * env, jclass clazz) {
    std::string api_key = "https://agent.treatpay.com/response.php?";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upilibrary_Wrap_t5(JNIEnv * env, jclass clazz) {
    std::string api_key = "https://agent.treatpay.com/pay.php";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upilibrary_Wrap_t6(JNIEnv * env, jclass clazz) {
    std::string api_key = "xayjuqy79po6nrhp";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upilibrary_Wrap_t7(JNIEnv * env, jclass clazz) {
    std::string api_key = "https://api.treatpay.com/GTW/payments_update_enc.php?";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upilibrary_Wrap_t8(JNIEnv * env, jclass clazz) {
    std::string api_key = "anoroc";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upilibrary_Wrap_t9(JNIEnv * env, jclass clazz) {
    std::string api_key = "https://api.treatpay.com/GTW/payments_enc.php?";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upilibrary_Wrap_t10(JNIEnv * env, jclass clazz) {
    std::string api_key = "9fb663ccd2bc5c1e9656427563634503";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upilibrary_Wrap_t11(JNIEnv * env, jclass clazz) {
    std::string api_key = "9005065666";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upilibrary_Wrap_t12(JNIEnv * env, jclass clazz) {
    std::string api_key = "https://treatpay.com/img/logo_aeps.png";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upilibrary_Wrap_t13(JNIEnv * env, jclass clazz) {
    std::string api_key = "https://treatpay.com/aeps_android_b2c.php";
    return env->NewStringUTF(api_key.c_str());
}

extern "C"
JNIEXPORT jint JNICALL
Java_in_abhiworld_upilibrary_Wrap_enc(
        JNIEnv* pEnv,
        jclass pThis,
        jint a) {
    return (a + 1)*(a + 1);
}

extern "C"
JNIEXPORT jstring JNICALL
Java_in_abhiworld_upilibrary_Wrap_r1(JNIEnv * env, jclass clazz, jint n) {
    std::string api_key = "";
    char chars[]= "abcdefghijklmnopqrstuvwxyz0123456789";
    jint len=strlen(chars);
    for(int  i=0;i<n;i++) {
        api_key+=chars[rand() % len];
    }
    return env->NewStringUTF(api_key.c_str());
}
