inherit "room/room";

reset(arg) {
   if(arg) return;
   add_exit("east","/wizards/morgatai/viemari/viemari9.c");
   add_exit("west","/wizards/morgatai/viemari/viemari19.c");
   short_desc = "Perkeleellinen Viemäri";
   long_desc = "Tämä on viemäri.\n";
   set_light(1);
}
