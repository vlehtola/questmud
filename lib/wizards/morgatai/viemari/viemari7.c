inherit "room/room";

reset(arg) {
   if(arg) return;
   add_exit("west","/wizards/morgatai/viemari/viemari25.c");
   add_exit("north","/wizards/morgatai/viemari/viemari22.c");
   add_exit("east","/wizards/morgatai/viemari/viemari26.c");
   short_desc = "Perkeleellinen Viemäri";
   long_desc = "Tämä on viemäri.\n";
   set_light(1);
}
