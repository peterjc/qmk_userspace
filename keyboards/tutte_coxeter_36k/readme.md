# Gamma-Omega TC36K keyboard firmware

This is firmware for a Raspberry Pi Pico PR2040 controller monoblock 36 key design
(split 3x5_3 - three rows of five, and three thumb keys, for each hand): the
[Gamma Omega TC36K keyboard](https://github.com/unspecworks/gamma-omega/tree/main/tc36k).
This is a *diode-free* design with a sparse 13 by 13 scanning matrix designed using a
partial [Tutte-Coxeter Graph](https://en.wikipedia.org/wiki/Tutte%E2%80%93Coxeter_graph)
(using only 26 vertices or GPIO pins, with 36 edges or keys - see this
[blog post](https://astrobeano.blogspot.com/2025/05/ergo-mech-keyboard-wiring-using-tutte-coxeter-graph.html)
for background, although the final pin selection and trace routing changed).

![Partial Tutte-Coxeter Graph (26/30 vertices, 36/45 edges)](https://blogger.googleusercontent.com/img/b/R29vZ2xl/AVvXsEhvS5QfAl7YotptMtpu0nG8XOHOsqG2vocUFF2sRgrn_QwAcUQNhDkctHt_42rQor3Bb5tbAW6FiOsYqv2craP086HMTuAqWk9U0A4yOeEsQkhyphenhyphenUxoayJWf5e-N3_Jg1TC1p9YAiVPTK02pEVCUu3hl72REIk5BAjXgZGoF7T-NWQ28iRirwFs6yzFzAe0/w200-h194/Screenshot%202025-05-28%20at%2014.59.35.png)

This matrix shows the 13×13 partial Tutte-Coxeter bipartite scanning matrix
in the physical column order (QAZ colunm first) with rows sorted to ensure Q
is top left as the first matrix entry. If using the full matrix this would
be 15x15 using 30 GPIOs and have another 9 keys making 45 in all.
The allocation of keys to matrix elements and scanning matrix rows and columns
to GPIO pins was arbitrary and down to how easy it was to layout the PCB traces:

| GP | 20 | 21 | 28 | 27 | 26 | 19 | 16 | 15 | 7 | 4 | 3 | 10 | 11 |
|---:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:--:|:-:|:-:|:-:|:--:|:--:|
| 5  | Q  |    |    |    |    |    | R1 |    |   | J |   |    |    |
| 8  | A  |    |    |    |    |    |    |    |   |   |   | L  | P  |
| 17 | Z  |    | C  |    |    | L3 |    |    |   |   |   |    |    |
| 1  |    | W  |    |    |    |    |    |    |   | U | K |    |    |
| 14 |    | S  |    |    |    |    |    | R3 |   |   |   |    | ;  |
| 18 |    | X  |    |    | B  | L2 |    |    |   |   |   |    |    |
| 0  |    |    | E  | R  |    |    |    |    |   |   | I |    |    |
| 13 |    |    | D  |    |    |    |    | R2 | N |   |   |    |    |
| 12 |    |    |    | F  |    |    |    |    |   |   |   |    | /  |
| 22 |    |    |    | V  | G  |    | L1 |    |   |   |   |    |    |
| 2  |    |    |    |    | T  |    |    |    | Y |   |   | O  |    |
| 6  |    |    |    |    |    |    |    |    | H | M |   |    |    |
| 9  |    |    |    |    |    |    |    |    |   |   | , | .  |    |

The keys here are labeled as per Qwerty, with L3, L2, L1, R1, R2, and R3 for the thumbs:

| Q | W |  E |  R |  T |   |  Y |  U |  I | O | P |
|:-:|:-:|:--:|:--:|:--:|:-:|:--:|:--:|:--:|:-:|:-:|
| A | S |  D |  F |  G |   |  H |  J |  K | L | ; |
| Z | X |  C |  V |  B |   |  N |  M |  , | . | / |
|   |   | L3 | L2 | L1 |   | R1 | R2 | R3 |   |   |

The QMK firmware follows the `LAYOUT_split_3x5_3` QMK community layout convention, making
it much easier to use with an existing layout like Miryoku. Also, the Raspberry Pi Pico
controller's user LED on GPIO pin 25 is set to show the Caps Lock state.

* Keyboard Maintainer: [Peter J. A. Cock](https://github.com/peterjc)
* Hardware Supported: Gamma Omega TC36K (no-diode single PCB) using Raspberry Pi Pico
* Hardware Availability: https://github.com/unspecworks/gamma-omega/tree/main/tc36k

See also the [TC36K ZMK firmware](https://github.com/peterjc/zmk-keyboard-graph-theory/tree/main/boards/shields/tc36k).

Make example for this keyboard (after setting up your build environment):

    make tutte_coxeter_36k:default

Flashing example for this keyboard:

    make tutte_coxetter_36k:default:flash

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).

## Bootloader

Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (top left key, Qwerty `Q`) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the controller (if physically accessible)
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available
