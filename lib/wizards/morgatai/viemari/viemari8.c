inherit "room/room";

reset(arg) {
   if(arg) return;
   add_exit("north","/wizards/morgatai/viemari/viemari14.c");
   add_exit("east","/wizards/morgatai/viemari/viemari17.c");
   add_exit("south","/wizards/morgatai/viemari/viemari21.c");
   short_desc = "Perkeleellinen Viem�ri";
   long_desc = "T�m� on viem�ri.\n";
   set_light(1);
}
