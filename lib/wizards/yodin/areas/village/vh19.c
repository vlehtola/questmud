inherit "room/room";
inherit "room/shop_d";
object mob;
reset(arg) {
  if(!mob) {
   mob = clone_object("/wizards/yodin/areas/village/monsters/armoury");
   move_object(mob, this_object());
 }

  ::reset(arg);
  if(arg) return;
  short_desc = "The village's armoury";
  long_desc =   "A large room lit with candles here and there. Several large racks are\n" +
				"standing against the walls, each wearing different kind of armours.\n" +
				"The western racks are holding chainmails while the eastern racks\n" +
				"consists of platemail equipment. A large desk can be seen at the\n" +
				"northern end of this room with a man standing behind it. Small windows\n" +
				"allow the light to shine in and extend the view of this otherwise\n" +
				"so dark place.\n" +
                "Available commands: list, sell <item>, buy <item>, peek <item>\n";

property = allocate(4);
  property[0] = "no_kill";
  property[1] = "no_skill";
  property[2] = "no_spell";
  property[3] = "no_summon";
  set_light(3);

  add_exit("east", "vh17.c");
}

init() {
  ::init();
  ::shop_commands();
}

can_sell(ob) {
  if(ob->query_ac()) {
    if(!ob->drop())
    return 1;
  }
}

save_shop() {}
