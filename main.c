#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "base64.h"

#ifdef __cplusplus
extern "C" {
#endif

static void
test(unsigned char *encode, unsigned int encodelen,
     char *decode, unsigned int decodelen)
{
	char *encode_out;;
	unsigned char *decode_out;

	encode_out = (char *)malloc(BASE64_ENCODE_OUT_SIZE(encodelen));
	decode_out = (unsigned char *)malloc(BASE64_DECODE_OUT_SIZE(decodelen));

	assert(encode_out);
	assert(decode_out);

	assert(base64_encode(encode, encodelen, encode_out) == decodelen);
	assert(memcmp(encode_out, decode, decodelen) == 0);

	assert(base64_decode(decode, decodelen, decode_out) == encodelen);
	assert(memcmp(decode_out, encode, encodelen) == 0);

	free(encode_out);
	free(decode_out);
}

int
main(void)
{
	test((unsigned char *)"foobar", 6, (char *)"Zm9vYmFy", 8);

	printf("all check pass!\n");

	return 0;
}

#ifdef __cplusplus
}
#endif

