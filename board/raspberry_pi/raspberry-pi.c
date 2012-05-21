/*
 */
#include <common.h>

#ifdef CONFIG_USB_EHCI
#include <usb.h>
#include <asm/arch/ehci.h>
#include <asm/ehci-omap.h>
#endif

DECLARE_GLOBAL_DATA_PTR;

/**
 * @brief board_init
 *
 * @return 0
 */
int board_init(void)
{

	gd->bd->bi_arch_number = MACH_TYPE_BCM2708;
	gd->bd->bi_boot_params = (0xc0000000 + 0x100); /* boot param addr */

	return 0;
}

int board_eth_init(bd_t *bis)
{
	return 0;
}

/**
 * @brief misc_init_r - Configure RaspberryPi board specific configurations
 * such as ethernet initialization as phase2 of
 * boot sequence
 *
 * @return 0
 */
int misc_init_r(void)
{

	return 0;
}


#if !defined(CONFIG_SPL_BUILD) && defined(CONFIG_GENERIC_MMC)
int board_mmc_init(bd_t *bis)
{
	omap_mmc_init(0);
	return 0;
}
#endif

#ifdef CONFIG_USB_EHCI

static struct omap_usbhs_board_data usbhs_bdata = {
	.port_mode[0] = OMAP_EHCI_PORT_MODE_PHY,
	.port_mode[1] = OMAP_USBHS_PORT_MODE_UNUSED,
	.port_mode[2] = OMAP_USBHS_PORT_MODE_UNUSED,
};

int ehci_hcd_init(void)
{
	return 0;
}

int ehci_hcd_stop(void)
{

	return omap_ehci_hcd_stop();
}
#endif

/*
 * get_board_rev() - get board revision
 */
u32 get_board_rev(void)
{

	return 0x0;
}

int dram_init(void)
{
	gd->bd->bi_dram[0].start = PHYS_SDRAM_1;
	gd->bd->bi_dram[0].size = PHYS_SDRAM_1_SIZE;

	return 0;
}

void reset_cpu(ulong addr)
{
	// do nothing
}

