inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("cornsnake");
    set_alias("");
    set_short("a cornsnake");
    set_long("This common cornsnake has a reddish hue to it's scales and an even pattern of\n" +
             "yellow bands across. The bright colors makes you belive it's a dangerous snake.\n" +
             "Better leave it be.\n");
}
