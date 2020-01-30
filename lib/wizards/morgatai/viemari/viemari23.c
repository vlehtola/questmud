inherit "room/room";

reset(arg) {
   if(arg) return;
   add_exit("north","/wizards/morgatai/viemari/viemari9.c");
   add_exit("south","/wizards/morgatai/viemari/viemari2.c");
   short_desc = "Perkeleellinen Viemäri";
   long_desc = "Tämä on viemäri.\n";
   set_light(1);
}
