inherit "obj/monster";
reset(arg) {

::reset(arg);
if(arg) { return; }
set_level(18);
set_name("wolf");
set_short("A huge grey wolf searching prey");
set_long("The huge grey wolf is searching prey. Its wry, red eyes, upright\n"+
         "ears and straight, long tail are the things, what makes the wolf\n"+
         "look-alike wolf. Its sharp, blood-red teeth reveals, when the\n"+
         "wolf notices you and begins growl.\n");
set_al(0);
set_aggressive(0);
set_gender(0);
set_animal(1);
}
