#include <jni.h>
#include "StartProgram.h"
#include <stdio.h>

JNIEnv *globalEnv;
jobject objectOfISR;

void isrhand();

JNIEXPORT void JNICALL Java_StartProgram_printText(JNIEnv *env, jobject obj) {
	printf("pritnTextt\n");
}

JNIEXPORT void JNICALL Java_StartProgram_initializeInterruptHandler(JNIEnv *env, jobject obj, jobject objInterruptHandler) {
	globalEnv = env;
	objectOfISR = objInterruptHandler;

	isrhand();
	// jmethodID mid;
	// jobject methodOfInterruptHandler;

	// // jclass referenceToClassFromEnv = (*env)->GetObjectClass(env, objInterruptHandler);
	// // mid = (*env)->GetMethodID(env, referenceToClassFromEnv, "firePropertyChangeInterruptHandler", "(Ljava/lang/String;)V");
	// // jstring interruptSource = (*env)->NewStringUTF(env, "Sensor 1");
	// // (*env)->CallVoidMethod(env, objInterruptHandler, mid, interruptSource);
}

void isrhand(){
	jmethodID mid;
	jobject methodOfInterruptHandler;

	jclass referenceToClassFromEnv = (*globalEnv)->GetObjectClass(globalEnv, objectOfISR);
	mid = (*globalEnv)->GetMethodID(globalEnv, referenceToClassFromEnv, "firePropertyChangeInterruptHandler", "(Ljava/lang/String;)V");
	jstring interruptSource = (*globalEnv)->NewStringUTF(globalEnv, "Sensor 1");
	(*globalEnv)->CallVoidMethod(globalEnv, objectOfISR, mid, interruptSource);

	jstring interruptSource2 = (*globalEnv)->NewStringUTF(globalEnv, "Sensor 2");
	(*globalEnv)->CallVoidMethod(globalEnv, objectOfISR, mid, interruptSource2);
}