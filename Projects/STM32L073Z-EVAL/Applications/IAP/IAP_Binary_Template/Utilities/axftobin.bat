@echo off
echo AXF to BIN file generation ...

"C:\Program Files\Keil\ARM\ARMCC\bin\fromelf.exe" --bin --output ..\MDK-ARM\STM32L073Z_EVAL\STM32L073Z_EVAL_SysTick.bin ..\MDK-ARM\STM32L073Z_EVAL\STM32L073Z_EVAL.axf 

echo AXF to BIN file generation completed.

