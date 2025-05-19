#include <am.h>
#include <riscv/riscv.h>
#include <klib.h>

static Context *(*user_handler)(Event, Context *) = NULL;

Context *__am_irq_handle(Context *c)
{
	// printf("irq %d\n", c->mcause);
	// printf("pc %x\n", c->mepc);
	// printf("mstatus %x\n", c->mstatus);
	if (user_handler)
	{
		Event ev = {0};
		switch (c->mcause)
		{
		case 11:
			ev.event = EVENT_YIELD;
			c->mepc += 4;
			break;
		case 8:
			ev.event = EVENT_YIELD;
			c->mepc += 4;
			break;
		default:
			ev.event = EVENT_ERROR;
			break;
		}
		c = user_handler(ev, c);
		// skip ecall
		assert(c != NULL);
	}

	return c;
}

extern void __am_asm_trap(void);

bool cte_init(Context *(*handler)(Event, Context *))
{
	// initialize exception entry
	asm volatile("csrw mtvec, %0" : : "r"(__am_asm_trap));

	// register event handler
	user_handler = handler;

	return true;
}
// 首先cte_init会设置异常处理函数的入口地址
// 然后会将用户注册的事件处理函数的地址赋值给user_handler
// 在程序调用yield函数，执行至到ecall指令时，
// 程序会将会完成pc值的更新，跳转到__am_asm_trap函数
// 在__am_asm_trap函数中会将当前的上下文保存到寄存器中
// 然后会调用__am_irq_handle函数
// 在__am_irq_handle函数中会判断当前的异常类型
// 如果是11号异常，则会将event的event成员设置为EVENT_YIELD
// 然后会调用用户注册的事件处理函数
// 在用户注册的事件处理函数中会调用schedule函数
// 在schedule函数中会将当前的上下文,准确来说，是指向当前上下文的指针
// 赋值给current->cp
// 第一次调用yield的上下文指针会被存入pcb_boot的cp成员中
// 然后会将current指向pcb[0]，
// 函数返回时会将pcb[0]的cp成员的值返回

Context *kcontext(Area kstack, void (*entry)(void *), void *arg)
{

	Context *ctx = (Context *)((uintptr_t)kstack.end - sizeof(Context));
	ctx->mepc = (uintptr_t)entry;
	ctx->gpr[2] = (uintptr_t)kstack.end; // stack pointer
	ctx->gpr[10] = (uintptr_t)arg;		 // a0
	// printf("the address of ctx is %x\n", (uint32_t)ctx);
	return ctx;
}

void yield()
{
#ifdef __riscv_e
	asm volatile("li a5, -1; ecall");
#else
	asm volatile("li a7, -1; ecall");
#endif
}

bool ienabled()
{
	return false;
}

void iset(bool enable)
{
}
