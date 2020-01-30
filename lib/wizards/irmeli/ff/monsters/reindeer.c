inherit "obj/monster";
reset(arg) {

::reset(arg);
if(arg) { return; }
set_level(26);
set_name("reindeer");
set_alias("reindeer");
set_short("A wild and timid reindeer");
set_long("A wild, timid and big reindeer is searching moss, especially\n"+
         "reindeer moss, among the snow covered ground. The reindeer has\n"+
         "two massive, sharp and beatiful antlers sticking out of its\n"+
         "head and four strong, muscular hoofs.\n");
set_al(50);
set_aggressive(0);
set_gender(0);
set_animal(1);
set_move_at_random(4);
}


