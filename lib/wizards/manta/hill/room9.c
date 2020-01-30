inherit "room/room";

object monster;

reset(status arg) {
 if(!monster) move_object(monster = clone_object("/wizards/manta/castle/dem2.c"), this_object());
 if(arg) return;
 add_exit("south", "/wizards/manta/hill/room5.c");
 set_short("Kitchen");
 set_long("This is once so cozy kitchen but now deserted ruin crying for revenge.\n" +
"Maybe you should revenge for these people who lost their lives.\n" +
         "Fighting to protect their home.\n");
 set_light(3);
 set_not_out();

}

