/*
 * dxlAPRS toolchain
 *
 * Copyright (C) Christian Rabler <oe5dxl@oevsv.at>
 *
 * SPDX-License-Identifier:	GPL-2.0+
 */


#ifndef libsrtm_H_
#define libsrtm_H_
#ifndef X2C_H_
#include "X2C.h"
#endif
#ifndef aprsstr_H_
#include "aprsstr.h"
#endif

#define libsrtm_ATTRWATER 3

#define libsrtm_ATTRWOOD 2

#define libsrtm_ATTRURBAN 1

struct libsrtm_METAINFO;


struct libsrtm_METAINFO {
   char withslant;
   char aliasattr;
   float slantx;
   float slanty;
   float attrweights[8];
};

typedef struct libsrtm_METAINFO * libsrtm_pMETAINFO;

extern uint32_t libsrtm_srtmmem;

extern uint32_t libsrtm_srtmmaxmem;

extern uint32_t libsrtm_accesses;

extern uint32_t libsrtm_accessescached;

extern char libsrtm_srtmdir[1024];

extern char libsrtm_bicubic;

extern int32_t libsrtm_opensrtm(uint8_t, uint32_t, uint32_t);

extern float libsrtm_getsrtm(struct aprsstr_POSITION, uint32_t,
                float *);

extern float libsrtm_getsrtmlong(double, double, uint32_t,
                char, float *, uint8_t *, libsrtm_pMETAINFO);

extern void libsrtm_initsrtm(void);

extern void libsrtm_closesrtmfile(void);

extern float libsrtm_egm96(struct aprsstr_POSITION, char *);


extern void libsrtm_BEGIN(void);


#endif /* libsrtm_H_ */
