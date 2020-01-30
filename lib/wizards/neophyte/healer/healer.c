inherit "obj/monster";

int seconds,i;
object *user;
object x;
string spells;

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_level(80);
    set_name("healer");
    set_alias("verot");
    set_race("human");
    set_short("Travelling healer giving a free healings");
    set_long("She is wearing a white cape and small oaken staff.\n"+
             "She is constantly mumbling something about healing.\n");
    set_gender(2);
   set_al(0);
    set_heart_beat(1);
    set_skill("chanting", 100);
    set_skill("channel", 100);
    set_skill("cast divine", 100);
    set_skill("cast wide", 100);
    set_skill("cast major", 100);
    set_skill("mastery of medicine", 100);
    set_wis(query_wis()*10);
    set_max_hp(query_hp()*10);
    set_hp(query_max_hp());
}

void heart_beat() {
   ::heart_beat();
  user = users();
  spells = "chl kfq mar";
  if (!this_object()->query_spell() && !this_object()->query_stunned() && random(100) > 90) {
	  x = clone_object("/guilds/obj/spell");
	  move_object(x,this_object());
	  x->start_spell(spells);
  }
}
