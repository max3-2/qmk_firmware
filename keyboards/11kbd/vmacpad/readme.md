# vmacad

TODO ADD RENDER

*A macro pad with a large and high quality encoder*

* Keyboard Maintainer: [max3-2](https://github.com/max3-2/hedgehog-kb)
* Hardware Supported: Custom PCB with QMK support build on STM32f4

Make example for this keyboard (after setting up your build environment):

    qmk compile -kb 11kbd/vmacpad -km default

Flashing example for this keyboard:

    qmk flash -kb 11kbd/vmacpad -km default

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Flip the switch (backside) to boot and power cycle the board to ender DFU
