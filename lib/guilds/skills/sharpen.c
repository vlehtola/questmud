/* made by Celtron */

int get_time() {
    return 10;
}
int ep_cost() { return 10; }
query_type() { return "neutral"; }

void resolve_skill(string tgt) {
  object ob, varjo;

  if(!tgt) {
    write("Sharpen what?\n");
    return;
  }
  ob = present(tgt,environment(this_player()));
  if(!ob) ob = present(tgt, this_player());
  if(!ob) {
    write("Sharpen what?\n");
    return;
  }
  if(ob->query_sharpen()) {
    write(ob->short()+" has already been sharpened.\n");
    return;
  }
  if(environment(this_player())->guild_name() != "Smith") {
   write("You don't have the needed equipments to do it.\n");
   return;
 }
  varjo = clone_object("/guilds/skill_obj/sharpen_ob");
  varjo->start(ob);
}

void fail_skill(string str) {
  write("You fail to sharpen your weapon.\n");
}
