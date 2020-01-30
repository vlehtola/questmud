inherit "room/room";

reset(arg) {
   if(arg) return;
   add_exit("north","/wizards/morgatai/viemari/viemari16.c");
   add_exit("west","/wizards/morgatai/viemari/viemari20.c");
   add_exit("south","/wizards/morgatai/viemari/viemari23.c");
   short_desc = "Perkeleellinen Viemäri";
   long_desc = "Tämä on viemäri.\n";
   set_light(1);
}
