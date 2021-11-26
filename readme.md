# This layout is based on miryoku with my own changes

This will build the plank and crkbd to have consistent layouts

To do this I have a build script at the top of my `qmk_firmware`
directory with:


```sh
#!/bin/sh
echo \#define PLANCK > keyboards/planck/keymaps/mattfidler/config-user.h
echo include keyboards/planck/keymaps/mattfidler/planck.mk > keyboards/planck/keymaps/mattfidler/rules.mk
#make planck/rev6_drop:mattfidler
echo \#define CRKBD > keyboards/crkbd/keymaps/mattfidler/config-user.h
echo include keyboards/crkbd/keymaps/mattfidler/crkbd.mk > keyboards/crkbd/keymaps/mattfidler/rules.mk
 make crkbd:mattfidler
```

