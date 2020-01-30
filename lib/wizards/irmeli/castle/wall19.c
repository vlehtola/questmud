inherit "room/room";
object monster;
reset(arg) {

if(!monster) {
monster = clone_object("/wizards/irmeli/castle/monsters/watchman.c");
move_object(monster, this_object());

}
if(arg) return;

add_exit("north","/wizards/irmeli/castle/wall18.c");
add_exit("stairs","/wizards/irmeli/castle/wall20.c");

short_desc = "West wall of the castle of Asgroth";
long_desc = "You are standing on the west wall. The west wall is thirty meters high. The\n"+ 
            "terrain in the west is full of old thick trees. Far-reaching forest is\n"+
            "growing in there. Some rocks are dropping down from the wall where you are\n"+
            "standing on, hitting down to the yard and to the moat. The deep moat on the\n"+
            "ground is thirty metres below you. It would be a certain death if you would\n"+
            "fall down from the wall. There is no fence around the wall. A guardhouse,\n"+ 
            "stocked with a roof is south from here twenty meters above you. A strong and\n"+ 
            "cold wind is blowing hard against the west wall. There are stairs leading up\n"+
            "to the south wall. Towards north is two massive towers rising up to the sky,\n"+ 
            "reaching almost to the cloudline.\n";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
