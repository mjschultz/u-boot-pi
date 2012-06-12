/*
 * (C) Copyright 2010
 * Texas Instruments Incorporated.
 * Steve Sakoman  <steve@sakoman.com>
 *
 * Configuration settings for the TI OMAP4 Panda board.
 * See omap4_common.h for OMAP4 common part
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston,
 * MA 02111-1307 USA
 */

#ifndef __CONFIG_PANDA_H
#define __CONFIG_PANDA_H

#include <asm/sizes.h>

#define CONFIG_DEBUG_EARLY_SERIAL
#define DEBUG
#define CONFIG_DEBUG_DUMP
#define CONFIG_DEBUG_DUMP_SYMS

/* Architecture, CPU, etc */
#define CONFIG_ARM1176
#define CONFIG_RASPBERRY_PI
#define CONFIG_ARCH_CPU_INIT
#define CONFIG_SYS_TEXT_BASE		0x00008000
#define CONFIG_SYS_UBOOT_BASE		CONFIG_SYS_TEXT_BASE
#define CONFIG_DISABLE_TCM

#define BCM2835_PERI_BASE			0x20000000


/* XXX*/
#define CONFIG_SYS_TIMERBASE	(BCM2835_PERI_BASE + 0x003000) 
#define CONFIG_SYS_HZ_CLOCK		250000000
#define CONFIG_SYS_HZ			1000

/* Memory Info */
#define CONFIG_SYS_MALLOC_LEN		(0x10000 + 1*1024*1024)

/* Serial Driver Info */
#define CONFIG_SYS_NS16550
#define CONFIG_SYS_NS16550_SERIAL
#define CONFIG_SYS_NS16550_REG_SIZE	(-4)
#define CONFIG_SYS_NS16550_COM1		(BCM2835_PERI_BASE + 0x215040)
#define CONFIG_SYS_NS16550_CLK		512000000
#define CONFIG_CONS_INDEX		1
#define CONFIG_BAUDRATE			115200
#define CONFIG_SYS_BAUDRATE_TABLE	{ 9600, 19200, 38400, 57600, 115200 }

/* Memory Info */
#define CONFIG_SYS_MALLOC_LEN		(0x10000 + 1*1024*1024)
#define PHYS_SDRAM_1			0
#define PHYS_SDRAM_1_SIZE		0x08000000
#define CONFIG_SYS_MEMTEST_START	PHYS_SDRAM_1
#define CONFIG_SYS_MEMTEST_END		(PHYS_SDRAM_1 + 16*1024*1024)
#define CONFIG_NR_DRAM_BANKS		1
#define CONFIG_STACKSIZE		(256*1024)

#define CONFIG_SYS_SDRAM_BASE		PHYS_SDRAM_1
#define CONFIG_SYS_INIT_RAM_SIZE	(PHYS_SDRAM_1_SIZE/2)
#define CONFIG_SYS_INIT_SP_ADDR		(CONFIG_SYS_SDRAM_BASE + \
					 CONFIG_SYS_INIT_RAM_SIZE - \
					 GENERATED_GBL_DATA_SIZE)

/* Flash and environment info */
#define CONFIG_SYS_NO_FLASH
#define CONFIG_ENV_SIZE			(SZ_128K)

/* USB Networking options */
#define CONFIG_USB_HOST_ETHER
#define CONFIG_USB_ETHER_SMSC95XX

#define CONFIG_UBOOT_ENABLE_PADS_ALL

#define CONFIG_CMD_PING
#define CONFIG_CMD_DHCP
#define CONFIG_CMD_LOADB

#define CONFIG_USB_DWC_OTG
#define CONFIG_DOS_PARTITION
#define CONFIG_CMD_USB
#define CONFIG_CMD_NET

/* GPIO */
// #define CONFIG_CMD_GPIO

/* ENV related config options */
#define CONFIG_ENV_IS_NOWHERE

#define CONFIG_SYS_PROMPT		"Raspberry-Pi # "
#define CONFIG_SYS_CBSIZE		1024
#define CONFIG_SYS_MAXARGS		64
#define CONFIG_SYS_PBSIZE		(CONFIG_SYS_CBSIZE +		\
					 sizeof(CONFIG_SYS_PROMPT) + 16)
#define CONFIG_SYS_LOAD_ADDR		(CONFIG_SYS_MEMTEST_START +	\
					 0x700000)

#endif /* __CONFIG_PANDA_H */
