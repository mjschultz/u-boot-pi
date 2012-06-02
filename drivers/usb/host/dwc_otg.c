/*
 * (C) Copyright 2004
 * Wolfgang Denk, DENX Software Engineering, wd@denx.de.
 *
 * This code is based on linux driver for sl811hs chip, source at
 * drivers/usb/host/sl811.c:
 *
 * SL811 Host Controller Interface driver for USB.
 *
 * Copyright (c) 2003/06, Courage Co., Ltd.
 *
 * Based on:
 *	1.uhci.c by Linus Torvalds, Johannes Erdfelt, Randy Dunlap,
 *	  Georg Acher, Deti Fliegl, Thomas Sailer, Roman Weissgaerber,
 *	  Adam Richter, Gregory P. Smith;
 *	2.Original SL811 driver (hc_sl811.o) by Pei Liu <pbl@cypress.com>
 *	3.Rewrited as sl811.o by Yin Aihua <yinah:couragetech.com.cn>
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

#include <common.h>
#include <usb.h>

static int root_hub_devnum = 0;
static struct usb_port_status rh_status = { 0 };/* root hub port status */

#undef DWC_OTG_DEBUG

static int debug = 9;

#ifdef DWC_OTG_DEBUG
	#define PDEBUG(level, fmt, args...) \
		if (debug >= (level)) printf("[%s:%d] " fmt, \
			__PRETTY_FUNCTION__, __LINE__ , ## args)
#else
        #define PDEBUG(level, fmt, args...) do {} while(0)
#endif

int usb_lowlevel_init(void)
{
	root_hub_devnum = 0;
	return 0;
}

int usb_lowlevel_stop(void)
{
	return 0;
}

int submit_bulk_msg(struct usb_device *dev, unsigned long pipe, void *buffer,
		    int len)
{
	int dir_out = usb_pipeout(pipe);
	int ep = usb_pipeendpoint(pipe);
	int max = usb_maxpacket(dev, pipe);
	int done = 0;

	PDEBUG(7, "dev = %ld pipe = %ld buf = %p size = %d dir_out = %d\n",
	       usb_pipedevice(pipe), usb_pipeendpoint(pipe), buffer, len, dir_out);

	dev->status = 0;

	dev->act_len = done;

	return 0;
}

int submit_control_msg(struct usb_device *dev, unsigned long pipe, void *buffer,
		       int len,struct devrequest *setup)
{
	int done = 0;
	int devnum = usb_pipedevice(pipe);
	int ep = usb_pipeendpoint(pipe);

	dev->status = 0;

#if 0
	if (devnum == root_hub_devnum)
		...
#endif

	PDEBUG(7, "dev = %d pipe = %ld buf = %p size = %d rt = %#x req = %#x\n",
	       devnum, ep, buffer, len, (int)setup->requesttype,
	       (int)setup->request);

	return done;
}

int submit_int_msg(struct usb_device *dev, unsigned long pipe, void *buffer,
		   int len, int interval)
{
	PDEBUG(0, "dev = %p pipe = %#lx buf = %p size = %d int = %d\n", dev, pipe,
	       buffer, len, interval);
	return -1;
}
