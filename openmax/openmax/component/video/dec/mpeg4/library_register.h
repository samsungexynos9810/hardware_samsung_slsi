/*
 *
 * Copyright 2012 Samsung Electronics S.LSI Co. LTD
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

/*
 * @file        library_register.h
 * @brief
 * @author      Yunji Kim (yunji.kim@samsung.com)
 * @version     2.0.0
 * @history
 *   2012.02.20 : Create
 */

#ifndef EXYNOS_OMX_MPEG4_DEC_REG
#define EXYNOS_OMX_MPEG4_DEC_REG

#include "Exynos_OMX_Def.h"
#include "OMX_Component.h"
#include "Exynos_OMX_Component_Register.h"


#define OSCL_EXPORT_REF __attribute__((visibility("default")))
#define MAX_COMPONENT_NUM         3
#define MAX_COMPONENT_ROLE_NUM    1

/* MPEG4 */
#ifndef USE_CUSTOM_COMPONENT_SUPPORT
#define EXYNOS_OMX_COMPONENT_MPEG4_DEC            "OMX.Exynos.MPEG4.Decoder"
#define EXYNOS_OMX_COMPONENT_MPEG4_DRM_DEC        "OMX.Exynos.MPEG4.Decoder.secure"
#else
#define EXYNOS_OMX_COMPONENT_MPEG4_DEC            "OMX.Exynos.mpeg4.dec"
#define EXYNOS_OMX_COMPONENT_MPEG4_DRM_DEC        "OMX.Exynos.mpeg4.dec.secure"
#endif

#define EXYNOS_OMX_COMPONENT_MPEG4_DEC_ROLE       "video_decoder.mpeg4"


/* H.263 */
#ifndef USE_CUSTOM_COMPONENT_SUPPORT
#define EXYNOS_OMX_COMPONENT_H263_DEC         "OMX.Exynos.H263.Decoder"
#else
#define EXYNOS_OMX_COMPONENT_H263_DEC         "OMX.Exynos.h263.dec"
#endif

#define EXYNOS_OMX_COMPONENT_H263_DEC_ROLE    "video_decoder.h263"


#ifdef __cplusplus
extern "C" {
#endif

OSCL_EXPORT_REF int Exynos_OMX_COMPONENT_Library_Register(
    ExynosRegisterComponentType **ppExynosComponent);

#ifdef __cplusplus
};
#endif

#endif
