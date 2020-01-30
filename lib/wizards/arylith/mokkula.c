inherit "obj/monster";

object *user;
object award;
object cash;
object vial;
int i,x;
reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_level(25);
    set_name("khietor");
    set_alias("dryad");
    set_race("human");
    set_short("Khietor the evil dryad");
    set_long("She is dressed in dress made from oak leafs She has a quite\n"+
             "evil look on her face. Maybe you should kill her while she is\n"+
             "still here.\n");
    set_gender(2);
    set_al(50);
    set_heart_beat(1);
    set_dead_ob(this_object());
    set_max_hp(query_hp()*50);
    set_hp(query_max_hp());
    set_max_sp(query_sp()*50);
    set_sp(query_max_sp());
    set_max_ep(query_ep()*50);
    set_ep(query_max_ep());
    set_special(10);
}

void heart_beat() {
   ::heart_beat();
  user = users();
  if (random(100) > 75) {
          for(i=0;i<sizeof(user);i++) {
      x = random(i);
  }
  if(!user[i]->query_wiz() && user[i]->idle() < 600) {
          x = random(i);
      say("Dryad leaves in the puff of smoke.\n");
      cash = present("coins", user[x]);
          move_object(this_object(),environment(user[x]));
          say("Dryad arrives in the puff of smoke.\n");
          tell_object(user[x], "Khietor looks at you and you can't resist the beauty.\n");
          tell_object(user[x], "And suddenly she throws an vial at you!\n");
          vial = clone_object("/guilds/witch/potions/"+({ "fire_single", "cold_single", "electric_single", "poison", "curse", "stun", "firewall", "electricwall", "coldwall",})[random(8)]+".c");
          vial->start(random(50)+5, user[x]);
          if(cash) {
          move_object(cash, this_object());
          tell_object(user[x], "You feel like lost something.\n");
  }
}
}
}

monster_died() {
        call_other("/wizards/yodin/event/khietor/start", "winner", 0);
        shout("The dryad shouts: "+this_player()->query_name()+" got me this time but i will return!\n");
        write("As you give the last hit to dryad, a city guard arrives and gives you something.\n");
        award = clone_object("/obj/new_money");
        award->set_type(6);
        award->add_value(10);
        move_object(award, this_player());
        return 0;
}

special_move() {
        object ob,ob1,tgt;
        int i;
        i = random(20)+5;
        ob1 = this_object()->query_attack();
        tgt = ob1->query_name();
        tell_object(ob1, "Khietor throws vial at you!\n");
        ob = clone_object("/guilds/witch/potions/"+({ "fire_single", "cold_single", "electric_single", "poison", "curse", "stun",})[random(5)]+".c");
        ob->start(i, ob1);
        return 1;
}
