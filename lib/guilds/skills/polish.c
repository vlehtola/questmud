/* made by Celtron */

int get_time() {
    return 10;
}
int ep_cost() { return 10; }
query_type() { return "neutral"; }

void resolve_skill(string tgt) {
  object ob;
  int dmg;
  string adj;

  if(!tgt) {
    write("Polish what?\n");
    return;
  }
  ob = present(tgt,environment(this_player()));
  if(!ob) ob = present(tgt, this_player());
  if(!ob) {
    write("Polish what?\n");
    return;
  }
  if(ob->query_dur() > ob->query_max_dur()) {
    write(ob->short()+" has already been polished.\n");
    return;
  }
  if(ob->query_dur() < ob->query_max_dur()) {
    write("You must repair "+ob->short()+" first.\n");
    return;
  }
  if(environment(this_player())->guild_name() != "Smith") {
   write("You don't have the needed equipments to do it.\n");
   return;
 }
  /* maxx +50% dur */
  dmg = ob->query_max_dur() * this_player()->query_skills("polish") / 200;
  dmg = dmg / 2 + random(dmg/2) + 5 + ob->query_max_dur();
  ob->set_dur(dmg, 1);

  if(dmg >= ob->query_max_dur() * 150 / 100) adj = "outstandingly";
  else if(dmg >= ob->query_max_dur() * 140 / 100) adj = "very well";
  else if(dmg >= ob->query_max_dur() * 130 / 100) adj = "well";
  else if(dmg >= ob->query_max_dur() * 120 / 100) adj = "fairly";
  else if(dmg >= ob->query_max_dur() * 110 / 100) adj = "adequatly";
  else adj = "poorly";

  write("You make your best effort to improve "+ob->short()+"'s shape and to remove impurities and rust from it.\n");
  write("Judging your own work you succeeded "+adj+".\n");
  say(this_player()->query_name()+" makes an effort to polish "+ob->short()+".\n");
}

void fail_skill(string str) {
  write("You fail to polish your weapon.\n");
}
