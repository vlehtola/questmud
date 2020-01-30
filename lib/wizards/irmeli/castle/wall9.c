inherit "room/room";

reset(arg) {
if(arg) return;

add_exit("south","/wizards/irmeli/castle/wall8.c");

short_desc = "East wall of the castle of Asgroth";
long_desc = "Castle's five-metre thick east wall is under your feet. This must be the\n"+
            "thickest castle wall in this castle. A small and creepy-looking graveyard\n"+
            "is full of old graves and mist is at ground level, about fifty metres beneath\n"+
            "you towards east. The castle's east wall is disintegrating gradually. You can\n"+
            "see some rocks which are dashing against the tombstones in the graveyard. The\n"+
            "castle's east wall is not shaking, even though the strong wind is blowing hard.\n"+
            "There are two towers rising up to the sky, another is towards north and the\n"+ 
            "other is towards northwest. The towers are made of solid rock and there are no\n"+
            "windows. You must turn back because the other tower is blocking your way towards\n"+
            "north. It's impossible to climb up to the tower from here.\n"; 
           
  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
