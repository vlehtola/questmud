inherit "room/room";

object monster;

reset(arg) {
   add_exit("up", "/guilds/mage/master_mage");
   add_exit("down", "/guilds/mage/adv_mages");
   short_desc = "A landing in staircase";
   long_desc = 
"There is a small landing in the round stone staircase. Magical globes\n"+
"light the stone walls.\n";
   if (!monster) {
	monster = clone_object("guilds/mage/monsters/guardian");
	move_object(monster, this_object());
   }
   set_light(3);
   set_not_out(1);

   items = allocate(2);
   items[0] = "globes";
   items[1] = "These globes seem to be magical. They provide light";
}

