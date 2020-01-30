#include "/guilds/witch/effects.c"
int time, damage;
object tp;

status test(object ob) {
        if(living(ob)) { return 1; }
        return 0;
}

burn() {
  object ob;
  int i;
  ob = all_inventory(environment(this_object()));
  ob = filter_array(ob,"test");
  while(i<sizeof(ob)) {
          if(ob[i]) tell_object(ob[i], "The feezing cold hurts your lungs!\n");
          ob[i]->hit_with_spell(damage, "cold");
          i += 1;
  }
  call_out("burn", 15);
}

short() {
  return "A large cloud is emitting coldness";
}

long() {
  write("It is large cloud.\n");
}

id(str) { return str == "cloud" || str == "coldwall"; }


start(int bonus, object ob) {
        time = bonus+30;
        damage = AREA_DAMA;
        tp = ob;
        if(present("coldwall", environment(tp))) { tell_object(tp, "Nothing happens.\n");
        destruct(this_object()); return 1; }

        move_object(this_object(), environment(tp));
    call_out("remove", time);
  burn();
}

remove() {
  tell_room(environment(this_object()), "The cloud starts moving and it is suddendly gone.\n");
  destruct(this_object());
}

init() {
        add_action("move_test", "north");
        add_action("move_test", "south");
        add_action("move_test", "west");
        add_action("move_test", "east");
        add_action("move_test", "northwest");
        add_action("move_test", "northeast");
        add_action("move_test", "southwest");
        add_action("move_test", "southeast");
}
move_test() {
        write("The freezing cold hurts your lungs as you try to move!\n");
        this_player()->hit_with_spell(damage*2, "cold");
}
