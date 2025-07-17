//Copyright 2025-Present riplin

#include <dpmi.h>
#include <go32.h>
#include <has/system/sysasm.h>
#include <has/system/interrup.h>

namespace Has::System::InterruptTable
{

static _go32_dpmi_seginfo s_OldHandler[16] =
{
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

static _go32_dpmi_seginfo s_NewHandler[16] =
{
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0},
    {0,0,0,0,0}
};

void SetupHandler(uint8_t interrupt, void (*handler)())
{
    interrupt &= 0x0f;

    s_NewHandler[interrupt].pm_offset = (unsigned long)handler;
    s_NewHandler[interrupt].pm_selector = _go32_my_cs();
    _go32_dpmi_allocate_iret_wrapper(&s_NewHandler[interrupt]);
    
    SYS_ClearInterrupts();
    _go32_dpmi_get_protected_mode_interrupt_vector(interrupt, &s_OldHandler[interrupt]);
    _go32_dpmi_set_protected_mode_interrupt_vector(interrupt, &s_NewHandler[interrupt]);
    SYS_RestoreInterrupts();
}

void RestoreHandler(uint8_t interrupt)
{
    interrupt &= 0x0f;

    SYS_ClearInterrupts();
    _go32_dpmi_set_protected_mode_interrupt_vector(interrupt, &s_OldHandler[interrupt]);
    SYS_RestoreInterrupts();

    _go32_dpmi_free_iret_wrapper(&s_NewHandler[interrupt]);
}

}