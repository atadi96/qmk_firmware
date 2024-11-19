# Workman custom layout for Equals 48

## Compiling

1. ```
   qmk json2c qmk_firmware/keyboards/boardsource/equals/48/keymaps/workman/workman.json
    ```
2. Copy THE DATA from the outputted array to the `keymap.c` file. The declaration is not correct because the keymap relies on a mutable `keymaps` array.
3. ```
   qmk compile -kb boardsource/equals/48 -km workman
   ```
4. ```
   qmk flash -kb boardsource/equals/48 -km workman
   ```
5. Press the `QK_BOOT` button. (ADJUST+(0,0) on current layout WITH THE KEYBOARD UPSIDE DOWN.)
6. Enjoy! :)

Alternatively instead of Step 4. press the `QK_BOOT` button and copy the `.uf2` file from `qmk_firmware` to the drive.
**This way the settings on the keyboard are preserved.**

## Troubleshooting

For linking error, try `qmk clean -a`. Other case could be that the same settings are enabled in multiple `rules.mk` files.

## Updating QMK

### Source

To update the source, run git.
```
git fetch upstream
git merge upstream/master
```
After that, we need to open QMK MSYS and update the git submodules.
```
qmk git-submodule
```

### QMK MSYS

In QMK MSYS, run the following command:
```
pacman -Syu
```
If needed, run `pacman -Su` after it.
Based on [QMK documentation](https://msys.qmk.fm/faq#how-do-i-keep-my-environment-up-to-date).