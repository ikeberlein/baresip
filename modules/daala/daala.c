/**
 * @file daala.c  Experimental video-codec using Daala
 *
 * Copyright (C) 2010 - 2015 Creytiv.com
 */

#include <re.h>
#include <baresip.h>
#include <daala/codec.h>
#include "daala.h"


/**
 * @defgroup daala daala
 *
 * Very experimental video-codec using Daala
 *
 * TODO:
 *
 * - Define and implement fragmentation of large packets
 * - Define an IETF RTP Payload type
 *
 *
 * References:
 *
 *    https://wiki.xiph.org/Daala
 */


static struct vidcodec daala = {
	.name      = "daala",
	.encupdh   = daala_encode_update,
	.ench      = daala_encode,
	.decupdh   = daala_decode_update,
	.dech      = daala_decode,
};


static int module_init(void)
{
	info("daala: using version '%s'\n", daala_version_string());

	vidcodec_register(&daala);

	return 0;
}


static int module_close(void)
{
	vidcodec_unregister(&daala);

	return 0;
}


EXPORT_SYM const struct mod_export DECL_EXPORTS(daala) = {
	"daala",
	"video codec",
	module_init,
	module_close,
};
