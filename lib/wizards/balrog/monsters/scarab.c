inherit "obj/monster";

reset(arg) {
  ::reset(arg);
    set_animal(1);
    set_name("scarab");
    set_alias("");
    set_short("a scarab");
    set_long("This is a beetle the size of your palm and has seemingly powerful jaws. It's black\n" +
             "carapace is easilly visibly divided into 3 larger sections. No apparent weaknesses in\n" +
             "it's layout. Well protected from it's natural predators makes it a tough survivor.\n");
}
