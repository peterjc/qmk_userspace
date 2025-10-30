# Peter's QMK Userspace fork

[![pre-commit.ci status](https://results.pre-commit.ci/badge/github/peterjc/qmk_userspace/main.svg)](https://results.pre-commit.ci/latest/github/peterjc/qmk_userspace/main)
[![GitHub Actions status](https://github.com/peterjc/qmk_userspace/actions/workflows/build_binaries.yaml/badge.svg?branch=main)](https://github.com/peterjc/qmk_userspace//actions)

This is my fork of the [QMK Userspace repository](https://github.com/qmk/qmk_userspace),
so that I can experiment with keyboards and layouts without the overhead of the full
[QMK firmware repository](https://github.com/qmk/qmk_firmware/). My keyboard PCB designs:

* [Gamma Omega TC36K](keyboards/tutte_coxeter_36k/readme.md) - a no-diode single
  PCB design for a monoblock split 3x5_3 design using Graph Theory (topology) to
  avoid ghosting. This has a sparse 13x13 scanning matrix (using 26 GPIO pins)
  for 36 keys with 6-key rollover.

You can [download pre-compiled firmware](https://github.com/peterjc/qmk_userspace/releases).
An 'offical' release is recommended, the 'latest' binaries may contain experimental changes.
The versions with Vial support are strongly recommended as you can the use the
[Vial GUI tool](https://get.vial.today/) to configure your layout by point-and-click
(the default layout is deliberately very minimal).

These are compiled using [QMK Userspace GitHub Actions](.github/workflows/build_binaries.yaml)
with a tweak to the compile new keyboard(s), and a second workflow to build the Vial layouts
against the [Vial fork of the QMK firmware](https://github.com/vial-kb/vial-qmk/) repository,
where [vial.json](vial.json) rather than [qmk.json](qmk.json) lists the layouts to build.

------------------------------------------------------------------------------

# QMK Userspace

This is a template repository which allows for an external set of QMK keymaps to be defined and compiled. This is useful for users who want to maintain their own keymaps without having to fork the main QMK repository.

## Howto configure your build targets

1. Run the normal `qmk setup` procedure if you haven't already done so -- see [QMK Docs](https://docs.qmk.fm/#/newbs) for details.
1. Fork this repository
1. Clone your fork to your local machine
1. Enable userspace in QMK config using `qmk config user.overlay_dir="$(realpath qmk_userspace)"`
1. Add a new keymap for your board using `qmk new-keymap`
    * This will create a new keymap in the `keyboards` directory, in the same location that would normally be used in the main QMK repository. For example, if you wanted to add a keymap for the Planck, it will be created in `keyboards/planck/keymaps/<your keymap name>`
    * You can also create a new keymap using `qmk new-keymap -kb <your_keyboard> -km <your_keymap>`
    * Alternatively, add your keymap manually by placing it in the location specified above.
    * `layouts/<layout name>/<your keymap name>/keymap.*` is also supported if you prefer the layout system
1. Add your keymap(s) to the build by running `qmk userspace-add -kb <your_keyboard> -km <your_keymap>`
    * This will automatically update your `qmk.json` file
    * Corresponding `qmk userspace-remove -kb <your_keyboard> -km <your_keymap>` will delete it
    * Listing the build targets can be done with `qmk userspace-list`
1. Commit your changes

## Howto build with GitHub

1. In the GitHub Actions tab, enable workflows
1. Push your changes above to your forked GitHub repository
1. Look at the GitHub Actions for a new actions run
1. Wait for the actions run to complete
1. Inspect the Releases tab on your repository for the latest firmware build

## Howto build locally

1. Run the normal `qmk setup` procedure if you haven't already done so -- see [QMK Docs](https://docs.qmk.fm/#/newbs) for details.
1. Fork this repository
1. Clone your fork to your local machine
1. `cd` into this repository's clone directory
1. Set global userspace path: `qmk config user.overlay_dir="$(realpath .)"` -- you MUST be located in the cloned userspace location for this to work correctly
    * This will be automatically detected if you've `cd`ed into your userspace repository, but the above makes your userspace available regardless of your shell location.
1. Compile normally: `qmk compile -kb your_keyboard -km your_keymap` or `make your_keyboard:your_keymap`

Alternatively, if you configured your build targets above, you can use `qmk userspace-compile` to build all of your userspace targets at once.

## Extra info

If you wish to point GitHub actions to a different repository, a different branch, or even a different keymap name, you can modify `.github/workflows/build_binaries.yml` to suit your needs.

To override the `build` job, you can change the following parameters to use a different QMK repository or branch:
```
    with:
      qmk_repo: qmk/qmk_firmware
      qmk_ref: master
```

If you wish to manually manage `qmk_firmware` using git within the userspace repository, you can add `qmk_firmware` as a submodule in the userspace directory instead. GitHub Actions will automatically use the submodule at the pinned revision if it exists, otherwise it will use the default latest revision of `qmk_firmware` from the main repository.

This can also be used to control which fork is used, though only upstream `qmk_firmware` will have support for external userspace until other manufacturers update their forks.

1. (First time only) `git submodule add https://github.com/qmk/qmk_firmware.git`
1. (To update) `git submodule update --init --recursive`
1. Commit your changes to your userspace repository
