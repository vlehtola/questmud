inherit "obj/monster";
object ob,ring;

reset(arg) {
  ::reset(arg);
  if(arg) { return; }
  set_level(85+random(10));
  set_name("golem");
  set_alias("golem");
  set_short("A huge golem");
  set_long("Nearly 5 meters tall golem, which seems really angry\n"+
           "and it's trying to trample over everything what moves in this room.\n"+
           "You feel very uncomfortable as you are trying to avoid to be crushed\n"+
           "under its big foot. Golem looks like it has grown up from this hard rock\n"+
           "and you feel uncomfortable as you are trying to avoid\n"+
           "to be crushed under it's foot. Golem looks as it is part of\n"+
           "this hard rock.\n");
  set_al(0);
  set_aggressive(1);
set_max_hp(query_max_hp()*2);
set_hp(query_max_hp());
set_str(query_str()*2);
set_special(10);
set_skill("stun", 100);
set_skill("attack", 100);
set_skill("strike", 60);
set_skill("bare hands", 60);
set_skill("tumble", 70);
set_skill("find weakness", 70);
set_skill("agility", 90);
set_skill("critical", 90);
set_skill("enhance critical", 90);
set_skill("dodge", 100);
set_skill("foresee attack", 100);
set_skill("counter spell", 100);
set_skill("reflect spell", 100);
set_skill("doublehit", 100);
set_log();

ring = clone_object("/wizards/kaappi/mine/kamat/rinkula.c");
       move_object(ring, this_object());
       init_command("wear ring");

set_dead_ob(this_object());
}
special_move() {
  object ob;
  ob = this_object()->query_attack();
  tell_object(ob, "Suddenly Golem gets an evil grin in it's face\n"+
                  "and JUMPS towards you. You are crushed under it's feet!\n");
          say("Suddenly Golem gets an evil grin in it's face\n"+
               "and JUMPS towards "+ob->query_name()+". "+ob->query_name()+" is crushed under it's feet!\n");
ob->hit_with_spell(3500, "earth");
}

monster_died() {
 ob = query_attacker();
  if(!ob->query_quests("Help the dwarven miners")) {
   this_object()->query_attack()->set_party_quest("Help the dwarven miners");
   tell_object(this_object()->query_attack(), "You have killed the golem and completed\n"+
              "'Help the dwarven miners' quest.\n"); }
else { tell_object(ob, "You have already completed this quest.\n"); }
return 0;
}
