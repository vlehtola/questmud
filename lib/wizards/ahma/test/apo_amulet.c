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

init() {
  ::init();
  add_action("wear", "wear");
  add_action("remove","remove");
  add_action("drop","drop");
  add_action("give","give");
  add_action("store","store");
}

wear(str) {
  if(!str) return;
  if(present(str) == this_object() && !query_worn()) {
    do_wear();
    if(!skin)
      skin = clone_object("/guilds/spell_obj/stone_skin");
    if(!this_player()->query_stone_skin())
      skin->start(this_player(),-1);
  this_player()->update_stats();
    return 1;
  }
  return;
}


remove(str) {
  if(!str) return;
  if(present(str) == this_object() && query_worn()) {
    if(skin)
      skin->end_stone_skin();
    stop_wearing();
  this_player()->update_stats();
    return 1;
  }
  return;
}

drop(str) {
  if(!str) return;
  if(this_player()->query_keep(this_object())) return;
  if((str == "all" || present(str) == this_object()) && query_worn()) {
    if(skin)
     skin->end_stone_skin();
  this_player()->update_stats();
    return;
  }
  return;
}

give(str) {
  string obj,tgt;
  if(!str) return;
  if(this_player()->query_keep(this_object())) return;
  if(sscanf(str,"%s to %s",obj,tgt) != 2) return;
  if(str == "all" || present(obj) == this_object() && query_worn()) {
    if(skin)
      skin->end_stone_skin();
  this_player()->update_stats();
    return;
  }
  return;
}

store(str) {
        string ob;
        int n;
        if(!str) return;
        if(sscanf(str,"%s to %d",ob,n) != 2) return;
        if(present(ob) == this_object()) {
          if(skin)
            skin->end_stone_skin();
  this_player()->update_stats();
          return;
        }
        return;
}

