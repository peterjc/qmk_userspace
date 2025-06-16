# Tutte Coxeter 36k

![Partial Tutte-Coxeter Graph (26/30 vertices, 36/45 edges)](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEhvS5QfAl7YotptMtpu0nG8XOHOsqG2vocUFF2sRgrn_QwAcUQNhDkctHt_42rQor3Bb5tbAW6FiOsYqv2craP086HMTuAqWk9U0A4yOeEsQkhyphenhyphenUxoayJWf5e-N3_Jg1TC1p9YAiVPTK02pEVCUu3hl72REIk5BAjXgZGoF7T-NWQ28iRirwFs6yzFzAe0/w200-h194/Screenshot%202025-05-28%20at%2014.59.35.png)

This is firmware for an Raspberry Pi Pico PR2040 controller monoblock 36 key design
(three rows of five, and three thumb keys, for each hand). This is a *diode-free*
design with a sparse 13 by 13 scanning matrix designed using a partial
[Tutte-Coxeter](https://en.wikipedia.org/wiki/Tutte%E2%80%93Coxeter_graph) graph
(using only 26 vertices or GPIO pins with 36 edges or keys - see this
[blog post](https://astrobeano.blogspot.com/2025/05/ergo-mech-keyboard-wiring-using-tutte-coxeter-graph.html)
for background, although the final pin selection and trace routing changed).

The first physical PCB for this is designed to fit in the [Gamma Omega keyboard](https://github.com/unspecworks/gamma-omega) case,
and use the same Raspberry Pi Pico based microcontroller board.

* Keyboard Maintainer: [Peter J. A. Cock](https://github.com/peterjc)
* Hardware Supported: Tutte Coxeter 36k (single PCB) with Raspberry Pi Pico
* Hardware Availability: https://github.com/peterjc/gamma-omega

Make example for this keyboard (after setting up your build environment):

    make tutte_coxeter_36k:default

Flashing example for this keyboard:

    make tutte_coxetter_36k:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (bottom left key, Qwerty `z`) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
