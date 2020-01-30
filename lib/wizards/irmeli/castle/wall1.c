inherit "room/room";
reset(arg) {
if(arg) return;

add_exit("east","/wizards/irmeli/castle/wall2.c");
add_exit("west","/wizards/irmeli/castle/wall21.c");
add_exit("down","/wizards/irmeli/castle/yard2.c");

short_desc = "South wall of the castle of Asgroth";
long_desc = "A beautiful view can be seen to the south over the whole valley. It can be\n"+ 
            "seen only from here, from the top of the castle's south wall. A broad river,\n"+
            "green grass, beatiful flowers, old trees and thick bushes, these are the\n"+
            "things that make the valley so beatiful. Not to forget the animals which are\n"+
            "running free around the valley. A hole is on the ground where the stairs are\n"+
            "leading down to the yard. There are some rocks dropping down to the yard and\n"+
            "to the moat surrounding the castle. A strong and cold wind is blowing har,\n"+
            "shaking the castle's south wall. There are two big towers rising up to the sky\n"+
            "from the north wall. The towers are made of solid rock and there are no windows.\n";
  
  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
