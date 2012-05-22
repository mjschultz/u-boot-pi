/*
 * TNETV107X: Architecture initialization
 *
 * See file CREDITS for list of people who contributed to this
 * project.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <common.h>
#include <asm/io.h>

#define PUTC(c) do {					\
			while (!(*aux_lsr & 64))	\
				;						\
			*aux_mu_io = (c);			\
			while ((*aux_lsr & 64))		\
				;						\
} while (0)

#define UART_BASE 0x20215000
#define GPIO_BASE 0x20200000

int arch_cpu_init(void)
{
        volatile int *aux_enables = (int*)(UART_BASE + 0x4);
        volatile int *aux_mu_io = (int*)(UART_BASE + 0x40);
        volatile int *aux_lcr = (int*)(UART_BASE + 0x4C);
        volatile int *aux_lsr = (int*)(UART_BASE + 0x54);
        volatile int *aux_cntl = (int*)(UART_BASE + 0x60);
        volatile int *aux_baudrate = (int*)(UART_BASE + 0x68);
        volatile int *gpio_fsel1 = (int*)(GPIO_BASE + 0x04);

        int v;
        int cnt = 0;
        char c = '0';

        // Configure GPIO pins 14 and 15 to serve as ALT5 func (TXD1 RXD1)
        v = *gpio_fsel1;
        v &= ~((7 << (4*3)));
        v |= ((2 << (4*3)));
        v &= ~((7 << (5*3)));
        v |= ((2 << (5*3)));
        *gpio_fsel1 = v;
        v = *gpio_fsel1;

        // enable UART
        v = *aux_enables;
        v |= 1;
        *aux_enables = v;

		// 8 bits
        *aux_lcr = 1;
		// enable only transmitter for now
        *aux_cntl = 2;

		// select baudrate
        *aux_baudrate = 271; // 115200
        // *aux_baudrate = 541; // 57600
		
		PUTC('P');
		PUTC('I');
		PUTC('-');
		PUTC('B');
		PUTC('O');
		PUTC('O');
		PUTC('T');
		PUTC('\r');
		PUTC('\n');

        icache_enable();

        return 0;
}
