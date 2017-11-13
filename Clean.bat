@echo off
echo ARGO Cleaner ver 1.0
echo Author: Contiero Enrico 
echo Inizio procedura cancellazione file in corso....
cd MDK-ARM\OUT
del *.crf
del *.htm
del *.axf
del *.sct
del *.o
del *.lnp
del *.iex
del *.dep
del *.d
cd..
cd LST
del *.txt
del *.lst
del *.txt
echo Cancellazione file completata correttamente
echo on
pause