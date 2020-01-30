inherit "room/room";
object monster;
reset(arg) {

if(!monster) {
monster = clone_object("/wizards/irmeli/castle/monsters/watchman.c");
move_object(monster, this_object());

}
if(arg) return;

add_exit("south","/wizards/irmeli/castle/wall17.c");

short_desc = "West wall of the castle of Asgroth";
long_desc = "The terrain in the west from the castle's west wall is full of old, thick\n"+
            "trees. A far-reaching forest is growing in there. Some rocks are dropping down\n"+
            "from the west wall, hitting down to the yard and to the moat. The deep moat\n"+
            "on the ground is fifty metres below you. A strong and cold wind is blowing hard\n"+
            "against the west wall. There are two towers rising up to the sky, another is\n"+ 
            "towards north and the other is towards northeast. The towers are made of solid\n"+ 
            "rock and there are no windows. You must turn back because the other tower is\n"+
            "blocking your way towards north. It's impossible to climb up to the tower from\n"+
            "here.\n";

  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
