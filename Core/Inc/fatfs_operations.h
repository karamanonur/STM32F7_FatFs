/*
 * fatfs_operations.h
 *
 *  Created on: Oct 28, 2021
 *      Author: onurkaraman
 */

#ifndef INC_FATFS_OPERATIONS_H_
#define INC_FATFS_OPERATIONS_H_

#include "fatfs.h"
#include <string.h>

void fatfs_write(void);
void fatfs_read(void);

/*Read bytes number*/
uint32_t numOfBytesRead;

#endif /* INC_FATFS_OPERATIONS_H_ */
