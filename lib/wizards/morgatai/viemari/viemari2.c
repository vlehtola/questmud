inherit "room/room";

reset(arg) {
   if(arg) return;
   add_exit("north","/wizards/morgatai/viemari/viemari23.c");
   add_exit("west","/wizards/morgatai/viemari/viemari27.c");
   short_desc = "Perkeleellinen Viemäri";
   long_desc = "Tämä on viemäri.\n";
   set_light(1);
}
