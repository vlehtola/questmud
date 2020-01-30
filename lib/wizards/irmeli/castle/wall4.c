inherit "room/room";
object monster;
reset(arg) {

if(!monster) {
monster = clone_object("/wizards/irmeli/castle/monsters/watchman.c");
move_object(monster, this_object());

}
if(arg) return;

add_exit("east","/wizards/irmeli/castle/wall5.c");
add_exit("west","/wizards/irmeli/castle/wall3.c");

short_desc = "South wall of the castle of Asgroth";
long_desc = "On the top of the castle's disintegrating south wall. A beautiful view to the\n"+
            "south can be seen from here. A beautiful valley with broad river, green grass,\n"+
            "beautiful flowers, old trees, thick bushes and much more, these are the things\n"+
            "that can be seen in the massive valley. Not to forget the free animals which\n"+
            "are running around. There are some rocks dropping down to the yard and to the\n"+
            "moat from the south wall. The moat in the ground is full of clear water and\n"+ 
            "big, hungry crocodiles as you can see from here. A guardhouse, stocked with a\n"+
            "roof is eastwards. A strong and cold wind is blowing hard, shaking the castle's\n"+ 
            "south wall. There are two big towers rising up to the sky from the north wall.\n";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
