inherit "room/room";

reset(status arg) {
   if(arg) return;
   add_exit("east","/wizards/morgatai/viemari/viemari19.c");
   add_exit("west","/wizards/morgatai/viemari/viemari18.c");
   add_exit("south","/wizards/morgatai/viemari/viemari22.c");
   short_desc = "Perkeleellinen Viem�ri";
   long_desc = "T�m� on viem�ri.\n";
   set_light(1);
}
