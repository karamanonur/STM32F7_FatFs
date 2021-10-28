/*
 * fatfs_operations.c
 *
 *  Created on: Oct 28, 2021
 *      Author: onurkaraman
 */

#include "fatfs_operations.h"

void fatfs_write(void)
{
	/*Written bytes number*/
	uint32_t numOfBytesWritten; /*File write/read counts*/

	/*Buffer for the written text*/
	uint8_t written_text[] = "Mission Accomplished";

	/*Working buffer, _MAX_SS = 512 (Range of sector size)*/
	BYTE work[_MAX_SS];

	f_mount(&SDFatFS, (TCHAR const*)SDPath, 0);

	f_mkfs((TCHAR const*)SDPath, FM_ANY, 0, work, sizeof(work));

	f_open(&SDFile, "SAMPLE.TXT", FA_CREATE_ALWAYS | FA_WRITE);

	f_write(&SDFile, written_text, strlen((char*)written_text), (void*)&numOfBytesWritten);

	f_close(&SDFile);

	f_mount(&SDFatFS, (TCHAR const*)NULL, 0);
}

void fatfs_read(void)
{
	/*Buffer for the read text*/
	BYTE read_text[4096];

	f_mount(&SDFatFS, (TCHAR const*)SDPath, 0);

	f_open(&SDFile, "SAMPLE.TXT", FA_READ);

	f_read(&SDFile, read_text, sizeof read_text, (void *)&numOfBytesRead);

	f_close(&SDFile);

	f_mount(&SDFatFS, (TCHAR const*)NULL, 0);
}

