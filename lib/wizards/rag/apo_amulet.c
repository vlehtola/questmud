inherit "obj/armour";
object skin;

start() {
  set_class(5);
  set_slot("amulet");
  set_name("amulet");
  set_short("'Strato' The amulet of Apocalypse");
  set_long("This mighty piece of equipment is centuries old\n"+
           "and it is rumoured that if this amulet ever reaches\n"+
           "it's highest aura, the world will be devastated. It\n"+
           "was made by ancient cult that worshipped Apocalypse,\n"+
           "after the cult extincted, Dark-god Odel got his hands\n"+
           "on it. Apocalypse almost came true when Odel found out\n"+
           "how to get the amulet to it's highest aura. After a huge\n"+
           "battle, one of Odel's minions Mondasa got his hands on\n"+
           "the amulet, after that the path of the amulet is unknown");
  set_ac(10);
  set_value(25000);
  set_stats("str", 7);
  set_stats("con", 7);
  set_stats("dex", 7);
  set_stats("spr", 5);

}

do_wear(arg) {
  ::do_wear(arg);
  if(!skin) {
    skin = clone_object("/guilds/spell_obj/stone_skin");
  }
  this_player()->end_stone_skin();
  skin->start(this_player(),-1);
  return 1;
}


stop_wearing(arg) {
  this_player()->end_stone_skin();
  if ( skin ) destruct(skin);
  ::stop_wearing(arg);
  return 1;
}

remove(arg) {
  if ( present(arg) == this_object() && worn ) {
    this_player()->end_stone_skin();
    if ( skin ) destruct(skin);
  }
  ::remove(arg);
  return 1;
}