inherit "obj/monster";

int helpers;
int phase;
object torso,gloves,legs,paper1,paper2,paper3;

reset(arg)
{
 ::reset(arg);

 if (arg)
    {
     return;
     phase = 0;
     helpers = 0;
    }

    set_level(76+random(4));
    set_name("ghost");
    set_alias("navigator_ghost");
    set_short("A enourmous ghost of navigators");
    set_long("The ghost doesn't look like a normal ghost, more like"+
             "several\nghosts binded together. It has everglowing "+
             "bright eye sockets.\n");

    set_al(-100);
    set_undead(1);
    set_aggressive(1);
    set_special(10);
    set_extra(1);
    set_log();
    set_dead_ob(this_object());
    set_str(query_str()+100);
     torso = clone_object("/wizards/neophyte/city/eq/torso.c");
        move_object(torso, this_object());
     init_command("wear mail");
     gloves = clone_object("/wizards/neophyte/city/eq/gloves.c");
        move_object(gloves, this_object());
     init_command("wear gloves");
     legs = clone_object("/wizards/neophyte/city/eq/legs.c");
        move_object(legs, this_object());
     init_command("wear leggings");
     /*
     paper1 = clone_object("/wizards/neophyte/city/eq/paper1");
     move_object(paper1,this_object());
     paper2 = clone_object("/wizards/neophyte/city/eq/paper1");
     move_object(paper2,this_object());
     paper3 = clone_object("/wizards/neophyte/city/eq/paper1");
     move_object(paper3,this_object());
     */
}

catch_tell(str) {
  string who;
  if(sscanf(str, "%s is DEAD, R.I.P.", who) == 1) {
    if(who != "Ghost") {
      tell_room(environment(this_object()), "The ghost looks much more healthier as "+who+" dies.\n");
      this_object()->heal_self(15000);
      return 1;
    }
  }
}

extra() {
  int i;
  if(phase == 4) { return 1; }
  ///*
  phase = get_phase(this_object()->query_hp()*100 / this_object()->query_max_hp());
  //*/
  //tell_room(environment(this_object()),"THE GHOST PHASE IS NOW "+phase+".\n");
  i = phase*10;
  set_special(10+i);
}

get_phase(int i)
{
  switch(i)
  {
   case 0..25: return 4;
   case 26.. 40: return 3;
   case 41..54: return 2;
   case 55..85: return 1;
  }
 return 0;
}

special_move() {
  object ob;
  ob = this_object()->query_attacker();
  if(phase == 0) {
  move_object(ob, "/wizards/neophyte/city/lighthouse/corridor16");
  tell_object(ob, "The ghost pushes you out of the room.\n");
  init_command("close door");
  return 1;
}

if(phase == 1) {
  helper();
  return 1;
}

if(phase == 2) {
  hp_leech();
  return 1;
}

if(phase == 3) {
  move_phase();
  return 1;
}

if(phase ==4) {
  if(!random(2)) {
  hp_leech();
}

if(!random(5)) {
  helper();
  return 1;
 }
}
}
helper() {
  object ghost;
  if(helpers < 3) {
  ghost = clone_object("/wizards/neophyte/city/monst/ghost");
  move_object(ghost,environment(this_object()));
  tell_room(environment(this_object()), "The ghost yells loudly 'ASHOHIA' and a minor ghost appears from shadows.\n");
  helpers += 1;
  return 1;
}
}
hp_leech() {
  object *ob, leechob;
  int x,xx;
  ob = all_inventory(this_object());
  for(x=0;x<sizeof(ob);x++) {
    if(living(ob[x])) {
    xx = random(x);
    if(!ob[xx]->query_hp_leech()) {
    leechob = clone_object("/wizards/neophyte/city/obj/leechob");
    leechob->start(ob[xx],random(120));
    tell_object(ob[xx], "The ghost starts to leech you!\n");
    say("The ghost starts to leech "+ob[xx]->query_name()+"!\n",ob[xx]);
    return 1;
  }
}
}
}
move_phase() {
  object portal;
  tell_room(environment(this_object()), "The ghost chants magical words and suddenly a portal appears from nowhere.\n");
  tell_room(environment(this_object()), "The ghost steps in the portal and it is gone.\n");
  portal = clone_object("/wizards/neophyte/city/obj/portal");
  move_object(portal,environment(this_object()));
  move_object(this_object(), "/wizards/neophyte/city/void");
  phase = 4;
  return 1;
}

reduce_number() {
  helpers -= 1;
}


query_phase() { return phase; }
set_phase(int i) { phase=i; }
query_helper() { return helpers; }

