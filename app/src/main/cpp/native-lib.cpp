#include <jni.h>
#include <string>
#include "duckdb.hpp"
using namespace  duckdb;
using namespace  std;

extern "C"
JNIEXPORT jstring JNICALL
Java_com_example_tpch_MainActivity_stringFromJNI(JNIEnv *env, jobject thiz) {
    // TODO: implement stringFromJNI()
    std::string hello = "Hello from C++";
    DuckDB db(nullptr);
    Connection con(db);
    con.EnableProfiling();
    con.Query("CREATE TABLE integers(i INTEGER);");
    con.Query("INSERT INTO integers VALUES (3);");
    auto result = con.Query("select * from duckdb_extensions();");
    return env->NewStringUTF(hello.c_str());
}