inherit "room/room";

reset(arg) {
   if(arg) return;
   add_exit("east","/wizards/morgatai/viemari/viemari2.c");
   add_exit("west","/wizards/morgatai/viemari/viemari26.c");
   short_desc = "Perkeleellinen Viem�ri";
   long_desc = "T�m� on viem�ri.\n";
   set_light(1);
}
