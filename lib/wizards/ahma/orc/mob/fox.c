inherit "obj/monster";
object room, ob;
int h;

reset(arg) {
  string chat_str;
  ::reset(arg);
  if(arg) { return; }
  set_level(random(3)+19);
  set_name("fox");
  set_alt_name("animal");
  set_alias("walkeri");
  set_short("An agile fox");
  set_long("Red-haired, slim animal seems to be digging the ground in here. Foxes jet\n" + 
           "black eyes glitter as it observes its surroundings for possible hostile\n" + 
           "creatures. Foxes' furry, red hides are quite respected among the hunters\n" + 
           "because the foxes are very hard to capture or hunt down for their superior\n" +
           "agility.\n");

  
  if(!chat_str) {
    chat_str = allocate(3);
    chat_str[0] = "Fox swings its red, furry tail.\n";
    chat_str[1] = "Fox eyes at you carefully.\n";
    chat_str[2] = "Fox digs something from the ground and eats it.\n";
  }
  load_chat(3, chat_str);
  
  set_dex(query_dex() + 50);
  set_animal();
  set_special(15);
  if(!h) { call_out("poproom", 1); h++; }
  set_dead_ob(this_object());  
  set_move_at_random(4+random(10));

  set_skill("tumble", 100);
  set_skill("dodge", 90);
  set_skill("alertness", 80);
  set_skill("foresee attack", 60);
  set_al(10);
}

monster_died() {
  call_other(room, "mobdead");
  return 0;
}

poproom() {
  room = environment(this_object());
}

checkroom() {
  if(query_current_room() == "/wizards/ahma/orc/village/vil01") {
  call_out("wrongroom1", 1);
  }
  if(query_current_room() == "/wizards/ahma/orc/forest/for01") {
  call_out("wrongroom2", 4);
  }
  if(query_current_room() == "/wizards/ahma/orc/village/vil14") {
  call_out("wrongroom3", 1);
  }
  if(query_current_room() == "/wizards/ahma/orc/village/vil21") {
  call_out("wrongroom4", 1);
  }
  if(query_current_room() == "/wizards/ahma/orc/village/vil26") {
  call_out("wrongroom5", 1);
  }
}

wrongroom1() { 
  init_command("sw");
  say("Fox arrives from northeast.\n");
  init_command("sw");
  say("Fox arrives from northeast.\n");
  init_command("w");
  say("Fox arrives from east.\n");
}

wrongroom2() {
  init_command("ne");
  say("Fox arrives from southwest.\n");
  init_command("ne");
  say("Fox arrives from southwest.\n");
}

wrongroom3() {
  init_command("w");
  say("Fox arrives from east.\n");
  init_command("sw");
  say("Fox arrives from northeast.\n");
  init_command("s");
  say("Fox arrives from north.\n");
}

special_move() {
  ob = this_object()->query_attack();
  tell_room(environment(this_object()), "Fox quickly disappears in the thick forest.\n");
  move_object(this_object(), "/wizards/ahma/orc/void");
  call_out("spec2", (random(7)+3), ob);
  return 1;
}

spec2(ob) {
  move_object(this_object(), environment(ob));
  tell_room(environment(this_object()), "Fox rushes in behind the trees and attacks.\n");
  attack_object(ob);
  return 1;
}

wrongroom4() {
  init_command("n");
  say("Fox arrives from south.\n");
  init_command("n");
  say("Fox arrives from south.\n");
  if(!random(2))
    { init_command("nw"); say("Fox arrives from southeast.\n"); }
    { init_command("ne"); say("Fox arrives from southwest.\n"); }
}


wrongroom5() {
  init_command("ne");
  say("Fox arrives from southeast.\n");
  init_command("n");
  say("Fox arrives from south.\n");
  if(!random(2)) {
    init_command("nw"); say("Fox arrives from southeast.\n"); init_command("e"); say("Fox arrives from east.\n");
    }
    else {
      if(!random(2)) {
      init_command("nw"); say("Fox arrives from southeast.\n"); init_command("nw"); say("Fox arrives from southeast.\n");
      }
      else {
        return 1;
      }
   }
}
