/*
 * Copyright (C) 2008 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "logging.h"

#include "JniConstants.h"  // Last to avoid problems with LOG redefinition.
#include "ScopedPrimitiveArray.h"  // Last to avoid problems with LOG redefinition.

namespace art {

namespace {

static void DdmServer_nativeSendChunk(JNIEnv* env, jclass, jint type,
                                      jbyteArray javaData, jint offset, jint length)
{
  ScopedByteArrayRO data(env, javaData);
  DCHECK_LE(offset + length, static_cast<int32_t>(data.size()));
  UNIMPLEMENTED(WARNING) << "dvmDbgDdmSendChunk(type, length, data->get() + offset);";
}

static JNINativeMethod gMethods[] = {
  NATIVE_METHOD(DdmServer, nativeSendChunk, "(I[BII)V"),
};

}  // namespace

void register_org_apache_harmony_dalvik_ddmc_DdmServer(JNIEnv* env) {
    jniRegisterNativeMethods(env, "org/apache/harmony/dalvik/ddmc/DdmServer", gMethods, NELEM(gMethods));
}

}  // namespace art
