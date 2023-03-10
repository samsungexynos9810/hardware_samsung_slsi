/*
 *
 * Copyright 2013 Samsung Electronics S.LSI Co. LTD
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
 * @file        Exynos_OMX_Vp9enc.h
 * @brief
 * @author      SeungBeom Kim (sbcrux.kim@samsung.com)
 *              Taehwan Kim (t_h.kim@samsung.com)
 * @version     2.0.0
 * @history
 *   2015.04.14 : Create
 */

#ifndef EXYNOS_OMX_VP9_ENC_COMPONENT
#define EXYNOS_OMX_VP9_ENC_COMPONENT

#include "Exynos_OMX_Def.h"
#include "OMX_Component.h"
#include "OMX_Video.h"

#include "ExynosVideoApi.h"

typedef struct _EXYNOS_MFC_VP9ENC_HANDLE
{
    OMX_HANDLETYPE  hMFCHandle;

    OMX_U32     indexTimestamp;
    OMX_U32     outputIndexTimestamp;
    OMX_BOOL    bConfiguredMFCSrc;
    OMX_BOOL    bConfiguredMFCDst;

    ExynosVideoEncOps           *pEncOps;
    ExynosVideoEncBufferOps     *pInbufOps;
    ExynosVideoEncBufferOps     *pOutbufOps;
    ExynosVideoEncParam          encParam;
    ExynosVideoInstInfo          videoInstInfo;

    OMX_U32 nRefForPframes;

    #define MAX_PROFILE_NUM 4
    OMX_VIDEO_VP9PROFILETYPE   profiles[MAX_PROFILE_NUM];
    OMX_S32                    nProfileCnt;
    OMX_VIDEO_VP9LEVELTYPE     maxLevel;
} EXYNOS_MFC_VP9ENC_HANDLE;

typedef struct _EXYNOS_VP9ENC_HANDLE
{
    /* OMX Codec specific */
    OMX_VIDEO_PARAM_VP9TYPE             VP9Component[ALL_PORT_NUM];
    OMX_VIDEO_PARAM_ERRORCORRECTIONTYPE errorCorrectionType[ALL_PORT_NUM];
    OMX_U32                             nPFrames;  /* IDR period control */
    OMX_VIDEO_QPRANGE                   qpRangeI;
    OMX_VIDEO_QPRANGE                   qpRangeP;

    OMX_VIDEO_PARAM_ANDROID_VP8ENCODERTYPE  AndroidVp9EncoderType;

    /* SEC MFC Codec specific */
    EXYNOS_MFC_VP9ENC_HANDLE hMFCVp9Handle;

    OMX_BOOL        bSourceStart;
    OMX_BOOL        bDestinationStart;
    OMX_HANDLETYPE  hSourceStartEvent;
    OMX_HANDLETYPE  hDestinationInStartEvent;
    OMX_HANDLETYPE  hDestinationOutStartEvent;

    EXYNOS_QUEUE    bypassBufferInfoQ;
} EXYNOS_VP9ENC_HANDLE;

#ifdef __cplusplus
extern "C" {
#endif

OSCL_EXPORT_REF OMX_ERRORTYPE Exynos_OMX_ComponentInit(OMX_HANDLETYPE hComponent, OMX_STRING componentName);
                OMX_ERRORTYPE Exynos_OMX_ComponentDeinit(OMX_HANDLETYPE hComponent);

#ifdef __cplusplus
};
#endif

#endif
