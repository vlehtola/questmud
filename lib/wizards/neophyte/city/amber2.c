inherit "room/room";

reset (arg) {
    if(arg) return;
        short_desc = "Amber street";
        long_desc = "+######\n"+
                    "|#We#Ar You are on the amber street, which continues to\n"+
                    "+--*--+ the west and east. There are lots of sailors and\n"+
                    "|#####| travellers browsing the shops. To the north is\n"+
                    "+#####+ the weapon shop. There can be heard banging noises\n"+
                    "        and cursing. This street is also known as 'Market\n"+
                    "        Street'.\n";
   add_exit("west","/wizards/neophyte/city/rudder7");
   add_exit("east","/wizards/neophyte/city/amber3");
   add_exit("north","/wizards/neophyte/city/weapon_shop");
}

init() {
   ::init();
   add_action("map", "map");
}

map(arg) {
   if (arg) {
        return 0;
   }
   cat("/wizards/neophyte/city/map");
   return 1;
}
