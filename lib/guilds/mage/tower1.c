inherit "room/room";

reset(arg) {
   add_exit("out", "/guilds/mage/entrance");
   add_exit("up", "/guilds/mage/tower2");
   short_desc = "Stairway leading up";
   long_desc = "This round stone stairway is leading up. There are some\n"+
	"strange glowing globes attached to the wall.\n";
   set_light(3);
   set_not_out(1);

   items = allocate(2);
   items[0] = "globes";
   items[1] = "These globes seem to be magical. They provide light";
}

