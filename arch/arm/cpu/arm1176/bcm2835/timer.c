#include <common.h>
#include <asm/io.h>

struct timer_regs {
	u_int32_t t_cs;
	u_int32_t t_clo;
	u_int32_t t_chi;
	u_int32_t t_c0;
	u_int32_t t_c1;
	u_int32_t t_c2;
	u_int32_t t_c3;
};

#define regs ((struct timer_regs *)CONFIG_SYS_TIMERBASE)

#define TIMER_LOAD_VAL	(CONFIG_SYS_HZ_CLOCK / CONFIG_SYS_HZ)
#define TIM_CLK_DIV	16

static u_int64_t timestamp;
static u_int64_t lastinc;

int timer_init(void)
{
	lastinc = timestamp = 0;

	return 0;
}

static ulong get_timer_raw(void)
{
	u_int64_t now = (u_int64_t)__raw_readl(&regs->t_chi) << 32;
	now |= __raw_readl(&regs->t_clo);

	if (now >= lastinc)
		timestamp += now - lastinc;
	else
		timestamp += (~lastinc + 1) + now;

	lastinc = now;

	return timestamp;
}

ulong get_timer(ulong base)
{
	return (get_timer_raw()) - base;
}

unsigned long long get_ticks(void)
{
	return get_timer(0);
}

void __udelay(unsigned long usec)
{
	ulong tmo;
	ulong endtime;
	signed long diff;

	tmo = CONFIG_SYS_HZ_CLOCK / 1000;
	tmo *= usec;
	tmo /= 1000;

	endtime = get_timer_raw() + tmo;

	do {
		ulong now = get_timer_raw();
		diff = endtime - now;
	} while (diff >= 0);
}

ulong get_tbclk(void)
{
	return CONFIG_SYS_HZ;
}
