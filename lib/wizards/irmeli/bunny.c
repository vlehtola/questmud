inherit "obj/monster";
reset(arg) {

::reset(arg);
if(arg) { return; }
set_level(13);
set_name("bunny");
set_short("A frightened bunny bounding around");
set_long("A white-coloured bunny looks pale, like something has frighten it.\n"+
         "The bunny is cute looking, thin and quite young, easy prey for\n"+
         "bigger, flesh-eating animals. It has long, white ears, small,\n"+
         "cute eyes and two white, sharp tooth sticking out of its mouth.\n");
set_al(0);
set_aggressive(0);
set_gender(0);
set_animal(1);
}
