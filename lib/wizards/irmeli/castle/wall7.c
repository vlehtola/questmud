inherit "room/room";

reset(arg) {
if(arg) return;

add_exit("north","/wizards/irmeli/castle/wall8.c");
add_exit("south","/wizards/irmeli/castle/wall6.c");

short_desc = "East wall of the castle of Asgroth";
long_desc = "You are standing on the castle's five-metre thick east wall. The east wall is\n"+
            "steady, or it feels steadier than the other castle walls. A creepy-looking and\n"+
            "small graveyard which is covered with tombstones and mist is at ground level,\n"+
            "east from here. Only the deep moat separates the graveyard from the castle's\n"+
            "east wall. The graveyard is surrounded with high fence made of rock. It seems\n"+
            "like there's no entrance to the graveyard. The castle's east wall is\n"+
            "disintegrating, causing dangerous situations on the yard as the rocks smash\n"+
            "down. The freezing wind is blowing hard in here. Towards south is the south wall\n"+
            "which is twenty meters higher than the other walls. Towards north there are two\n"+ 
            "massive towers rising up to the sky, reaching almost to the cloudline.\n"; 
           
  property = allocate(2);
  property[0] = "no_summon";
  property[1] = "no_tele";
}
