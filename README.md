# Memento mori

This script will remind you the number of days passed since your birth
and the number of days to a nominal death.

## Usage

Put your birth date and expected death date into `gettimes.py` and
then update memento.c with that input.

By default, the number of days to death is not displayed (it was a feature, but then I decided that the uncertainty in death is too large): uncommed the appropriate `#define` statement in `memento.c` if you want to use this feature.

This script also checks for any unsent mail left in my outbox (I use
`offlineimap` for sending email in the backgground). You might want to comment out lines 26-28 and 30.

Use `make` to compile and then add something like this to your
`.bashrc`:

```
if [ "$color_prompt" = yes ]; then
    PS1='${debian_chroot:+($debian_chroot)}\[\033[03;29m\]\u@\h\[\033[00m\]: \[\033[01;33m\]\w\[\033[00m\] $(/home/anze/local/bin/memento) ▶ '
else
    PS1='${debian_chroot:+($debian_chroot)}\u@\h: \w$(/home/anze/local/bin/memento) ▶ '
fi
```

The result is command prompt like this

```
anze@kosovel: ~ [14747 <-> 14837] ▶ 
```

meaning that 14746 days have passed since my birth and I have some
~14800 left.

## Update in 2023

I am now here:
```
anze@kosovel: ~ [16700] ❱❱ 
```
