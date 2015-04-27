/*
 * Copyright 2015 Nokia
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
/******************************************************************************
 * @File    CFakePlatform.h
 * @Brief   It isolate the difference of os api and hardware from the bussiness.
 ******************************************************************************/

#ifndef __C_FAKE_PLATFORM_H__
#define __C_FAKE_PLATFORM_H__

#ifdef __cplusplus
    extern "C" {
#endif

#include "CFakeDatabase.h"

/* Component Object Method Definitions */
typedef struct SFakePlatform {
    /* Quit current progress after print errors */
    void (* RaiseFatal)(char * format, ...);

    /* Check if config param is valid */
    void (* CheckIn)(SFakeConfigParam * configParamPtr);

    /* Replace func as mock */
    SFakeDataInfo * (* EnableMock)(SFakeConfigParam * configParamPtr);

    /* Recover func from mock */
    void (* DisableMock)(SFakeConfigParam *  configParamPtr,
                         SFakeDataInfo    ** dataInfoPtr);
} SFakePlatform;

/* Component Object Statement(Singleton Pattern) */
extern SFakePlatform gFakePlatform;

#ifdef __cplusplus
}
#endif

#endif /* __C_FAKE_PLATFORM_H__ */

