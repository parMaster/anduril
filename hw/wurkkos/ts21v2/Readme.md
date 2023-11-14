# avrdude

avrdude.conf with jtag2updi enabled and everything else to flash UPDI devices with an Arduino:
https://github.com/ElTangas/jtag2updi

# Dumps are made by:

	avrdude -c jtag2updi -P /dev/ttyUSB0 -p t1616 -v -Uflash:r:flash-dump.hex:i -Ueeprom:r:eeprom-dump.hex:i

	md5sum eeprom-dump.hex 
	2b8ee39bee808bda44db3adcb8a606ff  eeprom-dump.hex

	md5sum flash-dump.hex 
	7557c4c610d39aedbf13d0265c148e7f  flash-dump.hex

# New flash
Built like this:

	./bin/build-all.sh ts21v2

And flashed like this:

	avrdude -c jtag2updi -P /dev/ttyUSB0 -p t1616 -v -u -Uflash:w:anduril.wurkkos-ts21v2.hex
