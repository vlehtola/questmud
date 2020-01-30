inherit "room/room";
object monster;
reset(arg) {

if(!monster) {
monster = clone_object("/wizards/irmeli/castle/monsters/watchman.c");
move_object(monster, this_object());

}
if(arg) return;

add_exit("north","/wizards/irmeli/castle/wall7.c");
add_exit("stairs","/wizards/irmeli/castle/wall5.c");

short_desc = "East wall of the castle of Asgroth";
long_desc = "Castle's five-metre thick east wall is under your feet. This must be the\n"+
            "thickest castle wall in this castle. The east wall is thirty meters high.\n"+
            "A small and creepy-looking graveyard full of old graves is towards east.\n"+ 
            "Mist is covering the graveyard. There seems to be no entry to the graveyard.\n"+
            "Jumping down would be a fatal error. The castle's east wall is disintegrating\n"+
            "gradually. Some rocks are dashing down against the tombstones. A guardhouse,\n"+
            "stocked with a roof is towards south twenty meters above you. The castles east\n"+
            "wall is not shaking even though the strong wind is blowing hard. There are\n"+
            "stairs leading up to the south wall. Towards north there are two massive\n"+ 
            "towers rising up to the sky, reaching almost to the cloudline.\n"; 
           
  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
