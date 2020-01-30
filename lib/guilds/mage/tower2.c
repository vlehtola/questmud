inherit "room/room";

reset(arg) {
   add_exit("north", "/guilds/mage/arcaners");
   add_exit("west", "/guilds/mage/ice_adept");
   add_exit("east", "/guilds/mage/fire_adept");
   add_exit("up", "/guilds/mage/adv_mages");
   add_exit("down", "/guilds/mage/tower1");
   short_desc = "In round stairway";
   long_desc = 
"You are in a round stone staircase. There is a big landing with\n"+
"corridors leading east, west and north. Hot air is flowing in from the\n"+
"east corridor. There is a slight chill coming from the western corridor.\n"+
"Magical globes light the stone walls.\n";

   set_light(3);
   set_not_out(1);

   items = allocate(2);
   items[0] = "globes";
   items[1] = "These globes seem to be magical. They provide light";
}

